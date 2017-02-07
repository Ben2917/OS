

#include "block.h"

BLOCK initInode(char *imageName, const int offset) {
    BLOCK in = loadBlock(imageName, offset, INODE_SIZE);
    if(in) {
        uint16_t iMode = attribToUint(getAttribute(in, I_MODE_OFFSET, I_MODE_LENGTH), I_MODE_LENGTH);
        printf("%c", (iMode &= S_IROTH) ? 'r' : '-');
        printf("%c", (iMode &= S_IWOTH) ? 'w' : '-');
        printf("%c", (iMode &= S_IXOTH) ? 'x' : '-');
        printf("%c", (iMode &= S_IRGRP) ? 'r' : '-');
        printf("%c", (iMode &= S_IWGRP) ? 'w' : '-');
        printf("%c", (iMode &= S_IXGRP) ? 'x' : '-');
        printf("%c", (iMode &= S_IRUSR) ? 'r' : '-');
        printf("%c", (iMode &= S_IWUSR) ? 'w' : '-');
        printf("%c", (iMode &= S_IXUSR) ? 'x' : '-');
        printf("\n");
        return in;
    }
    else {
        // Set global error message.
        return NULL;
    }
}
