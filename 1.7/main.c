#include "include/functions.h"


int main(int argc, char * argv[]) {
    if (argc != 3) {
        usage(argc);
        return ERR_INVALID_ARGC;
    }

    FILE * input = fopen(argv[1], "r");
    if (!input) {
        printf("Error: Failed to open input file\n");
        return ERR_FILE_OPEN;
    }

    FILE * output = fopen(argv[2], "w");
    if (!input) {
        printf("Error: Failed to open output file\n");
        return ERR_FILE_OPEN;
    }

    int result = solve(input, output);
    switch (result) {
        case ERR_MEMORY_ALLOC:
            printf("Error: Failed to allocate memory\n");
            return ERR_MEMORY_ALLOC;
        default:
            return SUCCESS;
    }
}