#include "../include/tests.h"


void run_test(const char * title, const char * input, bool expected) {
    bool got = check_brackets(input);
    bool ok = (got == expected);

    printf("%s\n", title);
    printf("  input: \"%s\"\n", input);
    printf("  expected: %s\n", expected ? "VALID" : "INVALID");
    printf("  got: %s\n", got ? "VALID" : "INVALID");
    printf("  verdict: %s\n\n", ok ? "PASS" : "FAIL");
}

void test_valid() {
    puts("<<< Valid bracket sequences >>>");
    run_test("T1. empty string", "", true);
    run_test("T2. no brackets", "Hello, world!", true);
    run_test("T3. simple ()", "()", true);
    run_test("T4. mixed types", "()[]{}<>", true);
    run_test("T5. nested", "<({[]})>", true);
    run_test("T6. with text", "if (a[2] < b) { return; }", true);
    run_test("T7. deep nesting", "(((([[[[{{{<>}}}]]]]))))", true);
}

void test_invalid() {
    puts("<<< Invalid bracket sequences >>>");
    run_test("T1. single (", "(", false);
    run_test("T2. single )", ")", false);
    run_test("T3. wrong order", "(]", false);
    run_test("T4. wrong nesting", "[(])", false);
    run_test("T5. equal amount", "(()))(", false);
    run_test("T6. with text", "if (a[2) > b] {", false);
    run_test("T7. nested", "[(<{)>}]", false);
}

void test_edge_cases() {
    puts("<<< Edge Cases >>>");
    run_test("T1. long invalid", "(((((((((((((((((((((((((((())))))))))))))))))))))))))])", false);
    run_test("T2. garbage", "#@$!%@$%^&*()_###[[]]@!!{}}", false);
    run_test("T3. massive mixed correct", "a(b[c{d<e>f}g]h)i[j{k(l<m>n)o}p]q", true);
}
