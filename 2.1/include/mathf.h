#ifndef MATHF_H
#define MATHF_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


typedef enum {
    SUCCESS = 0,
    ERR_INVALID_NUMBER,
    ERR_PERIODIC_FRAC,
    ERR_INVALID_BASE,
    ERR_MEMORY_ALLOC
} err;


long long gcd(const long long a, const long long b);
long long * factorization_number(err * error, const long long number);

#endif