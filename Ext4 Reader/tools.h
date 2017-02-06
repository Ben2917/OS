

#ifndef TOOLS_H_
#define TOOLS_H_

#include <stdint.h>
#include <limits.h> // Use this to check no attribs go over the bounds.

#define TOOLS_BIG_ENDIAN 0
#define TOOLS_LITTLE_ENDIAN 1

#define UINT8_WIDTH  1
#define UINT16_WIDTH 2
#define UINT32_WIDTH 4
#define UINT64_WIDTH 8

uint64_t attribToUint(unsigned char *, const int width);

#endif // TOOLS_H_
