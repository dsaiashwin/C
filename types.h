#ifndef TYPES_H
#define TYPES_H

/* User defined types */
typedef unsigned int uint;

/* Status will be used in function return type */
typedef enum
{
    e_success,
    e_failure
} Status;
/* OperationType will be to find wheather to do Encoding or decoding */
typedef enum
{
    e_encode,
    e_decode,
    e_unsupported
} OperationType;

#endif
