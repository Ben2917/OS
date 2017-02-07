

#ifndef BLOCK_H_
#define BLOCK_H_

#include <stdio.h>
#include <stdlib.h>

#include "checksums.h"

#define BLOCK unsigned char *

/**
* @param Name of the image file to load block from.
* @param The number of the block on disk.
* @return NULL for error opening file, else valid block.
**/
BLOCK loadBlock(char *, const int, const int); 

/**
* @param The block to get the attribute from.
* @param The byte offset of the attribute in the block.
* @param The size of the attribute.
* @return The attribute in character array format normalized for little endian.
**/
unsigned char *getAttribute(BLOCK, int, int);

#endif // BLOCK_H_


#ifndef SUPERBLOCK_H_
#define SUPERBLOCK_H_

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

#define S_INODE_SIZE_OFFSET 0x58
#define S_INODE_SIZE_LENGTH 0x02

#define S_BLOCK_GROUP_NUM_OFFSET 0x5A
#define S_BLOCK_GROUP_NUM_LENGTH 0x02

#define S_FEATURE_INCOMPAT_OFFSET 0x60
#define S_FEATURE_INCOMPAT_LENGTH 0x04

#define S_UUID_OFFSET 0x68
#define S_UUID_LENGTH 0x10 // NOTE: Used in group descriptor checksum.

#define S_VOLUME_NAME_OFFSET 0x78
#define S_VOLUME_NAME_LENGTH 0x10

#define S_GROUP_DESCRIPTOR_SIZE_OFFSET 0xFE // NOTE: If the 64bit incompat flag is enabled.
#define S_GROUP_DESCRIPTOR_SIZE_LENGTH 0x02

BLOCK initSuperblock(char *);

#endif // SUPERBLOCK_H_


#ifndef GROUP_DESCRIPTOR_H_
#define GROUP_DESCRIPTOR_H_

#include <stdint.h>

#define GROUP_DESCRIPTOR unsigned char *

#define BG_GROUP_DESCRIPTOR_SIZE 0x20

#define BG_BLOCK_BITMAP_LO_OFFSET 0x00
#define BG_BLOCK_BITMAP_LO_LENGTH 0x04

#define BG_INODE_BITMAP_LO_OFFSET 0x04
#define BG_INODE_BITMAP_LO_LENGTH 0x04

#define BG_INODE_TABLE_LO_OFFSET 0x08
#define BG_INODE_TABLE_LO_LENGTH 0x04

#define BG_FREE_BLOCKS_COUNT_LO_OFFSET 0x0C
#define BG_FREE_BLOCKS_COUNT_LO_LENGTH 0x02

#define BG_FREE_INODES_COUNT_LO_OFFSET 0x0E
#define BG_FREE_INODES_COUNT_LO_LENGTH 0x02

#define BG_USED_DIRS_COUNT_LO_OFFSET 0x10
#define BG_USED_DIRS_COUNT_LO_LENGTH 0x02

#define BG_FLAGS_OFFSET 0x12
#define BG_FLAGS_LENGTH 0x02

#define BG_EXCLUDE_BITMAP_LO_OFFSET 0x14
#define BG_EXCLUDE_BITMAP_LO_LENGTH 0x04

#define BG_BLOCK_BITMAP_CSUM_LO_OFFSET 0x18
#define BG_BLOCK_BITMAP_CSUM_LO_LENGTH 0x02

#define BG_INODE_BITMAP_CSUM_LO_OFFSET 0x1A
#define BG_INODE_BITMAP_CSUM_LO_LENGTH 0x02

#define BG_ITABLE_UNUSED_LO_OFFSET 0x1C
#define BG_ITABLE_UNUSED_LO_LENGTH 0x02

#define BG_CHECKSUM_OFFSET 0x1E
#define BG_CHECKSUM_LENGTH 0x02

// 64 bit features

#define BG_BLOCK_BITMAP_HI_OFFSET 0x20
#define BG_BLOCK_BITMAP_HI_LENGTH 0x04

#define BG_INODE_BITMAP_HI_OFFSET 0x24
#define BG_INODE_BITMAP_HI_LENGTH 0x04

#define BG_INODE_TABLE_HI_OFFSET 0x28
#define BG_INODE_TABLE_HI_LENGTH 0x04

#define BG_FREE_BLOCKS_COUNT_HI_OFFSET 0x2C
#define BG_FREE_BLOCKS_COUNT_HI_LENGTH 0x02

#define BG_FREE_INODES_COUNT_HI_OFFSET 0x2E
#define BG_FREE_INODES_COUNT_HI_LENGTH 0x02

#define BG_USED_DIRS_COUNT_HI_OFFSET 0x30
#define BG_USED_DIRS_COUNT_HI_LENGTH 0x02

#define BG_ITABLE_UNUSED_HI_OFFSET 0x32
#define BG_ITABLE_UNUSED_HI_LENGTH 0x02

#define BG_EXCLUDE_BITMAP_HI_OFFSET 0x34
#define BG_EXCLUDE_BITMAP_HI_LENGTH 0x04

#define BG_BLOCK_BITMAP_CSUM_HI_OFFSET 0x38
#define BG_BLOCK_BITMAP_CSUM_HI_LENGTH 0x02

#define BG_INODE_BITMAP_CSUM_HI_OFFSET 0x3A
#define BG_INODE_BITMAP_CSUM_HI_LENGTH 0x02

#define BG_RESERVED_OFFSET 0x3C
#define BG_RESERVED_LENGTH 0x04

/**
* @param The block group number to get the group descriptor for.
* @param The group descriptor number to get.
* @param The size of the group descriptor.
* @return The raw data representing the group descriptor.
* **/
BLOCK initGroupdescriptor(char *, const int, const uint32_t);

#endif // GROUP_DESCRIPTOR_H_


#ifndef INODE_H_
#define INODE_H_

#include <stdint.h>

#include "tools.h"

// TODO: Add any flags that may be necessary to this file.

/* Imode flags */

#define S_IXOTH   0x1 // Others may execute
#define S_IWOTH   0x2 // Others may write
#define S_IROTH   0x4 // Others may read
#define S_IXGRP   0x8 // Group members may execute
#define S_IWGRP  0x10 // Group members may write
#define S_IRGRP  0x20 // Group members may read
#define S_IXUSR  0x40 // Owner may execute
#define S_IWUSR  0x80 // Owner may write
#define S_IRUSR 0x100 // Owner may read
#define S_ISVTX 0x200 // Sticky bit
#define S_ISGID 0x400 // Set GID
#define S_ISUID 0x800 // Set UID

/* These are mutually-exclusive file types: */

#define S_IFIFO  0x1000 // FIFO
#define S_IFCHR  0x2000 // Character device
#define S_IFDIR  0x4000 // Directory
#define S_IFBLK  0x6000 // Block device
#define S_IFREG  0x8000 // Regular file
#define S_IFLNK  0xA000 // Symbolic link
#define S_IFSOCK 0xC000 // Socket

#define INODE unsigned char *
#define INODE_SIZE 256 // NOTE: variable sizes, should get from s_inode_size field of sb

#define I_MODE_OFFSET 0x00
#define I_MODE_LENGTH 0x02

#define I_UID_OFFSET 0x02
#define I_UID_LENGTH 0x02

#define I_SIZE_LO_OFFSET 0x04
#define I_SIZE_LO_LENGTH 0x04

#define I_ATIME_OFFSET 0x08
#define I_ATIME_LENGTH 0x04

#define I_CTIME_OFFSET 0x0C
#define I_CTIME_LENGTH 0x04

#define I_MTIME_OFFSET 0x10
#define I_MTIME_LENGTH 0x04

#define I_DTIME_OFFSET 0x14
#define I_DTIME_LENGTH 0x04

#define I_GID_OFFSET 0x18
#define I_GID_LENGTH 0x02

#define I_LINKS_COUNT_OFFSET 0x1A
#define I_LINKS_COUNT_LENGTH 0x02

#define I_BLOCKS_LO_OFFSET 0x1C
#define I_BLOCKS_LO_LENGTH 0x04

#define I_FLAGS_OFFSET 0x20
#define I_FLAGS_LENGTH 0x04

#define I_OSD1_OFFSET 0x24
#define I_OSD1_LENGTH 0x04

#define I_BLOCK_OFFSET 0x28
#define I_BLOCK_LENGTH 0x3C

#define I_GENERATION_OFFSET 0x64
#define I_GENERATION_LENGTH 0x04

#define I_FILE_ACL_LO_OFFSET 0x68
#define I_FILE_ACL_LO_LENGTH 0x04

#define I_SIZE_HI_OFFSET 0x6C
#define I_SIZE_HI_LENGTH 0x04

#define I_OSD2_OFFSET 0x74
#define I_OSD2_LENGTH 0x0C

#define I_EXTRA_ISIZE_OFFSET 0x80
#define I_EXTRA_ISIZE_LENGTH 0x02

#define I_CHECKSUM_HI_OFFSET 0x82
#define I_CHECKSUM_HI_LENGTH 0x02

#define I_CTIME_EXTRA_OFFSET 0x84
#define I_CTIME_EXTRA_LENGTH 0x04

#define I_MTIME_EXTRA_OFFSET 0x88
#define I_MTIME_EXTRA_LENGTH 0x04

#define I_ATIME_EXTRA_OFFSET 0x8C
#define I_ATIME_EXTRA_LENGTH 0x04

#define I_CRTIME_OFFSET 0x90
#define I_CRTIME_LENGTH 0x04

#define I_CRTIME_EXTRA_OFFSET 0x94
#define I_CRTIME_EXTRA_LENGTH 0x04

#define I_VERSION_HI_OFFSET 0x98
#define I_VERSION_HI_LENGTH 0x04

#define I_PROJID_OFFSET 0x9C
#define I_PROJID_LENGTH 0x04

/**
* @param The name of the image to get the inode from.
* @param The size of the inode in bytes.
**/
BLOCK initInode(char *, const int);

#endif // INODE_H_


