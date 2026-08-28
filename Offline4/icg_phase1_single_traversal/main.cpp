#include "CSubsetLexer.h"
#include "CSubsetParser.h"
#include "ICGVisitor.h"
#include "PeepholeOptimizer.h"
#include "antlr4-runtime.h"


#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input.c>\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Could not open input file: " << argv[1] << '\n';
        return 1;
    }

    const string source(
        (istreambuf_iterator<char>(inputFile)),
        istreambuf_iterator<char>());

    try {
        // PASS 1: ANTLR reads the input and creates ONE parse tree.
        antlr4::ANTLRInputStream input(source);
        CSubsetLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer); 
        CSubsetParser parser(&tokens);

        antlr4::tree::ParseTree* tree = parser.start();

        if (parser.getNumberOfSyntaxErrors() != 0) {
            cerr << "ICG stopped because the input has syntax errors.\n";
            return 1;
        }

        // PASS 2: traverse that parse tree exactly ONCE and generate code.asm.
        ICGVisitor visitor("mycode.asm");
        visitor.generate(tree);

        // Required post-generation peephole optimization. This does NOT
        // traverse the parse tree; it only processes generated assembly text.
        PeepholeOptimizer::optimize("mycode.asm", "optimized_code.asm");
    }
    catch (const exception& e) {
        cerr << "ICG error: " << e.what() << '\n';
        return 1;
    }

    cout << "Generated mycode.asm and optimized_code.asm\n";
    return 0;
}
