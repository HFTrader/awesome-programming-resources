#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <limits>
#include <algorithm>
#include <string_view>

#include "functions.h"
#include "utils.h"

namespace caleth {
double callfn(void* fn, const std::vector<double>& args);
};
namespace fred {
double callfn(void* fn, const std::vector<double>& args);
};
namespace fred2 {
double callfn(void* fn, const std::vector<double>& args);
};
namespace trivial {
double callfn(void* fn, const std::vector<double>& args);
};

template <double (*Fn)(void*, const std::vector<double>&)>
void test(std::string_view name, Function fn, const std::vector<double>& args) {
    struct Result {
        long long elapsed = 0;
        double value = 0;
        bool operator<(const Result& rhs) {
            return elapsed < rhs.elapsed;
        }
    };
    std::array<Result, 10000> samples;
    bool first = true;
    for (auto& result : samples) {
        auto t0 = tic();
        if (!first) {
            result.value = Fn(fn.fnptr, args);
            result.elapsed = toc() - t0;
        } else {
            result.elapsed = toc() - t0;
            result.value = 0;
            first = false;
        }
    }
    samples[0].value = samples[1].value;
    std::sort(samples.begin(), samples.end());
    long long noop = samples[0].elapsed;
    long long median = samples[samples.size() / 2].elapsed - noop;
    long long slowest = samples.back().elapsed - noop;
    long long best = samples[1].elapsed - noop;
    double sum = 0;
    for (const auto& result : samples) {
        sum += result.value;
    }
    std::cout << name << " " << sum / samples.size() << " " << best << " " << median
              << " " << slowest << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "Usage: caller <fnum> [<value>...]" << std::endl;
        return 0;
    }
    int fnum = std::atoi(argv[1]);
    int numargs = argc - 2;
    std::vector<double> args(numargs);
    for (int j = 0; j < numargs; ++j) args[j] = std::atof(argv[j + 2]);
    Function fn = fntable[fnum];
    if (fn.numargs != numargs) {
        std::cout << "Wrong number of arguments for function #" << fnum << ". Got "
                  << numargs << " expected " << fn.numargs << std::endl;
        return 1;
    }

#if defined(RUN_CALETH) || defined(RUN_ALL)
    test<caleth::callfn>("StackOverflow::caleth", fn, args);
#endif
#if defined(RUN_TRIVIAL) || defined(RUN_ALL)
    test<trivial::callfn>("Trivial solution     ", fn, args);
#endif
#if defined(RUN_FRED) || defined(RUN_ALL)
    test<fred::callfn>("Fred's solution      ", fn, args);
#endif
#if defined(RUN_FRED2) || defined(RUN_ALL)
    test<fred2::callfn>("Fred's solution 2    ", fn, args);
#endif
}
