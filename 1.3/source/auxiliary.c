#include "../include/auxiliary.h"


void usage() {
    printf("Usage: <flag> <parameters>\n");
}

void usageq() {
    printf("Usage: <flag> <parameters>\n");
    printf("Example: -q 0.0001 2.5 -3.0 1.2\n");
}

void usagem() {
    printf("Usage: <flag> <parameters>\n");
    printf("Example: -m 20 10\n");
}

void usaget() {
    printf("Usage: <flag> <parameters>\n");
    printf("Example: -t 0.0001 2.5 3.0 1.2\n");
}

void quadratic_equation_derivation(double * result, const double * a, const double * b, const double * c) {
    printf("Quadratic equation: %.4lfx^2 + %.4lfx + %.4lf\n", *a, *b, *c);
    if (result[0] == 0.0) printf("Result: No solutions\n");
    else if (result[0] == -1.0) printf("Result: Infinitely many solutions\n");
    else if (result[0] == 1.0) printf("Result: x = %.4lf\n", result[1]);
    else printf("Result: x1 = %.4lf, x2 = %.4lf\n", result[1], result[2]);
    printf("\n");
}
