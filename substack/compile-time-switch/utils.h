#pragma once
#include <cstdint>

static inline uint64_t tic() {
    uint64_t tsc;
    asm volatile(
        "MFENCE\n\t"
        "LFENCE\n\t"
        "RDTSC\n\t"
        "salq $32,   %%rdx\n\t"
        "orq  %%rdx, %%rax\n\t"
        : "=a"(tsc)
        :
        : "%rdx");
    return tsc;
}

static inline uint64_t toc() {
    uint64_t tsc;
    asm volatile(
        "LFENCE\n\t"
        "RDTSC\n\t"
        "salq $32, %%rdx\n\t"
        "orq %%rdx,%%rax\n\t"
        : "=a"(tsc)
        :
        : "%rdx", "%rcx");
    return tsc;
}
