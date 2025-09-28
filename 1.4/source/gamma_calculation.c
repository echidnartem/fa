#include "../include/gamma_calculation.h"
#include "../include/pi_calculation.h"


double limit_g_calc(double n) {
    double result = 0.0;
    for (double k = 1; k <= n; k++) {
        double combinations = factorial(n) / (factorial(k) * factorial(n - k));
        result += combinations * pow(-1, k) * log(factorial(k)) / k;
    }
    return result;
}

double limit_g(double precision) {
    double n = 1;
    double previous = limit_g_calc(n++);
    double current = limit_g_calc(n++);

    while (fabs(current - previous) >= precision) {
        if (n == 40) break;
        previous = current;
        current = limit_g_calc(n++);
    }

    return current;
}



double series_g_calc(double n) {
    return 1.0 / (floor(sqrt(n)) * floor(sqrt(n))) - 1.0 / n;
}

double series_g(double precision) {
    double n = 2;
    double previous = series_g_calc(n++);
    double current = previous + series_g_calc(n++);

    while (fabs(current - precision) >= precision) {
        if (n == 40000) break;
        previous = current;
        current = previous + series_g_calc(n++);
    }

    return current - equation_pi(precision) * equation_pi(precision) / 6;
}

int * finding_prime_numbers(int size) {
    int n = 78498;
    int * is_prime = (int*)malloc(size * sizeof(int));
    int * result = (int*)malloc(n * sizeof(int));

    if (!is_prime || !result) {
        if (is_prime) free(is_prime);
        if (result) free(result);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        is_prime[i] = 1;
    }

    is_prime[0] = 0;
    is_prime[1] = 0;
    int k = 0;

    for (int p = 2; p * p <= size; p++) {
        if (is_prime[p] == 1) {
            if (k == n) break;
            result[k] = p;
            k++;
            for (int i = p * p; i < size; i += p) {
                is_prime[i] = 0;
            }
        }
    }

    for (int p = (int)(sqrt(size)) + 1; p < size; p++) {
        if (is_prime[p] == 1) {
            if (k == n) break;
            result[k] = p;
            k++;
        }
    }

    free(is_prime);
    return result;
}

double equation_g(double precision) {
    int t = 1e6;
    int * primes = finding_prime_numbers(t);

    if (!primes) {
        return 0;
    }

    double product = log(t);
    for (int i = 0; i < 78498; i++) {
        product *= (primes[i] - 1.0) / primes[i];
    }

    double l = 0.0, r = 1.0, mid;
    
    while (fabs(r - l) >= precision) {
        mid = (l + r) / 2.0;
        if (exp(-mid) - product > 0.0) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    free(primes);
    return (l + r) / 2.0;
}
