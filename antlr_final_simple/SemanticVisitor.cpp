#include "SemanticVisitor.h"

#include <iomanip>
#include <sstream>

using namespace std;

// ============================================================
// Basic helpers
// ============================================================

SemanticVisitor::SemanticVisitor(string source, ofstream& logFile, int totalLines)
    : source(source), logFile(logFile), totalLines(totalLines) {
    declarationType = "error";
    nextCompoundIsFunctionBody = false;
    lastUnitBlankLines = 2;
    symbolTable.enterScope();
}

void SemanticVisitor::writeErrorFile(string fileName) {
    ofstream errorFile(fileName, ios::trunc);

    for (string error : errors) {
        errorFile << error << "\n\n";
    }
}

void SemanticVisitor::addError(antlr4::ParserRuleContext* ctx, string message) {
    int line = ctx->getStart()->getLine();
    string full = "Error at line " + to_string(line) + ": " + message;

    errors.push_back(full);
    logFile << full << "\n\n";
}

SemanticVisitor::NodeInfo SemanticVisitor::getInfo(any value) {
    if (!value.has_value()) {
        return NodeInfo();
    }
    return any_cast<NodeInfo>(value);
}

string SemanticVisitor::sourceText(antlr4::ParserRuleContext* ctx) {
    if (ctx == nullptr || ctx->getStart() == nullptr || ctx->getStop() == nullptr) {
        return "";
    }

    size_t start = ctx->getStart()->getStartIndex();
    size_t stop = ctx->getStop()->getStopIndex();

    if (start == (size_t)-1 || stop == (size_t)-1 ||
        start > stop || start >= source.size()) {
        return ctx->getText();
    }

    if (stop >= source.size()) {
        stop = source.size() - 1;
    }

    return source.substr(start, stop - start + 1);
}

string SemanticVisitor::gapBetween(antlr4::ParserRuleContext* left,
                                   antlr4::ParserRuleContext* right) {
    if (left == nullptr || right == nullptr ||
        left->getStop() == nullptr || right->getStart() == nullptr) {
        return "\n";
    }

    size_t leftStop = left->getStop()->getStopIndex();
    size_t rightStart = right->getStart()->getStartIndex();

    if (leftStop == (size_t)-1 || rightStart == (size_t)-1 ||
        rightStart <= leftStop + 1 || leftStop + 1 >= source.size()) {
        return "\n";
    }

    return source.substr(leftStop + 1, rightStart - leftStop - 1);
}

SemanticVisitor::NodeInfo SemanticVisitor::makeInfo(
    antlr4::ParserRuleContext* /* ctx */,
    string correctedText,
    bool changed) {

    NodeInfo result;
    result.changed = changed;
    result.text = correctedText;

    return result;
}

void SemanticVisitor::logRule(antlr4::ParserRuleContext* ctx,
                              string rule,
                              string production,
                              string text,
                              int line,
                              int blankLines) {
    if (line == 0) {
        line = ctx->getStart()->getLine();
    }

    logFile << "Line " << line << ": " << rule << " : " << production
            << "\n\n";

    while (!text.empty() && (text.back() == '\n' || text.back() == '\r')) {
        text.pop_back();
    }

    if (!text.empty()) {
        logFile << text << "\n";
        for (int i = 0; i < blankLines; i++) {
            logFile << "\n";
        }
    } else {
        for (int i = 1; i < blankLines; i++) {
            logFile << "\n";
        }
    }
}

// ============================================================
// Type helpers
// ============================================================

bool SemanticVisitor::canAssign(string leftType, string rightType) {
    if (leftType == "error" || rightType == "error") {
        return true;
    }

    // int -> float is allowed.
    if (leftType == "float" && rightType == "int") {
        return true;
    }

    return leftType == rightType;
}

string SemanticVisitor::arithmeticType(string leftType, string rightType) {
    if (leftType == "error" || rightType == "error") {
        return "error";
    }

    if (leftType == "void" || rightType == "void") {
        return "error";
    }

    if (leftType == "float" || rightType == "float") {
        return "float";
    }

    return "int";
}

bool SemanticVisitor::checkVoid(antlr4::ParserRuleContext* ctx,
                                ExprInfo& left,
                                ExprInfo& right) {
    if (left.type != "void" && right.type != "void") {
        return false;
    }

    addError(ctx, "Void function used in expression");
    left.type = "error";
    right.type = "error";
    return true;
}

// ============================================================
// Symbol-table helpers
// ============================================================

SymbolInfo* SemanticVisitor::lookup(string name) {
    return symbolTable.lookUp(name);
}

SymbolInfo* SemanticVisitor::lookupCurrent(string name) {
    return symbolTable.lookUpCurrent(name);
}

SymbolInfo* SemanticVisitor::insertSymbol(string name) {
    return symbolTable.insertAndGet(name, "ID");
}

bool SemanticVisitor::hasParameter(vector<ParameterInfo> parameters, string name) {
    if (name.empty()) {
        return false;
    }

    for (ParameterInfo parameter : parameters) {
        if (parameter.name == name) {
            return true;
        }
    }

    return false;
}

void SemanticVisitor::addFunction(antlr4::ParserRuleContext* ctx,
                                  string name,
                                  string returnType,
                                  vector<ParameterInfo> parameters,
                                  bool definition) {
    SymbolInfo* symbol = lookupCurrent(name);

    vector<string> parameterTypes;
    for (ParameterInfo parameter : parameters) {
        parameterTypes.push_back(parameter.type);
    }

    // First declaration/definition of this name.
    if (symbol == nullptr) {
        symbol = insertSymbol(name);

        symbol->setFunction(true);
        symbol->setReturnType(returnType);
        symbol->setDefinedFunction(definition);
        symbol->setParameterTypes(parameterTypes);
        return;
    }

    // Variable with same name, repeated declaration, or repeated definition.
    if (!symbol->isFunction() || !definition || symbol->isDefinedFunction()) {
        addError(ctx, "Multiple declaration of " + name);
        return;
    }

    // Here the previous symbol is a declaration and this is its definition.
    vector<string> oldTypes = symbol->getParameterTypes();

    if (symbol->getReturnType() != returnType) {
        addError(
            ctx,
            "Return type mismatch with function declaration in function " + name);
    } else if (oldTypes.size() != parameterTypes.size()) {
        addError(
            ctx,
            "Total number of arguments mismatch with declaration in function " +
                name);
    } else {
        for (int i = 0; i < (int)parameterTypes.size(); i++) {
            if (oldTypes[i] != parameterTypes[i]) {
                addError(
                    ctx,
                    to_string(i + 1) +
                        "th argument mismatch with declaration in function " + name);
                break;
            }
        }
    }

    symbol->setDefinedFunction(true);
}

void SemanticVisitor::enterFunctionScope(vector<ParameterInfo> parameters) {
    symbolTable.enterScope();

    for (ParameterInfo parameter : parameters) {
        if (parameter.name.empty() || parameter.type == "void") {
            continue;
        }

        // Duplicate parameter was already reported in parameter_list.
        if (lookupCurrent(parameter.name) != nullptr) {
            continue;
        }

        SymbolInfo* symbol = insertSymbol(parameter.name);
        symbol->setDataType(parameter.type);
        symbol->setArray(false);
        symbol->setFunction(false);
    }
}

void SemanticVisitor::declareVariable(antlr4::ParserRuleContext* ctx,
                                      string name,
                                      bool isArray) {
    if (declarationType == "void") {
        return;
    }

    if (lookupCurrent(name) != nullptr) {
        addError(ctx, "Multiple declaration of " + name);
        return;
    }

    SymbolInfo* symbol = insertSymbol(name);
    symbol->setDataType(declarationType);
    symbol->setArray(isArray);
    symbol->setFunction(false);
}

// ============================================================
// start / program / unit
// ============================================================

any SemanticVisitor::visitStart(CSubsetParser::StartContext* ctx) {
    NodeInfo program = getInfo(visit(ctx->program()));
    NodeInfo result = makeInfo(ctx, program.text, program.changed);

    logRule(ctx, "start", "program", "", 0, 3);
    symbolTable.printAll(logFile);
    logFile << "Total lines: " << totalLines << "\n";
    logFile << "Total errors: " << errors.size() << "\n\n";

    return result;
}

any SemanticVisitor::visitProgramMultiple(
    CSubsetParser::ProgramMultipleContext* ctx) {
    NodeInfo previous = getInfo(visit(ctx->previous));
    NodeInfo current = getInfo(visit(ctx->current));

    bool changed = previous.changed || current.changed;
    string separator =
        (!previous.text.empty() && previous.text.back() == '}') ? "\n\n" : "\n";
    string corrected = previous.text + separator + current.text;

    NodeInfo result = makeInfo(ctx, corrected, changed);

    int line = ctx->current->getStart()->getLine();
    logRule(ctx, "program", "program unit", result.text, line, lastUnitBlankLines);
    return result;
}

any SemanticVisitor::visitProgramSingle(
    CSubsetParser::ProgramSingleContext* ctx) {
    NodeInfo current = getInfo(visit(ctx->current));
    NodeInfo result = makeInfo(ctx, current.text, current.changed);

    int line = ctx->current->getStart()->getLine();
    logRule(ctx, "program", "unit", result.text, line, lastUnitBlankLines);
    return result;
}

any SemanticVisitor::visitUnitVariableDeclaration(
    CSubsetParser::UnitVariableDeclarationContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->var_declaration()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);

    lastUnitBlankLines = 2;
    logRule(ctx, "unit", "var_declaration", result.text, 0, 2);
    return result;
}

any SemanticVisitor::visitUnitFunctionDeclaration(
    CSubsetParser::UnitFunctionDeclarationContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->func_declaration()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);

    lastUnitBlankLines = 2;
    logRule(ctx, "unit", "func_declaration", result.text, 0, 2);
    return result;
}

any SemanticVisitor::visitUnitFunctionDefinition(
    CSubsetParser::UnitFunctionDefinitionContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->func_definition()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);

    lastUnitBlankLines = 3;
    logRule(ctx, "unit", "func_definition", result.text, 0, 3);
    return result;
}

// ============================================================
// Functions
// ============================================================

any SemanticVisitor::visitFunctionDeclarationWithParameters(
    CSubsetParser::FunctionDeclarationWithParametersContext* ctx) {
    NodeInfo type = getInfo(visit(ctx->type_specifier()));
    NodeInfo params = getInfo(visit(ctx->parameter_list()));

    string name = ctx->ID()->getText();
    addFunction(ctx, name, type.type, params.parameters, false);

    // Declaration scopes are not printed, but they count in scope numbering.
    symbolTable.enterScope();
    symbolTable.exitScope();

    bool changed = type.changed || params.changed;
    string corrected = type.type + " " + name + "(" + params.text + ");";
    NodeInfo result = makeInfo(ctx, corrected, changed);

    logRule(
        ctx,
        "func_declaration",
        "type_specifier ID LPAREN parameter_list RPAREN SEMICOLON",
        result.text,
        0,
        2);
    return result;
}

any SemanticVisitor::visitFunctionDeclarationWithoutParameters(
    CSubsetParser::FunctionDeclarationWithoutParametersContext* ctx) {
    NodeInfo type = getInfo(visit(ctx->type_specifier()));

    string name = ctx->ID()->getText();
    vector<ParameterInfo> parameters;
    addFunction(ctx, name, type.type, parameters, false);

    symbolTable.enterScope();
    symbolTable.exitScope();

    string corrected = type.type + " " + name + "();";
    NodeInfo result = makeInfo(ctx, corrected, type.changed);

    logRule(
        ctx,
        "func_declaration",
        "type_specifier ID LPAREN RPAREN SEMICOLON",
        result.text,
        0,
        2);
    return result;
}

any SemanticVisitor::visitFunctionDefinitionWithParameters(
    CSubsetParser::FunctionDefinitionWithParametersContext* ctx) {
    NodeInfo type = getInfo(visit(ctx->type_specifier()));
    NodeInfo params = getInfo(visit(ctx->parameter_list()));

    string name = ctx->ID()->getText();

    for (int i = 0; i < (int)params.parameters.size(); i++) {
        if (params.parameters[i].name.empty()) {
            addError(
                ctx,
                to_string(i + 1) +
                    "th parameter's name not given in function definition of " +
                    name);
        }
    }

    addFunction(ctx, name, type.type, params.parameters, true);

    enterFunctionScope(params.parameters);
    nextCompoundIsFunctionBody = true;
    NodeInfo body = getInfo(visit(ctx->compound_statement()));
    symbolTable.exitScope();

    bool changed = type.changed || params.changed || body.changed;
    string corrected =
        type.type + " " + name + "(" + params.text + ")" + body.text;

    NodeInfo result = makeInfo(ctx, corrected, changed);

    logRule(
        ctx,
        "func_definition",
        "type_specifier ID LPAREN parameter_list RPAREN compound_statement",
        result.text,
        0,
        2);
    return result;
}

any SemanticVisitor::visitFunctionDefinitionWithoutParameters(
    CSubsetParser::FunctionDefinitionWithoutParametersContext* ctx) {
    NodeInfo type = getInfo(visit(ctx->type_specifier()));

    string name = ctx->ID()->getText();
    vector<ParameterInfo> parameters;
    addFunction(ctx, name, type.type, parameters, true);

    enterFunctionScope(parameters);
    nextCompoundIsFunctionBody = true;
    NodeInfo body = getInfo(visit(ctx->compound_statement()));
    symbolTable.exitScope();

    bool changed = type.changed || body.changed;
    string corrected = type.type + " " + name + "()" + body.text;
    NodeInfo result = makeInfo(ctx, corrected, changed);

    logRule(
        ctx,
        "func_definition",
        "type_specifier ID LPAREN RPAREN compound_statement",
        result.text,
        0,
        2);
    return result;
}

// ============================================================
// parameter_list
// ============================================================

any SemanticVisitor::visitParameterNamedSingle(
    CSubsetParser::ParameterNamedSingleContext* ctx) {
    NodeInfo type = getInfo(visit(ctx->type_specifier()));

    ParameterInfo parameter;
    parameter.type = type.type;
    parameter.name = ctx->ID()->getText();

    string corrected = parameter.type + " " + parameter.name;
    NodeInfo result = makeInfo(ctx, corrected, type.changed);
    result.parameters.push_back(parameter);

    logRule(ctx, "parameter_list", "type_specifier ID", result.text);
    return result;
}

any SemanticVisitor::visitParameterUnnamedSingle(
    CSubsetParser::ParameterUnnamedSingleContext* ctx) {
    NodeInfo type = getInfo(visit(ctx->type_specifier()));

    ParameterInfo parameter;
    parameter.type = type.type;
    parameter.name = "";

    NodeInfo result = makeInfo(ctx, parameter.type, type.changed);
    result.parameters.push_back(parameter);

    logRule(ctx, "parameter_list", "type_specifier", result.text);
    return result;
}

any SemanticVisitor::visitParameterNamedAppend(
    CSubsetParser::ParameterNamedAppendContext* ctx) {
    NodeInfo previous = getInfo(visit(ctx->previous));
    NodeInfo type = getInfo(visit(ctx->type_specifier()));

    ParameterInfo parameter;
    parameter.type = type.type;
    parameter.name = ctx->ID()->getText();

    if (hasParameter(previous.parameters, parameter.name)) {
        addError(ctx, "Multiple declaration of " + parameter.name + " in parameter");
    }

    bool changed = previous.changed || type.changed;
    string corrected = previous.text + "," + parameter.type + " " + parameter.name;

    NodeInfo result = makeInfo(ctx, corrected, changed);
    result.parameters = previous.parameters;
    result.parameters.push_back(parameter);

    logRule(
        ctx,
        "parameter_list",
        "parameter_list COMMA type_specifier ID",
        result.text);
    return result;
}

any SemanticVisitor::visitParameterUnnamedAppend(
    CSubsetParser::ParameterUnnamedAppendContext* ctx) {
    NodeInfo previous = getInfo(visit(ctx->previous));
    NodeInfo type = getInfo(visit(ctx->type_specifier()));

    ParameterInfo parameter;
    parameter.type = type.type;
    parameter.name = "";

    bool changed = previous.changed || type.changed;
    string corrected = previous.text + "," + parameter.type;

    NodeInfo result = makeInfo(ctx, corrected, changed);
    result.parameters = previous.parameters;
    result.parameters.push_back(parameter);

    logRule(
        ctx,
        "parameter_list",
        "parameter_list COMMA type_specifier",
        result.text);
    return result;
}

any SemanticVisitor::visitParameterInvalidSingle(
    CSubsetParser::ParameterInvalidSingleContext* ctx) {
    NodeInfo type = getInfo(visit(ctx->type_specifier()));

    ParameterInfo parameter;
    parameter.type = type.type;
    parameter.name = "";

    NodeInfo result = makeInfo(ctx, parameter.type, true);
    result.parameters.push_back(parameter);

    // Expected order: valid prefix log first, then syntax error.
    logRule(ctx, "parameter_list", "type_specifier", result.text);
    addError(
        ctx,
        "syntax error, unexpected token(s) '" +
            ctx->ADDOP()->getText() + "' before ')'" );
    return result;
}

any SemanticVisitor::visitParameterInvalidAppend(
    CSubsetParser::ParameterInvalidAppendContext* ctx) {
    NodeInfo previous = getInfo(visit(ctx->previous));
    NodeInfo type = getInfo(visit(ctx->type_specifier()));

    ParameterInfo parameter;
    parameter.type = type.type;
    parameter.name = "";

    string corrected = previous.text + "," + parameter.type;
    NodeInfo result = makeInfo(ctx, corrected, true);
    result.parameters = previous.parameters;
    result.parameters.push_back(parameter);

    logRule(
        ctx,
        "parameter_list",
        "parameter_list COMMA type_specifier",
        result.text);
    addError(
        ctx,
        "syntax error, unexpected token(s) '" +
            ctx->ADDOP()->getText() + "' before ')'" );
    return result;
}

// ============================================================
// compound_statement / declarations / type_specifier
// ============================================================

any SemanticVisitor::visitCompoundWithStatements(
    CSubsetParser::CompoundWithStatementsContext* ctx) {
    bool functionBody = nextCompoundIsFunctionBody;
    nextCompoundIsFunctionBody = false;

    if (!functionBody) {
        symbolTable.enterScope();
    }

    NodeInfo statements = getInfo(visit(ctx->statements()));

    string corrected = "{\n" + statements.text + "\n}";
    NodeInfo result = makeInfo(ctx, corrected, statements.changed);

    logRule(
        ctx,
        "compound_statement",
        "LCURL statements RCURL",
        result.text,
        0,
        4);

    symbolTable.printAll(logFile);

    if (!functionBody) {
        symbolTable.exitScope();
    }

    return result;
}

any SemanticVisitor::visitCompoundEmpty(
    CSubsetParser::CompoundEmptyContext* ctx) {
    bool functionBody = nextCompoundIsFunctionBody;
    nextCompoundIsFunctionBody = false;

    if (!functionBody) {
        symbolTable.enterScope();
    }

    NodeInfo result = makeInfo(ctx, "{}", false);

    logRule(
        ctx,
        "compound_statement",
        "LCURL RCURL",
        result.text,
        0,
        4);

    symbolTable.printAll(logFile);

    if (!functionBody) {
        symbolTable.exitScope();
    }

    return result;
}

any SemanticVisitor::visitVar_declaration(
    CSubsetParser::Var_declarationContext* ctx) {
    NodeInfo type = getInfo(visit(ctx->type_specifier()));

    string oldType = declarationType;
    declarationType = type.type;

    NodeInfo list = getInfo(visit(ctx->declaration_list()));

    if (declarationType == "void") {
        addError(ctx, "Variable type cannot be void");
    }

    bool changed = type.changed || list.changed;
    string corrected = declarationType + " " + list.text + ";";
    NodeInfo result = makeInfo(ctx, corrected, changed);

    logRule(
        ctx,
        "var_declaration",
        "type_specifier declaration_list SEMICOLON",
        result.text);

    declarationType = oldType;
    return result;
}

any SemanticVisitor::visitTypeInt(CSubsetParser::TypeIntContext* ctx) {
    NodeInfo result = makeInfo(ctx, "int", false);
    result.type = "int";
    logRule(ctx, "type_specifier", "INT", result.text);
    return result;
}

any SemanticVisitor::visitTypeFloat(CSubsetParser::TypeFloatContext* ctx) {
    NodeInfo result = makeInfo(ctx, "float", false);
    result.type = "float";
    logRule(ctx, "type_specifier", "FLOAT", result.text);
    return result;
}

any SemanticVisitor::visitTypeVoid(CSubsetParser::TypeVoidContext* ctx) {
    NodeInfo result = makeInfo(ctx, "void", false);
    result.type = "void";
    logRule(ctx, "type_specifier", "VOID", result.text);
    return result;
}

any SemanticVisitor::visitDeclarationScalarSingle(
    CSubsetParser::DeclarationScalarSingleContext* ctx) {
    string name = ctx->ID()->getText();
    declareVariable(ctx, name, false);

    NodeInfo result = makeInfo(ctx, name, false);
    logRule(ctx, "declaration_list", "ID", result.text);
    return result;
}

any SemanticVisitor::visitDeclarationArraySingle(
    CSubsetParser::DeclarationArraySingleContext* ctx) {
    string name = ctx->ID()->getText();
    declareVariable(ctx, name, true);

    string corrected = name + "[" + ctx->CONST_INT()->getText() + "]";
    NodeInfo result = makeInfo(ctx, corrected, false);

    logRule(
        ctx,
        "declaration_list",
        "ID LTHIRD CONST_INT RTHIRD",
        result.text);
    return result;
}

any SemanticVisitor::visitDeclarationScalarAppend(
    CSubsetParser::DeclarationScalarAppendContext* ctx) {
    NodeInfo previous = getInfo(visit(ctx->previous));

    string name = ctx->ID()->getText();
    declareVariable(ctx, name, false);

    string corrected = previous.text + "," + name;
    NodeInfo result = makeInfo(ctx, corrected, previous.changed);

    logRule(
        ctx,
        "declaration_list",
        "declaration_list COMMA ID",
        result.text);
    return result;
}

any SemanticVisitor::visitDeclarationArrayAppend(
    CSubsetParser::DeclarationArrayAppendContext* ctx) {
    NodeInfo previous = getInfo(visit(ctx->previous));

    string name = ctx->ID()->getText();
    declareVariable(ctx, name, true);

    string current = name + "[" + ctx->CONST_INT()->getText() + "]";
    string corrected = previous.text + "," + current;
    NodeInfo result = makeInfo(ctx, corrected, previous.changed);

    logRule(
        ctx,
        "declaration_list",
        "declaration_list COMMA ID LTHIRD CONST_INT RTHIRD",
        result.text);
    return result;
}

any SemanticVisitor::visitDeclarationInvalidAppend(
    CSubsetParser::DeclarationInvalidAppendContext* ctx) {
    NodeInfo previous = getInfo(visit(ctx->previous));

    string bad = ctx->ADDOP()->getText() + " " + ctx->ID()->getText();
    addError(
        ctx,
        "syntax error, unexpected token(s) '" + bad +
            "' in declaration list");

    NodeInfo result = makeInfo(ctx, previous.text, true);
    return result;
}

// ============================================================
// statements / statement
// ============================================================

any SemanticVisitor::visitStatementsSingle(
    CSubsetParser::StatementsSingleContext* ctx) {
    NodeInfo statement = getInfo(visit(ctx->statement()));
    NodeInfo result = makeInfo(ctx, statement.text, statement.changed);

    logRule(ctx, "statements", "statement", result.text, 0, 2);
    return result;
}

any SemanticVisitor::visitStatementsMultiple(
    CSubsetParser::StatementsMultipleContext* ctx) {
    NodeInfo previous = getInfo(visit(ctx->previous));
    NodeInfo current = getInfo(visit(ctx->current));

    bool changed = previous.changed || current.changed;
    string corrected = previous.text + "\n" + current.text;
    NodeInfo result = makeInfo(ctx, corrected, changed);

    int line = ctx->current->getStart()->getLine();
    logRule(ctx, "statements", "statements statement", result.text, line, 2);
    return result;
}

any SemanticVisitor::visitStatementVariableDeclaration(
    CSubsetParser::StatementVariableDeclarationContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->var_declaration()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);

    logRule(ctx, "statement", "var_declaration", result.text, 0, 2);
    return result;
}

any SemanticVisitor::visitStatementExpression(
    CSubsetParser::StatementExpressionContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->expression_statement()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);

    logRule(ctx, "statement", "expression_statement", result.text, 0, 2);
    return result;
}

any SemanticVisitor::visitStatementCompound(
    CSubsetParser::StatementCompoundContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->compound_statement()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);

    logRule(ctx, "statement", "compound_statement", result.text, 0, 2);
    return result;
}

any SemanticVisitor::visitStatementFor(
    CSubsetParser::StatementForContext* ctx) {
    NodeInfo init = getInfo(visit(ctx->init));
    NodeInfo condition = getInfo(visit(ctx->condition));
    NodeInfo update = getInfo(visit(ctx->update));
    NodeInfo body = getInfo(visit(ctx->body));

    bool changed = init.changed || condition.changed ||
                   update.changed || body.changed;

    string corrected =
        "for(" + init.text + condition.text + update.text + ")" + body.text;

    NodeInfo result = makeInfo(ctx, corrected, changed);

    logRule(
        ctx,
        "statement",
        "FOR LPAREN expression_statement expression_statement expression RPAREN statement",
        result.text,
        0,
        2);
    return result;
}

any SemanticVisitor::visitStatementIfElse(
    CSubsetParser::StatementIfElseContext* ctx) {
    NodeInfo condition = getInfo(visit(ctx->condition));
    NodeInfo thenBranch = getInfo(visit(ctx->thenBranch));
    NodeInfo elseBranch = getInfo(visit(ctx->elseBranch));

    bool changed = condition.changed || thenBranch.changed || elseBranch.changed;

    string corrected =
        "if (" + condition.text + ")" + thenBranch.text +
        "\nelse\n" + elseBranch.text;

    NodeInfo result = makeInfo(ctx, corrected, changed);

    logRule(
        ctx,
        "statement",
        "IF LPAREN expression RPAREN statement ELSE statement",
        result.text,
        0,
        2);
    return result;
}

any SemanticVisitor::visitStatementIf(
    CSubsetParser::StatementIfContext* ctx) {
    NodeInfo condition = getInfo(visit(ctx->condition));
    NodeInfo thenBranch = getInfo(visit(ctx->thenBranch));

    bool changed = condition.changed || thenBranch.changed;
    string corrected = "if (" + condition.text + ")" + thenBranch.text;
    NodeInfo result = makeInfo(ctx, corrected, changed);

    logRule(
        ctx,
        "statement",
        "IF LPAREN expression RPAREN statement",
        result.text,
        0,
        2);
    return result;
}

any SemanticVisitor::visitStatementWhile(
    CSubsetParser::StatementWhileContext* ctx) {
    NodeInfo condition = getInfo(visit(ctx->condition));
    NodeInfo body = getInfo(visit(ctx->body));

    bool changed = condition.changed || body.changed;
    string corrected = "while (" + condition.text + ")" + body.text;
    NodeInfo result = makeInfo(ctx, corrected, changed);

    logRule(
        ctx,
        "statement",
        "WHILE LPAREN expression RPAREN statement",
        result.text,
        0,
        2);
    return result;
}

any SemanticVisitor::visitStatementPrintln(
    CSubsetParser::StatementPrintlnContext* ctx) {
    string name = ctx->ID()->getText();
    SymbolInfo* symbol = lookup(name);

    if (symbol == nullptr || symbol->isFunction()) {
        addError(ctx, "Undeclared variable " + name);
    } else if (symbol->isArray()) {
        addError(ctx, "Type mismatch, " + name + " is an array");
    }

    NodeInfo result = makeInfo(ctx, "printf(" + name + ");", false);
    logRule(
        ctx,
        "statement",
        "PRINTLN LPAREN ID RPAREN SEMICOLON",
        result.text,
        0,
        2);
    return result;
}

any SemanticVisitor::visitStatementReturn(
    CSubsetParser::StatementReturnContext* ctx) {
    NodeInfo expression = getInfo(visit(ctx->expression()));

    if (expression.type == "void") {
        addError(ctx, "Void function used in expression");
    }

    string corrected = "return " + expression.text + ";";
    NodeInfo result = makeInfo(ctx, corrected, expression.changed);

    logRule(
        ctx,
        "statement",
        "RETURN expression SEMICOLON",
        result.text,
        0,
        2);
    return result;
}

// ============================================================
// expression_statement
// ============================================================

any SemanticVisitor::visitExpressionStatementEmpty(
    CSubsetParser::ExpressionStatementEmptyContext* ctx) {
    NodeInfo result = makeInfo(ctx, ";", false);
    logRule(ctx, "expression_statement", "SEMICOLON", result.text);
    return result;
}

any SemanticVisitor::visitExpressionStatementNormal(
    CSubsetParser::ExpressionStatementNormalContext* ctx) {
    NodeInfo expression = getInfo(visit(ctx->expression()));

    string corrected = expression.text + ";";
    NodeInfo result = makeInfo(ctx, corrected, expression.changed);

    logRule(
        ctx,
        "expression_statement",
        "expression SEMICOLON",
        result.text);
    return result;
}

any SemanticVisitor::visitExpressionStatementMissingSemicolon(
    CSubsetParser::ExpressionStatementMissingSemicolonContext* ctx) {
    NodeInfo expression = getInfo(visit(ctx->expression()));

    NodeInfo result = makeInfo(ctx, expression.text, true);

    addError(
        ctx,
        "syntax error, missing ';' after expression '" + result.text + "'");

    logRule(
        ctx,
        "expression_statement",
        "expression (missing SEMICOLON)",
        result.text);
    return result;
}

// ============================================================
// variable / expression
// ============================================================

any SemanticVisitor::visitVariableScalar(
    CSubsetParser::VariableScalarContext* ctx) {
    string name = ctx->ID()->getText();
    SymbolInfo* symbol = lookup(name);

    NodeInfo result = makeInfo(ctx, name, false);

    if (symbol == nullptr || symbol->isFunction()) {
        addError(ctx, "Undeclared variable " + name);
        result.type = "error";
    } else if (symbol->isArray()) {
        addError(ctx, "Type mismatch, " + name + " is an array");
        result.type = "error";
    } else {
        result.type = symbol->getDataType();
    }

    logRule(ctx, "variable", "ID", result.text);
    return result;
}

any SemanticVisitor::visitVariableArray(
    CSubsetParser::VariableArrayContext* ctx) {
    NodeInfo index = getInfo(visit(ctx->index));

    string name = ctx->ID()->getText();
    SymbolInfo* symbol = lookup(name);

    string corrected = name + "[" + index.text + "]";
    NodeInfo result = makeInfo(ctx, corrected, index.changed);

    if (symbol == nullptr || symbol->isFunction()) {
        addError(ctx, "Undeclared variable " + name);
        result.type = "error";
    } else if (!symbol->isArray()) {
        addError(ctx, name + " not an array");
        result.type = "error";
    } else {
        if (index.type != "int" && index.type != "error") {
            addError(ctx, "Expression inside third brackets not an integer");
        }

        result.type = symbol->getDataType();
        if (index.type == "error") {
            result.type = "error";
        }
    }

    logRule(ctx, "variable", "ID LTHIRD expression RTHIRD", result.text);
    return result;
}

any SemanticVisitor::visitExpressionLogic(
    CSubsetParser::ExpressionLogicContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->logic_expression()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);
    result.type = child.type;
    result.isZero = child.isZero;

    // The spelling below intentionally matches the supplied logs.
    logRule(ctx, "expression", "logic expression", result.text);
    return result;
}

any SemanticVisitor::visitExpressionAssign(
    CSubsetParser::ExpressionAssignContext* ctx) {
    NodeInfo left = getInfo(visit(ctx->variable()));
    NodeInfo right = getInfo(visit(ctx->logic_expression()));

    if (right.type == "void") {
        addError(ctx, "Void function used in expression");
        right.type = "error";
    } else if (!canAssign(left.type, right.type)) {
        addError(ctx, "Type Mismatch");
    }

    bool changed = left.changed || right.changed;
    string corrected = left.text + "=" + right.text;
    NodeInfo result = makeInfo(ctx, corrected, changed);

    result.type = left.type;
    if (left.type == "error" || right.type == "error") {
        result.type = "error";
    }

    logRule(
        ctx,
        "expression",
        "variable ASSIGNOP logic_expression",
        result.text);
    return result;
}

// ============================================================
// logic / relational / arithmetic expressions
// ============================================================

any SemanticVisitor::visitLogicSingle(
    CSubsetParser::LogicSingleContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->rel_expression()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);
    result.type = child.type;
    result.isZero = child.isZero;

    logRule(ctx, "logic_expression", "rel_expression", result.text);
    return result;
}

any SemanticVisitor::visitLogicBinary(
    CSubsetParser::LogicBinaryContext* ctx) {
    NodeInfo leftNode = getInfo(visit(ctx->left));
    NodeInfo rightNode = getInfo(visit(ctx->right));

    ExprInfo left(leftNode.type, leftNode.isZero);
    ExprInfo right(rightNode.type, rightNode.isZero);
    checkVoid(ctx, left, right);

    bool changed = leftNode.changed || rightNode.changed;
    string corrected =
        leftNode.text + ctx->LOGICOP()->getText() + rightNode.text;

    NodeInfo result = makeInfo(ctx, corrected, changed);
    if (left.type == "error" || right.type == "error") {
        result.type = "error";
    } else {
        result.type = "int";
    }

    logRule(
        ctx,
        "logic_expression",
        "rel_expression LOGICOP rel_expression",
        result.text);
    return result;
}

any SemanticVisitor::visitRelSingle(
    CSubsetParser::RelSingleContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->simple_expression()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);
    result.type = child.type;
    result.isZero = child.isZero;

    logRule(ctx, "rel_expression", "simple_expression", result.text);
    return result;
}

any SemanticVisitor::visitRelBinary(
    CSubsetParser::RelBinaryContext* ctx) {
    NodeInfo leftNode = getInfo(visit(ctx->left));
    NodeInfo rightNode = getInfo(visit(ctx->right));

    ExprInfo left(leftNode.type, leftNode.isZero);
    ExprInfo right(rightNode.type, rightNode.isZero);
    checkVoid(ctx, left, right);

    bool changed = leftNode.changed || rightNode.changed;
    string corrected =
        leftNode.text + ctx->RELOP()->getText() + rightNode.text;

    NodeInfo result = makeInfo(ctx, corrected, changed);
    if (left.type == "error" || right.type == "error") {
        result.type = "error";
    } else {
        result.type = "int";
    }

    logRule(
        ctx,
        "rel_expression",
        "simple_expression RELOP simple_expression",
        result.text);
    return result;
}

any SemanticVisitor::visitSimpleSingle(
    CSubsetParser::SimpleSingleContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->term()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);
    result.type = child.type;
    result.isZero = child.isZero;

    logRule(ctx, "simple_expression", "term", result.text);
    return result;
}

any SemanticVisitor::visitSimpleBinary(
    CSubsetParser::SimpleBinaryContext* ctx) {
    NodeInfo leftNode = getInfo(visit(ctx->left));
    NodeInfo rightNode = getInfo(visit(ctx->right));

    ExprInfo left(leftNode.type, leftNode.isZero);
    ExprInfo right(rightNode.type, rightNode.isZero);
    checkVoid(ctx, left, right);

    bool changed = leftNode.changed || rightNode.changed;
    string corrected =
        leftNode.text + ctx->ADDOP()->getText() + rightNode.text;

    NodeInfo result = makeInfo(ctx, corrected, changed);
    result.type = arithmeticType(left.type, right.type);

    logRule(
        ctx,
        "simple_expression",
        "simple_expression ADDOP term",
        result.text);
    return result;
}

any SemanticVisitor::visitSimpleInvalidAssignment(
    CSubsetParser::SimpleInvalidAssignmentContext* ctx) {
    NodeInfo left = getInfo(visit(ctx->left));

    addError(
        ctx,
        "syntax error, invalid operand '=' after '" +
            ctx->ADDOP()->getText() + "'");

    NodeInfo result = makeInfo(ctx, left.text, true);
    result.type = left.type;
    result.isZero = left.isZero;

    // This malformed intermediate rule is not logged in the expected output.
    return result;
}

any SemanticVisitor::visitTermSingle(
    CSubsetParser::TermSingleContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->unary_expression()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);
    result.type = child.type;
    result.isZero = child.isZero;

    logRule(ctx, "term", "unary_expression", result.text);
    return result;
}

any SemanticVisitor::visitTermBinary(
    CSubsetParser::TermBinaryContext* ctx) {
    NodeInfo leftNode = getInfo(visit(ctx->left));
    NodeInfo rightNode = getInfo(visit(ctx->right));

    ExprInfo left(leftNode.type, leftNode.isZero);
    ExprInfo right(rightNode.type, rightNode.isZero);
    bool hadVoid = checkVoid(ctx, left, right);

    string op = ctx->MULOP()->getText();

    bool changed = leftNode.changed || rightNode.changed;
    string corrected = leftNode.text + op + rightNode.text;
    NodeInfo result = makeInfo(ctx, corrected, changed);

    if (hadVoid) {
        result.type = "error";
    } else if (op == "%") {
        if (left.type != "error" && right.type != "error" &&
            (left.type != "int" || right.type != "int")) {
            addError(ctx, "Non-Integer operand on modulus operator");
            result.type = "error";
        } else {
            if (left.type == "error" || right.type == "error") {
                result.type = "error";
            } else {
                result.type = "int";
            }

            if (right.type == "int" && right.isZero) {
                addError(ctx, "Modulus by Zero");
            }
        }
    } else {
        result.type = arithmeticType(left.type, right.type);
    }

    logRule(ctx, "term", "term MULOP unary_expression", result.text);
    return result;
}

// ============================================================
// unary_expression / factor
// ============================================================

any SemanticVisitor::visitUnaryAdd(
    CSubsetParser::UnaryAddContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->operand));

    NodeInfo result = makeInfo(
        ctx,
        ctx->ADDOP()->getText() + child.text,
        child.changed);

    result.type = child.type;
    result.isZero = child.isZero;

    if (result.type == "void") {
        addError(ctx, "Void function used in expression");
        result.type = "error";
    }

    logRule(ctx, "unary_expression", "ADDOP unary_expression", result.text);
    return result;
}

any SemanticVisitor::visitUnaryNot(
    CSubsetParser::UnaryNotContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->operand));

    NodeInfo result = makeInfo(ctx, "!" + child.text, child.changed);

    if (child.type == "void") {
        addError(ctx, "Void function used in expression");
        result.type = "error";
    } else if (child.type == "error") {
        result.type = "error";
    } else {
        result.type = "int";
    }

    // This production spelling intentionally matches the supplied logs.
    logRule(ctx, "unary_expression", "NOT unary expression", result.text);
    return result;
}

any SemanticVisitor::visitUnaryFactor(
    CSubsetParser::UnaryFactorContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->factor()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);
    result.type = child.type;
    result.isZero = child.isZero;

    logRule(ctx, "unary_expression", "factor", result.text);
    return result;
}

any SemanticVisitor::visitFactorVariable(
    CSubsetParser::FactorVariableContext* ctx) {
    NodeInfo child = getInfo(visit(ctx->variable()));
    NodeInfo result = makeInfo(ctx, child.text, child.changed);
    result.type = child.type;
    result.isZero = child.isZero;

    logRule(ctx, "factor", "variable", result.text);
    return result;
}

any SemanticVisitor::visitFactorFunctionCall(
    CSubsetParser::FactorFunctionCallContext* ctx) {
    NodeInfo argumentList = getInfo(visit(ctx->argument_list()));

    string name = ctx->ID()->getText();
    SymbolInfo* symbol = lookup(name);

    string corrected = name + "(" + argumentList.text + ")";
    NodeInfo result = makeInfo(ctx, corrected, argumentList.changed);

    if (symbol == nullptr) {
        addError(ctx, "Undeclared function " + name);
        result.type = "error";
    } else if (!symbol->isFunction()) {
        addError(ctx, name + " is not a function");
        result.type = "error";
    } else {
        vector<string> expected = symbol->getParameterTypes();

        if (expected.size() != argumentList.arguments.size()) {
            addError(
                ctx,
                "Total number of arguments mismatch in function " + name);
        } else {
            for (int i = 0; i < (int)argumentList.arguments.size(); i++) {
                if (!canAssign(expected[i], argumentList.arguments[i].type)) {
                    addError(
                        ctx,
                        to_string(i + 1) +
                            "th argument mismatch in function " + name);
                    break;
                }
            }
        }

        result.type = symbol->getReturnType();
    }

    logRule(
        ctx,
        "factor",
        "ID LPAREN argument_list RPAREN",
        result.text);
    return result;
}

any SemanticVisitor::visitFactorParenthesized(
    CSubsetParser::FactorParenthesizedContext* ctx) {
    NodeInfo expression = getInfo(visit(ctx->expression()));

    NodeInfo result = makeInfo(
        ctx,
        "(" + expression.text + ")",
        expression.changed);
    result.type = expression.type;
    result.isZero = expression.isZero;

    logRule(ctx, "factor", "LPAREN expression RPAREN", result.text);
    return result;
}

any SemanticVisitor::visitFactorInt(
    CSubsetParser::FactorIntContext* ctx) {
    NodeInfo result = makeInfo(ctx, ctx->CONST_INT()->getText(), false);
    result.type = "int";
    result.isZero = (ctx->CONST_INT()->getText() == "0");

    logRule(ctx, "factor", "CONST_INT", result.text);
    return result;
}

any SemanticVisitor::visitFactorFloat(
    CSubsetParser::FactorFloatContext* ctx) {
    ostringstream formatted;
    formatted << fixed << setprecision(2)
              << stod(ctx->CONST_FLOAT()->getText());

    NodeInfo result = makeInfo(ctx, formatted.str(), false);
    result.type = "float";

    logRule(ctx, "factor", "CONST_FLOAT", result.text);
    return result;
}

any SemanticVisitor::visitFactorIncrement(
    CSubsetParser::FactorIncrementContext* ctx) {
    NodeInfo variable = getInfo(visit(ctx->variable()));

    NodeInfo result = makeInfo(
        ctx,
        variable.text + "++",
        variable.changed);
    result.type = variable.type;

    logRule(ctx, "factor", "variable INCOP", result.text);
    return result;
}

any SemanticVisitor::visitFactorDecrement(
    CSubsetParser::FactorDecrementContext* ctx) {
    NodeInfo variable = getInfo(visit(ctx->variable()));

    NodeInfo result = makeInfo(
        ctx,
        variable.text + "--",
        variable.changed);
    result.type = variable.type;

    logRule(ctx, "factor", "variable DECOP", result.text);
    return result;
}

// ============================================================
// argument_list / arguments
// ============================================================

any SemanticVisitor::visitArgumentListNonEmpty(
    CSubsetParser::ArgumentListNonEmptyContext* ctx) {
    NodeInfo arguments = getInfo(visit(ctx->arguments()));

    NodeInfo result = makeInfo(ctx, arguments.text, arguments.changed);
    result.arguments = arguments.arguments;

    logRule(ctx, "argument_list", "arguments", result.text);
    return result;
}

any SemanticVisitor::visitArgumentListEmpty(
    CSubsetParser::ArgumentListEmptyContext* ctx) {
    (void)ctx;
    NodeInfo result;
    result.text = "";
    result.changed = false;

    // The expected logs omit the epsilon argument_list rule.
    return result;
}

any SemanticVisitor::visitArgumentsSingle(
    CSubsetParser::ArgumentsSingleContext* ctx) {
    NodeInfo current = getInfo(visit(ctx->current));

    ExprInfo argument(current.type, current.isZero);
    if (argument.type == "void") {
        addError(ctx, "Void function used in expression");
        argument.type = "error";
    }

    NodeInfo result = makeInfo(ctx, current.text, current.changed);
    result.arguments.push_back(argument);

    logRule(ctx, "arguments", "logic_expression", result.text);
    return result;
}

any SemanticVisitor::visitArgumentsMultiple(
    CSubsetParser::ArgumentsMultipleContext* ctx) {
    NodeInfo previous = getInfo(visit(ctx->previous));
    NodeInfo current = getInfo(visit(ctx->current));

    ExprInfo argument(current.type, current.isZero);
    if (argument.type == "void") {
        addError(ctx, "Void function used in expression");
        argument.type = "error";
    }

    bool changed = previous.changed || current.changed;
    string corrected = previous.text + "," + current.text;
    NodeInfo result = makeInfo(ctx, corrected, changed);

    result.arguments = previous.arguments;
    result.arguments.push_back(argument);

    logRule(
        ctx,
        "arguments",
        "arguments COMMA logic_expression",
        result.text);
    return result;
}
