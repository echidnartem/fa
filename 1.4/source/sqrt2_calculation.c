#include "../include/sqrt2_calculation.h"


double limit_sqrt2_calc(double n) {
    return n - n * n / 2.0 + 1.0;
}

double limit_sqrt2(double precision) {
    double n = -0.5;
    double previous = limit_sqrt2_calc(n);
    double current = limit_sqrt2_calc(previous);

    while (fabs(current - previous) >= precision) {
        previous = current;
        current = limit_sqrt2_calc(previous);
    }

    return current;
}



double series_sqrt2_calc(double n) {
    return pow(2.0, pow(2.0, -n));
}

double series_sqrt2(double precision) {
    double n = 2;
    double previous = series_sqrt2_calc(n++);
    double current = previous * series_sqrt2_calc(n++);

    while (fabs(current - previous) >= precision) {
        previous = current;
        current = previous * series_sqrt2_calc(n++);
    }

    return current;
}



double equation_sqrt2(double precision) {
    double l = 1.0, r = 2.0, mid;
    
    while (fabs(r - l) >= precision) {
        mid = (l + r) / 2.0;
        if (mid * mid - 2.0 > 0.0) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    return (l + r) / 2.0;
}
