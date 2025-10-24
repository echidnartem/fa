#include "include/print.h"


#define TEST(name, cond) printf("%-25s: %s\n", name, (cond) ? "OK" : "FAIL")


int main() {
    char buf[256];

    oversprintf(buf, "Hello %s %d!", "world", 42);
    TEST("standard sprintf", strcmp(buf, "Hello world 42!") == 0);

    oversprintf(buf, "Progress: 100%% complete");
    TEST("double percent", strcmp(buf, "Progress: 100% complete") == 0);

    oversprintf(buf, "Cv:%Cv CV:%CV to:%to TO:%TO", 31, 16, 31, 16, "1f", 16, "1F", 16);
    TEST("custom1",
        strstr(buf, "Cv:1f") && strstr(buf, "CV:1F") &&
        strstr(buf, "to:31") && strstr(buf, "TO:31"));

    oversprintf(buf, "%mi", 1);
    TEST("custom2", strstr(buf, "00000001") != NULL);

    oversprintf(buf, "Roman: %Ro, Num: %d, Zeckendorf: %Zr", 83, 83, 83);
    TEST("custom + standard mix", strstr(buf, "Roman: LXXXIII, Num: 83, Zeckendorf: 010100101") != NULL);

    int len = oversprintf(buf, "Test %d", 123);
    TEST("oversprintf length", len == (int)strlen("Test 123"));

    FILE * f = fopen("test_output.txt", "w");
    int ret = overfprintf(f, "Num: %d, Text: %s", 10, "Hello, world!");
    fclose(f);
    TEST("overfprintf ret", ret > 0);

    FILE * fin = fopen("test_output.txt", "r");
    fgets(buf, sizeof(buf), fin);
    fclose(fin);
    TEST("overfprintf content", strcmp(buf, "Num: 10, Text: Hello, world!") == 0);

    return 0;
}
