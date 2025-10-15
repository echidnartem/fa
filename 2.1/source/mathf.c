#include "..\include\mathf.h"


long long gcd(long long a, long long b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }

    return a + b;
}

long long * factorization_number(err * error, long long number) {
    if (number == 0 || number == 1) {
        long long * result = (long long*)malloc(sizeof(long long));
        if (!result) {
            *error = ERR_MEMORY_ALLOC;
            return NULL;
        }
        result[0] = 0;
        return result;
    }

    if (number < 0)
        number = -number;

    int size = 4;
    long long * result = (long long*)malloc(sizeof(long long) * size);
    if (!result) {
        *error = ERR_MEMORY_ALLOC;
        return NULL;
    }

    int index = 0;
    long long divider = 2;

    while (divider * divider <= number) {
        if (number % divider == 0) {
            if (index + 2 > size) {
                size *= 2;
                long long * temp = (long long*)realloc(result, sizeof(long long) * size);
                if (!temp) {
                    free(result);
                    *error = ERR_MEMORY_ALLOC;
                    return NULL;
                }
                result = temp;
            }
            result[++index] = divider;
            number /= divider;
        } else {
            ++divider;
        }
    }

    result[++index] = number;
    result[0] = index;

    return result;
}