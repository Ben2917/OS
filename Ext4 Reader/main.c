

#include <stdlib.h>
#include <stdio.h>

#include "hexdump.h"
#include "superblock.h"
#include "tools.h"

int main() {
    BLOCK *superblock = loadBlock(1);
    if(superblock == NULL) 
       return -1;
    unsigned char *totalInodes = getAttribute(superblock, 0x0, 4);
    dumpHexBytes(totalInodes, 4);
    printf("%u\n", attribToUint32(totalInodes));
    free(superblock);
    return 0;
}
