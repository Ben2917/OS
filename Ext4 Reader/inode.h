

#ifndef INODE_H_
#define INODE_H_

#include <stdint.h>

#include "block.h"
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

BLOCK initInode(const int);

#endif // INODE_H_
