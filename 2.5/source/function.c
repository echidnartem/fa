#include "../include/function.h"


void shift_right(char * text, int start, int end, int shift) {
    for (int i = end; i >= start; --i) {
        text[i + shift] = text[i];
    }
}

void analyze_line(char * line, int * wordCount, int * spaceLeft, int * lastWordPos, int border) {
    for (int i = 1; i < border + 1; ++i) {
        if (isspace(line[i]) && !isspace(line[i - 1])) {
            (*wordCount)++;
            *spaceLeft = border - i;
            *lastWordPos = i - 1;
        }
    }
}

void justify_line(char * buffer, int wordCount, int spaceLeft, int lastWordPos, int border) {
    int baseSpaces = spaceLeft / (wordCount - 1);
    int extraSpaces = spaceLeft % (wordCount - 1);

    for (int i = 1; i < border; ++i) {
        if (isspace(buffer[i]) && !isspace(buffer[i - 1])) {
            int add = baseSpaces + (extraSpaces > 0);
            shift_right(buffer, i, lastWordPos, add);

            for (int j = i; j < i + add; ++j) {
                buffer[j] = ' ';
            }

            lastWordPos += add;
            if (extraSpaces > 0) {
                extraSpaces--;
            }
        }
    }
}

Status process_text(FILE * input, FILE * output) {
    int size = BUFSIZ;
    char line[size];
    char adjusted[size];
    char * cursor;
    int wordCount, spaceLeft, lastWordPos;
    int remaining = 0;

    while (fgets(line, size, input)) {
        cursor = line;
        cursor += strspn(cursor, " \t\n");

        while (strlen(cursor) > 80) {
            int border = 80 - remaining;        // дополнительная переменная border позволяет корректно
            wordCount = 0;                      // обрабатывать текст вне зависимости от значения size
            spaceLeft = -1;

            analyze_line(cursor, &wordCount, &spaceLeft, &lastWordPos, border);

            if (!wordCount || (wordCount == 1 && lastWordPos != border - 1)) {
                return ERR_INVALID_WORD;
            }

            memcpy(adjusted, cursor, lastWordPos + 1);

            if (wordCount > 1) {
                justify_line(adjusted, wordCount, spaceLeft, lastWordPos, border);
            }

            cursor += lastWordPos + 1;
            cursor += strspn(cursor, " \t\n");

            for (int i = 0; i < border; ++i) {
                fputc(adjusted[i], output);
            }
            fputc('\n', output);

            remaining = 0;
        }

        remaining = strlen(cursor);

        if (*cursor) {
            fputs(cursor, output);
        }

        if (!line[strspn(line, " \t\n")]) {
            fputc('\n', output);
        }
    }

    return SUCCESS;
}