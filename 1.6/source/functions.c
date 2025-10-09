#include "../include/functions.h"


double a_function(double x) {
    if (fabs(x) < 1e-10) {
        return 1.0;
    }
    return log(1 + x)/x;
}

double b_function(double x) {
    return exp(-(x * x) / 2.0);
}

double c_function(double x) {
    return -log(1 - x);
}

double d_function(double x) {
    return pow(x, x);
}

double integral(double (*f)(double), double precision, double a, double b) {
    double step = b - a, x;
    double previous_value = 0.5 * (f(a) + f(b)) * step;
    double value = previous_value;
    int quantity = 1;

    do {
        previous_value = value;
        quantity *= 2;
        value = 0;
        step = (b - a) / quantity;
        x = a;
        for (double i = 0; i < quantity; i++) {
            value += (0.5 * (f(x) + f(x + step)));
            x += step;
        }
        value *= step;
    } while (fabs(value - previous_value) >= precision);

    return value;
}