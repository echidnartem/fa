#include "../include/function.h"


DECLARE_STACK(stack, char)

bool check_brackets(const char * str) {
    stack s;
    stack_create(&s);

    for (int i = 0; str[i]; i++) {
        char c = str[i];

        if (c == '(' || c == '[' || c == '{' || c == '<') {
            stack_push(&s, c);
        } else if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (stack_empty(&s)) {
                stack_destroy(&s);
                return false;
            }
            char open = *stack_top(&s);
            stack_pop(&s);

            if (!((open == '(' && c == ')') ||
                  (open == '[' && c == ']') ||
                  (open == '{' && c == '}') ||
                  (open == '<' && c == '>'))) {
                stack_destroy(&s);
                return false;
            }
        }
    }

    bool result = stack_empty(&s);
    stack_destroy(&s);
    return result;
}