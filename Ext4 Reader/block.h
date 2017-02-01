

#ifndef BLOCK_H_
#define BLOCK_H_

#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 4096
#define IMAGE_NAME "images/ext4.img"

#define BLOCK unsigned char *

/**
* @param The number of the block on disk.
* @return NULL for error opening file, else valid block.
**/
BLOCK loadBlock(const int, const int); 

/**
* @param The block to get the attribute from.
* @param The byte offset of the attribute in the block.
* @param The size of the attribute.
**/
unsigned char *getAttribute(BLOCK, int, int);

#endif // BLOCK_H_
