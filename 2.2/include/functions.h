#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <stdlib.h>

void * functions_memchr(const void * str, int c, size_t n);
int functions_memcmp(const void * str1, const void * str2, size_t n);
void * functions_memcpy(void * dest, const void * src, size_t n);
void * functions_memset(void * str, int c, size_t n);

char * functions_strncat(char * dest, const char * src, size_t n);
char * functions_strchr(const char * str, int c);
int functions_strncmp(const char * str1, const char * str2, size_t n);
char * functions_strncpy(char * dest, const char * src, size_t n);
size_t functions_strcspn(const char * str1, const char * str2);

size_t functions_strlen(const char * str);
char * functions_strpbrk(const char * str1, const char * str2);
char * functions_strrchr(const char * str, int c);
char * functions_strstr(const char * haystack, const char * needle);
char * functions_strtok(char * str, const char * delim);

#endif