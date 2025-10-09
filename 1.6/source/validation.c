#include "../include/validation.h"

bool validation(const char * str, double * result) {
    char * endptr;
    *result = strtod(str, &endptr);

    if (str == endptr || *endptr != '\0' || *result <= 0.0) {
        return false;
    }

    return true;
}