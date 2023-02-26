#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>
#include <iostream>
#include <memory>

namespace fred {
struct CallerBase {
    virtual ~CallerBase(){};
    virtual double call(void* fn, const double* ptr) = 0;
};

template <size_t N, size_t J, typename... Args>
struct Execute {
    using CallType = typename Execute<N, J - 1, double, Args...>::CallType;
    double exec(void* fn, const double* val, Args... args) {
        return Execute<N, J - 1, double, Args...>().exec(fn, val + 1, args..., val[0]);
    }
};

template <size_t N, typename... Args>
struct Execute<N, 0, Args...> {
    typedef double (*CallType)(Args...);
    double exec(void* fn, const double* ptr, Args... args) {
        return CallType(fn)(args...);
    }
};

template <size_t N>
struct Caller : public CallerBase {
    virtual double call(void* fn, const double* ptr) override {
        return Execute<N, N>().exec(fn, ptr);
    }
};

template <size_t J>
CallerBase* createCaller(size_t j) {
    if (j == J) return new Caller<J>();
    return createCaller<J - 1>(j);
}

template <>
CallerBase* createCaller<0>(size_t j) {
    return new Caller<0>();
}

template <size_t N, size_t J>
struct SwitchImpl : public SwitchImpl<N, J - 1> {
    double operator()(void* fn, const double* ptr, size_t size) {
        return SwitchImpl<N, 0>::fn[size]->call(fn, ptr);
    }
};

template <size_t N>
struct SwitchImpl<N, 0> {
    std::array<std::unique_ptr<CallerBase>, N> fn;
    SwitchImpl() {
        for (size_t j = 0; j < N; ++j) {
            fn[j].reset(createCaller<N>(j));
        }
    }
};

template <size_t N>
using Switch = SwitchImpl<N, N>;

double callfn(void* fn, const std::vector<double>& args) {
    static Switch<MAXARGS> sw;
    size_t size = args.size();
    const double* ptr = args.data();
    return sw(fn, ptr, size);
}

}  // namespace fred
