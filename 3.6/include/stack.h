#ifndef STACK_H
#define STACK_H


#include <stdlib.h>
#include <stdbool.h>

#define DECLARE_STACK(name, T) \
\
typedef struct name##_item { \
    T data; \
    struct name##_item * prev; \
} name##_item; \
\
typedef struct { \
    name##_item * top; \
    size_t size; \
} name; \
\
static inline void name##_create(name * s) { \
    s->top = NULL; \
    s->size = 0; \
} \
\
static inline bool name##_empty(const name * s) { \
    return s->size == 0; \
} \
\
static inline size_t name##_size(const name * s) { \
    return s->size; \
} \
\
static inline bool name##_push(name * s, T value) { \
    name##_item * i = malloc(sizeof(name##_item)); \
    if (!i) return false; \
    i->data = value; \
    i->prev = s->top; \
    s->top = i; \
    s->size++; \
    return true; \
} \
\
static inline T * name##_top(name * s) { \
    return s->top ? &s->top->data : NULL; \
} \
\
static inline bool name##_pop(name * s) { \
    if (s->size == 0) return false; \
    name##_item * i = s->top; \
    s->top = i->prev; \
    free(i); \
    s->size--; \
    return true; \
} \
\
static inline void name##_destroy(name * s) { \
    while (s->top) { \
        name##_item * i = s->top; \
        s->top = i->prev; \
        free(i); \
    } \
    s->size = 0; \
}

#endif