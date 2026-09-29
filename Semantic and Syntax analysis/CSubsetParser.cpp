
// Generated from CSubset.g4 by ANTLR 4.13.2


#include "CSubsetVisitor.h"

#include "CSubsetParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CSubsetParserStaticData final {
  CSubsetParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CSubsetParserStaticData(const CSubsetParserStaticData&) = delete;
  CSubsetParserStaticData(CSubsetParserStaticData&&) = delete;
  CSubsetParserStaticData& operator=(const CSubsetParserStaticData&) = delete;
  CSubsetParserStaticData& operator=(CSubsetParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag csubsetParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CSubsetParserStaticData> csubsetParserStaticData = nullptr;

void csubsetParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (csubsetParserStaticData != nullptr) {
    return;
  }
#else
  assert(csubsetParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CSubsetParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "type_specifier", 
      "declaration_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "'++'", "'--'", "", "", "'!'", "", "", 
      "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "INCOP", "DECOP", "ADDOP", "MULOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", 
      "ID", "CONST_FLOAT", "CONST_INT", "UNKNOWN"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,33,319,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,54,8,1,10,1,12,1,57,9,1,
  	1,2,1,2,1,2,3,2,62,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,3,3,77,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	3,4,92,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,102,8,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,117,8,5,10,5,12,5,120,9,5,1,
  	6,1,6,1,6,1,6,1,6,1,6,3,6,128,8,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,3,8,137,
  	8,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,145,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,5,9,159,8,9,10,9,12,9,162,9,9,1,10,1,10,1,10,1,10,1,
  	10,5,10,169,8,10,10,10,12,10,172,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,3,11,214,8,11,1,12,1,12,1,12,1,12,1,12,3,
  	12,221,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,229,8,13,1,14,1,14,1,14,
  	1,14,1,14,3,14,236,8,14,1,15,1,15,1,15,1,15,1,15,3,15,243,8,15,1,16,1,
  	16,1,16,1,16,1,16,3,16,250,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,5,17,261,8,17,10,17,12,17,264,9,17,1,18,1,18,1,18,1,18,1,18,1,
  	18,5,18,272,8,18,10,18,12,18,275,9,18,1,19,1,19,1,19,1,19,1,19,3,19,282,
  	8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,3,20,302,8,20,1,21,1,21,3,21,306,8,21,1,22,1,
  	22,1,22,1,22,1,22,1,22,5,22,314,8,22,10,22,12,22,317,9,22,1,22,0,7,2,
  	10,18,20,34,36,44,23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,
  	36,38,40,42,44,0,0,340,0,46,1,0,0,0,2,48,1,0,0,0,4,61,1,0,0,0,6,76,1,
  	0,0,0,8,91,1,0,0,0,10,101,1,0,0,0,12,127,1,0,0,0,14,129,1,0,0,0,16,136,
  	1,0,0,0,18,144,1,0,0,0,20,163,1,0,0,0,22,213,1,0,0,0,24,220,1,0,0,0,26,
  	228,1,0,0,0,28,235,1,0,0,0,30,242,1,0,0,0,32,249,1,0,0,0,34,251,1,0,0,
  	0,36,265,1,0,0,0,38,281,1,0,0,0,40,301,1,0,0,0,42,305,1,0,0,0,44,307,
  	1,0,0,0,46,47,3,2,1,0,47,1,1,0,0,0,48,49,6,1,-1,0,49,50,3,4,2,0,50,55,
  	1,0,0,0,51,52,10,2,0,0,52,54,3,4,2,0,53,51,1,0,0,0,54,57,1,0,0,0,55,53,
  	1,0,0,0,55,56,1,0,0,0,56,3,1,0,0,0,57,55,1,0,0,0,58,62,3,14,7,0,59,62,
  	3,6,3,0,60,62,3,8,4,0,61,58,1,0,0,0,61,59,1,0,0,0,61,60,1,0,0,0,62,5,
  	1,0,0,0,63,64,3,16,8,0,64,65,5,30,0,0,65,66,5,14,0,0,66,67,3,10,5,0,67,
  	68,5,15,0,0,68,69,5,20,0,0,69,77,1,0,0,0,70,71,3,16,8,0,71,72,5,30,0,
  	0,72,73,5,14,0,0,73,74,5,15,0,0,74,75,5,20,0,0,75,77,1,0,0,0,76,63,1,
  	0,0,0,76,70,1,0,0,0,77,7,1,0,0,0,78,79,3,16,8,0,79,80,5,30,0,0,80,81,
  	5,14,0,0,81,82,3,10,5,0,82,83,5,15,0,0,83,84,3,12,6,0,84,92,1,0,0,0,85,
  	86,3,16,8,0,86,87,5,30,0,0,87,88,5,14,0,0,88,89,5,15,0,0,89,90,3,12,6,
  	0,90,92,1,0,0,0,91,78,1,0,0,0,91,85,1,0,0,0,92,9,1,0,0,0,93,94,6,5,-1,
  	0,94,95,3,16,8,0,95,96,5,30,0,0,96,102,1,0,0,0,97,102,3,16,8,0,98,99,
  	3,16,8,0,99,100,5,24,0,0,100,102,1,0,0,0,101,93,1,0,0,0,101,97,1,0,0,
  	0,101,98,1,0,0,0,102,118,1,0,0,0,103,104,10,6,0,0,104,105,5,21,0,0,105,
  	106,3,16,8,0,106,107,5,30,0,0,107,117,1,0,0,0,108,109,10,5,0,0,109,110,
  	5,21,0,0,110,117,3,16,8,0,111,112,10,2,0,0,112,113,5,21,0,0,113,114,3,
  	16,8,0,114,115,5,24,0,0,115,117,1,0,0,0,116,103,1,0,0,0,116,108,1,0,0,
  	0,116,111,1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,119,
  	11,1,0,0,0,120,118,1,0,0,0,121,122,5,16,0,0,122,123,3,20,10,0,123,124,
  	5,17,0,0,124,128,1,0,0,0,125,126,5,16,0,0,126,128,5,17,0,0,127,121,1,
  	0,0,0,127,125,1,0,0,0,128,13,1,0,0,0,129,130,3,16,8,0,130,131,3,18,9,
  	0,131,132,5,20,0,0,132,15,1,0,0,0,133,137,5,11,0,0,134,137,5,12,0,0,135,
  	137,5,13,0,0,136,133,1,0,0,0,136,134,1,0,0,0,136,135,1,0,0,0,137,17,1,
  	0,0,0,138,139,6,9,-1,0,139,145,5,30,0,0,140,141,5,30,0,0,141,142,5,18,
  	0,0,142,143,5,32,0,0,143,145,5,19,0,0,144,138,1,0,0,0,144,140,1,0,0,0,
  	145,160,1,0,0,0,146,147,10,5,0,0,147,148,5,21,0,0,148,159,5,30,0,0,149,
  	150,10,4,0,0,150,151,5,21,0,0,151,152,5,30,0,0,152,153,5,18,0,0,153,154,
  	5,32,0,0,154,159,5,19,0,0,155,156,10,1,0,0,156,157,5,24,0,0,157,159,5,
  	30,0,0,158,146,1,0,0,0,158,149,1,0,0,0,158,155,1,0,0,0,159,162,1,0,0,
  	0,160,158,1,0,0,0,160,161,1,0,0,0,161,19,1,0,0,0,162,160,1,0,0,0,163,
  	164,6,10,-1,0,164,165,3,22,11,0,165,170,1,0,0,0,166,167,10,1,0,0,167,
  	169,3,22,11,0,168,166,1,0,0,0,169,172,1,0,0,0,170,168,1,0,0,0,170,171,
  	1,0,0,0,171,21,1,0,0,0,172,170,1,0,0,0,173,214,3,14,7,0,174,214,3,24,
  	12,0,175,214,3,12,6,0,176,177,5,7,0,0,177,178,5,14,0,0,178,179,3,24,12,
  	0,179,180,3,24,12,0,180,181,3,28,14,0,181,182,5,15,0,0,182,183,3,22,11,
  	0,183,214,1,0,0,0,184,185,5,5,0,0,185,186,5,14,0,0,186,187,3,28,14,0,
  	187,188,5,15,0,0,188,189,3,22,11,0,189,190,5,6,0,0,190,191,3,22,11,0,
  	191,214,1,0,0,0,192,193,5,5,0,0,193,194,5,14,0,0,194,195,3,28,14,0,195,
  	196,5,15,0,0,196,197,3,22,11,0,197,214,1,0,0,0,198,199,5,8,0,0,199,200,
  	5,14,0,0,200,201,3,28,14,0,201,202,5,15,0,0,202,203,3,22,11,0,203,214,
  	1,0,0,0,204,205,5,9,0,0,205,206,5,14,0,0,206,207,5,30,0,0,207,208,5,15,
  	0,0,208,214,5,20,0,0,209,210,5,10,0,0,210,211,3,28,14,0,211,212,5,20,
  	0,0,212,214,1,0,0,0,213,173,1,0,0,0,213,174,1,0,0,0,213,175,1,0,0,0,213,
  	176,1,0,0,0,213,184,1,0,0,0,213,192,1,0,0,0,213,198,1,0,0,0,213,204,1,
  	0,0,0,213,209,1,0,0,0,214,23,1,0,0,0,215,221,5,20,0,0,216,217,3,28,14,
  	0,217,218,5,20,0,0,218,221,1,0,0,0,219,221,3,28,14,0,220,215,1,0,0,0,
  	220,216,1,0,0,0,220,219,1,0,0,0,221,25,1,0,0,0,222,229,5,30,0,0,223,224,
  	5,30,0,0,224,225,5,18,0,0,225,226,3,28,14,0,226,227,5,19,0,0,227,229,
  	1,0,0,0,228,222,1,0,0,0,228,223,1,0,0,0,229,27,1,0,0,0,230,236,3,30,15,
  	0,231,232,3,26,13,0,232,233,5,29,0,0,233,234,3,30,15,0,234,236,1,0,0,
  	0,235,230,1,0,0,0,235,231,1,0,0,0,236,29,1,0,0,0,237,243,3,32,16,0,238,
  	239,3,32,16,0,239,240,5,28,0,0,240,241,3,32,16,0,241,243,1,0,0,0,242,
  	237,1,0,0,0,242,238,1,0,0,0,243,31,1,0,0,0,244,250,3,34,17,0,245,246,
  	3,34,17,0,246,247,5,27,0,0,247,248,3,34,17,0,248,250,1,0,0,0,249,244,
  	1,0,0,0,249,245,1,0,0,0,250,33,1,0,0,0,251,252,6,17,-1,0,252,253,3,36,
  	18,0,253,262,1,0,0,0,254,255,10,2,0,0,255,256,5,24,0,0,256,261,3,36,18,
  	0,257,258,10,1,0,0,258,259,5,24,0,0,259,261,5,29,0,0,260,254,1,0,0,0,
  	260,257,1,0,0,0,261,264,1,0,0,0,262,260,1,0,0,0,262,263,1,0,0,0,263,35,
  	1,0,0,0,264,262,1,0,0,0,265,266,6,18,-1,0,266,267,3,38,19,0,267,273,1,
  	0,0,0,268,269,10,1,0,0,269,270,5,25,0,0,270,272,3,38,19,0,271,268,1,0,
  	0,0,272,275,1,0,0,0,273,271,1,0,0,0,273,274,1,0,0,0,274,37,1,0,0,0,275,
  	273,1,0,0,0,276,277,5,24,0,0,277,282,3,38,19,0,278,279,5,26,0,0,279,282,
  	3,38,19,0,280,282,3,40,20,0,281,276,1,0,0,0,281,278,1,0,0,0,281,280,1,
  	0,0,0,282,39,1,0,0,0,283,302,3,26,13,0,284,285,5,30,0,0,285,286,5,14,
  	0,0,286,287,3,42,21,0,287,288,5,15,0,0,288,302,1,0,0,0,289,290,5,14,0,
  	0,290,291,3,28,14,0,291,292,5,15,0,0,292,302,1,0,0,0,293,302,5,32,0,0,
  	294,302,5,31,0,0,295,296,3,26,13,0,296,297,5,22,0,0,297,302,1,0,0,0,298,
  	299,3,26,13,0,299,300,5,23,0,0,300,302,1,0,0,0,301,283,1,0,0,0,301,284,
  	1,0,0,0,301,289,1,0,0,0,301,293,1,0,0,0,301,294,1,0,0,0,301,295,1,0,0,
  	0,301,298,1,0,0,0,302,41,1,0,0,0,303,306,3,44,22,0,304,306,1,0,0,0,305,
  	303,1,0,0,0,305,304,1,0,0,0,306,43,1,0,0,0,307,308,6,22,-1,0,308,309,
  	3,30,15,0,309,315,1,0,0,0,310,311,10,2,0,0,311,312,5,21,0,0,312,314,3,
  	30,15,0,313,310,1,0,0,0,314,317,1,0,0,0,315,313,1,0,0,0,315,316,1,0,0,
  	0,316,45,1,0,0,0,317,315,1,0,0,0,26,55,61,76,91,101,116,118,127,136,144,
  	158,160,170,213,220,228,235,242,249,260,262,273,281,301,305,315
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  csubsetParserStaticData = std::move(staticData);
}

}

CSubsetParser::CSubsetParser(TokenStream *input) : CSubsetParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CSubsetParser::CSubsetParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CSubsetParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *csubsetParserStaticData->atn, csubsetParserStaticData->decisionToDFA, csubsetParserStaticData->sharedContextCache, options);
}

CSubsetParser::~CSubsetParser() {
  delete _interpreter;
}

const atn::ATN& CSubsetParser::getATN() const {
  return *csubsetParserStaticData->atn;
}

std::string CSubsetParser::getGrammarFileName() const {
  return "CSubset.g4";
}

const std::vector<std::string>& CSubsetParser::getRuleNames() const {
  return csubsetParserStaticData->ruleNames;
}

const dfa::Vocabulary& CSubsetParser::getVocabulary() const {
  return csubsetParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CSubsetParser::getSerializedATN() const {
  return csubsetParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

CSubsetParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::ProgramContext* CSubsetParser::StartContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}


size_t CSubsetParser::StartContext::getRuleIndex() const {
  return CSubsetParser::RuleStart;
}


std::any CSubsetParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::StartContext* CSubsetParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, CSubsetParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    program(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

CSubsetParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ProgramContext::getRuleIndex() const {
  return CSubsetParser::RuleProgram;
}

void CSubsetParser::ProgramContext::copyFrom(ProgramContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProgramMultipleContext ------------------------------------------------------------------

CSubsetParser::ProgramContext* CSubsetParser::ProgramMultipleContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}

CSubsetParser::UnitContext* CSubsetParser::ProgramMultipleContext::unit() {
  return getRuleContext<CSubsetParser::UnitContext>(0);
}

CSubsetParser::ProgramMultipleContext::ProgramMultipleContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ProgramMultipleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitProgramMultiple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProgramSingleContext ------------------------------------------------------------------

CSubsetParser::UnitContext* CSubsetParser::ProgramSingleContext::unit() {
  return getRuleContext<CSubsetParser::UnitContext>(0);
}

CSubsetParser::ProgramSingleContext::ProgramSingleContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ProgramSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitProgramSingle(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::ProgramContext* CSubsetParser::program() {
   return program(0);
}

CSubsetParser::ProgramContext* CSubsetParser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  CSubsetParser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, CSubsetParser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<ProgramSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(49);
    antlrcpp::downCast<ProgramSingleContext *>(_localctx)->current = unit();
    _ctx->stop = _input->LT(-1);
    setState(55);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ProgramMultipleContext>(_tracker.createInstance<ProgramContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->previous = previousContext;
        pushNewRecursionContext(newContext, startState, RuleProgram);
        setState(51);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(52);
        antlrcpp::downCast<ProgramMultipleContext *>(_localctx)->current = unit(); 
      }
      setState(57);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

CSubsetParser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::UnitContext::getRuleIndex() const {
  return CSubsetParser::RuleUnit;
}

void CSubsetParser::UnitContext::copyFrom(UnitContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnitFunctionDefinitionContext ------------------------------------------------------------------

CSubsetParser::Func_definitionContext* CSubsetParser::UnitFunctionDefinitionContext::func_definition() {
  return getRuleContext<CSubsetParser::Func_definitionContext>(0);
}

CSubsetParser::UnitFunctionDefinitionContext::UnitFunctionDefinitionContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnitFunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnitFunctionDeclarationContext ------------------------------------------------------------------

CSubsetParser::Func_declarationContext* CSubsetParser::UnitFunctionDeclarationContext::func_declaration() {
  return getRuleContext<CSubsetParser::Func_declarationContext>(0);
}

CSubsetParser::UnitFunctionDeclarationContext::UnitFunctionDeclarationContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnitFunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnitVariableDeclarationContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext* CSubsetParser::UnitVariableDeclarationContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

CSubsetParser::UnitVariableDeclarationContext::UnitVariableDeclarationContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnitVariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::UnitContext* CSubsetParser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, CSubsetParser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::UnitVariableDeclarationContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(58);
      var_declaration();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::UnitFunctionDeclarationContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(59);
      func_declaration();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::UnitFunctionDefinitionContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(60);
      func_definition();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

CSubsetParser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Func_declarationContext::getRuleIndex() const {
  return CSubsetParser::RuleFunc_declaration;
}

void CSubsetParser::Func_declarationContext::copyFrom(Func_declarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunctionDeclarationWithParametersContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FunctionDeclarationWithParametersContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithParametersContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithParametersContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::FunctionDeclarationWithParametersContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithParametersContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithParametersContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::FunctionDeclarationWithParametersContext::FunctionDeclarationWithParametersContext(Func_declarationContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FunctionDeclarationWithParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclarationWithParameters(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionDeclarationWithoutParametersContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FunctionDeclarationWithoutParametersContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithoutParametersContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithoutParametersContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithoutParametersContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithoutParametersContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::FunctionDeclarationWithoutParametersContext::FunctionDeclarationWithoutParametersContext(Func_declarationContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FunctionDeclarationWithoutParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclarationWithoutParameters(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Func_declarationContext* CSubsetParser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, CSubsetParser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FunctionDeclarationWithParametersContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(63);
      type_specifier();
      setState(64);
      match(CSubsetParser::ID);
      setState(65);
      match(CSubsetParser::LPAREN);
      setState(66);
      parameter_list(0);
      setState(67);
      match(CSubsetParser::RPAREN);
      setState(68);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FunctionDeclarationWithoutParametersContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(70);
      type_specifier();
      setState(71);
      match(CSubsetParser::ID);
      setState(72);
      match(CSubsetParser::LPAREN);
      setState(73);
      match(CSubsetParser::RPAREN);
      setState(74);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

CSubsetParser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Func_definitionContext::getRuleIndex() const {
  return CSubsetParser::RuleFunc_definition;
}

void CSubsetParser::Func_definitionContext::copyFrom(Func_definitionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunctionDefinitionWithParametersContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FunctionDefinitionWithParametersContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithParametersContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithParametersContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::FunctionDefinitionWithParametersContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithParametersContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Compound_statementContext* CSubsetParser::FunctionDefinitionWithParametersContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::FunctionDefinitionWithParametersContext::FunctionDefinitionWithParametersContext(Func_definitionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FunctionDefinitionWithParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinitionWithParameters(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionDefinitionWithoutParametersContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FunctionDefinitionWithoutParametersContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithoutParametersContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithoutParametersContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithoutParametersContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Compound_statementContext* CSubsetParser::FunctionDefinitionWithoutParametersContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::FunctionDefinitionWithoutParametersContext::FunctionDefinitionWithoutParametersContext(Func_definitionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FunctionDefinitionWithoutParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinitionWithoutParameters(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Func_definitionContext* CSubsetParser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, CSubsetParser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(91);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FunctionDefinitionWithParametersContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(78);
      type_specifier();
      setState(79);
      match(CSubsetParser::ID);
      setState(80);
      match(CSubsetParser::LPAREN);
      setState(81);
      parameter_list(0);
      setState(82);
      match(CSubsetParser::RPAREN);
      setState(83);
      compound_statement();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FunctionDefinitionWithoutParametersContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(85);
      type_specifier();
      setState(86);
      match(CSubsetParser::ID);
      setState(87);
      match(CSubsetParser::LPAREN);
      setState(88);
      match(CSubsetParser::RPAREN);
      setState(89);
      compound_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Parameter_listContext::getRuleIndex() const {
  return CSubsetParser::RuleParameter_list;
}

void CSubsetParser::Parameter_listContext::copyFrom(Parameter_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParameterUnnamedAppendContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ParameterUnnamedAppendContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterUnnamedAppendContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::ParameterUnnamedAppendContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

CSubsetParser::ParameterUnnamedAppendContext::ParameterUnnamedAppendContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterUnnamedAppendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterUnnamedAppend(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParameterInvalidSingleContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterInvalidSingleContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::ParameterInvalidSingleContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::ParameterInvalidSingleContext::ParameterInvalidSingleContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterInvalidSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterInvalidSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParameterNamedAppendContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ParameterNamedAppendContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterNamedAppendContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::ParameterNamedAppendContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::ParameterNamedAppendContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

CSubsetParser::ParameterNamedAppendContext::ParameterNamedAppendContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterNamedAppendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterNamedAppend(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParameterInvalidAppendContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ParameterInvalidAppendContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterInvalidAppendContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::ParameterInvalidAppendContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::ParameterInvalidAppendContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

CSubsetParser::ParameterInvalidAppendContext::ParameterInvalidAppendContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterInvalidAppendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterInvalidAppend(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParameterUnnamedSingleContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterUnnamedSingleContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::ParameterUnnamedSingleContext::ParameterUnnamedSingleContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterUnnamedSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterUnnamedSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParameterNamedSingleContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterNamedSingleContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::ParameterNamedSingleContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::ParameterNamedSingleContext::ParameterNamedSingleContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterNamedSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterNamedSingle(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Parameter_listContext* CSubsetParser::parameter_list() {
   return parameter_list(0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  CSubsetParser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, CSubsetParser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(101);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParameterNamedSingleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(94);
      type_specifier();
      setState(95);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParameterUnnamedSingleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      type_specifier();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ParameterInvalidSingleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(98);
      type_specifier();
      setState(99);
      match(CSubsetParser::ADDOP);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(118);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(116);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ParameterNamedAppendContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->previous = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(103);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(104);
          match(CSubsetParser::COMMA);
          setState(105);
          type_specifier();
          setState(106);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ParameterUnnamedAppendContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->previous = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(108);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(109);
          match(CSubsetParser::COMMA);
          setState(110);
          type_specifier();
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ParameterInvalidAppendContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->previous = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(111);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(112);
          match(CSubsetParser::COMMA);
          setState(113);
          type_specifier();
          setState(114);
          match(CSubsetParser::ADDOP);
          break;
        }

        default:
          break;
        } 
      }
      setState(120);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

CSubsetParser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Compound_statementContext::getRuleIndex() const {
  return CSubsetParser::RuleCompound_statement;
}

void CSubsetParser::Compound_statementContext::copyFrom(Compound_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CompoundWithStatementsContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::CompoundWithStatementsContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

CSubsetParser::StatementsContext* CSubsetParser::CompoundWithStatementsContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

tree::TerminalNode* CSubsetParser::CompoundWithStatementsContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}

CSubsetParser::CompoundWithStatementsContext::CompoundWithStatementsContext(Compound_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::CompoundWithStatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompoundWithStatements(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompoundEmptyContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::CompoundEmptyContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

tree::TerminalNode* CSubsetParser::CompoundEmptyContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}

CSubsetParser::CompoundEmptyContext::CompoundEmptyContext(Compound_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::CompoundEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompoundEmpty(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Compound_statementContext* CSubsetParser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, CSubsetParser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::CompoundWithStatementsContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(121);
      match(CSubsetParser::LCURL);
      setState(122);
      statements(0);
      setState(123);
      match(CSubsetParser::RCURL);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::CompoundEmptyContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(125);
      match(CSubsetParser::LCURL);
      setState(126);
      match(CSubsetParser::RCURL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Type_specifierContext* CSubsetParser::Var_declarationContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::Var_declarationContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Var_declarationContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}


size_t CSubsetParser::Var_declarationContext::getRuleIndex() const {
  return CSubsetParser::RuleVar_declaration;
}


std::any CSubsetParser::Var_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVar_declaration(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Var_declarationContext* CSubsetParser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, CSubsetParser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    type_specifier();
    setState(130);
    declaration_list(0);
    setState(131);
    match(CSubsetParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Type_specifierContext::getRuleIndex() const {
  return CSubsetParser::RuleType_specifier;
}

void CSubsetParser::Type_specifierContext::copyFrom(Type_specifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TypeFloatContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::TypeFloatContext::FLOAT() {
  return getToken(CSubsetParser::FLOAT, 0);
}

CSubsetParser::TypeFloatContext::TypeFloatContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TypeFloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTypeFloat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeVoidContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::TypeVoidContext::VOID() {
  return getToken(CSubsetParser::VOID, 0);
}

CSubsetParser::TypeVoidContext::TypeVoidContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TypeVoidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTypeVoid(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeIntContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::TypeIntContext::INT() {
  return getToken(CSubsetParser::INT, 0);
}

CSubsetParser::TypeIntContext::TypeIntContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TypeIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTypeInt(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Type_specifierContext* CSubsetParser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 16, CSubsetParser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::INT: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeIntContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(133);
        match(CSubsetParser::INT);
        break;
      }

      case CSubsetParser::FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeFloatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(134);
        match(CSubsetParser::FLOAT);
        break;
      }

      case CSubsetParser::VOID: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeVoidContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(135);
        match(CSubsetParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Declaration_listContext::getRuleIndex() const {
  return CSubsetParser::RuleDeclaration_list;
}

void CSubsetParser::Declaration_listContext::copyFrom(Declaration_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DeclarationArrayAppendContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::DeclarationArrayAppendContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationArrayAppendContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationArrayAppendContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationArrayAppendContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationArrayAppendContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::DeclarationArrayAppendContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

CSubsetParser::DeclarationArrayAppendContext::DeclarationArrayAppendContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclarationArrayAppendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclarationArrayAppend(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationInvalidAppendContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::DeclarationInvalidAppendContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationInvalidAppendContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::DeclarationInvalidAppendContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

CSubsetParser::DeclarationInvalidAppendContext::DeclarationInvalidAppendContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclarationInvalidAppendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclarationInvalidAppend(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationArraySingleContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::DeclarationArraySingleContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationArraySingleContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationArraySingleContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationArraySingleContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::DeclarationArraySingleContext::DeclarationArraySingleContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclarationArraySingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclarationArraySingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationScalarAppendContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::DeclarationScalarAppendContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationScalarAppendContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::DeclarationScalarAppendContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

CSubsetParser::DeclarationScalarAppendContext::DeclarationScalarAppendContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclarationScalarAppendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclarationScalarAppend(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationScalarSingleContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::DeclarationScalarSingleContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::DeclarationScalarSingleContext::DeclarationScalarSingleContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclarationScalarSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclarationScalarSingle(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list() {
   return declaration_list(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  CSubsetParser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, CSubsetParser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<DeclarationScalarSingleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(139);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<DeclarationArraySingleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(140);
      match(CSubsetParser::ID);
      setState(141);
      match(CSubsetParser::LTHIRD);
      setState(142);
      match(CSubsetParser::CONST_INT);
      setState(143);
      match(CSubsetParser::RTHIRD);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(160);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(158);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<DeclarationScalarAppendContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->previous = previousContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(146);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(147);
          match(CSubsetParser::COMMA);
          setState(148);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DeclarationArrayAppendContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->previous = previousContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(149);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(150);
          match(CSubsetParser::COMMA);
          setState(151);
          match(CSubsetParser::ID);
          setState(152);
          match(CSubsetParser::LTHIRD);
          setState(153);
          match(CSubsetParser::CONST_INT);
          setState(154);
          match(CSubsetParser::RTHIRD);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<DeclarationInvalidAppendContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->previous = previousContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(155);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(156);
          match(CSubsetParser::ADDOP);
          setState(157);
          match(CSubsetParser::ID);
          break;
        }

        default:
          break;
        } 
      }
      setState(162);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

CSubsetParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::StatementsContext::getRuleIndex() const {
  return CSubsetParser::RuleStatements;
}

void CSubsetParser::StatementsContext::copyFrom(StatementsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StatementsSingleContext ------------------------------------------------------------------

CSubsetParser::StatementContext* CSubsetParser::StatementsSingleContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StatementsSingleContext::StatementsSingleContext(StatementsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementsSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementsSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementsMultipleContext ------------------------------------------------------------------

CSubsetParser::StatementsContext* CSubsetParser::StatementsMultipleContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

CSubsetParser::StatementContext* CSubsetParser::StatementsMultipleContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StatementsMultipleContext::StatementsMultipleContext(StatementsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementsMultipleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementsMultiple(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::StatementsContext* CSubsetParser::statements() {
   return statements(0);
}

CSubsetParser::StatementsContext* CSubsetParser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  CSubsetParser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, CSubsetParser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<StatementsSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(164);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(170);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<StatementsMultipleContext>(_tracker.createInstance<StatementsContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->previous = previousContext;
        pushNewRecursionContext(newContext, startState, RuleStatements);
        setState(166);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(167);
        antlrcpp::downCast<StatementsMultipleContext *>(_localctx)->current = statement(); 
      }
      setState(172);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CSubsetParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::StatementContext::getRuleIndex() const {
  return CSubsetParser::RuleStatement;
}

void CSubsetParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StatementIfContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StatementIfContext::IF() {
  return getToken(CSubsetParser::IF, 0);
}

tree::TerminalNode* CSubsetParser::StatementIfContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::StatementIfContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::StatementIfContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

CSubsetParser::StatementContext* CSubsetParser::StatementIfContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StatementIfContext::StatementIfContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementIf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementVariableDeclarationContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext* CSubsetParser::StatementVariableDeclarationContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

CSubsetParser::StatementVariableDeclarationContext::StatementVariableDeclarationContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementVariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementForContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StatementForContext::FOR() {
  return getToken(CSubsetParser::FOR, 0);
}

tree::TerminalNode* CSubsetParser::StatementForContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::StatementForContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

std::vector<CSubsetParser::Expression_statementContext *> CSubsetParser::StatementForContext::expression_statement() {
  return getRuleContexts<CSubsetParser::Expression_statementContext>();
}

CSubsetParser::Expression_statementContext* CSubsetParser::StatementForContext::expression_statement(size_t i) {
  return getRuleContext<CSubsetParser::Expression_statementContext>(i);
}

CSubsetParser::ExpressionContext* CSubsetParser::StatementForContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

CSubsetParser::StatementContext* CSubsetParser::StatementForContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StatementForContext::StatementForContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementFor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementReturnContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StatementReturnContext::RETURN() {
  return getToken(CSubsetParser::RETURN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::StatementReturnContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::StatementReturnContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::StatementReturnContext::StatementReturnContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementReturn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementWhileContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StatementWhileContext::WHILE() {
  return getToken(CSubsetParser::WHILE, 0);
}

tree::TerminalNode* CSubsetParser::StatementWhileContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::StatementWhileContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::StatementWhileContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

CSubsetParser::StatementContext* CSubsetParser::StatementWhileContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StatementWhileContext::StatementWhileContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementExpressionContext ------------------------------------------------------------------

CSubsetParser::Expression_statementContext* CSubsetParser::StatementExpressionContext::expression_statement() {
  return getRuleContext<CSubsetParser::Expression_statementContext>(0);
}

CSubsetParser::StatementExpressionContext::StatementExpressionContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementCompoundContext ------------------------------------------------------------------

CSubsetParser::Compound_statementContext* CSubsetParser::StatementCompoundContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::StatementCompoundContext::StatementCompoundContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementCompoundContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementCompound(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementPrintlnContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StatementPrintlnContext::PRINTLN() {
  return getToken(CSubsetParser::PRINTLN, 0);
}

tree::TerminalNode* CSubsetParser::StatementPrintlnContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::StatementPrintlnContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::StatementPrintlnContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::StatementPrintlnContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::StatementPrintlnContext::StatementPrintlnContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementPrintlnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementPrintln(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementIfElseContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StatementIfElseContext::IF() {
  return getToken(CSubsetParser::IF, 0);
}

tree::TerminalNode* CSubsetParser::StatementIfElseContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::StatementIfElseContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::StatementIfElseContext::ELSE() {
  return getToken(CSubsetParser::ELSE, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::StatementIfElseContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

std::vector<CSubsetParser::StatementContext *> CSubsetParser::StatementIfElseContext::statement() {
  return getRuleContexts<CSubsetParser::StatementContext>();
}

CSubsetParser::StatementContext* CSubsetParser::StatementIfElseContext::statement(size_t i) {
  return getRuleContext<CSubsetParser::StatementContext>(i);
}

CSubsetParser::StatementIfElseContext::StatementIfElseContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementIfElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementIfElse(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::StatementContext* CSubsetParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, CSubsetParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::StatementVariableDeclarationContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(173);
      var_declaration();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::StatementExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(174);
      expression_statement();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::StatementCompoundContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(175);
      compound_statement();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::StatementForContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(176);
      match(CSubsetParser::FOR);
      setState(177);
      match(CSubsetParser::LPAREN);
      setState(178);
      antlrcpp::downCast<StatementForContext *>(_localctx)->init = expression_statement();
      setState(179);
      antlrcpp::downCast<StatementForContext *>(_localctx)->condition = expression_statement();
      setState(180);
      antlrcpp::downCast<StatementForContext *>(_localctx)->update = expression();
      setState(181);
      match(CSubsetParser::RPAREN);
      setState(182);
      antlrcpp::downCast<StatementForContext *>(_localctx)->body = statement();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubsetParser::StatementIfElseContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(184);
      match(CSubsetParser::IF);
      setState(185);
      match(CSubsetParser::LPAREN);
      setState(186);
      antlrcpp::downCast<StatementIfElseContext *>(_localctx)->condition = expression();
      setState(187);
      match(CSubsetParser::RPAREN);
      setState(188);
      antlrcpp::downCast<StatementIfElseContext *>(_localctx)->thenBranch = statement();
      setState(189);
      match(CSubsetParser::ELSE);
      setState(190);
      antlrcpp::downCast<StatementIfElseContext *>(_localctx)->elseBranch = statement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubsetParser::StatementIfContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(192);
      match(CSubsetParser::IF);
      setState(193);
      match(CSubsetParser::LPAREN);
      setState(194);
      antlrcpp::downCast<StatementIfContext *>(_localctx)->condition = expression();
      setState(195);
      match(CSubsetParser::RPAREN);
      setState(196);
      antlrcpp::downCast<StatementIfContext *>(_localctx)->thenBranch = statement();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubsetParser::StatementWhileContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(198);
      match(CSubsetParser::WHILE);
      setState(199);
      match(CSubsetParser::LPAREN);
      setState(200);
      antlrcpp::downCast<StatementWhileContext *>(_localctx)->condition = expression();
      setState(201);
      match(CSubsetParser::RPAREN);
      setState(202);
      antlrcpp::downCast<StatementWhileContext *>(_localctx)->body = statement();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<CSubsetParser::StatementPrintlnContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(204);
      match(CSubsetParser::PRINTLN);
      setState(205);
      match(CSubsetParser::LPAREN);
      setState(206);
      match(CSubsetParser::ID);
      setState(207);
      match(CSubsetParser::RPAREN);
      setState(208);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<CSubsetParser::StatementReturnContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(209);
      match(CSubsetParser::RETURN);
      setState(210);
      expression();
      setState(211);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

CSubsetParser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Expression_statementContext::getRuleIndex() const {
  return CSubsetParser::RuleExpression_statement;
}

void CSubsetParser::Expression_statementContext::copyFrom(Expression_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExpressionStatementEmptyContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ExpressionStatementEmptyContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::ExpressionStatementEmptyContext::ExpressionStatementEmptyContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ExpressionStatementEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpressionStatementEmpty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpressionStatementNormalContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext* CSubsetParser::ExpressionStatementNormalContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::ExpressionStatementNormalContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::ExpressionStatementNormalContext::ExpressionStatementNormalContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ExpressionStatementNormalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpressionStatementNormal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpressionStatementMissingSemicolonContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext* CSubsetParser::ExpressionStatementMissingSemicolonContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

CSubsetParser::ExpressionStatementMissingSemicolonContext::ExpressionStatementMissingSemicolonContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ExpressionStatementMissingSemicolonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpressionStatementMissingSemicolon(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Expression_statementContext* CSubsetParser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 24, CSubsetParser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::ExpressionStatementEmptyContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(215);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::ExpressionStatementNormalContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(216);
      expression();
      setState(217);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::ExpressionStatementMissingSemicolonContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(219);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

CSubsetParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::VariableContext::getRuleIndex() const {
  return CSubsetParser::RuleVariable;
}

void CSubsetParser::VariableContext::copyFrom(VariableContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariableScalarContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::VariableScalarContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::VariableScalarContext::VariableScalarContext(VariableContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::VariableScalarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVariableScalar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableArrayContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::VariableArrayContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::VariableArrayContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::VariableArrayContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::VariableArrayContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

CSubsetParser::VariableArrayContext::VariableArrayContext(VariableContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::VariableArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVariableArray(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::VariableContext* CSubsetParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 26, CSubsetParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(228);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::VariableScalarContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(222);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::VariableArrayContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(223);
      match(CSubsetParser::ID);
      setState(224);
      match(CSubsetParser::LTHIRD);
      setState(225);
      antlrcpp::downCast<VariableArrayContext *>(_localctx)->index = expression();
      setState(226);
      match(CSubsetParser::RTHIRD);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ExpressionContext::getRuleIndex() const {
  return CSubsetParser::RuleExpression;
}

void CSubsetParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExpressionLogicContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext* CSubsetParser::ExpressionLogicContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ExpressionLogicContext::ExpressionLogicContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ExpressionLogicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpressionLogic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpressionAssignContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::ExpressionAssignContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::ExpressionAssignContext::ASSIGNOP() {
  return getToken(CSubsetParser::ASSIGNOP, 0);
}

CSubsetParser::Logic_expressionContext* CSubsetParser::ExpressionAssignContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ExpressionAssignContext::ExpressionAssignContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ExpressionAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpressionAssign(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::ExpressionContext* CSubsetParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, CSubsetParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(235);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::ExpressionLogicContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(230);
      logic_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::ExpressionAssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(231);
      variable();
      setState(232);
      match(CSubsetParser::ASSIGNOP);
      setState(233);
      logic_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Logic_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleLogic_expression;
}

void CSubsetParser::Logic_expressionContext::copyFrom(Logic_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LogicSingleContext ------------------------------------------------------------------

CSubsetParser::Rel_expressionContext* CSubsetParser::LogicSingleContext::rel_expression() {
  return getRuleContext<CSubsetParser::Rel_expressionContext>(0);
}

CSubsetParser::LogicSingleContext::LogicSingleContext(Logic_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::LogicSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitLogicSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicBinaryContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::LogicBinaryContext::LOGICOP() {
  return getToken(CSubsetParser::LOGICOP, 0);
}

std::vector<CSubsetParser::Rel_expressionContext *> CSubsetParser::LogicBinaryContext::rel_expression() {
  return getRuleContexts<CSubsetParser::Rel_expressionContext>();
}

CSubsetParser::Rel_expressionContext* CSubsetParser::LogicBinaryContext::rel_expression(size_t i) {
  return getRuleContext<CSubsetParser::Rel_expressionContext>(i);
}

CSubsetParser::LogicBinaryContext::LogicBinaryContext(Logic_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::LogicBinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitLogicBinary(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Logic_expressionContext* CSubsetParser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 30, CSubsetParser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::LogicSingleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(237);
      rel_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::LogicBinaryContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(238);
      antlrcpp::downCast<LogicBinaryContext *>(_localctx)->left = rel_expression();
      setState(239);
      match(CSubsetParser::LOGICOP);
      setState(240);
      antlrcpp::downCast<LogicBinaryContext *>(_localctx)->right = rel_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

CSubsetParser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Rel_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleRel_expression;
}

void CSubsetParser::Rel_expressionContext::copyFrom(Rel_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RelSingleContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext* CSubsetParser::RelSingleContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

CSubsetParser::RelSingleContext::RelSingleContext(Rel_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::RelSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitRelSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelBinaryContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::RelBinaryContext::RELOP() {
  return getToken(CSubsetParser::RELOP, 0);
}

std::vector<CSubsetParser::Simple_expressionContext *> CSubsetParser::RelBinaryContext::simple_expression() {
  return getRuleContexts<CSubsetParser::Simple_expressionContext>();
}

CSubsetParser::Simple_expressionContext* CSubsetParser::RelBinaryContext::simple_expression(size_t i) {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(i);
}

CSubsetParser::RelBinaryContext::RelBinaryContext(Rel_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::RelBinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitRelBinary(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Rel_expressionContext* CSubsetParser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, CSubsetParser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(249);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::RelSingleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(244);
      simple_expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::RelBinaryContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(245);
      antlrcpp::downCast<RelBinaryContext *>(_localctx)->left = simple_expression(0);
      setState(246);
      match(CSubsetParser::RELOP);
      setState(247);
      antlrcpp::downCast<RelBinaryContext *>(_localctx)->right = simple_expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Simple_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleSimple_expression;
}

void CSubsetParser::Simple_expressionContext::copyFrom(Simple_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SimpleSingleContext ------------------------------------------------------------------

CSubsetParser::TermContext* CSubsetParser::SimpleSingleContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

CSubsetParser::SimpleSingleContext::SimpleSingleContext(Simple_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::SimpleSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSimpleSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SimpleBinaryContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::SimpleBinaryContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::SimpleBinaryContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

CSubsetParser::TermContext* CSubsetParser::SimpleBinaryContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

CSubsetParser::SimpleBinaryContext::SimpleBinaryContext(Simple_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::SimpleBinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSimpleBinary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SimpleInvalidAssignmentContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::SimpleInvalidAssignmentContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

tree::TerminalNode* CSubsetParser::SimpleInvalidAssignmentContext::ASSIGNOP() {
  return getToken(CSubsetParser::ASSIGNOP, 0);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::SimpleInvalidAssignmentContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

CSubsetParser::SimpleInvalidAssignmentContext::SimpleInvalidAssignmentContext(Simple_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::SimpleInvalidAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSimpleInvalidAssignment(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::simple_expression() {
   return simple_expression(0);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  CSubsetParser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CSubsetParser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<SimpleSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(252);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(262);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(260);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<SimpleBinaryContext>(_tracker.createInstance<Simple_expressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_expression);
          setState(254);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(255);
          match(CSubsetParser::ADDOP);
          setState(256);
          antlrcpp::downCast<SimpleBinaryContext *>(_localctx)->right = term(0);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<SimpleInvalidAssignmentContext>(_tracker.createInstance<Simple_expressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_expression);
          setState(257);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(258);
          match(CSubsetParser::ADDOP);
          setState(259);
          match(CSubsetParser::ASSIGNOP);
          break;
        }

        default:
          break;
        } 
      }
      setState(264);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

CSubsetParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::TermContext::getRuleIndex() const {
  return CSubsetParser::RuleTerm;
}

void CSubsetParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TermSingleContext ------------------------------------------------------------------

CSubsetParser::Unary_expressionContext* CSubsetParser::TermSingleContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::TermSingleContext::TermSingleContext(TermContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TermSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTermSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TermBinaryContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::TermBinaryContext::MULOP() {
  return getToken(CSubsetParser::MULOP, 0);
}

CSubsetParser::TermContext* CSubsetParser::TermBinaryContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::TermBinaryContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::TermBinaryContext::TermBinaryContext(TermContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TermBinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTermBinary(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::TermContext* CSubsetParser::term() {
   return term(0);
}

CSubsetParser::TermContext* CSubsetParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  CSubsetParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, CSubsetParser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<TermSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(266);
    unary_expression();
    _ctx->stop = _input->LT(-1);
    setState(273);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<TermBinaryContext>(_tracker.createInstance<TermContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->left = previousContext;
        pushNewRecursionContext(newContext, startState, RuleTerm);
        setState(268);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(269);
        match(CSubsetParser::MULOP);
        setState(270);
        antlrcpp::downCast<TermBinaryContext *>(_localctx)->right = unary_expression(); 
      }
      setState(275);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

CSubsetParser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Unary_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleUnary_expression;
}

void CSubsetParser::Unary_expressionContext::copyFrom(Unary_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryNotContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::UnaryNotContext::NOT() {
  return getToken(CSubsetParser::NOT, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::UnaryNotContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::UnaryNotContext::UnaryNotContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnaryNotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnaryNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryFactorContext ------------------------------------------------------------------

CSubsetParser::FactorContext* CSubsetParser::UnaryFactorContext::factor() {
  return getRuleContext<CSubsetParser::FactorContext>(0);
}

CSubsetParser::UnaryFactorContext::UnaryFactorContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnaryFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnaryFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryAddContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::UnaryAddContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::UnaryAddContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::UnaryAddContext::UnaryAddContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnaryAddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnaryAdd(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Unary_expressionContext* CSubsetParser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 38, CSubsetParser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(281);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::ADDOP: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryAddContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(276);
        match(CSubsetParser::ADDOP);
        setState(277);
        antlrcpp::downCast<UnaryAddContext *>(_localctx)->operand = unary_expression();
        break;
      }

      case CSubsetParser::NOT: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryNotContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(278);
        match(CSubsetParser::NOT);
        setState(279);
        antlrcpp::downCast<UnaryNotContext *>(_localctx)->operand = unary_expression();
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_FLOAT:
      case CSubsetParser::CONST_INT: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryFactorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(280);
        factor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

CSubsetParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::FactorContext::getRuleIndex() const {
  return CSubsetParser::RuleFactor;
}

void CSubsetParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FactorFunctionCallContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FactorFunctionCallContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FactorFunctionCallContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Argument_listContext* CSubsetParser::FactorFunctionCallContext::argument_list() {
  return getRuleContext<CSubsetParser::Argument_listContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorFunctionCallContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::FactorFunctionCallContext::FactorFunctionCallContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorFunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorFunctionCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorVariableContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::FactorVariableContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

CSubsetParser::FactorVariableContext::FactorVariableContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorIntContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FactorIntContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

CSubsetParser::FactorIntContext::FactorIntContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorParenthesizedContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FactorParenthesizedContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::FactorParenthesizedContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorParenthesizedContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::FactorParenthesizedContext::FactorParenthesizedContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorParenthesizedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorParenthesized(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorFloatContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FactorFloatContext::CONST_FLOAT() {
  return getToken(CSubsetParser::CONST_FLOAT, 0);
}

CSubsetParser::FactorFloatContext::FactorFloatContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorFloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorFloat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorIncrementContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::FactorIncrementContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorIncrementContext::INCOP() {
  return getToken(CSubsetParser::INCOP, 0);
}

CSubsetParser::FactorIncrementContext::FactorIncrementContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorIncrementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorIncrement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorDecrementContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::FactorDecrementContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorDecrementContext::DECOP() {
  return getToken(CSubsetParser::DECOP, 0);
}

CSubsetParser::FactorDecrementContext::FactorDecrementContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorDecrementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorDecrement(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::FactorContext* CSubsetParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 40, CSubsetParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorVariableContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(283);
      variable();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorFunctionCallContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(284);
      match(CSubsetParser::ID);
      setState(285);
      match(CSubsetParser::LPAREN);
      setState(286);
      argument_list();
      setState(287);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorParenthesizedContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(289);
      match(CSubsetParser::LPAREN);
      setState(290);
      expression();
      setState(291);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorIntContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(293);
      match(CSubsetParser::CONST_INT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorFloatContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(294);
      match(CSubsetParser::CONST_FLOAT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorIncrementContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(295);
      variable();
      setState(296);
      match(CSubsetParser::INCOP);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorDecrementContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(298);
      variable();
      setState(299);
      match(CSubsetParser::DECOP);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

CSubsetParser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Argument_listContext::getRuleIndex() const {
  return CSubsetParser::RuleArgument_list;
}

void CSubsetParser::Argument_listContext::copyFrom(Argument_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArgumentListEmptyContext ------------------------------------------------------------------

CSubsetParser::ArgumentListEmptyContext::ArgumentListEmptyContext(Argument_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgumentListEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgumentListEmpty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgumentListNonEmptyContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext* CSubsetParser::ArgumentListNonEmptyContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

CSubsetParser::ArgumentListNonEmptyContext::ArgumentListNonEmptyContext(Argument_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgumentListNonEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgumentListNonEmpty(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Argument_listContext* CSubsetParser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 42, CSubsetParser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::LPAREN:
      case CSubsetParser::ADDOP:
      case CSubsetParser::NOT:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_FLOAT:
      case CSubsetParser::CONST_INT: {
        _localctx = _tracker.createInstance<CSubsetParser::ArgumentListNonEmptyContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(303);
        arguments(0);
        break;
      }

      case CSubsetParser::RPAREN: {
        _localctx = _tracker.createInstance<CSubsetParser::ArgumentListEmptyContext>(_localctx);
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ArgumentsContext::getRuleIndex() const {
  return CSubsetParser::RuleArguments;
}

void CSubsetParser::ArgumentsContext::copyFrom(ArgumentsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArgumentsSingleContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext* CSubsetParser::ArgumentsSingleContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ArgumentsSingleContext::ArgumentsSingleContext(ArgumentsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgumentsSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgumentsSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgumentsMultipleContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ArgumentsMultipleContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::ArgumentsContext* CSubsetParser::ArgumentsMultipleContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

CSubsetParser::Logic_expressionContext* CSubsetParser::ArgumentsMultipleContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ArgumentsMultipleContext::ArgumentsMultipleContext(ArgumentsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgumentsMultipleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgumentsMultiple(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::ArgumentsContext* CSubsetParser::arguments() {
   return arguments(0);
}

CSubsetParser::ArgumentsContext* CSubsetParser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  CSubsetParser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, CSubsetParser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<ArgumentsSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(308);
    antlrcpp::downCast<ArgumentsSingleContext *>(_localctx)->current = logic_expression();
    _ctx->stop = _input->LT(-1);
    setState(315);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ArgumentsMultipleContext>(_tracker.createInstance<ArgumentsContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->previous = previousContext;
        pushNewRecursionContext(newContext, startState, RuleArguments);
        setState(310);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(311);
        match(CSubsetParser::COMMA);
        setState(312);
        antlrcpp::downCast<ArgumentsMultipleContext *>(_localctx)->current = logic_expression(); 
      }
      setState(317);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CSubsetParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 9: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 10: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 17: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 18: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 22: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 5);
    case 5: return precpred(_ctx, 4);
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void CSubsetParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  csubsetParserInitialize();
#else
  ::antlr4::internal::call_once(csubsetParserOnceFlag, csubsetParserInitialize);
#endif
}
