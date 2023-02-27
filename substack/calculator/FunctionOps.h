#pragma once

#include "Pointer.h"
#include "Node.h"

#include <string_view>

namespace Interpreter {

template <size_t>
using double_t = double;

//! Creates the function call type and unpacks the vector inside it
template <std::size_t... I>
double callfn_impl(void* fn, const double* values, std::index_sequence<I...>) {
    using CallType = double (*)(double_t<I>...);
    return CallType(fn)(values[I]...);
}

//! Builds the call for a given number of arguments. Relies on callfn_impl
template <std::size_t N>
double callfn(void* fn, const double* values) {
    using Indices = std::make_index_sequence<N>;
    return callfn_impl(fn, values, Indices{});
}

//! Dispatches the call to one of our templated functions using
//! a big switch statement
double callfn(void* fn, const double* args, size_t size) {
    switch (size) {
        case 0: return callfn<0>(fn, args); break;
        case 1: return callfn<1>(fn, args); break;
        case 2: return callfn<2>(fn, args); break;
        case 3: return callfn<3>(fn, args); break;
        case 4: return callfn<4>(fn, args); break;
        case 5: return callfn<5>(fn, args); break;
        case 6: return callfn<6>(fn, args); break;
        case 7: return callfn<7>(fn, args); break;
        case 8: return callfn<8>(fn, args); break;
        case 9: return callfn<9>(fn, args); break;
        case 10: return callfn<10>(fn, args); break;
    };
    return std::numeric_limits<double>::quiet_NaN();
}

}  // namespace Interpreter
