

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "hexdump.h"
#include "superblock.h"
#include "groupdescriptor.h"
#include "inode.h"
#include "tools.h"

// TODO: test with ext2 image to check backwards compatibility

int main(int argc, char **argv) {
    
    BLOCK sb = initSuperblock();
    
    uint32_t blockSize = (uint32_t)attribToUint(getAttribute(sb, S_LOG_BLOCK_SIZE_OFFSET, 
        S_LOG_BLOCK_SIZE_LENGTH), S_LOG_BLOCK_SIZE_LENGTH);
    
    uint16_t inodeSize = (uint16_t)attribToUint(getAttribute(sb, S_INODE_SIZE_OFFSET,
        S_INODE_SIZE_LENGTH), S_INODE_SIZE_LENGTH);
    
    blockSize = (uint32_t)pow(2.0, 10.0 + (double)blockSize);
        
    printf("Block Size: %u\nInode Size: %u\n", blockSize, inodeSize);

    // TODO: Focus on superblock reading to accurately set up the environment
    // for the given image.
	
    // Should be group descriptor for bg 0
    BLOCK gd = initGroupdescriptor(0, blockSize);
    
    dumpHexBytes(gd, BG_GROUP_DESCRIPTOR_SIZE);
    
    uint32_t inodeTableLo = (uint32_t)attribToUint(getAttribute(gd, 
		BG_INODE_TABLE_LO_OFFSET, BG_INODE_TABLE_LO_LENGTH), BG_INODE_TABLE_LO_LENGTH);
    printf("Inode table lo: %u\n", inodeTableLo);
	    
    // Inode numbers start at 1?
	INODE inodeTwo = initInode(inodeTableLo * blockSize + 1 * inodeSize);
	
	dumpHexBytes(inodeTwo, inodeSize);
	
	printf ("Data Blocks?\n");
	dumpHexBytes(getAttribute(inodeTwo, I_BLOCK_OFFSET, I_BLOCK_LENGTH), I_BLOCK_LENGTH);
		
	uint32_t dataBlockZero = (uint32_t)attribToUint(getAttribute(inodeTwo, 
		I_BLOCK_OFFSET, UINT32_WIDTH), UINT32_WIDTH);

    // Need to figure out how to build extent tree from these data blocks.
		
	printf("Data Block 0: %u\n", dataBlockZero);
	
	BLOCK root = loadBlock(dataBlockZero * blockSize, blockSize);
	
	dumpHexBytes(root, blockSize);
    
    // Use the raw root data to build a file struct up
    
    free(sb);
    free(gd);
    free(inodeTwo);
    free(test);
    return 0;
}
