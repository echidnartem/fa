#include <stdio.h>
#include "include/fractions.h"


void error_handling(err * error) {
    switch (*error) {
        case ERR_INVALID_NUMBER:
            printf(" Error: Invalid fraction (number out of range (0;1)).\n");
            break;

        case ERR_MEMORY_ALLOC:
            printf(" Error: Memory allocation failed.\n");
            break;

        case ERR_PERIODIC_FRAC:
            printf(" Error: Periodic fraction detected.\n");
            break;

        case ERR_INVALID_BASE:
            printf(" Error: Invalid base.\n");
            break;

        default:
            printf(" Unknown error.\n");
            break;
    }  
}

int main(void) {
    err error = SUCCESS;

    printf("=== Tests started ===\n\n");

    printf("Base 10 results:\n");
    bool * results10 = is_finite_representation(&error, 10, 4, 0.5, 0.25, 0.0001, 0.125);

    if (error != SUCCESS) error_handling(&error);
    else {
        printf("  0.5     -> %s\n", results10[0] ? "finite" : "infinite");
        printf("  0.25    -> %s\n", results10[1] ? "finite" : "infinite");
        printf("  0.0001  -> %s\n", results10[2] ? "finite" : "infinite");
        printf("  0.125   -> %s\n", results10[3] ? "finite" : "infinite");
    }
    free(results10);
    printf("\n");



    printf("Base 2 results:\n");
    error = SUCCESS;
    bool * results2 = is_finite_representation(&error, 2, 2, 0.25, 0.2);

    if (error != SUCCESS) error_handling(&error);
    else {
        printf("  0.25 -> %s\n", results2[0] ? "finite" : "infinite");
        printf("  0.2  -> %s\n", results2[1] ? "finite" : "infinite");
    }
    free(results2);
    printf("\n");



    printf("Base 8 results:\n");
    error = SUCCESS;
    bool * results8 = is_finite_representation(&error, 8, 3, 0.125, 0.2, 0.625);

    if (error != SUCCESS) error_handling(&error);
    else {
        printf("  0.125 -> %s\n", results8[0] ? "finite" : "infinite");
        printf("  0.2   -> %s\n", results8[1] ? "finite" : "infinite");
        printf("  0.625 -> %s\n", results8[2] ? "finite" : "infinite");
    }
    free(results8);
    printf("\n");



    printf("Base 10 periodic test:\n");
    error = SUCCESS;
    bool * results_periodic = is_finite_representation(&error, 10, 1, 1.0 / 3.0);

    if (error != SUCCESS) error_handling(&error);
    else {
        printf("  1/3     -> %s\n", results_periodic[0] ? "finite" : "infinite");
    }
    free(results_periodic);
    printf("\n");



    printf("Invalid base test:\n");
    error = SUCCESS;
    bool * results_base = is_finite_representation(&error, 0, 1, 0.5);

    if (error != SUCCESS) error_handling(&error);
    else {
        printf("  0.5     -> %s\n", results_base[0] ? "finite" : "infinite");
    }
    free(results_base);
    printf("\n");



    printf("Invalid fraction test:\n");
    error = SUCCESS;
    bool * results_fraction = is_finite_representation(&error, 2, 1, 1);

    if (error != SUCCESS) error_handling(&error);
    else {
        printf("  1     -> %s\n", results_fraction[0] ? "finite" : "infinite");
    }
    free(results_fraction);

    printf("\n=== Tests finished ===\n");
    return 0;
}