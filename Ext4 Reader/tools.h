

#ifndef TOOLS_H_
#define TOOLS_H_

#include <stdint.h>
#include <limits.h> // Use this to check no attribs go over the bounds.

#define TOOLS_BIG_ENDIAN 0
#define TOOLS_LITTLE_ENDIAN 1

uint16_t attribToUint16(unsigned char *);

uint32_t attribToUint32(unsigned char *);

uint64_t attribToUint64(unsigned char *);

#endif // TOOLS_H_
