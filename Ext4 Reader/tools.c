

#include "tools.h"
#include "stdio.h"

uint64_t attribToUint(unsigned char *attribute, const int width) {
    uint64_t value = 0;
    for(int i = (width - 1); i >= 0; --i) {
        // printf("%02hhX", attribute[i]);
        value |= ((uint64_t)attribute[i]) << (i * 8);
    }
    //printf("\n");
    return value; 
}
