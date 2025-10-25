#ifndef FUNCTION_H
#define FUNCTION_H


#include <stdio.h>
#include <string.h>
#include <ctype.h>


typedef enum {
    SUCCESS = 0,
    ERR_INVALID_WORD
} Status;


Status process_text(FILE * input, FILE * output);

#endif