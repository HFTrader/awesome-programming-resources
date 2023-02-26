#include "functions.h"

double sum1(double a, double b, double c) {
    return a + b + c;
}

double sum2(double a, double b, double c, double d) {
    return a + b + c + d;
}

double sum3(double a, double b) {
    return a + b;
}

double sum4() {
    return 10;
}

std::vector<Function> fntable = {
    {(void*)&sum1, 3}, {(void*)&sum2, 4}, {(void*)&sum3, 2}, {(void*)&sum4, 0}};
