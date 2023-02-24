#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>

struct Function {
    void* fnptr;
    size_t numargs;
};

extern std::vector<Function> fntable;