

#include "groupdescriptor.h"

BLOCK initGroupdescriptor(const int num) {
    BLOCK gd = loadBlock(1 * BLOCK_SIZE + num * BG_GROUP_DESCRIPTOR_SIZE, BG_GROUP_DESCRIPTOR_SIZE);
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
