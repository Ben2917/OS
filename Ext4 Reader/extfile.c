

#include "extfile.h"

EXT_FILE *initLinearDirectory(BLOCK data, const uint32_t size) {
    EXT_FILE *dir = malloc(sizeof(EXT_FILE));
    if(dir) {
        uint32_t bytesHandled = 0;
        int recIndex = 0; // TODO: Replace with numRecords field of dir
        while(bytesHandled < size) { // TODO: Be sure to not read too many records
            dir->records[recIndex] = malloc(sizeof(EXT_RECORD));
            dir->records[recIndex]->inode = (uint32_t)attribToUint(getAttribute(data,
                bytesHandled, UINT32_WIDTH), UINT32_WIDTH);
            dir->records[recIndex]->recLen = (uint16_t)attribToUint(getAttribute(data, 
                bytesHandled + 4, UINT16_WIDTH), UINT16_WIDTH);
            dir->records[recIndex]->nameLen = (uint8_t)attribToUint(getAttribute(data,
                bytesHandled + 6, UINT8_WIDTH), UINT8_WIDTH);
            dir->records[recIndex]->fileType = (uint8_t)attribToUint(getAttribute(data,
                bytesHandled + 7, UINT8_WIDTH), UINT8_WIDTH);
            uint16_t nameLen = dir->records[recIndex]->recLen - 7;
            dir->records[recIndex]->name = malloc(sizeof(char) * nameLen + 1);
            dir->records[recIndex]->name = getAttribute(data, bytesHandled + 8, nameLen);
            dir->records[recIndex]->name[nameLen] = '\0';
            bytesHandled += dir->records[recIndex]->recLen;
            dir->numRecords++;
            recIndex++;
        }
        return dir;
    }
    else {
        // Set global error message.
        return NULL;
    }
}

void ls(EXT_FILE *file) {
    for(int i = 0; i < file->numRecords; ++i) {
        printf("%5u %5u %5u %5u %20s\n", file->records[i]->inode, file->records[i]->recLen, 
            file->records[i]->nameLen, file->records[i]->fileType, file->records[i]->name);
    }
}

int magicNumberPresent(BLOCK data) {
    return ((uint16_t)attribToUint(getAttribute(data, EH_MAGIC_OFFSET, 
        EH_MAGIC_LENGTH), EH_MAGIC_LENGTH) == EXTENT_MAGIC_NUM);
}

EXT_EH *initHeader(BLOCK data) {
    EXT_EH *eh = malloc(sizeof(EXT_EH));
    if(eh) {
        eh->magic = (uint16_t)attribToUint(getAttribute(data, EH_MAGIC_OFFSET,
            EH_MAGIC_LENGTH), EH_MAGIC_LENGTH);
        eh->entries = (uint16_t)attribToUint(getAttribute(data, EH_ENTRIES_OFFSET,
            EH_ENTRIES_LENGTH), EH_ENTRIES_LENGTH);
        eh->max = (uint16_t)attribToUint(getAttribute(data, EH_MAX_OFFSET,
            EH_MAX_LENGTH), EH_MAX_LENGTH);
        eh->depth = (uint16_t)attribToUint(getAttribute(data, EH_DEPTH_OFFSET,
            EH_DEPTH_LENGTH), EH_DEPTH_LENGTH);
        eh->generation = (uint32_t)attribToUint(getAttribute(data, EH_GENERATION_OFFSET,
            EH_GENERATION_LENGTH), EH_GENERATION_LENGTH);
        return eh;
    }
    else {
        // Set global error message.
        return NULL;
    }
}
