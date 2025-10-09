#include <stdbool.h>
#include <string.h>


enum {
    SUCCESS = 0,
    ERR_MEMORY_ALLOC,
    ERR_INVALID_ARGC,
    ERR_INVALID_FLAG,
    ERR_FILE_OPEN
};


bool isFlag(char * string);
unsigned int validation(int argc, char * argv[]);
