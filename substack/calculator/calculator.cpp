#include "Calculator.h"

// Stolen from Google Benchmarks for the quick benchmark below
template <typename Tp>
static inline void DoNotOptimize(Tp const& value) {
    asm volatile("" : : "r,m"(value) : "memory");
}

// Our main namespace
using namespace Interpreter;

// Quick cycles gathering
uint64_t now() {
    return __builtin_ia32_rdtsc();
}

int main(int argc, char* argv[]) {
    // Usage
    if (argc < 2) {
        printf("Usage: calc <expression>\n");
        return 0;
    }

    // Create the main class
    Calculator calc;

    // Run through every argument as expressions
    for (int j = 1; j < argc; ++j) {
        std::string cmd = argv[j];
        printf("Solving %s\n", cmd.c_str());

        // The resulting value from expression
        double value;

        // Start counting time
        uint64_t t0 = now();
        for (int j = 0; j < 10000; ++j) {
            // Parse the expression
            Pointer<Node> ast = calc.parse(cmd);

            // Compute the expression in the AST tree
            value = ast->calc();

            // This so the above does not get optimized away from compiler
            DoNotOptimize(value);
        }

        // Compute elapsed time in CPU ticks
        uint64_t t1 = now();
        double elapsed = (t1 - t0) / 10000.;
        printf("Result: %f Avg:%f cycles\n", value, elapsed);
    }
}