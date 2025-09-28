#include "../include/epsilon_calculation.h"


double limit_e_calc(double n) {
    return pow(1.0 + 1.0 / n, n);
}

double limit_e(double precision) {
    double n = 1;
    double previous = limit_e_calc(n++);
    double current = limit_e_calc(n++);

    while (fabs(current - previous) >= precision) {
        previous = current;
        current = limit_e_calc(n++);
    }

    return current;
}



double series_e_calc(double n) {
    return 1.0 / factorial(n);
}

double series_e(double precision) {
    double n = 0;
    double previous = series_e_calc(n++);
    double current = previous + series_e_calc(n++);

    while (fabs(current - precision) >= precision) {
        if (n == 40) break;
        previous = current;
        current = previous + series_e_calc(n++);
    }

    return current;
}



double equation_e(double precision) {
    double l = 2.0, r = 4.0, mid;
    
    while (fabs(r - l) >= precision) {
        mid = (l + r) / 2.0;
        if (log(mid) - 1.0 > 0.0) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    return (l + r) / 2.0;
}
