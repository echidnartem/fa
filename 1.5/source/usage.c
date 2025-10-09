#include "../include/usage.h"

void usage() {
    printf("Usage: <flag> <input_file> [output_file]\n");
    printf("Note: add 'n' after '-' or '/' to specify output file (e.g. -nd)\n\n");

    printf("Flags:\n");
    printf("  -d or /d  |  -nd or /nd : remove digits from the input file\n");
    printf("  -i or /i  |  -ni or /ni : count Latin letters in each line\n");
    printf("  -s or /s  |  -ns or /ns : count non-letter, non-digit, non-space symbols in each line\n");
    printf("  -a or /a  |  -na or /na : replace non-digit characters with their ASCII hex codes\n\n");

    printf("Examples:\n");
    printf("  -d input.txt\n");
    printf("  -nd input.txt output.txt\n");
}

void usagec(int argc) {
    printf("Error: Invalid number of parameters (%d)\n", argc - 1);
    usage();
}

void usagef(char * flag) {
    printf("Error: Invalid flag format (%s)\n", flag);
    usage();
}