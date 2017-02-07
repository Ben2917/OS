

#ifndef EXT_FILE_H_
#define EXT_FILE_H_

#include <stdint.h>
#include <stdbool.h>

#include "block.h"
#include "tools.h"

#define MAX_RECORDS 30 // A temporary record maximum.

/* Support for linear directories. */

#define F_INODE_OFFSET 0x00
#define F_INODE_LENGTH 0x04

#define F_REC_LEN_OFFSET 0x04
#define F_REC_LEN_LENGTH 0x02

#define F_NAME_LEN_OFFSET 0x06
#define F_NAME_LEN_LENGTH 0x02

#define F_NAME_OFFSET 0x08

typedef struct {
    uint32_t inode;
    uint16_t recLen;
    uint8_t nameLen;
    uint8_t fileType;
    char *name;
} EXT_RECORD;

typedef struct {
    EXT_RECORD *records[MAX_RECORDS];
    int numRecords;
} EXT_FILE;

/**
 * @param Raw directory data.
 * @param The size of the raw directory data.
 * @return An initialised directory or NULL if errors occured.
 * **/
EXT_FILE *initLinearDirectory(BLOCK, const uint32_t);

/**
 * Lists the files and directories within this directory.
 * @param The directory.
 * **/
void ls(EXT_FILE *);

#define EXTENT_MAGIC_NUM 0xF30A

#define EH_MAGIC_OFFSET 0x00
#define EH_MAGIC_LENGTH 0x02

#define EH_ENTRIES_OFFSET 0x02
#define EH_ENTRIES_LENGTH 0x02

#define EH_MAX_OFFSET 0x04
#define EH_MAX_LENGTH 0x02

#define EH_DEPTH_OFFSET 0x06
#define EH_DEPTH_LENGTH 0x02

#define EH_GENERATION_OFFSET 0x08
#define EH_GENERATION_LENGTH 0x04

/**
 * Determines whether the extent tree magic number is present. 
 * Potential bug if data block 0 of the linear blocks happens to be the same as the magic num.
 * @param The data blocks from the inode.
 * @return TRUE if present, else FALSE.
 * **/
int magicNumberPresent(BLOCK);

#endif // EXT_FILE_H_
