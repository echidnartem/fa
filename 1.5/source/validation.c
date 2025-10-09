#include "../include/validation.h"


bool isFlag(char * string) {
    if (string == NULL) return false;

    if (string[0] != '/' && string[0] != '-') return false;

    size_t len = strlen(string);
    if (len < 2 || len > 3) return false;

    if (string[1] == 'n') return len == 3 && strchr("disa", string[2]) != NULL;
    else return len == 2 && strchr("disa", string[1]) != NULL;
}



unsigned int validation(int argc, char * argv[]) {
    if (argc < 3) return ERR_INVALID_ARGC;

    if (!isFlag(argv[1])) return ERR_INVALID_FLAG;

    if ((argv[1][1] == 'n' && argc != 4) || (argv[1][1] != 'n' && argc != 3)) return ERR_INVALID_ARGC;
    
    return SUCCESS;
}