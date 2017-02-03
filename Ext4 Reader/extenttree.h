

#ifndef EXTENT_TREE_H_
#define EXTENT_TREE_H_

/* Extent header macros */

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

/* Extent index macros */

#define EI_BLOCK_OFFSET 0x00
#define EI_BLOCK_LENGTH 0x04

#define EI_LEAF_LO_OFFSET 0x04
#define EI_LEAF_LO_LENGTH 0x04

#define EI_LEAF_HI_OFFSET 0x08
#define EI_LEAF_HI_LENGTH 0x02

#define EI_UNUSED_OFFSET 0x0A
#define EI_UNUSED_LENGTH 0x02

/* Extent leaf macros */

#define EE_BLOCK_OFFSET 0x00
#define EE_BLOCK_LENGTH 0x04

#define EE_LEN_OFFSET 0x04
#define EE_LEN_LENGTH 0x02

#define EE_START_HI_OFFSET 0x06
#define EE_START_HI_LENGTH 0x02

#define EE_START_LO_OFFSET 0x08
#define EE_START_LO_LENGTH 0x04

/* Extent tail macros */

#define EB_CHECKSUM_OFFSET 0x00
#define EB_CHECKSUM_LENGTH 0x04

#endif // EXTENT_TREE_H_


