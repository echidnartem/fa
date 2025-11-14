#include "include/tests.h"


int main() {
    printf("Running test suite for translate_to_base\n\n");

    test_valid();
    test_invalid();
    test_edge_cases();

    return 0;
}