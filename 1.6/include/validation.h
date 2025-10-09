#include <stdbool.h>
#include <stdlib.h>


enum {
    SUCCESS = 0,
    ERR_INVALID_NUMBER,
    ERR_INVALID_ARGC,
};


bool validation(const char * str, double * result);