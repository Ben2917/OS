

#include "block.h"

BLOCK initSuperblock(char *imageName) {
    BLOCK sb = loadBlock(imageName, 1024, SUPERBLOCK_SIZE);
    if(sb) {
        // Successfully got data. Make sure it's correct
        uint32_t magicNumber = (uint32_t)attribToUint(getAttribute(sb, S_MAGIC_NUMBER_OFFSET, 
            S_MAGIC_NUMBER_LENGTH), S_MAGIC_NUMBER_LENGTH);
        if(magicNumber == EXPECTED_MAGIC_NUMBER) {
            // Perform checksum (if 64 bit).
            uint32_t featureIncompat = (uint32_t)attribToUint(getAttribute(sb, 
        		S_FEATURE_INCOMPAT_OFFSET, S_FEATURE_INCOMPAT_LENGTH), S_FEATURE_INCOMPAT_LENGTH);
        	if(!(featureIncompat & 0x80)) // TODO: 64 bit support
		        printf("64 bit incompatible.\n");
            return sb;
        }
        else {
            // Set a global error message.
            return NULL;
        }
    }
    else {
        // Set a global error message
        return NULL;
    }    
}
