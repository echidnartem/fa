#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


enum {
    SUCCESS = 0,
    ERR_MEMORY_ALLOC,
    ERR_INVALID_ARGC,
    ERR_FILE_OPEN
};


void usage(int argc);
int search_mns(char * number, int length);
int mns_to_dns(char * number, int length, int mns);
void process_word(FILE * output, char * number, int index);
int solve(FILE * input, FILE * output);