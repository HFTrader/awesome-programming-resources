#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <limits>

#include "functions.h"

namespace trivial {

template <size_t N, typename... Args>
struct FnType {
    using Call = typename FnType<N - 1, double, Args...>::Call;
};

template <typename... Args>
struct FnType<0, Args...> {
    typedef double (*Call)(Args...);
};

struct trivial {
    static double callfn(void* fn, const std::vector<double>& args);
};

/*
# Generated with python
print( "case 0: return FnType<0>::Call(fn)(); break;")
for n in range(1,51,1):
        str =  "case %d:" % (n)
        str += " return FnType<%d>::Call(fn)(args[0]" % (n)
        for j in range(1,n):
                str += ", args[%d]" % (j)
        str += "); break;"
        print(str)
*/
double callfn(void* fn, const std::vector<double>& args) {
    switch (args.size()) {
        case 0: return FnType<0>::Call(fn)(); break;
        case 1: return FnType<1>::Call(fn)(args[0]); break;
        case 2: return FnType<2>::Call(fn)(args[0], args[1]); break;
        case 3: return FnType<3>::Call(fn)(args[0], args[1], args[2]); break;
        case 4: return FnType<4>::Call(fn)(args[0], args[1], args[2], args[3]); break;
        case 5:
            return FnType<5>::Call(fn)(args[0], args[1], args[2], args[3], args[4]);
            break;
        case 6:
            return FnType<6>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                       args[5]);
            break;
        case 7:
            return FnType<7>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                       args[5], args[6]);
            break;
        case 8:
            return FnType<8>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                       args[5], args[6], args[7]);
            break;
        case 9:
            return FnType<9>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                       args[5], args[6], args[7], args[8]);
            break;
        case 10:
            return FnType<10>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9]);
            break;
        case 11:
            return FnType<11>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10]);
            break;
        case 12:
            return FnType<12>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11]);
            break;
        case 13:
            return FnType<13>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12]);
            break;
        case 14:
            return FnType<14>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13]);
            break;
        case 15:
            return FnType<15>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13], args[14]);
            break;
        case 16:
            return FnType<16>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13], args[14],
                                        args[15]);
            break;
        case 17:
            return FnType<17>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13], args[14],
                                        args[15], args[16]);
            break;
        case 18:
            return FnType<18>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13], args[14],
                                        args[15], args[16], args[17]);
            break;
        case 19:
            return FnType<19>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13], args[14],
                                        args[15], args[16], args[17], args[18]);
            break;
        case 20:
            return FnType<20>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13], args[14],
                                        args[15], args[16], args[17], args[18], args[19]);
            break;
        case 21:
            return FnType<21>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20]);
            break;
        case 22:
            return FnType<22>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21]);
            break;
        case 23:
            return FnType<23>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13], args[14],
                                        args[15], args[16], args[17], args[18], args[19],
                                        args[20], args[21], args[22]);
            break;
        case 24:
            return FnType<24>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13], args[14],
                                        args[15], args[16], args[17], args[18], args[19],
                                        args[20], args[21], args[22], args[23]);
            break;
        case 25:
            return FnType<25>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13], args[14],
                                        args[15], args[16], args[17], args[18], args[19],
                                        args[20], args[21], args[22], args[23], args[24]);
            break;
        case 26:
            return FnType<26>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25]);
            break;
        case 27:
            return FnType<27>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26]);
            break;
        case 28:
            return FnType<28>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27]);
            break;
        case 29:
            return FnType<29>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28]);
            break;
        case 30:
            return FnType<30>::Call(fn)(args[0], args[1], args[2], args[3], args[4],
                                        args[5], args[6], args[7], args[8], args[9],
                                        args[10], args[11], args[12], args[13], args[14],
                                        args[15], args[16], args[17], args[18], args[19],
                                        args[20], args[21], args[22], args[23], args[24],
                                        args[25], args[26], args[27], args[28], args[29]);
            break;
        case 31:
            return FnType<31>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30]);
            break;
        case 32:
            return FnType<32>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31]);
            break;
        case 33:
            return FnType<33>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32]);
            break;
        case 34:
            return FnType<34>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33]);
            break;
        case 35:
            return FnType<35>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34]);
            break;
        case 36:
            return FnType<36>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35]);
            break;
        case 37:
            return FnType<37>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36]);
            break;
        case 38:
            return FnType<38>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37]);
            break;
        case 39:
            return FnType<39>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38]);
            break;
        case 40:
            return FnType<40>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39]);
            break;
        case 41:
            return FnType<41>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39], args[40]);
            break;
        case 42:
            return FnType<42>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39], args[40], args[41]);
            break;
        case 43:
            return FnType<43>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39], args[40], args[41], args[42]);
            break;
        case 44:
            return FnType<44>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39], args[40], args[41], args[42],
                args[43]);
            break;
        case 45:
            return FnType<45>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39], args[40], args[41], args[42],
                args[43], args[44]);
            break;
        case 46:
            return FnType<46>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39], args[40], args[41], args[42],
                args[43], args[44], args[45]);
            break;
        case 47:
            return FnType<47>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39], args[40], args[41], args[42],
                args[43], args[44], args[45], args[46]);
            break;
        case 48:
            return FnType<48>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39], args[40], args[41], args[42],
                args[43], args[44], args[45], args[46], args[47]);
            break;
        case 49:
            return FnType<49>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39], args[40], args[41], args[42],
                args[43], args[44], args[45], args[46], args[47], args[48]);
            break;
        case 50:
            return FnType<50>::Call(fn)(
                args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7],
                args[8], args[9], args[10], args[11], args[12], args[13], args[14],
                args[15], args[16], args[17], args[18], args[19], args[20], args[21],
                args[22], args[23], args[24], args[25], args[26], args[27], args[28],
                args[29], args[30], args[31], args[32], args[33], args[34], args[35],
                args[36], args[37], args[38], args[39], args[40], args[41], args[42],
                args[43], args[44], args[45], args[46], args[47], args[48], args[49]);
            break;
    };
    return std::numeric_limits<double>::quiet_NaN();
}
}  // namespace trivial