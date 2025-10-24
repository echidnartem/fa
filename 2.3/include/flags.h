
#ifndef FLAGS_H
#define FLAGS_H


#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>


typedef enum {
    SUCCESS = 0,
    CANNOT_BE_ROMAN,
    VSPF_ERROR,
    NOT_IN_BASE,
    HAS_EXCEPTION,
    UNCORRECT_NUM,
    LONG_OVERFLOW,
    SHOULD_BE_UPPER,
    SHOULD_BE_LOWER
} Status;


#define max(a, b) (((a) > (b)) ? (a) : (b))


Status Ro(char * buf, int * wr, va_list l);
Status Zr(char * buf, int * wr, va_list l);
Status Cv(char * buf, int * wr, va_list l);
Status CV(char * buf, int * wr, va_list l);
Status to(char * buf, int * wr, va_list l);
Status TO(char * buf, int * wr, va_list l);
Status mi(char * buf, int * wr, va_list l);
Status mu(char * buf, int * wr, va_list l);
Status md(char * buf, int * wr, va_list l);
Status mf(char * buf, int * wr, va_list l);


#endif