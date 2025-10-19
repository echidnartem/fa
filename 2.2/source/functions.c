#include "../include/functions.h"
#include "../include/errors.h"

void * functions_memchr(const void * str, int c, size_t n) {
    const unsigned char * copy_str = (unsigned char*)str;
    const unsigned char * ptr_c = NULL;
    const unsigned char char_c = (unsigned char)c;  
    for (size_t i = 0; i < n; ++i) {
        if (copy_str[i] == char_c) {
            ptr_c = copy_str + i;
            break;
        }        
    }
    return (void*)ptr_c;
}

int functions_memcmp(const void * str1, const void * str2, size_t n) {
    const unsigned char * a = (unsigned char*)str1;
    const unsigned char * b = (unsigned char*)str2;

    for (size_t i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            return (int)(a[i] - b[i]);
        }
    }
    
    return 0;
}

void * functions_memcpy(void * dest, const void * src, size_t n) {
    unsigned char * d = (unsigned char*)dest;
    const unsigned char * s = (unsigned char*)src;

    for (size_t i = 0; i < n; ++i) {
        d[i] = s[i];
    }

    return (void*)dest;
}


void * functions_memset(void * str, int c, size_t n) {
    const unsigned char p = (unsigned char)c;
    unsigned char * value = (unsigned char*)str;

    for (size_t i = 0; i < n; ++i) {
        value[i] = p;
    }

    return (void*)str;
}

char * functions_strncat(char * dest, const char * src, size_t n) {
    size_t len = functions_strlen(dest);
    size_t i = 0;
    for (; i < n && src[i] != '\0'; ++i) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}

char * functions_strchr(const char * str, int c) {
    const unsigned char char_c = (unsigned char)c;
    size_t n = functions_strlen(str);
    for (size_t i = 0; i < n; ++i) {
        if (str[i] == char_c) {
            return (char*)(str + i); 
        }
    }

    if (char_c == '\0') {
        return (char*)(str + n);
    }

    return NULL;
}

int functions_strncmp(const char * str1, const char * str2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        unsigned char c1 = (unsigned char)str1[i];
        unsigned char c2 = (unsigned char)str2[i];

        if (c1 != c2) {
            return c1 - c2; 
        }

        if (c1 == '\0') {
            return 0;
        }
    }
    return 0;
}

char * functions_strncpy(char * dest, const char * src, size_t n) {
    size_t i = 0;
    for (; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    for (; i < n; ++i) {
        dest[i] = '\0';
    }
    return dest;
}

size_t functions_strcspn(const char * str1, const char * str2) {
    const size_t len_str1 = functions_strlen(str1);
    const size_t len_str2 = functions_strlen(str2);
    size_t i = 0;
    for (; i < len_str1; ++i) {
        const char c = str1[i];
        for (size_t j = 0; j < len_str2; ++j) {
            if (c == str2[j]) {
                return i;
            }
        }
    }
    return len_str1;
}

size_t functions_strlen(const char * str) {
    size_t i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char * functions_strpbrk(const char * str1, const char * str2) {
    const size_t len_str1 = functions_strlen(str1);
    const size_t len_str2 = functions_strlen(str2);

    char c = '\0';
    for (size_t i = 0; i < len_str1; ++i) {
        c = str1[i];
        for (size_t j = 0; j < len_str2; ++j) {
            if (str2[j] == c) {
                return (char*)(str1 + i);
            }
        } 
    }

    return NULL;
}

char * functions_strrchr(const char *str, int c) {
    size_t len = functions_strlen(str);

    if ((unsigned char)c == '\0') {
        return (char*)(str + len);
    }

    for (size_t i = len; i > 0;) {
        if (str[--i] == (unsigned char)c) {
            return (char*)(str + i);
        }
    }

    return NULL;
}

char * functions_strstr(const char * haystack, const char * needle) {
    const size_t n = functions_strlen(haystack);
    const size_t m = functions_strlen(needle);

    int flag = 1;

    for (size_t i = 0; i < n; ++i) {
        flag = 1;
        size_t j = 0;
        for (; j < m; ++j) {
            if (i + j >= n) {
                flag = 0;
                break;
            }
            if (haystack[i + j] != needle[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return (char*)(haystack + i);
        }
    }
    return NULL;
}

int is_delim(char c, const char * delim) {
    return functions_strchr(delim, c) != NULL;
}

char * functions_strtok(char * str, const char * delim) {
    static char * save_str = NULL;
    
    if (str == NULL) {
        str = save_str;
        if (str == NULL) {
            return NULL;
        }
    }

    while (*str != '\0' && is_delim(*str, delim)) {
        str++;
    }

    if (*str == '\0') {
        save_str = NULL;
        return NULL;
    }

    char * token = str;
    while (*str != '\0' && !is_delim(*str, delim)) {
        str++;
    }

    if (*str == '\0') {
        save_str = NULL;
    } 
    else {
        *str = '\0';
        save_str = str + 1;
    }

    return token;
}