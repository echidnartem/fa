#include "include/validation.h"
#include "include/functions.h"
#include <stdio.h>

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Error: Invalid number of parameters (%d)\n", argc - 1);
        printf("Usage: <precision>\n");
        return ERR_INVALID_ARGC;
    }

    double precision;
    if (!(validation(argv[1], &precision))) {
        printf("Error: Incorrect precision value\n");
        printf("Usage: <precision>\n");
        return ERR_INVALID_NUMBER;
    }

    double a = 0.0, b = 1.0;

    double a_ans = integral(a_function, precision, a, b);
    double b_ans = integral(b_function, precision, a, b);
    double c_ans = integral(c_function, precision, a, b - 1e-10);
    double d_ans = integral(d_function, precision, a, b);

    printf("a. %lf\nb. %lf\nc. %lf\nd. %lf\n", a_ans, b_ans, c_ans, d_ans);
}