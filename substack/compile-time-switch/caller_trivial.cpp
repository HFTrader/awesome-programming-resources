#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <limits>

#include "functions.h"

namespace trivial {

struct trivial {
    static double callfn(void* fn, const std::vector<double>& args);
};

}