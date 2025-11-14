#include "../include/tests.h"


void run_test(const char * title, unsigned int number, int r, const char * expected) {
    char output[100];
    output[0] = '\0';
    
    translate_to_base(number, r, output);

    int ok = strcmp(output, expected) == 0;
    printf("%s\n", title);
    printf("  input: number = %u, r = %d (base %u)\n", number, r, 1u << r);
    printf("  expected: %s\n", expected);
    printf("  got: %s\n", output);
    printf("  verdict: %s\n\n", ok ? "PASS" : "FAIL");
}

void test_r1() {
    puts("<<< Tests for r = 1 (base 2) >>>");
    run_test("T1. zero", 0u, 1, "0");
    run_test("T2. 5 -> 101 in base 2", 5u, 1, "101");
    run_test("T3. 1 -> 1 in base 2", 1u, 1, "1");
    run_test("T4. 255 -> 11111111 in base 2", 255u, 1, "11111111");
}

void test_r2() {
    puts("<<< Tests for r = 2 (base 4) >>>");
    run_test("T1. zero", 0u, 2, "0");
    run_test("T2. 10 -> 22 in base 4", 10u, 2, "22");
    run_test("T3. 255 -> 3333 in base 4", 255u, 2, "3333");
    run_test("T4. 7 -> 13 in base 4", 7u, 2, "13");
}

void test_r3() {
    puts("<<< Tests for r = 3 (base 8) >>>");
    run_test("T1. zero", 0u, 3, "0");
    run_test("T2. 15 -> 17 in base 8", 15u, 3, "17");
    run_test("T3. 25 -> 31 in base 8", 25u, 3, "31");
    run_test("T4. 64 -> 100 in base 8", 64u, 3, "100");
}

void test_r4() {
    puts("<<< Tests for r = 4 (base 16) >>>");
    run_test("T1. zero", 0u, 4, "0");
    run_test("T2. 27 -> 1B in base 16", 27u, 4, "1B");
    run_test("T3. 255 -> FF in base 16", 255u, 4, "FF");
    run_test("T4. 4095 -> FFF in base 16", 4095u, 4, "FFF");
}

void test_r5() {
    puts("<<< Tests for r = 5 (base 32) >>>");
    run_test("T1. zero", 0u, 5, "0");
    run_test("T2. 42 -> 1A in base 32", 42u, 5, "1A");
    run_test("T3. 31 -> V in base 32", 31u, 5, "V");
    run_test("T4. 1023 -> VV in base 32", 1023u, 5, "VV");
}

void test_edge_cases() {
    puts("<<< Edge Cases >>>");
    run_test("T1. 32 -> 10 in base 32", 32u, 5, "10");
    run_test("T2. 64 -> 20 in base 32", 64u, 5, "20");
    run_test("T3. 31 -> V in base 32", 31u, 5, "V");
    run_test("T4. 33 -> 11 in base 32", 33u, 5, "11");
    run_test("T5. 1024 -> 100 in base 32", 1024u, 5, "100");
    run_test("T6. 4294967295 -> FFFFFFFF in base 16", 4294967295u, 4, "FFFFFFFF");
}
