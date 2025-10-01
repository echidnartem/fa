#include "include/flags.h"
#include "include/auxiliary.h"
#include <string.h>


enum {
    SUCCESS = 0,
    ERR_INVALID_NUMBER,
    ERR_MEMORY_ALLOC,
    ERR_INVALID_ARGC,
    ERR_INVALID_FLAG
};

int main(int argc, char * argv[]) {
    if (argc < 4) {
        printf("Error: Expected 3 or more arguments, got %d\n", argc - 1);
        usage();
        return ERR_INVALID_ARGC;
    }

    char * flag = argv[1];

    if (strlen(flag) != 2 || (flag[0] != '-' && flag[0] != '/') || (flag[1] != 'q' && flag[1] != 'm' && flag[1] != 't')) {
        printf("Error: Invalid flag format: %s\n", flag);
        usage();
        return ERR_INVALID_FLAG;
    }

    switch(flag[1]) {
        case 'q':
            if (argc != 6) {
                usageq(argc);
                return ERR_INVALID_ARGC;
            }
            double e1, a, b, c;
            if (sscanf(argv[2], "%lf", &e1) != 1 ||
                sscanf(argv[3], "%lf", &a) != 1 ||
                sscanf(argv[4], "%lf", &b) != 1 ||
                sscanf(argv[5], "%lf", &c) != 1) {
                printf("Error: Failed to read 4 real numbers\n");
                return ERR_INVALID_NUMBER;
            }

            double * solves;
            solves = q(&e1, &a, &b, &c);
            if (!solves) {
                printf("Error: Failed to allocate memory\n");
                return ERR_MEMORY_ALLOC;
            }
            quadratic_equation_derivation(solves, &a, &b, &c);
            free(solves);

            if (!(a == b && b == c)) {
                if (a == b) {
                    solves = q(&e1, &a, &c, &b);
                    if (!solves) {
                        printf("Error: Failed to allocate memory\n");
                        return ERR_MEMORY_ALLOC;
                    }
                    quadratic_equation_derivation(solves, &a, &c, &b);
                    free(solves);

                    solves = q(&e1, &c, &a, &b);
                    if (!solves) {
                        printf("Error: Failed to allocate memory\n");
                        return ERR_MEMORY_ALLOC;
                    }
                    quadratic_equation_derivation(solves, &c, &a, &b);
                    free(solves);

                } else if (b == c) {
                    solves = q(&e1, &c, &b, &a);
                    if (!solves) {
                        printf("Error: Failed to allocate memory\n");
                        return ERR_MEMORY_ALLOC;
                    }
                    quadratic_equation_derivation(solves, &c, &b, &a);
                    free(solves);

                    solves = q(&e1, &b, &a, &c);
                    if (!solves) {
                        printf("Error: Failed to allocate memory\n");
                        return ERR_MEMORY_ALLOC;
                    }
                    quadratic_equation_derivation(solves, &b, &a, &c);
                    free(solves);

                } else {
                    solves = q(&e1, &a, &c, &b);
                    if (!solves) {
                        printf("Error: Failed to allocate memory\n");
                        return ERR_MEMORY_ALLOC;
                    }
                    quadratic_equation_derivation(solves, &a, &c, &b);
                    free(solves);

                    solves = q(&e1, &c, &a, &b);
                    if (!solves) {
                        printf("Error: Failed to allocate memory\n");
                        return ERR_MEMORY_ALLOC;
                    }
                    quadratic_equation_derivation(solves, &c, &a, &b);
                    free(solves);

                    solves = q(&e1, &c, &b, &a);
                    if (!solves) {
                        printf("Error: Failed to allocate memory\n");
                        return ERR_MEMORY_ALLOC;
                    }
                    quadratic_equation_derivation(solves, &c, &b, &a);
                    free(solves);

                    solves = q(&e1, &b, &a, &c);
                    if (!solves) {
                        printf("Error: Failed to allocate memory\n");
                        return ERR_MEMORY_ALLOC;
                    }
                    quadratic_equation_derivation(solves, &b, &a, &c);
                    free(solves);

                    solves = q(&e1, &b, &c, &a);
                    if (!solves) {
                        printf("Error: Failed to allocate memory\n");
                        return ERR_MEMORY_ALLOC;
                    }
                    quadratic_equation_derivation(solves, &b, &c, &a);
                    free(solves);
                }
            }
            break;
            
            case 'm':
                if (argc != 4) {
                    usagem(argc);
                    return ERR_INVALID_ARGC;
                }
                int e, f;
                if (sscanf(argv[2], "%d", &e) != 1 ||
                    sscanf(argv[3], "%d", &f) != 1 ||
                    e == 0 || f == 0) {
                    printf("Error: Failed to read 2 non-zero integers\n");
                    return ERR_INVALID_NUMBER;
                }

                if (m(&e, &f)) printf("The first number is a multiple of the second\n");
                else printf("The first number is not a multiple of the second\n");
                break;
            
            case 't':
                if (argc != 6) {
                    usaget(argc);
                    return ERR_INVALID_ARGC;
                }
                double e2, g, h, i;
                if (sscanf(argv[2], "%lf", &e2) != 1 ||
                    sscanf(argv[3], "%lf", &g) != 1 ||
                    sscanf(argv[4], "%lf", &h) != 1 ||
                    sscanf(argv[5], "%lf", &i) != 1) {
                    printf("Error: Failed to read 4 real numbers\n");
                    return ERR_INVALID_NUMBER;
                }
                if (t(&e2, &g, &h, &i)) printf("These values can be the lengths of the sides of a right triangle\n");
                else printf("These values can not be the lengths of the sides of a right triangle\n");
                break;
    }

    return SUCCESS;
}
