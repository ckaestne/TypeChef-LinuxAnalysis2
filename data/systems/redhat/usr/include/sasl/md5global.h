/* GLOBAL.H - RSAREF types and constants
 */
#ifndef MD5GLOBAL_H
#define MD5GLOBAL_H

/* PROTOTYPES should be set to one if and only if the compiler supports
  function argument prototyping.
The following makes PROTOTYPES default to 0 if it has not already
  been defined with C compiler flags.
 */
#ifndef PROTOTYPES
#define PROTOTYPES 0
#endif

/* POINTER defines a generic pointer type */
typedef unsigned char *POINTER;

/* We try to define integer types for our use */
#include <inttypes.h>

typedef int8_t INT1;			/*  8 bits */
typedef int16_t INT2;			/* 16 bits */
typedef int32_t INT4;			/* 32 bits */
typedef int64_t INT8;			/* 64 bits */
typedef uint8_t UINT1;			/*  8 bits */
typedef uint16_t UINT2;			/* 16 bits */
typedef uint32_t UINT4;			/* 32 bits */
typedef uint64_t UINT8;			/* 64 bits */

/* PROTO_LIST is defined depending on how PROTOTYPES is defined above.
If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it
returns an empty list.
*/
#if PROTOTYPES
#define PROTO_LIST(list) list
#else
#define PROTO_LIST(list) ()
#endif

#endif /* MD5GLOBAL_H */

