

#include <stdlib.h>
#include <stdio.h>

#include "hexdump.h"
#include "superblock.h"
#include "groupdescriptor.h"
#include "tools.h"

int main() {
    BLOCK *superblock = loadBlock(1), *groupDescriptor = loadBlock(2);
    if(superblock == NULL || groupDescriptor == NULL) 
       return -1;
    unsigned char *totalInodes = getAttribute(superblock, 0x0, 4);
    dumpHexBytes(totalInodes, 4);
    printf("%u\n", (uint32_t)attribToUint(totalInodes, UINT32_WIDTH));
    free(superblock);
    uint64_t inodeTableLoc = attribToUint(getAttribute(groupDescriptor, 
        BG_INODE_TABLE_LO_OFFSET, BG_INODE_TABLE_LO_LENGTH), UINT64_WIDTH);
    inodeTableLoc |= (attribToUint(getAttribute(groupDescriptor, 
        BG_INODE_TABLE_LO_OFFSET, BG_INODE_TABLE_LO_LENGTH), UINT64_WIDTH) << 32);
    printf("%lu\n", inodeTableLoc);
    free(groupDescriptor);
    return 0;
}
