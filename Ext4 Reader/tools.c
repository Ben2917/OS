

#include "tools.h"
#include "stdio.h"

uint32_t attribToUint32(unsigned char *attribute) {
    uint32_t value = 0;
    for(int i = 3; i >= 0; --i) {
        printf("%u\n", attribute[i]);
        value |= ((uint32_t)attribute[i]) << (i * 8);
    }
    return value; 
}
