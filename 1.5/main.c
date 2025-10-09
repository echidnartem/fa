#include "include/validation.h"
#include "include/usage.h"
#include "include/functions.h"


int main(int argc, char * argv[]) {
    unsigned int result = validation(argc, argv);
    switch (result) {
        case ERR_INVALID_ARGC:
            usagec(argc);
            return ERR_INVALID_ARGC;
        case ERR_INVALID_FLAG:
            usagef(argv[1]);
            return ERR_INVALID_FLAG;
        default:
            break;
    }

    FILE * input = fopen(argv[2], "r");
    if (!input) {
        printf("Error: Failed to open input file\n");
        return ERR_FILE_OPEN;
    }

    char * flag = argv[1];

    FILE * output;
    if (flag[1] == 'n') output = fopen(argv[3], "w");
    else {
        char * name = make_output_name(argv[2]);
        if (!name) {
            printf("Error: Failed to allocate memory\n");
            return ERR_MEMORY_ALLOC;
        }
        output = fopen(name, "w");
        free(name);
    }
    if (!output) {
        printf("Error: Failed to open output file\n");
        return ERR_FILE_OPEN;
    }

    char f;
    if (strlen(flag) == 2) f = flag[1]; 
    else f = flag[2];

    switch (f) {
        case 'd':
            d_flag(input, output);
            break;
        case 'i':
            i_flag(input, output);
            break;
        case 's':
            s_flag(input, output);
            break;
        case 'a':
            a_flag(input, output);
            break;
    }
    
    return SUCCESS;
}