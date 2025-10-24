#ifndef PRINT_H
#define PRINT_H


#include "flags.h"


typedef enum {
    STANDARD,
    NOT_STANDARD
} Flag;


int oversprintf(char *buffer, const char *format, ...);
int overfprintf(FILE *stream, const char *format, ...);


#endif