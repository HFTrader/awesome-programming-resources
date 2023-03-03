#include <cstdint>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <cassert>
#include "benchmark/benchmark.h"

std::random_device rd;
std::mt19937 g(rd());

template <typename IntType>
std::ostream& operator<<(std::ostream& out, const std::vector<IntType>& values) {
    for (IntType val : values) {
        std::cout << val << " ";
    }
    return out;
}

template <typename IntType>
std::vector<IntType> createCycle(size_t size) {
    std::vector<IntType> indices(size), shuffled(size);
    for (size_t j = 0; j < size; ++j) indices[j] = j;
    std::shuffle(indices.begin(), indices.end(), g);
    size_t pos = indices[0];
    for (size_t j = 1; j < size; ++j) {
        size_t next = indices[j];
        shuffled[pos] = next;
        pos = next;
    }
    size_t next = indices[0];
    shuffled[pos] = next;
    return shuffled;
}

uint64_t now() {
    return __builtin_ia32_rdtsc();
}

template <typename IntType>
void TestCycle(benchmark::State& state) {
    size_t size = state.range(0);
    const size_t max_ticks = 10000;
    std::vector<IntType> indices = createCycle<IntType>(size);
    size_t pos = 0;
    size_t counter = 0;
    for (auto _ : state) {
        for (size_t j = 0; j < size; ++j) {
            pos = indices[pos];
        }
        benchmark::DoNotOptimize(pos);
    }
    state.counters["Rate"] = benchmark::Counter(
        size, benchmark::Counter::kIsIterationInvariantRate | benchmark::Counter::kInvert,
        benchmark::Counter::OneK::kIs1024);
}

BENCHMARK(TestCycle<uint64_t>)->RangeMultiplier(2)->Range(4, 1ULL << 28);
BENCHMARK_MAIN();