// Generated from /home/tanzeem/Documents/Compiler/Offline4/2205163_p2/CSubset.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class CSubsetParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LINE_COMMENT=1, BLOCK_COMMENT=2, STRING=3, WS=4, IF=5, ELSE=6, FOR=7, 
		WHILE=8, PRINTLN=9, RETURN=10, INT=11, FLOAT=12, VOID=13, LPAREN=14, RPAREN=15, 
		LCURL=16, RCURL=17, LTHIRD=18, RTHIRD=19, SEMICOLON=20, COMMA=21, INCOP=22, 
		DECOP=23, ADDOP=24, MULOP=25, NOT=26, RELOP=27, LOGICOP=28, ASSIGNOP=29, 
		ID=30, CONST_FLOAT=31, CONST_INT=32, UNKNOWN=33;
	public static final int
		RULE_start = 0, RULE_program = 1, RULE_unit = 2, RULE_func_declaration = 3, 
		RULE_func_definition = 4, RULE_parameter_list = 5, RULE_compound_statement = 6, 
		RULE_var_declaration = 7, RULE_type_specifier = 8, RULE_declaration_list = 9, 
		RULE_statements = 10, RULE_statement = 11, RULE_expression_statement = 12, 
		RULE_variable = 13, RULE_expression = 14, RULE_logic_expression = 15, 
		RULE_rel_expression = 16, RULE_simple_expression = 17, RULE_term = 18, 
		RULE_unary_expression = 19, RULE_factor = 20, RULE_argument_list = 21, 
		RULE_arguments = 22;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "program", "unit", "func_declaration", "func_definition", "parameter_list", 
			"compound_statement", "var_declaration", "type_specifier", "declaration_list", 
			"statements", "statement", "expression_statement", "variable", "expression", 
			"logic_expression", "rel_expression", "simple_expression", "term", "unary_expression", 
			"factor", "argument_list", "arguments"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, "'if'", "'else'", "'for'", "'while'", "'println'", 
			"'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
			"'['", "']'", "';'", "','", "'++'", "'--'", null, null, "'!'", null, 
			null, "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
			"FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
			"RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
			"INCOP", "DECOP", "ADDOP", "MULOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", 
			"ID", "CONST_FLOAT", "CONST_INT", "UNKNOWN"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "CSubset.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public CSubsetParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStart(this);
		}
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(46);
			program(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	 
		public ProgramContext() { }
		public void copyFrom(ProgramContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ProgramMultipleContext extends ProgramContext {
		public ProgramContext previous;
		public UnitContext current;
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public UnitContext unit() {
			return getRuleContext(UnitContext.class,0);
		}
		public ProgramMultipleContext(ProgramContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterProgramMultiple(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitProgramMultiple(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ProgramSingleContext extends ProgramContext {
		public UnitContext current;
		public UnitContext unit() {
			return getRuleContext(UnitContext.class,0);
		}
		public ProgramSingleContext(ProgramContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterProgramSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitProgramSingle(this);
		}
	}

	public final ProgramContext program() throws RecognitionException {
		return program(0);
	}

	private ProgramContext program(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ProgramContext _localctx = new ProgramContext(_ctx, _parentState);
		ProgramContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_program, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new ProgramSingleContext(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(49);
			((ProgramSingleContext)_localctx).current = unit();
			}
			_ctx.stop = _input.LT(-1);
			setState(55);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ProgramMultipleContext(new ProgramContext(_parentctx, _parentState));
					((ProgramMultipleContext)_localctx).previous = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_program);
					setState(51);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(52);
					((ProgramMultipleContext)_localctx).current = unit();
					}
					} 
				}
				setState(57);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnitContext extends ParserRuleContext {
		public UnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unit; }
	 
		public UnitContext() { }
		public void copyFrom(UnitContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UnitFunctionDefinitionContext extends UnitContext {
		public Func_definitionContext func_definition() {
			return getRuleContext(Func_definitionContext.class,0);
		}
		public UnitFunctionDefinitionContext(UnitContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterUnitFunctionDefinition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitUnitFunctionDefinition(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UnitFunctionDeclarationContext extends UnitContext {
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public UnitFunctionDeclarationContext(UnitContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterUnitFunctionDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitUnitFunctionDeclaration(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UnitVariableDeclarationContext extends UnitContext {
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public UnitVariableDeclarationContext(UnitContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterUnitVariableDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitUnitVariableDeclaration(this);
		}
	}

	public final UnitContext unit() throws RecognitionException {
		UnitContext _localctx = new UnitContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_unit);
		try {
			setState(61);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				_localctx = new UnitVariableDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(58);
				var_declaration();
				}
				break;
			case 2:
				_localctx = new UnitFunctionDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(59);
				func_declaration();
				}
				break;
			case 3:
				_localctx = new UnitFunctionDefinitionContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(60);
				func_definition();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_declarationContext extends ParserRuleContext {
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	 
		public Func_declarationContext() { }
		public void copyFrom(Func_declarationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FunctionDeclarationWithParametersContext extends Func_declarationContext {
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public TerminalNode SEMICOLON() { return getToken(CSubsetParser.SEMICOLON, 0); }
		public FunctionDeclarationWithParametersContext(Func_declarationContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFunctionDeclarationWithParameters(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFunctionDeclarationWithParameters(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FunctionDeclarationWithoutParametersContext extends Func_declarationContext {
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public TerminalNode SEMICOLON() { return getToken(CSubsetParser.SEMICOLON, 0); }
		public FunctionDeclarationWithoutParametersContext(Func_declarationContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFunctionDeclarationWithoutParameters(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFunctionDeclarationWithoutParameters(this);
		}
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_declaration);
		try {
			setState(76);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				_localctx = new FunctionDeclarationWithParametersContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(63);
				type_specifier();
				setState(64);
				match(ID);
				setState(65);
				match(LPAREN);
				setState(66);
				parameter_list(0);
				setState(67);
				match(RPAREN);
				setState(68);
				match(SEMICOLON);
				}
				break;
			case 2:
				_localctx = new FunctionDeclarationWithoutParametersContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(70);
				type_specifier();
				setState(71);
				match(ID);
				setState(72);
				match(LPAREN);
				setState(73);
				match(RPAREN);
				setState(74);
				match(SEMICOLON);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_definitionContext extends ParserRuleContext {
		public Func_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_definition; }
	 
		public Func_definitionContext() { }
		public void copyFrom(Func_definitionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FunctionDefinitionWithParametersContext extends Func_definitionContext {
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public FunctionDefinitionWithParametersContext(Func_definitionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFunctionDefinitionWithParameters(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFunctionDefinitionWithParameters(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FunctionDefinitionWithoutParametersContext extends Func_definitionContext {
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public FunctionDefinitionWithoutParametersContext(Func_definitionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFunctionDefinitionWithoutParameters(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFunctionDefinitionWithoutParameters(this);
		}
	}

	public final Func_definitionContext func_definition() throws RecognitionException {
		Func_definitionContext _localctx = new Func_definitionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_func_definition);
		try {
			setState(91);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				_localctx = new FunctionDefinitionWithParametersContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(78);
				type_specifier();
				setState(79);
				match(ID);
				setState(80);
				match(LPAREN);
				setState(81);
				parameter_list(0);
				setState(82);
				match(RPAREN);
				setState(83);
				compound_statement();
				}
				break;
			case 2:
				_localctx = new FunctionDefinitionWithoutParametersContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(85);
				type_specifier();
				setState(86);
				match(ID);
				setState(87);
				match(LPAREN);
				setState(88);
				match(RPAREN);
				setState(89);
				compound_statement();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_listContext extends ParserRuleContext {
		public Parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list; }
	 
		public Parameter_listContext() { }
		public void copyFrom(Parameter_listContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParameterUnnamedAppendContext extends Parameter_listContext {
		public Parameter_listContext previous;
		public TerminalNode COMMA() { return getToken(CSubsetParser.COMMA, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public ParameterUnnamedAppendContext(Parameter_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterParameterUnnamedAppend(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitParameterUnnamedAppend(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParameterInvalidSingleContext extends Parameter_listContext {
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(CSubsetParser.ADDOP, 0); }
		public ParameterInvalidSingleContext(Parameter_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterParameterInvalidSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitParameterInvalidSingle(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParameterNamedAppendContext extends Parameter_listContext {
		public Parameter_listContext previous;
		public TerminalNode COMMA() { return getToken(CSubsetParser.COMMA, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public ParameterNamedAppendContext(Parameter_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterParameterNamedAppend(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitParameterNamedAppend(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParameterInvalidAppendContext extends Parameter_listContext {
		public Parameter_listContext previous;
		public TerminalNode COMMA() { return getToken(CSubsetParser.COMMA, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(CSubsetParser.ADDOP, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public ParameterInvalidAppendContext(Parameter_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterParameterInvalidAppend(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitParameterInvalidAppend(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParameterUnnamedSingleContext extends Parameter_listContext {
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public ParameterUnnamedSingleContext(Parameter_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterParameterUnnamedSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitParameterUnnamedSingle(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParameterNamedSingleContext extends Parameter_listContext {
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public ParameterNamedSingleContext(Parameter_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterParameterNamedSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitParameterNamedSingle(this);
		}
	}

	public final Parameter_listContext parameter_list() throws RecognitionException {
		return parameter_list(0);
	}

	private Parameter_listContext parameter_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Parameter_listContext _localctx = new Parameter_listContext(_ctx, _parentState);
		Parameter_listContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_parameter_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(101);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				_localctx = new ParameterNamedSingleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(94);
				type_specifier();
				setState(95);
				match(ID);
				}
				break;
			case 2:
				{
				_localctx = new ParameterUnnamedSingleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(97);
				type_specifier();
				}
				break;
			case 3:
				{
				_localctx = new ParameterInvalidSingleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(98);
				type_specifier();
				setState(99);
				match(ADDOP);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(118);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(116);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new ParameterNamedAppendContext(new Parameter_listContext(_parentctx, _parentState));
						((ParameterNamedAppendContext)_localctx).previous = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(103);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(104);
						match(COMMA);
						setState(105);
						type_specifier();
						setState(106);
						match(ID);
						}
						break;
					case 2:
						{
						_localctx = new ParameterUnnamedAppendContext(new Parameter_listContext(_parentctx, _parentState));
						((ParameterUnnamedAppendContext)_localctx).previous = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(108);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(109);
						match(COMMA);
						setState(110);
						type_specifier();
						}
						break;
					case 3:
						{
						_localctx = new ParameterInvalidAppendContext(new Parameter_listContext(_parentctx, _parentState));
						((ParameterInvalidAppendContext)_localctx).previous = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(111);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(112);
						match(COMMA);
						setState(113);
						type_specifier();
						setState(114);
						match(ADDOP);
						}
						break;
					}
					} 
				}
				setState(120);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Compound_statementContext extends ParserRuleContext {
		public Compound_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compound_statement; }
	 
		public Compound_statementContext() { }
		public void copyFrom(Compound_statementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CompoundWithStatementsContext extends Compound_statementContext {
		public TerminalNode LCURL() { return getToken(CSubsetParser.LCURL, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode RCURL() { return getToken(CSubsetParser.RCURL, 0); }
		public CompoundWithStatementsContext(Compound_statementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterCompoundWithStatements(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitCompoundWithStatements(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CompoundEmptyContext extends Compound_statementContext {
		public TerminalNode LCURL() { return getToken(CSubsetParser.LCURL, 0); }
		public TerminalNode RCURL() { return getToken(CSubsetParser.RCURL, 0); }
		public CompoundEmptyContext(Compound_statementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterCompoundEmpty(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitCompoundEmpty(this);
		}
	}

	public final Compound_statementContext compound_statement() throws RecognitionException {
		Compound_statementContext _localctx = new Compound_statementContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_compound_statement);
		try {
			setState(127);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				_localctx = new CompoundWithStatementsContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(121);
				match(LCURL);
				setState(122);
				statements(0);
				setState(123);
				match(RCURL);
				}
				break;
			case 2:
				_localctx = new CompoundEmptyContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(125);
				match(LCURL);
				setState(126);
				match(RCURL);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_declarationContext extends ParserRuleContext {
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(CSubsetParser.SEMICOLON, 0); }
		public Var_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterVar_declaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitVar_declaration(this);
		}
	}

	public final Var_declarationContext var_declaration() throws RecognitionException {
		Var_declarationContext _localctx = new Var_declarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_var_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(129);
			type_specifier();
			setState(130);
			declaration_list(0);
			setState(131);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_specifierContext extends ParserRuleContext {
		public Type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_specifier; }
	 
		public Type_specifierContext() { }
		public void copyFrom(Type_specifierContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeFloatContext extends Type_specifierContext {
		public TerminalNode FLOAT() { return getToken(CSubsetParser.FLOAT, 0); }
		public TypeFloatContext(Type_specifierContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterTypeFloat(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitTypeFloat(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeVoidContext extends Type_specifierContext {
		public TerminalNode VOID() { return getToken(CSubsetParser.VOID, 0); }
		public TypeVoidContext(Type_specifierContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterTypeVoid(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitTypeVoid(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeIntContext extends Type_specifierContext {
		public TerminalNode INT() { return getToken(CSubsetParser.INT, 0); }
		public TypeIntContext(Type_specifierContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterTypeInt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitTypeInt(this);
		}
	}

	public final Type_specifierContext type_specifier() throws RecognitionException {
		Type_specifierContext _localctx = new Type_specifierContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_type_specifier);
		try {
			setState(136);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				_localctx = new TypeIntContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(133);
				match(INT);
				}
				break;
			case FLOAT:
				_localctx = new TypeFloatContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(134);
				match(FLOAT);
				}
				break;
			case VOID:
				_localctx = new TypeVoidContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(135);
				match(VOID);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_listContext extends ParserRuleContext {
		public Declaration_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list; }
	 
		public Declaration_listContext() { }
		public void copyFrom(Declaration_listContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationArrayAppendContext extends Declaration_listContext {
		public Declaration_listContext previous;
		public TerminalNode COMMA() { return getToken(CSubsetParser.COMMA, 0); }
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(CSubsetParser.LTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(CSubsetParser.CONST_INT, 0); }
		public TerminalNode RTHIRD() { return getToken(CSubsetParser.RTHIRD, 0); }
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public DeclarationArrayAppendContext(Declaration_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterDeclarationArrayAppend(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitDeclarationArrayAppend(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationInvalidAppendContext extends Declaration_listContext {
		public Declaration_listContext previous;
		public TerminalNode COMMA() { return getToken(CSubsetParser.COMMA, 0); }
		public TerminalNode ADDOP() { return getToken(CSubsetParser.ADDOP, 0); }
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public DeclarationInvalidAppendContext(Declaration_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterDeclarationInvalidAppend(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitDeclarationInvalidAppend(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationArraySingleContext extends Declaration_listContext {
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(CSubsetParser.LTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(CSubsetParser.CONST_INT, 0); }
		public TerminalNode RTHIRD() { return getToken(CSubsetParser.RTHIRD, 0); }
		public DeclarationArraySingleContext(Declaration_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterDeclarationArraySingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitDeclarationArraySingle(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationScalarAppendContext extends Declaration_listContext {
		public Declaration_listContext previous;
		public TerminalNode COMMA() { return getToken(CSubsetParser.COMMA, 0); }
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public DeclarationScalarAppendContext(Declaration_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterDeclarationScalarAppend(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitDeclarationScalarAppend(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationScalarSingleContext extends Declaration_listContext {
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public DeclarationScalarSingleContext(Declaration_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterDeclarationScalarSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitDeclarationScalarSingle(this);
		}
	}

	public final Declaration_listContext declaration_list() throws RecognitionException {
		return declaration_list(0);
	}

	private Declaration_listContext declaration_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Declaration_listContext _localctx = new Declaration_listContext(_ctx, _parentState);
		Declaration_listContext _prevctx = _localctx;
		int _startState = 18;
		enterRecursionRule(_localctx, 18, RULE_declaration_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(144);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				{
				_localctx = new DeclarationScalarSingleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(139);
				match(ID);
				}
				break;
			case 2:
				{
				_localctx = new DeclarationArraySingleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(140);
				match(ID);
				setState(141);
				match(LTHIRD);
				setState(142);
				match(CONST_INT);
				setState(143);
				match(RTHIRD);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(161);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(159);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
					case 1:
						{
						_localctx = new DeclarationScalarAppendContext(new Declaration_listContext(_parentctx, _parentState));
						((DeclarationScalarAppendContext)_localctx).previous = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(146);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(147);
						match(COMMA);
						setState(148);
						match(ID);
						}
						break;
					case 2:
						{
						_localctx = new DeclarationArrayAppendContext(new Declaration_listContext(_parentctx, _parentState));
						((DeclarationArrayAppendContext)_localctx).previous = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(149);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(150);
						match(COMMA);
						setState(151);
						match(ID);
						setState(152);
						match(LTHIRD);
						setState(153);
						match(CONST_INT);
						setState(154);
						match(RTHIRD);
						}
						break;
					case 3:
						{
						_localctx = new DeclarationInvalidAppendContext(new Declaration_listContext(_parentctx, _parentState));
						((DeclarationInvalidAppendContext)_localctx).previous = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(155);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(156);
						match(COMMA);
						setState(157);
						match(ADDOP);
						setState(158);
						match(ID);
						}
						break;
					}
					} 
				}
				setState(163);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementsContext extends ParserRuleContext {
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	 
		public StatementsContext() { }
		public void copyFrom(StatementsContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementsSingleContext extends StatementsContext {
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsSingleContext(StatementsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementsSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementsSingle(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementsMultipleContext extends StatementsContext {
		public StatementsContext previous;
		public StatementContext current;
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsMultipleContext(StatementsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementsMultiple(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementsMultiple(this);
		}
	}

	public final StatementsContext statements() throws RecognitionException {
		return statements(0);
	}

	private StatementsContext statements(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StatementsContext _localctx = new StatementsContext(_ctx, _parentState);
		StatementsContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_statements, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new StatementsSingleContext(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(165);
			statement();
			}
			_ctx.stop = _input.LT(-1);
			setState(171);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new StatementsMultipleContext(new StatementsContext(_parentctx, _parentState));
					((StatementsMultipleContext)_localctx).previous = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_statements);
					setState(167);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(168);
					((StatementsMultipleContext)_localctx).current = statement();
					}
					} 
				}
				setState(173);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	 
		public StatementContext() { }
		public void copyFrom(StatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementIfContext extends StatementContext {
		public ExpressionContext condition;
		public StatementContext thenBranch;
		public TerminalNode IF() { return getToken(CSubsetParser.IF, 0); }
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementIfContext(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementIf(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementIf(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementVariableDeclarationContext extends StatementContext {
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public StatementVariableDeclarationContext(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementVariableDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementVariableDeclaration(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementForContext extends StatementContext {
		public Expression_statementContext init;
		public Expression_statementContext condition;
		public ExpressionContext update;
		public StatementContext body;
		public TerminalNode FOR() { return getToken(CSubsetParser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public List<Expression_statementContext> expression_statement() {
			return getRuleContexts(Expression_statementContext.class);
		}
		public Expression_statementContext expression_statement(int i) {
			return getRuleContext(Expression_statementContext.class,i);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementForContext(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementFor(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementFor(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementReturnContext extends StatementContext {
		public TerminalNode RETURN() { return getToken(CSubsetParser.RETURN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(CSubsetParser.SEMICOLON, 0); }
		public StatementReturnContext(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementReturn(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementReturn(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementWhileContext extends StatementContext {
		public ExpressionContext condition;
		public StatementContext body;
		public TerminalNode WHILE() { return getToken(CSubsetParser.WHILE, 0); }
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementWhileContext(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementWhile(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementWhile(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementExpressionContext extends StatementContext {
		public Expression_statementContext expression_statement() {
			return getRuleContext(Expression_statementContext.class,0);
		}
		public StatementExpressionContext(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementExpression(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementCompoundContext extends StatementContext {
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public StatementCompoundContext(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementCompound(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementCompound(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementPrintlnContext extends StatementContext {
		public TerminalNode PRINTLN() { return getToken(CSubsetParser.PRINTLN, 0); }
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public TerminalNode SEMICOLON() { return getToken(CSubsetParser.SEMICOLON, 0); }
		public StatementPrintlnContext(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementPrintln(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementPrintln(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementIfElseContext extends StatementContext {
		public ExpressionContext condition;
		public StatementContext thenBranch;
		public StatementContext elseBranch;
		public TerminalNode IF() { return getToken(CSubsetParser.IF, 0); }
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public TerminalNode ELSE() { return getToken(CSubsetParser.ELSE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public StatementIfElseContext(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterStatementIfElse(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitStatementIfElse(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_statement);
		try {
			setState(214);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				_localctx = new StatementVariableDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(174);
				var_declaration();
				}
				break;
			case 2:
				_localctx = new StatementExpressionContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(175);
				expression_statement();
				}
				break;
			case 3:
				_localctx = new StatementCompoundContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(176);
				compound_statement();
				}
				break;
			case 4:
				_localctx = new StatementForContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(177);
				match(FOR);
				setState(178);
				match(LPAREN);
				setState(179);
				((StatementForContext)_localctx).init = expression_statement();
				setState(180);
				((StatementForContext)_localctx).condition = expression_statement();
				setState(181);
				((StatementForContext)_localctx).update = expression();
				setState(182);
				match(RPAREN);
				setState(183);
				((StatementForContext)_localctx).body = statement();
				}
				break;
			case 5:
				_localctx = new StatementIfContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(185);
				match(IF);
				setState(186);
				match(LPAREN);
				setState(187);
				((StatementIfContext)_localctx).condition = expression();
				setState(188);
				match(RPAREN);
				setState(189);
				((StatementIfContext)_localctx).thenBranch = statement();
				}
				break;
			case 6:
				_localctx = new StatementIfElseContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(191);
				match(IF);
				setState(192);
				match(LPAREN);
				setState(193);
				((StatementIfElseContext)_localctx).condition = expression();
				setState(194);
				match(RPAREN);
				setState(195);
				((StatementIfElseContext)_localctx).thenBranch = statement();
				setState(196);
				match(ELSE);
				setState(197);
				((StatementIfElseContext)_localctx).elseBranch = statement();
				}
				break;
			case 7:
				_localctx = new StatementWhileContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(199);
				match(WHILE);
				setState(200);
				match(LPAREN);
				setState(201);
				((StatementWhileContext)_localctx).condition = expression();
				setState(202);
				match(RPAREN);
				setState(203);
				((StatementWhileContext)_localctx).body = statement();
				}
				break;
			case 8:
				_localctx = new StatementPrintlnContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(205);
				match(PRINTLN);
				setState(206);
				match(LPAREN);
				setState(207);
				match(ID);
				setState(208);
				match(RPAREN);
				setState(209);
				match(SEMICOLON);
				}
				break;
			case 9:
				_localctx = new StatementReturnContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(210);
				match(RETURN);
				setState(211);
				expression();
				setState(212);
				match(SEMICOLON);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Expression_statementContext extends ParserRuleContext {
		public Expression_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression_statement; }
	 
		public Expression_statementContext() { }
		public void copyFrom(Expression_statementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionStatementEmptyContext extends Expression_statementContext {
		public TerminalNode SEMICOLON() { return getToken(CSubsetParser.SEMICOLON, 0); }
		public ExpressionStatementEmptyContext(Expression_statementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterExpressionStatementEmpty(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitExpressionStatementEmpty(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionStatementNormalContext extends Expression_statementContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(CSubsetParser.SEMICOLON, 0); }
		public ExpressionStatementNormalContext(Expression_statementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterExpressionStatementNormal(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitExpressionStatementNormal(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionStatementMissingSemicolonContext extends Expression_statementContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ExpressionStatementMissingSemicolonContext(Expression_statementContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterExpressionStatementMissingSemicolon(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitExpressionStatementMissingSemicolon(this);
		}
	}

	public final Expression_statementContext expression_statement() throws RecognitionException {
		Expression_statementContext _localctx = new Expression_statementContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_expression_statement);
		try {
			setState(221);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				_localctx = new ExpressionStatementEmptyContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(216);
				match(SEMICOLON);
				}
				break;
			case 2:
				_localctx = new ExpressionStatementNormalContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(217);
				expression();
				setState(218);
				match(SEMICOLON);
				}
				break;
			case 3:
				_localctx = new ExpressionStatementMissingSemicolonContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(220);
				expression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ParserRuleContext {
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	 
		public VariableContext() { }
		public void copyFrom(VariableContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VariableScalarContext extends VariableContext {
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public VariableScalarContext(VariableContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterVariableScalar(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitVariableScalar(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VariableArrayContext extends VariableContext {
		public ExpressionContext index;
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(CSubsetParser.LTHIRD, 0); }
		public TerminalNode RTHIRD() { return getToken(CSubsetParser.RTHIRD, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public VariableArrayContext(VariableContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterVariableArray(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitVariableArray(this);
		}
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_variable);
		try {
			setState(229);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				_localctx = new VariableScalarContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(223);
				match(ID);
				}
				break;
			case 2:
				_localctx = new VariableArrayContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(224);
				match(ID);
				setState(225);
				match(LTHIRD);
				setState(226);
				((VariableArrayContext)_localctx).index = expression();
				setState(227);
				match(RTHIRD);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	 
		public ExpressionContext() { }
		public void copyFrom(ExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionLogicContext extends ExpressionContext {
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public ExpressionLogicContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterExpressionLogic(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitExpressionLogic(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionAssignContext extends ExpressionContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(CSubsetParser.ASSIGNOP, 0); }
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public ExpressionAssignContext(ExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterExpressionAssign(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitExpressionAssign(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_expression);
		try {
			setState(236);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				_localctx = new ExpressionLogicContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(231);
				logic_expression();
				}
				break;
			case 2:
				_localctx = new ExpressionAssignContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(232);
				variable();
				setState(233);
				match(ASSIGNOP);
				setState(234);
				logic_expression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logic_expressionContext extends ParserRuleContext {
		public Logic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic_expression; }
	 
		public Logic_expressionContext() { }
		public void copyFrom(Logic_expressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LogicSingleContext extends Logic_expressionContext {
		public Rel_expressionContext rel_expression() {
			return getRuleContext(Rel_expressionContext.class,0);
		}
		public LogicSingleContext(Logic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterLogicSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitLogicSingle(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LogicBinaryContext extends Logic_expressionContext {
		public Rel_expressionContext left;
		public Rel_expressionContext right;
		public TerminalNode LOGICOP() { return getToken(CSubsetParser.LOGICOP, 0); }
		public List<Rel_expressionContext> rel_expression() {
			return getRuleContexts(Rel_expressionContext.class);
		}
		public Rel_expressionContext rel_expression(int i) {
			return getRuleContext(Rel_expressionContext.class,i);
		}
		public LogicBinaryContext(Logic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterLogicBinary(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitLogicBinary(this);
		}
	}

	public final Logic_expressionContext logic_expression() throws RecognitionException {
		Logic_expressionContext _localctx = new Logic_expressionContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_logic_expression);
		try {
			setState(243);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				_localctx = new LogicSingleContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(238);
				rel_expression();
				}
				break;
			case 2:
				_localctx = new LogicBinaryContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(239);
				((LogicBinaryContext)_localctx).left = rel_expression();
				setState(240);
				match(LOGICOP);
				setState(241);
				((LogicBinaryContext)_localctx).right = rel_expression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rel_expressionContext extends ParserRuleContext {
		public Rel_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rel_expression; }
	 
		public Rel_expressionContext() { }
		public void copyFrom(Rel_expressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class RelSingleContext extends Rel_expressionContext {
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public RelSingleContext(Rel_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterRelSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitRelSingle(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class RelBinaryContext extends Rel_expressionContext {
		public Simple_expressionContext left;
		public Simple_expressionContext right;
		public TerminalNode RELOP() { return getToken(CSubsetParser.RELOP, 0); }
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public RelBinaryContext(Rel_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterRelBinary(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitRelBinary(this);
		}
	}

	public final Rel_expressionContext rel_expression() throws RecognitionException {
		Rel_expressionContext _localctx = new Rel_expressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_rel_expression);
		try {
			setState(250);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				_localctx = new RelSingleContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(245);
				simple_expression(0);
				}
				break;
			case 2:
				_localctx = new RelBinaryContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(246);
				((RelBinaryContext)_localctx).left = simple_expression(0);
				setState(247);
				match(RELOP);
				setState(248);
				((RelBinaryContext)_localctx).right = simple_expression(0);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Simple_expressionContext extends ParserRuleContext {
		public Simple_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_expression; }
	 
		public Simple_expressionContext() { }
		public void copyFrom(Simple_expressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SimpleSingleContext extends Simple_expressionContext {
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public SimpleSingleContext(Simple_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterSimpleSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitSimpleSingle(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SimpleBinaryContext extends Simple_expressionContext {
		public Simple_expressionContext left;
		public TermContext right;
		public TerminalNode ADDOP() { return getToken(CSubsetParser.ADDOP, 0); }
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public SimpleBinaryContext(Simple_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterSimpleBinary(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitSimpleBinary(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SimpleInvalidAssignmentContext extends Simple_expressionContext {
		public Simple_expressionContext left;
		public TerminalNode ADDOP() { return getToken(CSubsetParser.ADDOP, 0); }
		public TerminalNode ASSIGNOP() { return getToken(CSubsetParser.ASSIGNOP, 0); }
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public SimpleInvalidAssignmentContext(Simple_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterSimpleInvalidAssignment(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitSimpleInvalidAssignment(this);
		}
	}

	public final Simple_expressionContext simple_expression() throws RecognitionException {
		return simple_expression(0);
	}

	private Simple_expressionContext simple_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Simple_expressionContext _localctx = new Simple_expressionContext(_ctx, _parentState);
		Simple_expressionContext _prevctx = _localctx;
		int _startState = 34;
		enterRecursionRule(_localctx, 34, RULE_simple_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new SimpleSingleContext(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(253);
			term(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(263);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(261);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
					case 1:
						{
						_localctx = new SimpleBinaryContext(new Simple_expressionContext(_parentctx, _parentState));
						((SimpleBinaryContext)_localctx).left = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
						setState(255);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(256);
						match(ADDOP);
						setState(257);
						((SimpleBinaryContext)_localctx).right = term(0);
						}
						break;
					case 2:
						{
						_localctx = new SimpleInvalidAssignmentContext(new Simple_expressionContext(_parentctx, _parentState));
						((SimpleInvalidAssignmentContext)_localctx).left = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
						setState(258);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(259);
						match(ADDOP);
						setState(260);
						match(ASSIGNOP);
						}
						break;
					}
					} 
				}
				setState(265);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	 
		public TermContext() { }
		public void copyFrom(TermContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TermSingleContext extends TermContext {
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TermSingleContext(TermContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterTermSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitTermSingle(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TermBinaryContext extends TermContext {
		public TermContext left;
		public Unary_expressionContext right;
		public TerminalNode MULOP() { return getToken(CSubsetParser.MULOP, 0); }
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TermBinaryContext(TermContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterTermBinary(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitTermBinary(this);
		}
	}

	public final TermContext term() throws RecognitionException {
		return term(0);
	}

	private TermContext term(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TermContext _localctx = new TermContext(_ctx, _parentState);
		TermContext _prevctx = _localctx;
		int _startState = 36;
		enterRecursionRule(_localctx, 36, RULE_term, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new TermSingleContext(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(267);
			unary_expression();
			}
			_ctx.stop = _input.LT(-1);
			setState(274);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TermBinaryContext(new TermContext(_parentctx, _parentState));
					((TermBinaryContext)_localctx).left = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_term);
					setState(269);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(270);
					match(MULOP);
					setState(271);
					((TermBinaryContext)_localctx).right = unary_expression();
					}
					} 
				}
				setState(276);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_expressionContext extends ParserRuleContext {
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
	 
		public Unary_expressionContext() { }
		public void copyFrom(Unary_expressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UnaryNotContext extends Unary_expressionContext {
		public Unary_expressionContext operand;
		public TerminalNode NOT() { return getToken(CSubsetParser.NOT, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public UnaryNotContext(Unary_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterUnaryNot(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitUnaryNot(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UnaryFactorContext extends Unary_expressionContext {
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public UnaryFactorContext(Unary_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterUnaryFactor(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitUnaryFactor(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UnaryAddContext extends Unary_expressionContext {
		public Unary_expressionContext operand;
		public TerminalNode ADDOP() { return getToken(CSubsetParser.ADDOP, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public UnaryAddContext(Unary_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterUnaryAdd(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitUnaryAdd(this);
		}
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_unary_expression);
		try {
			setState(282);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				_localctx = new UnaryAddContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(277);
				match(ADDOP);
				setState(278);
				((UnaryAddContext)_localctx).operand = unary_expression();
				}
				break;
			case NOT:
				_localctx = new UnaryNotContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(279);
				match(NOT);
				setState(280);
				((UnaryNotContext)_localctx).operand = unary_expression();
				}
				break;
			case LPAREN:
			case ID:
			case CONST_FLOAT:
			case CONST_INT:
				_localctx = new UnaryFactorContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(281);
				factor();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FactorContext extends ParserRuleContext {
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	 
		public FactorContext() { }
		public void copyFrom(FactorContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FactorFunctionCallContext extends FactorContext {
		public TerminalNode ID() { return getToken(CSubsetParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public FactorFunctionCallContext(FactorContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFactorFunctionCall(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFactorFunctionCall(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FactorVariableContext extends FactorContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public FactorVariableContext(FactorContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFactorVariable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFactorVariable(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FactorIntContext extends FactorContext {
		public TerminalNode CONST_INT() { return getToken(CSubsetParser.CONST_INT, 0); }
		public FactorIntContext(FactorContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFactorInt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFactorInt(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FactorParenthesizedContext extends FactorContext {
		public TerminalNode LPAREN() { return getToken(CSubsetParser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(CSubsetParser.RPAREN, 0); }
		public FactorParenthesizedContext(FactorContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFactorParenthesized(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFactorParenthesized(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FactorFloatContext extends FactorContext {
		public TerminalNode CONST_FLOAT() { return getToken(CSubsetParser.CONST_FLOAT, 0); }
		public FactorFloatContext(FactorContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFactorFloat(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFactorFloat(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FactorIncrementContext extends FactorContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode INCOP() { return getToken(CSubsetParser.INCOP, 0); }
		public FactorIncrementContext(FactorContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFactorIncrement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFactorIncrement(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FactorDecrementContext extends FactorContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode DECOP() { return getToken(CSubsetParser.DECOP, 0); }
		public FactorDecrementContext(FactorContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterFactorDecrement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitFactorDecrement(this);
		}
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_factor);
		try {
			setState(302);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				_localctx = new FactorVariableContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(284);
				variable();
				}
				break;
			case 2:
				_localctx = new FactorFunctionCallContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(285);
				match(ID);
				setState(286);
				match(LPAREN);
				setState(287);
				argument_list();
				setState(288);
				match(RPAREN);
				}
				break;
			case 3:
				_localctx = new FactorParenthesizedContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(290);
				match(LPAREN);
				setState(291);
				expression();
				setState(292);
				match(RPAREN);
				}
				break;
			case 4:
				_localctx = new FactorIntContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(294);
				match(CONST_INT);
				}
				break;
			case 5:
				_localctx = new FactorFloatContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(295);
				match(CONST_FLOAT);
				}
				break;
			case 6:
				_localctx = new FactorIncrementContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(296);
				variable();
				setState(297);
				match(INCOP);
				}
				break;
			case 7:
				_localctx = new FactorDecrementContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(299);
				variable();
				setState(300);
				match(DECOP);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Argument_listContext extends ParserRuleContext {
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	 
		public Argument_listContext() { }
		public void copyFrom(Argument_listContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentListEmptyContext extends Argument_listContext {
		public ArgumentListEmptyContext(Argument_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterArgumentListEmpty(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitArgumentListEmpty(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentListNonEmptyContext extends Argument_listContext {
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ArgumentListNonEmptyContext(Argument_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterArgumentListNonEmpty(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitArgumentListNonEmpty(this);
		}
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_argument_list);
		try {
			setState(306);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_FLOAT:
			case CONST_INT:
				_localctx = new ArgumentListNonEmptyContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(304);
				arguments(0);
				}
				break;
			case RPAREN:
				_localctx = new ArgumentListEmptyContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsContext extends ParserRuleContext {
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	 
		public ArgumentsContext() { }
		public void copyFrom(ArgumentsContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsSingleContext extends ArgumentsContext {
		public Logic_expressionContext current;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public ArgumentsSingleContext(ArgumentsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterArgumentsSingle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitArgumentsSingle(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsMultipleContext extends ArgumentsContext {
		public ArgumentsContext previous;
		public Logic_expressionContext current;
		public TerminalNode COMMA() { return getToken(CSubsetParser.COMMA, 0); }
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public ArgumentsMultipleContext(ArgumentsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).enterArgumentsMultiple(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSubsetListener ) ((CSubsetListener)listener).exitArgumentsMultiple(this);
		}
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		return arguments(0);
	}

	private ArgumentsContext arguments(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, _parentState);
		ArgumentsContext _prevctx = _localctx;
		int _startState = 44;
		enterRecursionRule(_localctx, 44, RULE_arguments, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new ArgumentsSingleContext(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(309);
			((ArgumentsSingleContext)_localctx).current = logic_expression();
			}
			_ctx.stop = _input.LT(-1);
			setState(316);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentsMultipleContext(new ArgumentsContext(_parentctx, _parentState));
					((ArgumentsMultipleContext)_localctx).previous = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_arguments);
					setState(311);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(312);
					match(COMMA);
					setState(313);
					((ArgumentsMultipleContext)_localctx).current = logic_expression();
					}
					} 
				}
				setState(318);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return program_sempred((ProgramContext)_localctx, predIndex);
		case 5:
			return parameter_list_sempred((Parameter_listContext)_localctx, predIndex);
		case 9:
			return declaration_list_sempred((Declaration_listContext)_localctx, predIndex);
		case 10:
			return statements_sempred((StatementsContext)_localctx, predIndex);
		case 17:
			return simple_expression_sempred((Simple_expressionContext)_localctx, predIndex);
		case 18:
			return term_sempred((TermContext)_localctx, predIndex);
		case 22:
			return arguments_sempred((ArgumentsContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean program_sempred(ProgramContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean parameter_list_sempred(Parameter_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 6);
		case 2:
			return precpred(_ctx, 5);
		case 3:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean declaration_list_sempred(Declaration_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 5);
		case 5:
			return precpred(_ctx, 4);
		case 6:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean statements_sempred(StatementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 7:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_expression_sempred(Simple_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 8:
			return precpred(_ctx, 2);
		case 9:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean term_sempred(TermContext _localctx, int predIndex) {
		switch (predIndex) {
		case 10:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean arguments_sempred(ArgumentsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 11:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001!\u0140\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u00016\b\u0001\n\u0001\f\u0001"+
		"9\t\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002>\b\u0002\u0001"+
		"\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001"+
		"\u0003\u0003\u0003M\b\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004\\\b\u0004\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0003\u0005f\b\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005u\b"+
		"\u0005\n\u0005\f\u0005x\t\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0003\u0006\u0080\b\u0006\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\b\u0003\b\u0089\b"+
		"\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0003\t\u0091\b\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0005\t\u00a0\b\t\n\t\f\t\u00a3\t\t\u0001\n"+
		"\u0001\n\u0001\n\u0001\n\u0001\n\u0005\n\u00aa\b\n\n\n\f\n\u00ad\t\n\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00d7\b\u000b\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0003\f\u00de\b\f\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0003\r\u00e6\b\r\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00ed\b\u000e\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u00f4\b\u000f\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u00fb"+
		"\b\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0005\u0011\u0106\b\u0011\n"+
		"\u0011\f\u0011\u0109\t\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0005\u0012\u0111\b\u0012\n\u0012\f\u0012"+
		"\u0114\t\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0003\u0013\u011b\b\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0003\u0014\u012f\b\u0014\u0001\u0015\u0001\u0015"+
		"\u0003\u0015\u0133\b\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0005\u0016\u013b\b\u0016\n\u0016\f\u0016\u013e"+
		"\t\u0016\u0001\u0016\u0000\u0007\u0002\n\u0012\u0014\"$,\u0017\u0000\u0002"+
		"\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e"+
		" \"$&(*,\u0000\u0000\u0155\u0000.\u0001\u0000\u0000\u0000\u00020\u0001"+
		"\u0000\u0000\u0000\u0004=\u0001\u0000\u0000\u0000\u0006L\u0001\u0000\u0000"+
		"\u0000\b[\u0001\u0000\u0000\u0000\ne\u0001\u0000\u0000\u0000\f\u007f\u0001"+
		"\u0000\u0000\u0000\u000e\u0081\u0001\u0000\u0000\u0000\u0010\u0088\u0001"+
		"\u0000\u0000\u0000\u0012\u0090\u0001\u0000\u0000\u0000\u0014\u00a4\u0001"+
		"\u0000\u0000\u0000\u0016\u00d6\u0001\u0000\u0000\u0000\u0018\u00dd\u0001"+
		"\u0000\u0000\u0000\u001a\u00e5\u0001\u0000\u0000\u0000\u001c\u00ec\u0001"+
		"\u0000\u0000\u0000\u001e\u00f3\u0001\u0000\u0000\u0000 \u00fa\u0001\u0000"+
		"\u0000\u0000\"\u00fc\u0001\u0000\u0000\u0000$\u010a\u0001\u0000\u0000"+
		"\u0000&\u011a\u0001\u0000\u0000\u0000(\u012e\u0001\u0000\u0000\u0000*"+
		"\u0132\u0001\u0000\u0000\u0000,\u0134\u0001\u0000\u0000\u0000./\u0003"+
		"\u0002\u0001\u0000/\u0001\u0001\u0000\u0000\u000001\u0006\u0001\uffff"+
		"\uffff\u000012\u0003\u0004\u0002\u000027\u0001\u0000\u0000\u000034\n\u0002"+
		"\u0000\u000046\u0003\u0004\u0002\u000053\u0001\u0000\u0000\u000069\u0001"+
		"\u0000\u0000\u000075\u0001\u0000\u0000\u000078\u0001\u0000\u0000\u0000"+
		"8\u0003\u0001\u0000\u0000\u000097\u0001\u0000\u0000\u0000:>\u0003\u000e"+
		"\u0007\u0000;>\u0003\u0006\u0003\u0000<>\u0003\b\u0004\u0000=:\u0001\u0000"+
		"\u0000\u0000=;\u0001\u0000\u0000\u0000=<\u0001\u0000\u0000\u0000>\u0005"+
		"\u0001\u0000\u0000\u0000?@\u0003\u0010\b\u0000@A\u0005\u001e\u0000\u0000"+
		"AB\u0005\u000e\u0000\u0000BC\u0003\n\u0005\u0000CD\u0005\u000f\u0000\u0000"+
		"DE\u0005\u0014\u0000\u0000EM\u0001\u0000\u0000\u0000FG\u0003\u0010\b\u0000"+
		"GH\u0005\u001e\u0000\u0000HI\u0005\u000e\u0000\u0000IJ\u0005\u000f\u0000"+
		"\u0000JK\u0005\u0014\u0000\u0000KM\u0001\u0000\u0000\u0000L?\u0001\u0000"+
		"\u0000\u0000LF\u0001\u0000\u0000\u0000M\u0007\u0001\u0000\u0000\u0000"+
		"NO\u0003\u0010\b\u0000OP\u0005\u001e\u0000\u0000PQ\u0005\u000e\u0000\u0000"+
		"QR\u0003\n\u0005\u0000RS\u0005\u000f\u0000\u0000ST\u0003\f\u0006\u0000"+
		"T\\\u0001\u0000\u0000\u0000UV\u0003\u0010\b\u0000VW\u0005\u001e\u0000"+
		"\u0000WX\u0005\u000e\u0000\u0000XY\u0005\u000f\u0000\u0000YZ\u0003\f\u0006"+
		"\u0000Z\\\u0001\u0000\u0000\u0000[N\u0001\u0000\u0000\u0000[U\u0001\u0000"+
		"\u0000\u0000\\\t\u0001\u0000\u0000\u0000]^\u0006\u0005\uffff\uffff\u0000"+
		"^_\u0003\u0010\b\u0000_`\u0005\u001e\u0000\u0000`f\u0001\u0000\u0000\u0000"+
		"af\u0003\u0010\b\u0000bc\u0003\u0010\b\u0000cd\u0005\u0018\u0000\u0000"+
		"df\u0001\u0000\u0000\u0000e]\u0001\u0000\u0000\u0000ea\u0001\u0000\u0000"+
		"\u0000eb\u0001\u0000\u0000\u0000fv\u0001\u0000\u0000\u0000gh\n\u0006\u0000"+
		"\u0000hi\u0005\u0015\u0000\u0000ij\u0003\u0010\b\u0000jk\u0005\u001e\u0000"+
		"\u0000ku\u0001\u0000\u0000\u0000lm\n\u0005\u0000\u0000mn\u0005\u0015\u0000"+
		"\u0000nu\u0003\u0010\b\u0000op\n\u0002\u0000\u0000pq\u0005\u0015\u0000"+
		"\u0000qr\u0003\u0010\b\u0000rs\u0005\u0018\u0000\u0000su\u0001\u0000\u0000"+
		"\u0000tg\u0001\u0000\u0000\u0000tl\u0001\u0000\u0000\u0000to\u0001\u0000"+
		"\u0000\u0000ux\u0001\u0000\u0000\u0000vt\u0001\u0000\u0000\u0000vw\u0001"+
		"\u0000\u0000\u0000w\u000b\u0001\u0000\u0000\u0000xv\u0001\u0000\u0000"+
		"\u0000yz\u0005\u0010\u0000\u0000z{\u0003\u0014\n\u0000{|\u0005\u0011\u0000"+
		"\u0000|\u0080\u0001\u0000\u0000\u0000}~\u0005\u0010\u0000\u0000~\u0080"+
		"\u0005\u0011\u0000\u0000\u007fy\u0001\u0000\u0000\u0000\u007f}\u0001\u0000"+
		"\u0000\u0000\u0080\r\u0001\u0000\u0000\u0000\u0081\u0082\u0003\u0010\b"+
		"\u0000\u0082\u0083\u0003\u0012\t\u0000\u0083\u0084\u0005\u0014\u0000\u0000"+
		"\u0084\u000f\u0001\u0000\u0000\u0000\u0085\u0089\u0005\u000b\u0000\u0000"+
		"\u0086\u0089\u0005\f\u0000\u0000\u0087\u0089\u0005\r\u0000\u0000\u0088"+
		"\u0085\u0001\u0000\u0000\u0000\u0088\u0086\u0001\u0000\u0000\u0000\u0088"+
		"\u0087\u0001\u0000\u0000\u0000\u0089\u0011\u0001\u0000\u0000\u0000\u008a"+
		"\u008b\u0006\t\uffff\uffff\u0000\u008b\u0091\u0005\u001e\u0000\u0000\u008c"+
		"\u008d\u0005\u001e\u0000\u0000\u008d\u008e\u0005\u0012\u0000\u0000\u008e"+
		"\u008f\u0005 \u0000\u0000\u008f\u0091\u0005\u0013\u0000\u0000\u0090\u008a"+
		"\u0001\u0000\u0000\u0000\u0090\u008c\u0001\u0000\u0000\u0000\u0091\u00a1"+
		"\u0001\u0000\u0000\u0000\u0092\u0093\n\u0005\u0000\u0000\u0093\u0094\u0005"+
		"\u0015\u0000\u0000\u0094\u00a0\u0005\u001e\u0000\u0000\u0095\u0096\n\u0004"+
		"\u0000\u0000\u0096\u0097\u0005\u0015\u0000\u0000\u0097\u0098\u0005\u001e"+
		"\u0000\u0000\u0098\u0099\u0005\u0012\u0000\u0000\u0099\u009a\u0005 \u0000"+
		"\u0000\u009a\u00a0\u0005\u0013\u0000\u0000\u009b\u009c\n\u0001\u0000\u0000"+
		"\u009c\u009d\u0005\u0015\u0000\u0000\u009d\u009e\u0005\u0018\u0000\u0000"+
		"\u009e\u00a0\u0005\u001e\u0000\u0000\u009f\u0092\u0001\u0000\u0000\u0000"+
		"\u009f\u0095\u0001\u0000\u0000\u0000\u009f\u009b\u0001\u0000\u0000\u0000"+
		"\u00a0\u00a3\u0001\u0000\u0000\u0000\u00a1\u009f\u0001\u0000\u0000\u0000"+
		"\u00a1\u00a2\u0001\u0000\u0000\u0000\u00a2\u0013\u0001\u0000\u0000\u0000"+
		"\u00a3\u00a1\u0001\u0000\u0000\u0000\u00a4\u00a5\u0006\n\uffff\uffff\u0000"+
		"\u00a5\u00a6\u0003\u0016\u000b\u0000\u00a6\u00ab\u0001\u0000\u0000\u0000"+
		"\u00a7\u00a8\n\u0001\u0000\u0000\u00a8\u00aa\u0003\u0016\u000b\u0000\u00a9"+
		"\u00a7\u0001\u0000\u0000\u0000\u00aa\u00ad\u0001\u0000\u0000\u0000\u00ab"+
		"\u00a9\u0001\u0000\u0000\u0000\u00ab\u00ac\u0001\u0000\u0000\u0000\u00ac"+
		"\u0015\u0001\u0000\u0000\u0000\u00ad\u00ab\u0001\u0000\u0000\u0000\u00ae"+
		"\u00d7\u0003\u000e\u0007\u0000\u00af\u00d7\u0003\u0018\f\u0000\u00b0\u00d7"+
		"\u0003\f\u0006\u0000\u00b1\u00b2\u0005\u0007\u0000\u0000\u00b2\u00b3\u0005"+
		"\u000e\u0000\u0000\u00b3\u00b4\u0003\u0018\f\u0000\u00b4\u00b5\u0003\u0018"+
		"\f\u0000\u00b5\u00b6\u0003\u001c\u000e\u0000\u00b6\u00b7\u0005\u000f\u0000"+
		"\u0000\u00b7\u00b8\u0003\u0016\u000b\u0000\u00b8\u00d7\u0001\u0000\u0000"+
		"\u0000\u00b9\u00ba\u0005\u0005\u0000\u0000\u00ba\u00bb\u0005\u000e\u0000"+
		"\u0000\u00bb\u00bc\u0003\u001c\u000e\u0000\u00bc\u00bd\u0005\u000f\u0000"+
		"\u0000\u00bd\u00be\u0003\u0016\u000b\u0000\u00be\u00d7\u0001\u0000\u0000"+
		"\u0000\u00bf\u00c0\u0005\u0005\u0000\u0000\u00c0\u00c1\u0005\u000e\u0000"+
		"\u0000\u00c1\u00c2\u0003\u001c\u000e\u0000\u00c2\u00c3\u0005\u000f\u0000"+
		"\u0000\u00c3\u00c4\u0003\u0016\u000b\u0000\u00c4\u00c5\u0005\u0006\u0000"+
		"\u0000\u00c5\u00c6\u0003\u0016\u000b\u0000\u00c6\u00d7\u0001\u0000\u0000"+
		"\u0000\u00c7\u00c8\u0005\b\u0000\u0000\u00c8\u00c9\u0005\u000e\u0000\u0000"+
		"\u00c9\u00ca\u0003\u001c\u000e\u0000\u00ca\u00cb\u0005\u000f\u0000\u0000"+
		"\u00cb\u00cc\u0003\u0016\u000b\u0000\u00cc\u00d7\u0001\u0000\u0000\u0000"+
		"\u00cd\u00ce\u0005\t\u0000\u0000\u00ce\u00cf\u0005\u000e\u0000\u0000\u00cf"+
		"\u00d0\u0005\u001e\u0000\u0000\u00d0\u00d1\u0005\u000f\u0000\u0000\u00d1"+
		"\u00d7\u0005\u0014\u0000\u0000\u00d2\u00d3\u0005\n\u0000\u0000\u00d3\u00d4"+
		"\u0003\u001c\u000e\u0000\u00d4\u00d5\u0005\u0014\u0000\u0000\u00d5\u00d7"+
		"\u0001\u0000\u0000\u0000\u00d6\u00ae\u0001\u0000\u0000\u0000\u00d6\u00af"+
		"\u0001\u0000\u0000\u0000\u00d6\u00b0\u0001\u0000\u0000\u0000\u00d6\u00b1"+
		"\u0001\u0000\u0000\u0000\u00d6\u00b9\u0001\u0000\u0000\u0000\u00d6\u00bf"+
		"\u0001\u0000\u0000\u0000\u00d6\u00c7\u0001\u0000\u0000\u0000\u00d6\u00cd"+
		"\u0001\u0000\u0000\u0000\u00d6\u00d2\u0001\u0000\u0000\u0000\u00d7\u0017"+
		"\u0001\u0000\u0000\u0000\u00d8\u00de\u0005\u0014\u0000\u0000\u00d9\u00da"+
		"\u0003\u001c\u000e\u0000\u00da\u00db\u0005\u0014\u0000\u0000\u00db\u00de"+
		"\u0001\u0000\u0000\u0000\u00dc\u00de\u0003\u001c\u000e\u0000\u00dd\u00d8"+
		"\u0001\u0000\u0000\u0000\u00dd\u00d9\u0001\u0000\u0000\u0000\u00dd\u00dc"+
		"\u0001\u0000\u0000\u0000\u00de\u0019\u0001\u0000\u0000\u0000\u00df\u00e6"+
		"\u0005\u001e\u0000\u0000\u00e0\u00e1\u0005\u001e\u0000\u0000\u00e1\u00e2"+
		"\u0005\u0012\u0000\u0000\u00e2\u00e3\u0003\u001c\u000e\u0000\u00e3\u00e4"+
		"\u0005\u0013\u0000\u0000\u00e4\u00e6\u0001\u0000\u0000\u0000\u00e5\u00df"+
		"\u0001\u0000\u0000\u0000\u00e5\u00e0\u0001\u0000\u0000\u0000\u00e6\u001b"+
		"\u0001\u0000\u0000\u0000\u00e7\u00ed\u0003\u001e\u000f\u0000\u00e8\u00e9"+
		"\u0003\u001a\r\u0000\u00e9\u00ea\u0005\u001d\u0000\u0000\u00ea\u00eb\u0003"+
		"\u001e\u000f\u0000\u00eb\u00ed\u0001\u0000\u0000\u0000\u00ec\u00e7\u0001"+
		"\u0000\u0000\u0000\u00ec\u00e8\u0001\u0000\u0000\u0000\u00ed\u001d\u0001"+
		"\u0000\u0000\u0000\u00ee\u00f4\u0003 \u0010\u0000\u00ef\u00f0\u0003 \u0010"+
		"\u0000\u00f0\u00f1\u0005\u001c\u0000\u0000\u00f1\u00f2\u0003 \u0010\u0000"+
		"\u00f2\u00f4\u0001\u0000\u0000\u0000\u00f3\u00ee\u0001\u0000\u0000\u0000"+
		"\u00f3\u00ef\u0001\u0000\u0000\u0000\u00f4\u001f\u0001\u0000\u0000\u0000"+
		"\u00f5\u00fb\u0003\"\u0011\u0000\u00f6\u00f7\u0003\"\u0011\u0000\u00f7"+
		"\u00f8\u0005\u001b\u0000\u0000\u00f8\u00f9\u0003\"\u0011\u0000\u00f9\u00fb"+
		"\u0001\u0000\u0000\u0000\u00fa\u00f5\u0001\u0000\u0000\u0000\u00fa\u00f6"+
		"\u0001\u0000\u0000\u0000\u00fb!\u0001\u0000\u0000\u0000\u00fc\u00fd\u0006"+
		"\u0011\uffff\uffff\u0000\u00fd\u00fe\u0003$\u0012\u0000\u00fe\u0107\u0001"+
		"\u0000\u0000\u0000\u00ff\u0100\n\u0002\u0000\u0000\u0100\u0101\u0005\u0018"+
		"\u0000\u0000\u0101\u0106\u0003$\u0012\u0000\u0102\u0103\n\u0001\u0000"+
		"\u0000\u0103\u0104\u0005\u0018\u0000\u0000\u0104\u0106\u0005\u001d\u0000"+
		"\u0000\u0105\u00ff\u0001\u0000\u0000\u0000\u0105\u0102\u0001\u0000\u0000"+
		"\u0000\u0106\u0109\u0001\u0000\u0000\u0000\u0107\u0105\u0001\u0000\u0000"+
		"\u0000\u0107\u0108\u0001\u0000\u0000\u0000\u0108#\u0001\u0000\u0000\u0000"+
		"\u0109\u0107\u0001\u0000\u0000\u0000\u010a\u010b\u0006\u0012\uffff\uffff"+
		"\u0000\u010b\u010c\u0003&\u0013\u0000\u010c\u0112\u0001\u0000\u0000\u0000"+
		"\u010d\u010e\n\u0001\u0000\u0000\u010e\u010f\u0005\u0019\u0000\u0000\u010f"+
		"\u0111\u0003&\u0013\u0000\u0110\u010d\u0001\u0000\u0000\u0000\u0111\u0114"+
		"\u0001\u0000\u0000\u0000\u0112\u0110\u0001\u0000\u0000\u0000\u0112\u0113"+
		"\u0001\u0000\u0000\u0000\u0113%\u0001\u0000\u0000\u0000\u0114\u0112\u0001"+
		"\u0000\u0000\u0000\u0115\u0116\u0005\u0018\u0000\u0000\u0116\u011b\u0003"+
		"&\u0013\u0000\u0117\u0118\u0005\u001a\u0000\u0000\u0118\u011b\u0003&\u0013"+
		"\u0000\u0119\u011b\u0003(\u0014\u0000\u011a\u0115\u0001\u0000\u0000\u0000"+
		"\u011a\u0117\u0001\u0000\u0000\u0000\u011a\u0119\u0001\u0000\u0000\u0000"+
		"\u011b\'\u0001\u0000\u0000\u0000\u011c\u012f\u0003\u001a\r\u0000\u011d"+
		"\u011e\u0005\u001e\u0000\u0000\u011e\u011f\u0005\u000e\u0000\u0000\u011f"+
		"\u0120\u0003*\u0015\u0000\u0120\u0121\u0005\u000f\u0000\u0000\u0121\u012f"+
		"\u0001\u0000\u0000\u0000\u0122\u0123\u0005\u000e\u0000\u0000\u0123\u0124"+
		"\u0003\u001c\u000e\u0000\u0124\u0125\u0005\u000f\u0000\u0000\u0125\u012f"+
		"\u0001\u0000\u0000\u0000\u0126\u012f\u0005 \u0000\u0000\u0127\u012f\u0005"+
		"\u001f\u0000\u0000\u0128\u0129\u0003\u001a\r\u0000\u0129\u012a\u0005\u0016"+
		"\u0000\u0000\u012a\u012f\u0001\u0000\u0000\u0000\u012b\u012c\u0003\u001a"+
		"\r\u0000\u012c\u012d\u0005\u0017\u0000\u0000\u012d\u012f\u0001\u0000\u0000"+
		"\u0000\u012e\u011c\u0001\u0000\u0000\u0000\u012e\u011d\u0001\u0000\u0000"+
		"\u0000\u012e\u0122\u0001\u0000\u0000\u0000\u012e\u0126\u0001\u0000\u0000"+
		"\u0000\u012e\u0127\u0001\u0000\u0000\u0000\u012e\u0128\u0001\u0000\u0000"+
		"\u0000\u012e\u012b\u0001\u0000\u0000\u0000\u012f)\u0001\u0000\u0000\u0000"+
		"\u0130\u0133\u0003,\u0016\u0000\u0131\u0133\u0001\u0000\u0000\u0000\u0132"+
		"\u0130\u0001\u0000\u0000\u0000\u0132\u0131\u0001\u0000\u0000\u0000\u0133"+
		"+\u0001\u0000\u0000\u0000\u0134\u0135\u0006\u0016\uffff\uffff\u0000\u0135"+
		"\u0136\u0003\u001e\u000f\u0000\u0136\u013c\u0001\u0000\u0000\u0000\u0137"+
		"\u0138\n\u0002\u0000\u0000\u0138\u0139\u0005\u0015\u0000\u0000\u0139\u013b"+
		"\u0003\u001e\u000f\u0000\u013a\u0137\u0001\u0000\u0000\u0000\u013b\u013e"+
		"\u0001\u0000\u0000\u0000\u013c\u013a\u0001\u0000\u0000\u0000\u013c\u013d"+
		"\u0001\u0000\u0000\u0000\u013d-\u0001\u0000\u0000\u0000\u013e\u013c\u0001"+
		"\u0000\u0000\u0000\u001a7=L[etv\u007f\u0088\u0090\u009f\u00a1\u00ab\u00d6"+
		"\u00dd\u00e5\u00ec\u00f3\u00fa\u0105\u0107\u0112\u011a\u012e\u0132\u013c";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}