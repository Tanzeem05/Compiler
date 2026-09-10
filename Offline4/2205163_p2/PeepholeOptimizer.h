#ifndef PEEPHOLE_OPTIMIZER_H
#define PEEPHOLE_OPTIMIZER_H

#include <string>

class PeepholeOptimizer {
public:
    static void optimize(
        const std::string& inputFile,
        const std::string& outputFile);
};

#endif
