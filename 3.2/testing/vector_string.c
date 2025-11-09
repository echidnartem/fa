#include <stdio.h>
#include <string.h>
#include "../include/vector.h"


char* str_copy(char* src) {
    if (!src) return NULL;
    char* copy = malloc(strlen(src) + 1);
    strcpy(copy, src);
    return copy;
}

void str_delete(char* str) {
    free(str);
}

DEFINE_VECTOR(char*)

int main() {
    printf("=== STRING VECTOR TESTS ===\n\n");

    Vector vec = create_vector(2, str_copy, str_delete);
    printf("[1] The first vector created: size = %zu, capacity = %zu\n", vec.size, vec.capacity);

    push_back_vector(&vec, str_copy("Hello"));
    push_back_vector(&vec, str_copy("World"));
    push_back_vector(&vec, str_copy("C Language"));
    printf("[2] After push_back_vector in the first vector: size = %zu, capacity = %zu\n", vec.size, vec.capacity);

    printf("[3] Elements of the first vector: ");
    for (size_t i = 0; i < vec.size; ++i) {
        printf("\"%s\" ", get_at_vector(&vec, i));
    }
    printf("\n");

    Vector vec_copy = create_vector(3, str_copy, str_delete);
    push_back_vector(&vec_copy, str_copy("Hello"));
    push_back_vector(&vec_copy, str_copy("World"));
    push_back_vector(&vec_copy, str_copy("C Language"));

    printf("[4] The second vector created: size = %zu\n", vec_copy.size);
    printf("[5] After push_back_vector in the second vector: size = %zu, capacity = %zu\n", vec_copy.size, vec_copy.capacity);

    printf("[6] Elements of the second vector: ");
    for (size_t i = 0; i < vec_copy.size; ++i) {
        printf("\"%s\" ", get_at_vector(&vec_copy, i));
    }
    printf("\n");

    printf("[7] Are vectors equal? %s\n", is_equal_vector(&vec, &vec_copy) ? "Yes" : "No");

    delete_at_vector(&vec, 1);
    printf("[8] After delete at index 1: size = %zu, elements: ", vec.size);
    for (size_t i = 0; i < vec.size; ++i) {
        printf("\"%s\" ", get_at_vector(&vec, i));
    }
    printf("\n");

    copy_vector(&vec, &vec_copy);
    printf("[9] After copy: size = %zu, elements: ", vec.size);
    for (size_t i = 0; i < vec.size; ++i) {
        printf("\"%s\" ", get_at_vector(&vec, i));
    }
    printf("\n");

    Vector* vec_clone = copy_vector_new(&vec);
    printf("[10] Cloned vector created: size = %zu\n", vec_clone->size);
    printf("     Original and clone equal? %s\n", is_equal_vector(&vec, vec_clone) ? "Yes" : "No");

    delete_vector(&vec);
    delete_vector(&vec_copy);
    delete_vector(vec_clone);
    free(vec_clone);

    printf("\n[11] All vectors destroyed. Test complete\n");

    return 0;
}
