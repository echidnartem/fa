#include "..\include\functions.h"



void usage(int argc) {
    printf("Error: Invalid number of parameters (%d)\n", argc - 1);
    printf("Usage: <input_file> <output_file>\n");
}



int search_mns(char * number, int length) {                    // ns = number system
    int mns = 2, cns;                                          // mns = minimal ns, cns = current ns
    char c;
    for (int i = 0; i < length; ++i) {
        c = toupper(number[i]);
        if (c >= '0' && c <= '9') {
            cns = (c - '0') + 1;
        } else if (c >= 'A' && c <= 'Z') {
            cns = (c - 'A') + 11;
        } else {
            return -1;
        }

        if (cns > mns) {
            mns = cns;
        }
    }
    return mns;
}

int mns_to_dns(char * number, int length, int mns) {           // dns = decimal ns
    int result = 0, r;
    char c;
    for (int i = 0; i < length; ++i) {
        c = toupper(number[i]);
        if (c >= '0' && c <= '9') {
            r = c - '0';
        } else r = (c - 'A') + 10; 

        result = result * mns + r;
    }
    return result; 
}

void process_word(FILE * output, char * number, int index) {
    int mns = search_mns(number, index);
    if (mns == -1) fprintf(output, "%s \t What is this?\n", number);
    else {
        int answer = mns_to_dns(number, index, mns);
        fprintf(output, "%s \t %d \t %d\n", number, mns, answer);
    }
}



int solve(FILE * input, FILE * output) {
    int buffer_size = 128;
    char * buffer = malloc(buffer_size);
    if (!buffer) {
        return ERR_MEMORY_ALLOC;
    }

    int index = 0;
    char c;
    while ((c = fgetc(input)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (index > 0) {
                buffer[index] = '\0';
                process_word(output, buffer, index);
                index = 0;
            }
            continue;
        }

        if (index + 1 == buffer_size) {
            buffer_size *= 2;
            char * temp = realloc(buffer, buffer_size);
            if (!temp) {
                return ERR_MEMORY_ALLOC;
            }
            buffer = temp;
        }

        buffer[index++] = c;
    }

    if (index > 0) {
        buffer[index] = '\0';
        process_word(output, buffer, index);
    }

    free(buffer);
    return SUCCESS;
}