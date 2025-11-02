#include "include/print.h"
#include <string.h>
#include <stdio.h>


#define TEST(name, cond) printf("%-25s: %s\n", name, (cond) ? "OK" : "FAIL")


void test_print_functions() {
    char buf[256];
    FILE * f, * fin;
    int len, ret;

    printf("=== Testing Print Functions ===\n");
    
    oversprintf(buf, "Hello %s %d!", "world", 42);
    TEST("standard sprintf", strcmp(buf, "Hello world 42!") == 0);

    oversprintf(buf, "Progress: 100%% complete");
    TEST("double percent", strcmp(buf, "Progress: 100% complete") == 0);

    oversprintf(buf, "Roman: %Ro, Num: %d, Zeckendorf: %Zr", 83, 83, 83);
    TEST("custom + standard mix", strstr(buf, "Roman: LXXXIII, Num: 83, Zeckendorf: 010100101") != NULL);

    len = oversprintf(buf, "Test %d", 123);
    TEST("oversprintf length", len == (int)strlen("Test 123"));

    f = fopen("test_output.txt", "w");
    ret = overfprintf(f, "Num: %d, Text: %s", 10, "Hello, world!");
    fclose(f);
    TEST("overfprintf ret", ret > 0);

    fin = fopen("test_output.txt", "r");
    fgets(buf, sizeof(buf), fin);
    fclose(fin);
    TEST("overfprintf content", strcmp(buf, "Num: 10, Text: Hello, world!") == 0);
}



void test_format_flags() {
    char buf[256];
    char expected[256];
    
    printf("\n=== Testing Format Flags ===\n");
    
    oversprintf(buf, "%Cv", 31, 16);
    snprintf(expected, sizeof(expected), "1f");
    TEST("%Cv flag (31->1f)", strstr(buf, "1f") != NULL);
    
    oversprintf(buf, "%CV", 31, 16);
    snprintf(expected, sizeof(expected), "1F");
    TEST("%CV flag (31->1F)", strstr(buf, "1F") != NULL);

    oversprintf(buf, "%to", "1f", 16);
    TEST("%to flag (1f->31 octal)", strstr(buf, "31") != NULL);
    
    oversprintf(buf, "%TO", "1F", 16); 
    TEST("%TO flag (1F->31 octal)", strstr(buf, "31") != NULL);

    oversprintf(buf, "%mi", 1);
    TEST("%mi flag (1->00000001)", strstr(buf, "00000001") != NULL);
    
    oversprintf(buf, "%Ro", 83);
    TEST("%Ro flag (83->LXXXIII)", strstr(buf, "LXXXIII") != NULL);
    
    oversprintf(buf, "%Zr", 83);
    TEST("%Zr flag (83->010100101)", strstr(buf, "010100101") != NULL);
}



int main() {
    test_print_functions();
    test_format_flags();
    
    return 0;
}