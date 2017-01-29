

#include <stdlib.h>
#include <stdio.h>

#include "hexdump.h"
#include "superblock.h"
#include "groupdescriptor.h"
#include "tools.h"

int main() {
    BLOCK *superblock = loadBlock(1, BLOCK_SIZE), 
        *groupDescriptor = loadBlock(4, GROUP_DESCRIPTOR_SIZE);    
    dumpHexBytes(superblock->data, BLOCK_SIZE);
    dumpHexBytes(groupDescriptor->data, GROUP_DESCRIPTOR_SIZE);
    printf("***************************************************************\n");
    if(superblock == NULL || groupDescriptor == NULL)
       return -1;
    if(superblock->data == NULL || groupDescriptor->data == NULL)
        return -2;
    unsigned char *totalInodes = getAttribute(superblock, 0x0, 0x04);
    dumpHexBytes(totalInodes, 0x04);
    printf("Total Inodes: %u\n", (uint32_t)attribToUint(totalInodes, UINT32_WIDTH));
     uint64_t inodeTableLoc = attribToUint(getAttribute(groupDescriptor, 
        BG_INODE_TABLE_LO_OFFSET, BG_INODE_TABLE_LO_LENGTH), UINT32_WIDTH);
    inodeTableLoc |= (attribToUint(getAttribute(groupDescriptor, 
        BG_INODE_TABLE_HI_OFFSET, BG_INODE_TABLE_HI_LENGTH), UINT32_WIDTH) << 32);
    printf("Inode table location: %lu\n", inodeTableLoc);
    // NOTE: Be sure to free all of the blocks here.
    return 0;
}
