//
// Created by leewc on 2024/4/30.
//

#ifndef CSTDLIB_CYCLE_BUFFER_H
#define CSTDLIB_CYCLE_BUFFER_H

#include "std_typedef.h"

typedef struct {
    uint8_t *buffer;
    uint32_t size;
    uint32_t header;
    uint32_t tail;
}CycleBuffer;

typedef enum {
    E_CYCLE_BUFFER_OK = 0,
    E_CYCLE_BUFFER_EMPTY = 1,
    E_CYCLE_BUFFER_NULLPTR = 2,
    E_CYCLE_BUFFER_OTHER = 99
}CycleBufferResult;


uint32_t  CycleBufferGetSize(CycleBuffer *cycleBuffer);
CycleBufferResult CycleBufferInit(CycleBuffer *cycleBuffer, uint8_t *buffer, uint32_t size);
CycleBufferResult CycleBufferInsert(CycleBuffer *cycleBuffer, const uint8_t *buffer, uint32_t size);
CycleBufferResult CycleBufferPop(CycleBuffer *cycleBuffer, uint8_t *buffer, uint32_t size, uint32_t *popSize);


#endif //CSTDLIB_CYCLE_BUFFER_H
