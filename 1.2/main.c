#include "include/func.h"
#include <stdio.h>

enum {
    SUCCESS = 0,
    ERR_INVALID_NUMBER,
    ERR_MEMORY_ALLOC
};

int main() {
    int t;
    printf("Enter the number of requests: ");
    if (!scanf("%d", &t) || t < 0) {
        printf("Error: Failed to read non-negative integer\n");
        return ERR_INVALID_NUMBER;
    }

    int * values = (int*)malloc(t * sizeof(int));
    if (!values) {
        printf("Error: Failed to allocate memory\n");
        return ERR_MEMORY_ALLOC;
    }
    
    int mx = 0;

    for (int i = 0; i < t; i++) {
        int value;
        if (!scanf("%d", &value)) {
            printf("Error: Failed to read number\n");
            return ERR_INVALID_NUMBER;
        }
        if (mx < value) {
            mx = value;
        }
        values[i] = value;
    }

    int * primes = finding_prime_numbers(mx);
    if (!primes) {
        printf("Error: Failed to allocate memory\n");
        return ERR_MEMORY_ALLOC;      
    }

    for (int i = 0; i < t; i++) {
        printf("The number %d is %d in order\n", primes[values[i] - 1], values[i]);
    }

    free(primes);
    free(values);

    return SUCCESS;
}
