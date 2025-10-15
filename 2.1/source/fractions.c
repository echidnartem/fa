#include "../include/fractions.h"


long long get_denominator(err * error, double num) {
    const double EPS = 1e-12;
    long long denom = 1, count = 0;
    double value = num;
    while (fabs(value - (int)value) > EPS) {
        value *= 10;
        denom *= 10;
        
        ++count;
        if (count >= 1e6) {
            *error = ERR_PERIODIC_FRAC;
            return false;
        }
    }

    long long numerator = (long long)round(value);
    long long g = gcd(numerator, denom);
    return denom / g;
}

bool has_finite_representation(err * error, double num, int base) {
    const double EPS = 1e-12;
    if (num <= EPS || num - 1.0 >= EPS) {
        *error = ERR_INVALID_NUMBER;
        return false;
    }

    long long * base_factors = factorization_number(error, base);
    if (*error == ERR_MEMORY_ALLOC) return false;

    long long denom = get_denominator(error, num);
    if (*error == ERR_PERIODIC_FRAC) return false;

    long long * denom_factors = factorization_number(error, denom);
    if (*error == ERR_MEMORY_ALLOC) {
        free(base_factors);
        return false;
    }

    bool finite = true;
    for (int i = 1; i <= denom_factors[0]; ++i) {
        bool found = false;
        for (int j = 1; j <= base_factors[0]; ++j) {
            if (denom_factors[i] == base_factors[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            finite = false;
            break;
        }
    }

    free(base_factors);
    free(denom_factors);
    return finite;
}


bool * is_finite_representation(err * error, int base, int count, ...) {
    va_list args;
    va_start(args, count);

    bool * result = (bool*)malloc(sizeof(bool) * count);
    if (!result) {
        *error = ERR_MEMORY_ALLOC;
        return NULL;
    }

    if (base < 2) {
        *error = ERR_INVALID_BASE;
        return NULL;
    }

    for (int i = 0; i < count; ++i) {
        double num = va_arg(args, double);
        if (!has_finite_representation(error, num, base)) result[i] = false;
        else result[i] = true;
    }

    va_end(args);
    return result;
}