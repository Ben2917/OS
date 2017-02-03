

#ifndef SUPERBLOCK_H_
#define SUPERBLOCK_H_

#include "block.h"
#include "tools.h"

/* General superblock macros. */

#define SUPERBLOCK_SIZE 1024
#define EXPECTED_MAGIC_NUMBER 0xEF53

/* Superblock attribute macros */

#define S_INODE_COUNT_OFFSET 0x0
#define S_INODE_COUNT_LENGTH 0x4

#define S_LOG_BLOCK_SIZE_OFFSET 0x18
#define S_LOG_BLOCK_SIZE_LENGTH 0x04

#define S_BLOCKS_PER_GROUP_OFFSET 0x20
#define S_BLOCKS_PER_GROUP_LENGTH 0x04

#define S_INODES_PER_GROUP_OFFSET 0x28
#define S_INODES_PER_GROUP_LENGTH 0x04

#define S_MAGIC_NUMBER_OFFSET 0x38
#define S_MAGIC_NUMBER_LENGTH 0x02

#define S_BLOCK_GROUP_NUM_OFFSET 0x5A
#define S_BLOCK_GROUP_NUM_LENGTH 0x02

#define S_FEATURE_INCOMPAT_OFFSET 0x60
#define S_FEATURE_INCOMPAT_LENGTH 0x04

#define S_VOLUME_NAME_OFFSET 0x78
#define S_VOLUME_NAME_LENGTH 0x10

// if the 64bit incompat flag is enabled
#define S_GROUP_DESCRIPTOR_SIZE_OFFSET 0xFE 
#define S_GROUP_DESCRIPTOR_SIZE_LENGTH 0x02

BLOCK initSuperblock();

#endif // SUPERBLOCK_H_
