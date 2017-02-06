

#ifndef EXT_FILE_H_
#define EXT_FILE_H_

#include <stdint.h>

#include "block.h"
#include "tools.h"

#define MAX_RECORDS 30 // A temporary record maximum.

/* Support for linear directories. */

#define F_INODE_OFFSET 0x0
#define F_INODE_LENGTH 0x4

#define F_REC_LEN_OFFSET 0x4
#define F_REC_LEN_LENGTH 0x2

#define F_NAME_LEN_OFFSET 0x6
#define F_NAME_LEN_LENGTH 0x2

#define F_NAME_OFFSET 0x8

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

EXT_FILE *initDirectory(BLOCK, const uint32_t);

void ls(EXT_FILE *);

#endif // EXT_FILE_H_
