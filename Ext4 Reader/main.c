

#include <stdlib.h>
#include <stdio.h>

#include "hexdump.h"
#include "superblock.h"
#include "groupdescriptor.h"
#include "tools.h"

// NOTE: looks like could have 4k block size

// NOTE: need to get s_desc_size field from superblock

int main() {
    
    BLOCK superblock = loadBlock(1, SUPERBLOCK_SIZE);    
    if(!superblock)
       return -1;
    uint32_t featureIncompat = (uint32_t)attribToUint(getAttribute(superblock, 
		S_FEATURE_INCOMPAT_OFFSET, S_FEATURE_INCOMPAT_LENGTH), S_FEATURE_INCOMPAT_LENGTH);
	if(!(featureIncompat & 0x80)) // TODO: 64 bit support
		printf("64 bit incompatible.\n");
    
    // Blocks per group * block size
    uint32_t blockSize = (uint32_t)attribToUint(getAttribute(superblock,
		S_LOG_BLOCK_SIZE_OFFSET, S_LOG_BLOCK_SIZE_LENGTH), S_LOG_BLOCK_SIZE_LENGTH);
	
	printf("Block size: %u\n", blockSize);
	
	// blockSize = (uint32_t)pow(2, 10 + blockSize);
	
	uint32_t blocksPerGroup = (uint32_t)attribToUint(getAttribute(superblock, 
		S_BLOCKS_PER_GROUP_OFFSET, S_BLOCKS_PER_GROUP_LENGTH), S_BLOCKS_PER_GROUP_LENGTH);
	
	printf("Group size %u\n", blocksPerGroup * BLOCK_SIZE);
	
    // Should be group descriptor for bg 1
    GROUP_DESCRIPTOR gd = loadBlock(1, BG_GROUP_DESCRIPTOR_SIZE);
    if(!gd)
		return -2;
    dumpHexBytes(gd, BG_GROUP_DESCRIPTOR_SIZE);
    
    uint32_t inodeTableLo = (uint32_t)attribToUint(getAttribute(gd, 
		BG_INODE_TABLE_LO_OFFSET, BG_INODE_TABLE_LO_LENGTH), BG_INODE_TABLE_LO_LENGTH);
	printf("Inode table lo: %u\n", inodeTableLo);
	
	unsigned char *inodeTable = loadBlock(inodeTableLo, BLOCK_SIZE);
	
	dumpHexBytes(inodeTable, BLOCK_SIZE);
	
    free(superblock);
    free(gd);
    return 0;
}
