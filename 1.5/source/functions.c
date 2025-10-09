#include "../include/functions.h"


char * make_output_name(char * input) {
    char * slash = strrchr(input, '\\');
    char * filename;
    size_t path_len = 0, len = strlen(input) + 5;

    if (slash) {
        filename = slash + 1;
        path_len = slash - input + 1;
    } else filename = input;
    
    char * out_name = malloc(len);
    if (!out_name) return NULL;

    if (slash) strncpy(out_name, input, path_len);

    sprintf(out_name + path_len, "out_%s", filename);

    return out_name;
}

int hex(char * result, int number) {
    int index = 31;
    result[32] = '\0';

    if (number == 0) {
        result[index--] = '0';
    } else {
        while (number != 0) {
            int r = number % 16;
            
            if (r > 9) result[index--] = (r - 10) + 'A';
            else result[index--] = r + '0';

            number /= 16;
        }
    }

    return index + 1;
}

void d_flag(FILE * input, FILE * output) {
    char c;
    while ((c = fgetc(input)) != EOF) {
        if (c <= '9' && c >= '0') {
            continue;
        }
        fputc(c, output);
    }
}

void i_flag(FILE * input, FILE * output) {
    int result = 0;
    char c;
    while ((c = fgetc(input)) != EOF) {
        if (c == '\n') {
            fprintf(output, "%d\n", result);
            result = 0;
        }

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            ++result;
        }
    }
    fprintf(output, "%d\n", result);
}

void s_flag(FILE * input, FILE * output) {
    int result = 0;
    char c;
    while ((c = fgetc(input)) != EOF) {
        if (c == '\n') {
            fprintf(output, "%d\n", result);
            result = 0;
            continue;
        }

        if (!( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ') ) {
            ++result;
        }
    }
    fprintf(output, "%d\n", result);
}

void a_flag(FILE * input, FILE * output) { 
    int c;
    char result[33];

    while ((c = fgetc(input)) != EOF) {
        if (!(c >= '0' && c <= '9') && c != '\n' && c != ' ') {
            int index = hex(result, c);
            for (int i = index; result[i] != '\0'; ++i)
                fputc(result[i], output);
        } else {
            fputc(c, output);
        }
    }
}