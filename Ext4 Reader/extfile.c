

#include "extfile.h"

EXT_FILE *initDirectory(BLOCK data, const uint32_t size) {
    EXT_FILE *dir = malloc(sizeof(EXT_FILE));
    if(dir) {
        uint32_t bytesHandled = 0;
        int recIndex = 0;
        while(bytesHandled < size) {
            //dir->records[recIndex] = malloc(sizeof(EXT_RECORD));
            EXT_RECORD *rec = malloc(sizeof(EXT_RECORD));
            rec->inode = (uint32_t)attribToUint(getAttribute(data,
                bytesHandled, UINT32_WIDTH), UINT32_WIDTH);
            rec->recLen = (uint16_t)attribToUint(getAttribute(data, 
                bytesHandled + 4, UINT16_WIDTH), UINT16_WIDTH);
            rec->nameLen = (uint8_t)attribToUint(getAttribute(data,
                bytesHandled + 6, UINT8_WIDTH), UINT8_WIDTH);
            rec->fileType = (uint8_t)attribToUint(getAttribute(data,
                bytesHandled + 7, UINT8_WIDTH), UINT8_WIDTH);
            uint16_t nameLen = rec->recLen - 7;
            rec->name = malloc(sizeof(char) * nameLen + 1);
            rec->name = getAttribute(data, bytesHandled + 8, nameLen);
            rec->name[nameLen] = '\0';
            bytesHandled += rec->recLen;
            dir->numRecords++;
            printf("%u %u %u %u %s\n", rec->inode, rec->recLen, 
                rec->nameLen, rec->fileType, rec->name);
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
        printf("%u %u %u %u %s\n", file->records[i]->inode, file->records[i]->recLen, 
            file->records[i]->nameLen, file->records[i]->fileType, file->records[i]->name);
    }
}
