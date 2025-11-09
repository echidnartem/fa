#ifndef VECTOR_H
#define VECTOR_H


#include <stdlib.h>


#define DEFINE_VECTOR(TYPE) \
typedef struct { \
    TYPE* data; \
    size_t size; \
    size_t capacity; \
    TYPE (*copy_fn)(TYPE); \
    void (*delete_fn)(TYPE); \
} Vector; \
\
Vector create_vector(size_t initial_capacity, TYPE (*copy_func)(TYPE), void (*delete_func)(TYPE)) { \
    Vector vec = {NULL, 0, initial_capacity, copy_func, delete_func}; \
    vec.data = (TYPE*)malloc(sizeof(TYPE) * initial_capacity); \
    if (!vec.data) { \
        vec.size = vec.capacity = 0; \
    } \
    return vec; \
} \
\
void erase_vector(Vector* vec) { \
    if (!vec || !vec->delete_fn) return; \
    for (size_t i = 0; i < vec->size; ++i) { \
        vec->delete_fn(vec->data[i]); \
    } \
    vec->size = 0; \
} \
\
int is_equal_vector(const Vector* a, const Vector* b) { \
    if (a->size != b->size) return 0; \
    for (size_t i = 0; i < a->size; ++i) { \
        if (a->data[i] != b->data[i]) return 0; \
    } \
    return 1; \
} \
\
void push_back_vector(Vector* vec, TYPE value) { \
    if (vec->size == vec->capacity) { \
        size_t new_capacity = vec->capacity ? vec->capacity * 2 : 2; \
        TYPE* new_data = (TYPE*)realloc(vec->data, sizeof(TYPE) * new_capacity); \
        if (!new_data) return; \
        vec->data = new_data; \
        vec->capacity = new_capacity; \
    } \
    vec->data[vec->size++] = value; \
} \
\
void copy_vector(Vector* dest, const Vector* src) { \
    if (!dest || !src) return; \
    erase_vector(dest); \
    for (size_t i = 0; i < src->size; ++i) { \
        push_back_vector(dest, src->copy_fn(src->data[i])); \
    } \
    dest->copy_fn = src->copy_fn; \
    dest->delete_fn = src->delete_fn; \
} \
\
Vector* copy_vector_new(const Vector* src) { \
    if (!src) return NULL; \
    Vector* new_vec = (Vector*)malloc(sizeof(Vector)); \
    if (!new_vec) return NULL; \
    *new_vec = create_vector(src->capacity, src->copy_fn, src->delete_fn); \
    for (size_t i = 0; i < src->size; ++i) { \
        push_back_vector(new_vec, src->copy_fn(src->data[i])); \
    } \
    return new_vec; \
} \
\
void delete_at_vector(Vector* vec, size_t index) { \
    if (!vec || index >= vec->size) return; \
    vec->delete_fn(vec->data[index]); \
    for (size_t i = index; i < vec->size - 1; ++i) { \
        vec->data[i] = vec->data[i + 1]; \
    } \
    --vec->size; \
} \
\
TYPE get_at_vector(const Vector* vec, size_t index) { \
    if (!vec || index >= vec->size) return (TYPE)0; \
    return vec->data[index]; \
} \
\
void delete_vector(Vector* vec) { \
    if (!vec) return; \
    erase_vector(vec); \
    free(vec->data); \
    vec->data = NULL; \
    vec->capacity = vec->size = 0; \
}

#endif