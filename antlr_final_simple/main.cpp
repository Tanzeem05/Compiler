#include "CSubsetLexer.h"
#include "CSubsetParser.h"
#include "SemanticVisitor.h"
#include "antlr4-runtime.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int countLines(string source) {
    if (source.empty()) {
        return 0;
    }

    int lines = count(source.begin(), source.end(), '\n');
    if (source.back() != '\n') {
        lines++;
    }

    return lines;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input.c>\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "Could not open input file\n";
        return 1;
    }

    string source(
        (istreambuf_iterator<char>(inputFile)),
        istreambuf_iterator<char>());

    ofstream logFile("log.txt", ios::trunc);

    antlr4::ANTLRInputStream input(source);
    CSubsetLexer lexer(&input);
    lexer.removeErrorListeners();

    antlr4::CommonTokenStream tokens(&lexer);
    CSubsetParser parser(&tokens);
    parser.removeErrorListeners();

    antlr4::tree::ParseTree* tree = parser.start();

    SemanticVisitor visitor(source, logFile, countLines(source));
    visitor.visit(tree);
    visitor.writeErrorFile("error.txt");

    return 0;
}
