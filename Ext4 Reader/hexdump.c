
#include <stdio.h>
#include <string.h>

#include "hexdump.h"

#define LINESIZE 16

void dumpHexBytes(char *bytes, int numBytes) {
    for(int i = 0; i < numBytes; ++i) {
        printf("%02hhX ", bytes[i]);
        if(!((i + 1) % LINESIZE)) 
            printf("\n");
    }
    printf("\n");
}

