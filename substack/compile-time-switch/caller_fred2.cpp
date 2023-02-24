#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>
#include <iostream>
#include <memory>

namespace fred2 {

typedef double (*CallType)(void* fn, const double* ptr);

template <size_t>
using double_t = double;

template <size_t... Is>
double execute(void* fn, const double* args, std::index_sequence<Is...>) {
    using CallTypeN = double (*)(double_t<Is>...);
    return CallTypeN(fn)(args[Is]...);
}

template< size_t N >
double execute( void* fn, const double* args ) {
    return execute( fn, args, std::make_index_sequence<N>{});
}

template <std::size_t N>
struct Switch {
    std::array<CallType, N> fn;
    template <std::size_t... Is>
    static void init(std::index_sequence<Is...> s,
                        std::array<CallType, N>& fn) {
        ((fn[Is] = &execute<Is>), ...);
    }
    Switch() {
        init(std::make_index_sequence<N>{}, fn);
    }
};

double callfn(void* fn, const std::vector<double>& args) {
    static Switch<MAXARGS> sw;
    return sw.fn[args.size()](fn, args.data());
}

}  // namespace fred2
