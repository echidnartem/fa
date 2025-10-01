#include "../include/ln2_calculation.h"


double limit_ln2_calc(double n) {
    return n * (pow(2.0, 1.0 / n) - 1.0);
}

double limit_ln2(double precision) {
    double n = 1;
    double previous = limit_ln2_calc(n++);
    double current = limit_ln2_calc(n++);

    while (fabs(current - previous) >= precision) {
        previous = current;
        current = limit_ln2_calc(n++);
    }

    return current;
}



double series_ln2_calc(double n) {
    return pow(-1.0, n - 1.0) / n;
}

double series_ln2(double precision) {
    double n = 1;
    double previous = series_ln2_calc(n++);
    double current = previous + series_ln2_calc(n++);

    while (fabs(current - previous) >= precision) {
        previous = current;
        current = previous + series_ln2_calc(n++);
    }

    return current;
}



double equation_ln2(double precision) {
    double l = 0.0, r = 2.0, mid;
    
    while (fabs(r - l) >= precision) {
        mid = (l + r) / 2.0;
        if (exp(mid) - 2.0 > 0.0) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    return (l + r) / 2.0;
}
