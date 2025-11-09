#include <stdio.h>
#include "../include/vector.h"


int int_copy(int value) {
    return value;
}

void int_delete(int value) {
    (void)value;
}

DEFINE_VECTOR(int)

int main() {
    printf("=== INT VECTOR TESTS ===\n\n");

    Vector vec = create_vector(2, int_copy, int_delete);
    printf("[1] The first vector created: size = %zu, capacity = %zu\n", vec.size, vec.capacity);

    push_back_vector(&vec, 10);
    push_back_vector(&vec, 20);
    push_back_vector(&vec, 30);
    printf("[2] After push_back_vector in the first vector: size = %zu, capacity = %zu\n", vec.size, vec.capacity);

    printf("[3] Elements of the first vector: ");
    for (size_t i = 0; i < vec.size; ++i) {
        printf("%d ", get_at_vector(&vec, i));
    }
    printf("\n");

    Vector vec_copy = create_vector(3, int_copy, int_delete);
    push_back_vector(&vec_copy, 10);
    push_back_vector(&vec_copy, 20);
    push_back_vector(&vec_copy, 30);

    printf("[4] The second vector created: size = %zu\n", vec_copy.size);\

    printf("[5] After push_back_vector in the second vector: size = %zu, capacity = %zu\n", vec.size, vec.capacity);

    printf("[6] Elements of the second vector: ");
    for (size_t i = 0; i < vec.size; ++i) {
        printf("%d ", get_at_vector(&vec, i));
    }
    printf("\n");
    printf("[7] Are vectors equal? %s\n", is_equal_vector(&vec, &vec_copy) ? "Yes" : "No");

    delete_at_vector(&vec, 1);
    printf("[8] After erase at index 1: size = %zu, elements: ", vec.size);
    for (size_t i = 0; i < vec.size; ++i) {
        printf("%d ", get_at_vector(&vec, i));
    }
    printf("\n");

    copy_vector(&vec, &vec_copy);
    printf("[9] After copy: size = %zu, elements: ", vec.size);
    for (size_t i = 0; i < vec.size; ++i) {
        printf("%d ", get_at_vector(&vec, i));
    }
    printf("\n");

    Vector* vec_clone = copy_vector_new(&vec);
    printf("[10] Cloned vector created: size = %zu\n", vec_clone->size);
    printf("    Original and clone equal? %s\n", is_equal_vector(&vec, vec_clone) ? "Yes" : "No");

    delete_vector(&vec);
    delete_vector(&vec_copy);
    delete_vector(vec_clone);
    free(vec_clone);

    printf("\n[11] All vectors destroyed. Test complete\n");

    return 0;
}
