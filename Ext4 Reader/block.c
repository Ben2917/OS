

#include "block.h"
#include "hexdump.h"

BLOCK loadBlock(char *imageName, const int offset, const int size) {
    BLOCK block = malloc(sizeof(unsigned char) * size);
    FILE *handle = fopen(imageName, "r");
    if(!handle) {
      return NULL;
    } // May get 1 byte too little. See man.
    fseek(handle, offset, SEEK_SET);
    for(int i = 0; i < size; i++) {
        fseek(handle, offset + i, SEEK_SET);
        block[i] = fgetc(handle);
    }
    fclose(handle);
    return block;
}

// Change to an incrementing pointers one for giggles (and efficiency)
unsigned char *getAttribute(BLOCK block, int offset, int size) {
    unsigned char *attrib = malloc(sizeof(unsigned char) * size);
    for(int i = offset, attribI = 0; i < offset + size; ++i, ++attribI)
        attrib[attribI] = block[i];
    return attrib;
}

