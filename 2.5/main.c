#include "include/function.h"


int main() {
    FILE * in, * out;
    char inputPath[BUFSIZ], outputPath[BUFSIZ];

    printf("Enter the path to the input file:\n");
    scanf("%s", inputPath);

    printf("Enter the path to the output file:\n");
    scanf("%s", outputPath);

    in = fopen(inputPath, "r");
    if (in == NULL) {
        printf("Error: Failed to open input file\n");
        return 1;
    }

    out = fopen(outputPath, "w");
    if (out == NULL) {
        printf("Error: Failed to open output file\n");
        fclose(in);
        return 1;
    }

    if (process_text(in, out) == ERR_INVALID_WORD) {
        printf("The input file contains an invalid word.\n");
        printf("A line with such a word cannot be split into 80-character lines according to the requirements.\n");
    }

    fclose(in);
    fclose(out);

    return 0;
}
