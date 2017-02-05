

#include "groupdescriptor.h"

BLOCK initGroupdescriptor(const int num, const uint32_t blockSize) {
    BLOCK gd;
    if(blockSize > 1024) {
        gd = loadBlock(1 * blockSize + num * BG_GROUP_DESCRIPTOR_SIZE, 
            BG_GROUP_DESCRIPTOR_SIZE);
    }
    else {
        // Jump over the padding + superblock
        gd = loadBlock(2048 + num * BG_GROUP_DESCRIPTOR_SIZE, 
            BG_GROUP_DESCRIPTOR_SIZE);
    }
    if(gd) {
        // Perform checksum
        /* crc16(sb_uuid + group_desc) or crc32c(sb_uuid + group_desc) & 0xFFFF */
        return gd;
    }
    else {
        // Set global error message.
        return NULL;
    }
}
