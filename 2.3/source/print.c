#include "..\include\print.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


typedef Status (*FormatFunc)(char * buf, int * written, va_list args);

static const char * CUSTOM_NAMES[] = {"Ro", "Zr", "Cv", "CV", "to", "TO", "mi", "mu", "md", "mf"};
static const FormatFunc CUSTOM_FUNCS[] = {Ro, Zr, Cv, CV, to, TO, mi, mu, md, mf};

#define CUSTOM_COUNT (sizeof(CUSTOM_NAMES) / sizeof(CUSTOM_NAMES[0]))


void parseSpec(const char * format, Flag * type, FormatFunc * outFunc) {
    *type = STANDARD;
    *outFunc = NULL;

    if (!format[1] || !format[2])
        return;

    char current[3] = {format[1], format[2], '\0'};

    for (int i = 0; i < CUSTOM_COUNT; ++i) {
        if (strcmp(CUSTOM_NAMES[i], current) == 0) {
            *type = NOT_STANDARD;
            *outFunc = CUSTOM_FUNCS[i];
            return;
        }
    }
}

int overformat(char * buffer, const char * format, va_list args) {
    int totalWritten = 0;
    Status status;
    FormatFunc handler;
    Flag flag;

    while (*format) {
        if (*format != '%') {
            *buffer++ = *format++;
            totalWritten++;
            continue;
        }

        if (format[1] == '%') {
            *buffer++ = '%';
            format += 2;
            totalWritten++;
            continue;
        }

        parseSpec(format, &flag, &handler);

        if (flag == NOT_STANDARD) {
            int written = 0;
            va_list argsCopy;
            va_copy(argsCopy, args);

            status = handler(buffer, &written, argsCopy);
            va_end(argsCopy);

            if (status != SUCCESS)
                return -status;

            if (!strncmp(format, "%Cv", 3) || !strncmp(format, "%CV", 3) ||
                !strncmp(format, "%to", 3) || !strncmp(format, "%TO", 3)) {
                va_arg(args, void*);
                va_arg(args, void*);
            } else {
                va_arg(args, void*);
            }

            buffer += written;
            totalWritten += written;
            format += 3;
            continue;
        }

        char fmtToken[64];
        char * p = fmtToken;
        *p++ = *format++;

        while (*format && !isalpha((unsigned char)*format) && *format != '%')
            *p++ = *format++;

        if (*format)
            *p++ = *format++;

        *p = '\0';

        va_list argsCopy;
        va_copy(argsCopy, args);
        int written = vsprintf(buffer, fmtToken, argsCopy);
        va_end(argsCopy);

        if (written < 0)
            return -VSPF_ERROR;

        va_arg(args, void*);

        buffer += written;
        totalWritten += written;
    }

    *buffer = '\0';
    return totalWritten;
}

int oversprintf(char * buffer, const char * format, ...) {
    va_list args;
    va_start(args, format);
    int result = overformat(buffer, format, args);
    va_end(args);
    return result;
}

int overfprintf(FILE * stream, const char *format, ...) {
    char buffer[BUFSIZ];
    va_list args;
    va_start(args, format);
    int result = overformat(buffer, format, args);
    va_end(args);

    fprintf(stream, "%s", buffer);
    return result;
}
