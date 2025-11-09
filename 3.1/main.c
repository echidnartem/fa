#include "include/tests.h"


int main() {
    printf("Running test suite for translate_to_base\n\n");

    test_r1();
    test_r2();
    test_r3();
    test_r4();
    test_r5();
    test_edge_cases();

    return 0;
}