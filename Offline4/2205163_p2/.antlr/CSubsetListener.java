// Generated from /home/tanzeem/Documents/Compiler/Offline4/2205163_p2/CSubset.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link CSubsetParser}.
 */
public interface CSubsetListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link CSubsetParser#start}.
	 * @param ctx the parse tree
	 */
	void enterStart(CSubsetParser.StartContext ctx);
	/**
	 * Exit a parse tree produced by {@link CSubsetParser#start}.
	 * @param ctx the parse tree
	 */
	void exitStart(CSubsetParser.StartContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ProgramMultiple}
	 * labeled alternative in {@link CSubsetParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgramMultiple(CSubsetParser.ProgramMultipleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ProgramMultiple}
	 * labeled alternative in {@link CSubsetParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgramMultiple(CSubsetParser.ProgramMultipleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ProgramSingle}
	 * labeled alternative in {@link CSubsetParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgramSingle(CSubsetParser.ProgramSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ProgramSingle}
	 * labeled alternative in {@link CSubsetParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgramSingle(CSubsetParser.ProgramSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnitVariableDeclaration}
	 * labeled alternative in {@link CSubsetParser#unit}.
	 * @param ctx the parse tree
	 */
	void enterUnitVariableDeclaration(CSubsetParser.UnitVariableDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnitVariableDeclaration}
	 * labeled alternative in {@link CSubsetParser#unit}.
	 * @param ctx the parse tree
	 */
	void exitUnitVariableDeclaration(CSubsetParser.UnitVariableDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnitFunctionDeclaration}
	 * labeled alternative in {@link CSubsetParser#unit}.
	 * @param ctx the parse tree
	 */
	void enterUnitFunctionDeclaration(CSubsetParser.UnitFunctionDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnitFunctionDeclaration}
	 * labeled alternative in {@link CSubsetParser#unit}.
	 * @param ctx the parse tree
	 */
	void exitUnitFunctionDeclaration(CSubsetParser.UnitFunctionDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnitFunctionDefinition}
	 * labeled alternative in {@link CSubsetParser#unit}.
	 * @param ctx the parse tree
	 */
	void enterUnitFunctionDefinition(CSubsetParser.UnitFunctionDefinitionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnitFunctionDefinition}
	 * labeled alternative in {@link CSubsetParser#unit}.
	 * @param ctx the parse tree
	 */
	void exitUnitFunctionDefinition(CSubsetParser.UnitFunctionDefinitionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionDeclarationWithParameters}
	 * labeled alternative in {@link CSubsetParser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDeclarationWithParameters(CSubsetParser.FunctionDeclarationWithParametersContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionDeclarationWithParameters}
	 * labeled alternative in {@link CSubsetParser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDeclarationWithParameters(CSubsetParser.FunctionDeclarationWithParametersContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionDeclarationWithoutParameters}
	 * labeled alternative in {@link CSubsetParser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDeclarationWithoutParameters(CSubsetParser.FunctionDeclarationWithoutParametersContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionDeclarationWithoutParameters}
	 * labeled alternative in {@link CSubsetParser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDeclarationWithoutParameters(CSubsetParser.FunctionDeclarationWithoutParametersContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionDefinitionWithParameters}
	 * labeled alternative in {@link CSubsetParser#func_definition}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDefinitionWithParameters(CSubsetParser.FunctionDefinitionWithParametersContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionDefinitionWithParameters}
	 * labeled alternative in {@link CSubsetParser#func_definition}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDefinitionWithParameters(CSubsetParser.FunctionDefinitionWithParametersContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionDefinitionWithoutParameters}
	 * labeled alternative in {@link CSubsetParser#func_definition}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDefinitionWithoutParameters(CSubsetParser.FunctionDefinitionWithoutParametersContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionDefinitionWithoutParameters}
	 * labeled alternative in {@link CSubsetParser#func_definition}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDefinitionWithoutParameters(CSubsetParser.FunctionDefinitionWithoutParametersContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParameterUnnamedAppend}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameterUnnamedAppend(CSubsetParser.ParameterUnnamedAppendContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParameterUnnamedAppend}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameterUnnamedAppend(CSubsetParser.ParameterUnnamedAppendContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParameterInvalidSingle}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameterInvalidSingle(CSubsetParser.ParameterInvalidSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParameterInvalidSingle}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameterInvalidSingle(CSubsetParser.ParameterInvalidSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParameterNamedAppend}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameterNamedAppend(CSubsetParser.ParameterNamedAppendContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParameterNamedAppend}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameterNamedAppend(CSubsetParser.ParameterNamedAppendContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParameterInvalidAppend}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameterInvalidAppend(CSubsetParser.ParameterInvalidAppendContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParameterInvalidAppend}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameterInvalidAppend(CSubsetParser.ParameterInvalidAppendContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParameterUnnamedSingle}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameterUnnamedSingle(CSubsetParser.ParameterUnnamedSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParameterUnnamedSingle}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameterUnnamedSingle(CSubsetParser.ParameterUnnamedSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParameterNamedSingle}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameterNamedSingle(CSubsetParser.ParameterNamedSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParameterNamedSingle}
	 * labeled alternative in {@link CSubsetParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameterNamedSingle(CSubsetParser.ParameterNamedSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code CompoundWithStatements}
	 * labeled alternative in {@link CSubsetParser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void enterCompoundWithStatements(CSubsetParser.CompoundWithStatementsContext ctx);
	/**
	 * Exit a parse tree produced by the {@code CompoundWithStatements}
	 * labeled alternative in {@link CSubsetParser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void exitCompoundWithStatements(CSubsetParser.CompoundWithStatementsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code CompoundEmpty}
	 * labeled alternative in {@link CSubsetParser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void enterCompoundEmpty(CSubsetParser.CompoundEmptyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code CompoundEmpty}
	 * labeled alternative in {@link CSubsetParser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void exitCompoundEmpty(CSubsetParser.CompoundEmptyContext ctx);
	/**
	 * Enter a parse tree produced by {@link CSubsetParser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void enterVar_declaration(CSubsetParser.Var_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link CSubsetParser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void exitVar_declaration(CSubsetParser.Var_declarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code TypeInt}
	 * labeled alternative in {@link CSubsetParser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void enterTypeInt(CSubsetParser.TypeIntContext ctx);
	/**
	 * Exit a parse tree produced by the {@code TypeInt}
	 * labeled alternative in {@link CSubsetParser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void exitTypeInt(CSubsetParser.TypeIntContext ctx);
	/**
	 * Enter a parse tree produced by the {@code TypeFloat}
	 * labeled alternative in {@link CSubsetParser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void enterTypeFloat(CSubsetParser.TypeFloatContext ctx);
	/**
	 * Exit a parse tree produced by the {@code TypeFloat}
	 * labeled alternative in {@link CSubsetParser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void exitTypeFloat(CSubsetParser.TypeFloatContext ctx);
	/**
	 * Enter a parse tree produced by the {@code TypeVoid}
	 * labeled alternative in {@link CSubsetParser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void enterTypeVoid(CSubsetParser.TypeVoidContext ctx);
	/**
	 * Exit a parse tree produced by the {@code TypeVoid}
	 * labeled alternative in {@link CSubsetParser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void exitTypeVoid(CSubsetParser.TypeVoidContext ctx);
	/**
	 * Enter a parse tree produced by the {@code DeclarationArrayAppend}
	 * labeled alternative in {@link CSubsetParser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void enterDeclarationArrayAppend(CSubsetParser.DeclarationArrayAppendContext ctx);
	/**
	 * Exit a parse tree produced by the {@code DeclarationArrayAppend}
	 * labeled alternative in {@link CSubsetParser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void exitDeclarationArrayAppend(CSubsetParser.DeclarationArrayAppendContext ctx);
	/**
	 * Enter a parse tree produced by the {@code DeclarationInvalidAppend}
	 * labeled alternative in {@link CSubsetParser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void enterDeclarationInvalidAppend(CSubsetParser.DeclarationInvalidAppendContext ctx);
	/**
	 * Exit a parse tree produced by the {@code DeclarationInvalidAppend}
	 * labeled alternative in {@link CSubsetParser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void exitDeclarationInvalidAppend(CSubsetParser.DeclarationInvalidAppendContext ctx);
	/**
	 * Enter a parse tree produced by the {@code DeclarationArraySingle}
	 * labeled alternative in {@link CSubsetParser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void enterDeclarationArraySingle(CSubsetParser.DeclarationArraySingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code DeclarationArraySingle}
	 * labeled alternative in {@link CSubsetParser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void exitDeclarationArraySingle(CSubsetParser.DeclarationArraySingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code DeclarationScalarAppend}
	 * labeled alternative in {@link CSubsetParser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void enterDeclarationScalarAppend(CSubsetParser.DeclarationScalarAppendContext ctx);
	/**
	 * Exit a parse tree produced by the {@code DeclarationScalarAppend}
	 * labeled alternative in {@link CSubsetParser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void exitDeclarationScalarAppend(CSubsetParser.DeclarationScalarAppendContext ctx);
	/**
	 * Enter a parse tree produced by the {@code DeclarationScalarSingle}
	 * labeled alternative in {@link CSubsetParser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void enterDeclarationScalarSingle(CSubsetParser.DeclarationScalarSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code DeclarationScalarSingle}
	 * labeled alternative in {@link CSubsetParser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void exitDeclarationScalarSingle(CSubsetParser.DeclarationScalarSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementsSingle}
	 * labeled alternative in {@link CSubsetParser#statements}.
	 * @param ctx the parse tree
	 */
	void enterStatementsSingle(CSubsetParser.StatementsSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementsSingle}
	 * labeled alternative in {@link CSubsetParser#statements}.
	 * @param ctx the parse tree
	 */
	void exitStatementsSingle(CSubsetParser.StatementsSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementsMultiple}
	 * labeled alternative in {@link CSubsetParser#statements}.
	 * @param ctx the parse tree
	 */
	void enterStatementsMultiple(CSubsetParser.StatementsMultipleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementsMultiple}
	 * labeled alternative in {@link CSubsetParser#statements}.
	 * @param ctx the parse tree
	 */
	void exitStatementsMultiple(CSubsetParser.StatementsMultipleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementVariableDeclaration}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatementVariableDeclaration(CSubsetParser.StatementVariableDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementVariableDeclaration}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatementVariableDeclaration(CSubsetParser.StatementVariableDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementExpression}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatementExpression(CSubsetParser.StatementExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementExpression}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatementExpression(CSubsetParser.StatementExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementCompound}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatementCompound(CSubsetParser.StatementCompoundContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementCompound}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatementCompound(CSubsetParser.StatementCompoundContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementFor}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatementFor(CSubsetParser.StatementForContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementFor}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatementFor(CSubsetParser.StatementForContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementIf}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatementIf(CSubsetParser.StatementIfContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementIf}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatementIf(CSubsetParser.StatementIfContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementIfElse}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatementIfElse(CSubsetParser.StatementIfElseContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementIfElse}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatementIfElse(CSubsetParser.StatementIfElseContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementWhile}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatementWhile(CSubsetParser.StatementWhileContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementWhile}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatementWhile(CSubsetParser.StatementWhileContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementPrintln}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatementPrintln(CSubsetParser.StatementPrintlnContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementPrintln}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatementPrintln(CSubsetParser.StatementPrintlnContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StatementReturn}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatementReturn(CSubsetParser.StatementReturnContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StatementReturn}
	 * labeled alternative in {@link CSubsetParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatementReturn(CSubsetParser.StatementReturnContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExpressionStatementEmpty}
	 * labeled alternative in {@link CSubsetParser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void enterExpressionStatementEmpty(CSubsetParser.ExpressionStatementEmptyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExpressionStatementEmpty}
	 * labeled alternative in {@link CSubsetParser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void exitExpressionStatementEmpty(CSubsetParser.ExpressionStatementEmptyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExpressionStatementNormal}
	 * labeled alternative in {@link CSubsetParser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void enterExpressionStatementNormal(CSubsetParser.ExpressionStatementNormalContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExpressionStatementNormal}
	 * labeled alternative in {@link CSubsetParser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void exitExpressionStatementNormal(CSubsetParser.ExpressionStatementNormalContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExpressionStatementMissingSemicolon}
	 * labeled alternative in {@link CSubsetParser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void enterExpressionStatementMissingSemicolon(CSubsetParser.ExpressionStatementMissingSemicolonContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExpressionStatementMissingSemicolon}
	 * labeled alternative in {@link CSubsetParser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void exitExpressionStatementMissingSemicolon(CSubsetParser.ExpressionStatementMissingSemicolonContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VariableScalar}
	 * labeled alternative in {@link CSubsetParser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariableScalar(CSubsetParser.VariableScalarContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VariableScalar}
	 * labeled alternative in {@link CSubsetParser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariableScalar(CSubsetParser.VariableScalarContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VariableArray}
	 * labeled alternative in {@link CSubsetParser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariableArray(CSubsetParser.VariableArrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VariableArray}
	 * labeled alternative in {@link CSubsetParser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariableArray(CSubsetParser.VariableArrayContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExpressionLogic}
	 * labeled alternative in {@link CSubsetParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpressionLogic(CSubsetParser.ExpressionLogicContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExpressionLogic}
	 * labeled alternative in {@link CSubsetParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpressionLogic(CSubsetParser.ExpressionLogicContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExpressionAssign}
	 * labeled alternative in {@link CSubsetParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpressionAssign(CSubsetParser.ExpressionAssignContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExpressionAssign}
	 * labeled alternative in {@link CSubsetParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpressionAssign(CSubsetParser.ExpressionAssignContext ctx);
	/**
	 * Enter a parse tree produced by the {@code LogicSingle}
	 * labeled alternative in {@link CSubsetParser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void enterLogicSingle(CSubsetParser.LogicSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code LogicSingle}
	 * labeled alternative in {@link CSubsetParser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void exitLogicSingle(CSubsetParser.LogicSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code LogicBinary}
	 * labeled alternative in {@link CSubsetParser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void enterLogicBinary(CSubsetParser.LogicBinaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code LogicBinary}
	 * labeled alternative in {@link CSubsetParser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void exitLogicBinary(CSubsetParser.LogicBinaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code RelSingle}
	 * labeled alternative in {@link CSubsetParser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void enterRelSingle(CSubsetParser.RelSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code RelSingle}
	 * labeled alternative in {@link CSubsetParser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void exitRelSingle(CSubsetParser.RelSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code RelBinary}
	 * labeled alternative in {@link CSubsetParser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void enterRelBinary(CSubsetParser.RelBinaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code RelBinary}
	 * labeled alternative in {@link CSubsetParser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void exitRelBinary(CSubsetParser.RelBinaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SimpleSingle}
	 * labeled alternative in {@link CSubsetParser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void enterSimpleSingle(CSubsetParser.SimpleSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SimpleSingle}
	 * labeled alternative in {@link CSubsetParser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void exitSimpleSingle(CSubsetParser.SimpleSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SimpleBinary}
	 * labeled alternative in {@link CSubsetParser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void enterSimpleBinary(CSubsetParser.SimpleBinaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SimpleBinary}
	 * labeled alternative in {@link CSubsetParser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void exitSimpleBinary(CSubsetParser.SimpleBinaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SimpleInvalidAssignment}
	 * labeled alternative in {@link CSubsetParser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void enterSimpleInvalidAssignment(CSubsetParser.SimpleInvalidAssignmentContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SimpleInvalidAssignment}
	 * labeled alternative in {@link CSubsetParser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void exitSimpleInvalidAssignment(CSubsetParser.SimpleInvalidAssignmentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code TermSingle}
	 * labeled alternative in {@link CSubsetParser#term}.
	 * @param ctx the parse tree
	 */
	void enterTermSingle(CSubsetParser.TermSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code TermSingle}
	 * labeled alternative in {@link CSubsetParser#term}.
	 * @param ctx the parse tree
	 */
	void exitTermSingle(CSubsetParser.TermSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code TermBinary}
	 * labeled alternative in {@link CSubsetParser#term}.
	 * @param ctx the parse tree
	 */
	void enterTermBinary(CSubsetParser.TermBinaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code TermBinary}
	 * labeled alternative in {@link CSubsetParser#term}.
	 * @param ctx the parse tree
	 */
	void exitTermBinary(CSubsetParser.TermBinaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryAdd}
	 * labeled alternative in {@link CSubsetParser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void enterUnaryAdd(CSubsetParser.UnaryAddContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryAdd}
	 * labeled alternative in {@link CSubsetParser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void exitUnaryAdd(CSubsetParser.UnaryAddContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryNot}
	 * labeled alternative in {@link CSubsetParser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void enterUnaryNot(CSubsetParser.UnaryNotContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryNot}
	 * labeled alternative in {@link CSubsetParser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void exitUnaryNot(CSubsetParser.UnaryNotContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryFactor}
	 * labeled alternative in {@link CSubsetParser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void enterUnaryFactor(CSubsetParser.UnaryFactorContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryFactor}
	 * labeled alternative in {@link CSubsetParser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void exitUnaryFactor(CSubsetParser.UnaryFactorContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FactorVariable}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactorVariable(CSubsetParser.FactorVariableContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FactorVariable}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactorVariable(CSubsetParser.FactorVariableContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FactorFunctionCall}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactorFunctionCall(CSubsetParser.FactorFunctionCallContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FactorFunctionCall}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactorFunctionCall(CSubsetParser.FactorFunctionCallContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FactorParenthesized}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactorParenthesized(CSubsetParser.FactorParenthesizedContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FactorParenthesized}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactorParenthesized(CSubsetParser.FactorParenthesizedContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FactorInt}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactorInt(CSubsetParser.FactorIntContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FactorInt}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactorInt(CSubsetParser.FactorIntContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FactorFloat}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactorFloat(CSubsetParser.FactorFloatContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FactorFloat}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactorFloat(CSubsetParser.FactorFloatContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FactorIncrement}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactorIncrement(CSubsetParser.FactorIncrementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FactorIncrement}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactorIncrement(CSubsetParser.FactorIncrementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FactorDecrement}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactorDecrement(CSubsetParser.FactorDecrementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FactorDecrement}
	 * labeled alternative in {@link CSubsetParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactorDecrement(CSubsetParser.FactorDecrementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ArgumentListNonEmpty}
	 * labeled alternative in {@link CSubsetParser#argument_list}.
	 * @param ctx the parse tree
	 */
	void enterArgumentListNonEmpty(CSubsetParser.ArgumentListNonEmptyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ArgumentListNonEmpty}
	 * labeled alternative in {@link CSubsetParser#argument_list}.
	 * @param ctx the parse tree
	 */
	void exitArgumentListNonEmpty(CSubsetParser.ArgumentListNonEmptyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ArgumentListEmpty}
	 * labeled alternative in {@link CSubsetParser#argument_list}.
	 * @param ctx the parse tree
	 */
	void enterArgumentListEmpty(CSubsetParser.ArgumentListEmptyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ArgumentListEmpty}
	 * labeled alternative in {@link CSubsetParser#argument_list}.
	 * @param ctx the parse tree
	 */
	void exitArgumentListEmpty(CSubsetParser.ArgumentListEmptyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ArgumentsSingle}
	 * labeled alternative in {@link CSubsetParser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArgumentsSingle(CSubsetParser.ArgumentsSingleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ArgumentsSingle}
	 * labeled alternative in {@link CSubsetParser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArgumentsSingle(CSubsetParser.ArgumentsSingleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ArgumentsMultiple}
	 * labeled alternative in {@link CSubsetParser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArgumentsMultiple(CSubsetParser.ArgumentsMultipleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ArgumentsMultiple}
	 * labeled alternative in {@link CSubsetParser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArgumentsMultiple(CSubsetParser.ArgumentsMultipleContext ctx);
}