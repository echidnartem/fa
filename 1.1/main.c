#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "include\flags.h"

enum {
    SUCCESS = 0,
    ERR_INVALID_ARGC,
    ERR_INVALID_NUMBER,
    ERR_MEMORY_ALLOC,
    ERR_NUMBER_TOO_LARGE,
    ERR_INVALID_FLAG
};

void usage() {
    printf("Usage: <natural number> <flag>\n");
    printf("Example: 123456789 -p\n");
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        printf("Error: Expected 2 arguments, got %d\n", argc - 1);
        usage();
        return ERR_INVALID_ARGC;
    }

    char * endptr;
    unsigned long long input = strtoull(argv[1], &endptr, 10);
    
    if (*endptr != '\0' || endptr == argv[1] || argv[1][0] == '-') {
        printf("Error: Invalid number format: %s\n", argv[1]);
        usage();
        return ERR_INVALID_NUMBER;
    }
    
    if (input > 9223372036854775807) {
        printf("Error: Number out of range: %s\n", argv[1]);
        usage();
        return ERR_NUMBER_TOO_LARGE;
    }

    ll number = (ll)input;

    char * flag = argv[2];

    if (strlen(flag) != 2 || (flag[0] != '-' && flag[0] != '/') || 
        (flag[1] != 'h' && flag[1] != 'p' && flag[1] != 's' && flag[1] != 'e' && flag[1] != 'a' && flag[1] != 'f')) {
        printf("Error: Invalid flag format: %s\n", flag);
        usage();
        return ERR_INVALID_FLAG;
    }

    switch (flag[1]) {
        case 'h':
            int result1[100] = {0};
            if(h(result1, &number) == true) {
                for (int i = 0; i < 100; i++) {
                    if (result1[i]) {
                        printf("%d ", i + 1);
                    }
                }
            } else printf("There are no multiples\n");
            break;
        case 'p':
            if (p(&number)) printf("This number is prime\n");
            else printf("This number is composite\n");
            break;
        case 's':
            char result2[32] = {'0'};
            int index = s(result2, &number);
            if (number == 0) printf("0");
            else for (int i = index; i < 32; i++) printf("%c ", result2[i]);
            break;
        case 'e':
            if (number > 10) {
                printf("The number must not be more than 10\n");
                break;
            }
            ll * result3 = (ll*)malloc(10 * number * sizeof(ll));
            if (!result3) {
                printf("Error: Failed to allocate memory\n");
                return ERR_MEMORY_ALLOC;
            }
            e(result3, &number);
            for (ll i = 0; i < 10 * number; i++) {
                if (i != 0 && i % number == 0) printf("\n");
                printf("%lld\t", result3[i]);
            }
            free(result3);
            break;
        case 'a':
            printf("%lld\n", a(&number));
            break;
        case 'f':
            printf("%lld\n", f(&number));
            break;
    }

    return SUCCESS;
}