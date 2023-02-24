#include <iostream>
#include <memory>
#include <vector>
#include <functional>

namespace caleth {

class Function {
    struct BaseCaller {
        virtual ~BaseCaller() {
        }
        virtual double call(std::vector<double>) const = 0;
    };

    template <typename... Args>
    class Caller : public BaseCaller {
        double (*func)(Args...);

    public:
        explicit Caller(double (*func)(Args...)) : func(func) {
        }
        double call(std::vector<double> args) const {
            return [&]<size_t... Is>(std::index_sequence<Is...>) {
                return func(args[Is]...);
            }
            (std::index_sequence_for<Args...>{});
        }
    };

    std::unique_ptr<BaseCaller> caller;

public:
    template <typename... Args>
    Function(double (*func)(Args...)) : caller(std::make_unique<Caller<Args...>>(func)) {
    }

    double operator()(const std::vector<double>& args) {
        return caller->call(args);
    }
};

constexpr size_t MaxArgs = MAXARGS;

template <size_t>
using double_t = double;

template <size_t... Is>
using RawFunction = double (*)(double_t<Is>...);

static const auto myarray = []<size_t... Is>(std::index_sequence<Is...>)
                                -> std::array<std::function<Function(void*)>, MaxArgs> {
    auto cast = []<size_t... Js>(std::index_sequence<Js...>, void* f) {
        return Function(reinterpret_cast<RawFunction<Js...>>(f));
    };
    return {[=](void* f) { return cast(std::make_index_sequence<Is>{}, f); }...};
}
(std::make_index_sequence<MaxArgs>{});

Function from_void(void* f, size_t numargs) {
    return myarray[numargs](f);
}

double callfn(void* fn, const std::vector<double>& args) {
    return from_void(fn, args.size())(args);
}

}  // namespace caleth
