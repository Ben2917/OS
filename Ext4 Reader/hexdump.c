
#include <stdio.h>
#include <string.h>

#include "hexdump.h"

#define LINESIZE 16

void dumpHexBytes(char *bytes, int numBytes) {
    char hexLine[LINESIZE + 1], asciiLine[LINESIZE + 1];
    for(int i = 0; i < numBytes; ++i) {
        printf("%02hhX ", bytes[i]); // NOTE: Need formatted write to string
        // printf("%c ", (bytes[i] > 32 && bytes[i] < 127) ? bytes[i] : '.');
        if(!((i + 1) % LINESIZE)) {
            printf("\n");
            // Clear the strings.
        }
    }
    printf("\n");
}

