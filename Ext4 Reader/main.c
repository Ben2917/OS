

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "hexdump.h"
#include "block.h"
#include "tools.h"
#include "extfile.h"

int main(int argc, char **argv) {

    if(argc != 2) {
        printf("Invalid command line arguments. Please use \"filereader <image name>\"\n");
        return -1;
    } 

    BLOCK sb = initSuperblock(argv[1]);
    
    uint32_t blockSize = (uint32_t)attribToUint(getAttribute(sb, S_LOG_BLOCK_SIZE_OFFSET, 
        S_LOG_BLOCK_SIZE_LENGTH), S_LOG_BLOCK_SIZE_LENGTH);
    
    uint16_t inodeSize = (uint16_t)attribToUint(getAttribute(sb, S_INODE_SIZE_OFFSET,
        S_INODE_SIZE_LENGTH), S_INODE_SIZE_LENGTH);
    
    blockSize = (uint32_t)pow(2.0, 10.0 + (double)blockSize);
        
    printf("Block Size: %u\nInode Size: %u\n", blockSize, inodeSize);

    BLOCK gd = initGroupdescriptor(argv[1], 0, blockSize);
    
    uint32_t inodeTableLo = (uint32_t)attribToUint(getAttribute(gd, 
		BG_INODE_TABLE_LO_OFFSET, BG_INODE_TABLE_LO_LENGTH), BG_INODE_TABLE_LO_LENGTH);
    printf("Inode table lo: %u\n", inodeTableLo);
	    
    INODE inodeTwo = initInode(argv[1], inodeTableLo * blockSize + 1 * inodeSize);
    
    BLOCK inodeTwoData = getAttribute(inodeTwo, I_BLOCK_OFFSET, I_BLOCK_LENGTH);
    
    if(!magicNumberPresent(inodeTwoData)) {
        uint32_t dataBlockZero = (uint32_t)attribToUint(getAttribute(inodeTwo, 
            I_BLOCK_OFFSET, UINT32_WIDTH), UINT32_WIDTH);
            
        BLOCK rawRoot = loadBlock(argv[1], dataBlockZero * blockSize, blockSize);
        
        EXT_FILE *root = initLinearDirectory(rawRoot, blockSize);
        ls(root);
        
        free(rawRoot);
        free(root);
    }
    else { // Handle extent tree stuff
        
    }
    
    free(sb);
    free(gd);
    free(inodeTwo);
    return 0;
}
