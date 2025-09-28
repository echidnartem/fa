#include "../include/pi_calculation.h"


double limit_pi_calc(double n) {
    return pow(pow(2.0, n) * factorial(n), 4) / (n * pow(factorial(2.0 * n), 2));
}

double limit_pi(double precision) {
    double n = 1;
    double previous = limit_pi_calc(n++);
    double current = limit_pi_calc(n++);

    while (fabs(current - previous) >= precision) {
        if (n == 40) break;
        previous = current;
        current = limit_pi_calc(n++);
    }

    return current;
}



double series_pi_calc(double n) {
    return pow(-1.0, n - 1.0) / (2.0 * n - 1.0);
}

double series_pi(double precision) {
    double n = 1;
    double previous = series_pi_calc(n++);
    double current = previous + series_pi_calc(n++);

    while (fabs(current - precision) >= precision) {
        if (n == 40000) break;
        previous = current;
        current = previous + series_pi_calc(n++);
    }

    return 4.0 * current;
}



double equation_pi(double precision) {
    double value = 3.0;

    while (cos(value) + 1.0  >= precision) {
        value += (cos(value) + 1) / sin(value);
    }

    return value;
}
