

#ifndef SUPERBLOCK_H_
#define SUPERBLOCK_H_

#include "block.h"

/**
* Macros to get the attributes of the superblock to be defined here.
**/

#define S_BLOCKS_PER_GROUP_OFFSET 0x20
#define S_BLOCKS_PER_GROUP_LENGTH 0x04

#define S_INODES_PER_GROUP_OFFSET 0x28
#define S_INODES_PER_GROUP_LENGTH 0x04

#define S_MAGIC_NUMBER_OFFSET 0x38
#define S_MAGIC_NUMBER_LENGTH 0x02

#define S_VOLUME_NAME_OFFSET 0x78
#define S_VOLUME_NAME_LENGTH 0x10

#endif // SUPERBLOCK_H_
