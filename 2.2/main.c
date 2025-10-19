#include "include\functions.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TEST(name, cond) \
    printf("%-20s: %s\n", name, (cond) ? "OK" : "FAIL")

    
int main(void) {
    TEST("strlen", strlen("hello") == functions_strlen("hello"));

    char a1[] = "abc", a2[] = "abc", a3[] = "abd";
    TEST("memcmp eq", memcmp(a1, a2, 3) == functions_memcmp(a1, a2, 3));
    TEST("memcmp lt", memcmp(a1, a3, 3) == functions_memcmp(a1, a3, 3));
    TEST("memcmp gt", memcmp(a3, a1, 3) == functions_memcmp(a3, a1, 3));

    char src1[] = "abcdef", dst1[10], dst2[10];
    memcpy(dst1, src1, 6);
    functions_memcpy(dst2, src1, 6);
    TEST("memcpy", memcmp(dst1, dst2, 6) == 0);

    char ms1[5], ms2[5];
    memset(ms1, 'x', 5);
    functions_memset(ms2, 'x', 5);
    TEST("memset", memcmp(ms1, ms2, 5) == 0);

    char mstr[] = "abcdef";
    TEST("memchr found", memchr(mstr, 'c', 6) == functions_memchr(mstr, 'c', 6));
    TEST("memchr notfound", memchr(mstr, 'z', 6) == functions_memchr(mstr, 'z', 6));

    TEST("strncmp eq", strncmp("abc", "abc", 3) == functions_strncmp("abc", "abc", 3));
    TEST("strncmp lt", strncmp("abc", "abd", 3) == functions_strncmp("abc", "abd", 3));
    TEST("strncmp gt", strncmp("abd", "abc", 3) == functions_strncmp("abd", "abc", 3));

    char nd1[10], nd2[10];
    strncpy(nd1, "abc", 5);
    functions_strncpy(nd2, "abc", 5);
    TEST("strncpy", memcmp(nd1, nd2, 6) == 0);

    char nc1[20] = "foo", nc2[20] = "foo";
    strncat(nc1, "bar", 4);
    functions_strncat(nc2, "bar", 4);
    TEST("strncat", strcmp(nc1, nc2) == 0);

    TEST("strchr found", strchr("hello", 'l') == functions_strchr("hello", 'l'));
    TEST("strchr notfound", strchr("hello", 'z') == functions_strchr("hello", 'z'));
    TEST("strchr nullterm", strchr("hello", '\0') == functions_strchr("hello", '\0'));

    TEST("strrchr last", strrchr("hello", 'l') == functions_strrchr("hello", 'l'));
    TEST("strrchr notfound", strrchr("hello", 'z') == functions_strrchr("hello", 'z'));
    TEST("strrchr nullterm", strrchr("hello", '\0') == functions_strrchr("hello", '\0'));

    TEST("strcspn", strcspn("abcdef", "xzcd") == functions_strcspn("abcdef", "xzcd"));

    TEST("strpbrk found", strpbrk("abcdef", "xcz") == functions_strpbrk("abcdef", "xcz"));
    TEST("strpbrk notfound", strpbrk("abcdef", "XYZ") == functions_strpbrk("abcdef", "XYZ"));

    TEST("strstr found", strstr("hello world", "world") == functions_strstr("hello world", "world"));
    TEST("strstr notfound", strstr("hello", "xyz") == functions_strstr("hello", "xyz"));
    TEST("strstr empty needle", strstr("abc", "") == functions_strstr("abc", ""));

    char s1[] = "one,two,three";
    char s2[] = "one,two,three";
    char *tok1 = strtok(s1, ",");
    char *tok2 = functions_strtok(s2, ",");
    int ok = 1;
    while (tok1 && tok2) {
        if (strcmp(tok1, tok2) != 0) ok = 0;
        tok1 = strtok(NULL, ",");
        tok2 = functions_strtok(NULL, ",");
    }
    TEST("strtok", ok && tok1 == tok2);

    return 0;
}
