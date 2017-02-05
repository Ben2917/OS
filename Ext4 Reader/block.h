

#ifndef BLOCK_H_
#define BLOCK_H_

#include <stdio.h>
#include <stdlib.h>

#include "checksums.h"

#define IMAGE_NAME "images/ext2"

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
