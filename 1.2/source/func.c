#include "../include/func.h"

int * finding_prime_numbers(int n) {
    int size = n * 100;
    int * is_prime = (int*)malloc(size * sizeof(int));
    int * result = (int*)malloc((n + 1) * sizeof(int));

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
            if (k == (n + 1)) break;
            result[k] = p;
            k++;
            for (int i = p * p; i < size; i += p) {
                is_prime[i] = 0;
            }
        }
    }

    for (int p = (int)(sqrt(size)) + 1; p < size; p++) {
        if (is_prime[p] == 1) {
            if (k == (n + 1)) break;
            result[k] = p;
            k++;
        }
    }

    free(is_prime);
    return result;
}