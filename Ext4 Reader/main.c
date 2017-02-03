

#include <stdlib.h>
#include <stdio.h>

#include "hexdump.h"
#include "superblock.h"
#include "groupdescriptor.h"
#include "inode.h"
#include "tools.h"

int main() {
    
    BLOCK sb = initSuperblock();
	
    // Should be group descriptor for bg 0
    BLOCK gd = initGroupdescriptor(0);

    uint32_t inodeTableLo = (uint32_t)attribToUint(getAttribute(gd, 
		BG_INODE_TABLE_LO_OFFSET, BG_INODE_TABLE_LO_LENGTH), BG_INODE_TABLE_LO_LENGTH);
    printf("Inode table lo: %u\n", inodeTableLo);
	
	INODE inodeTwo = loadBlock(inodeTableLo * BLOCK_SIZE + 2 * INODE_SIZE, INODE_SIZE);
	
	dumpHexBytes(inodeTwo, INODE_SIZE);
	
	printf ("Data Blocks?\n");
	dumpHexBytes(getAttribute(inodeTwo, I_BLOCK_OFFSET, I_BLOCK_LENGTH), I_BLOCK_LENGTH);
		
	uint32_t dataBlockZero = (uint32_t)attribToUint(getAttribute(inodeTwo, 
		I_BLOCK_OFFSET, UINT32_WIDTH), UINT32_WIDTH);
		
	printf("Data Block 0: %u\n", dataBlockZero);
	
	BLOCK test = loadBlock(dataBlockZero, BLOCK_SIZE);
	
	dumpHexBytes(test, BLOCK_SIZE);
		
    free(superblock);
    free(gd);
    free(inodeTwo);
    free(test);
    return 0;
}
