

#include "block.h"

#include "hexdump.h"

BLOCK *loadBlock(int offset) {
    BLOCK *block = malloc(sizeof(BLOCK));
    FILE *handle = fopen(IMAGE_NAME, "rw");
    if(!handle) {
      return NULL;
    } // May get 1 byte too little. See man.
    fseek(handle, offset * BLOCK_SIZE, SEEK_SET);
    fgets(block->data, BLOCK_SIZE, handle);
    fclose(handle);
    return block;
}

// Change to an incrementing pointers one for giggles (and efficiency)
unsigned char *getAttribute(BLOCK *block, int offset, int size) {
    unsigned char *attrib = malloc(sizeof(char) * size);
    for(int i = offset, attribI = 0; i < offset + size; ++i, ++attribI)
        attrib[attribI] = block->data[i];
    return attrib;
}

