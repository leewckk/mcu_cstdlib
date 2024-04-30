/**
 *
 *
 */

#include "cycle_buffer.h"

///**
// * @param dest
// * @param src
// * @param size
// */
//void cycleBufferCopy(void* dest, void* src, uint32_t size){
//    uint32_t i = 0;
//    for(i = 0; i < size; i++){
//        ((uint8_t*) dest)[i] = ((uint8_t*) src)[i];
//    }
//}

/**
 * @param cycleBuffer
 * @return
 */
uint32_t  CycleBufferGetSize(CycleBuffer *cycleBuffer){
    return ((cycleBuffer->tail + cycleBuffer->size - cycleBuffer->header) % cycleBuffer->size);
}

/**
 * @brief
 *      init cycle buffer object
 * @param[in] cycleBuffer
 * @param[in] buffer
 * @param[in] size
 * @return
 *  0 : successful
 *  1 : failed
 */
CycleBufferResult CycleBufferInit(CycleBuffer *cycleBuffer, uint8_t *buffer, uint32_t size){
    CycleBufferResult retVal = E_CYCLE_BUFFER_OK;

    do {

        if (NULL == cycleBuffer || NULL == buffer){
            retVal = E_CYCLE_BUFFER_NULLPTR;
            break;
        }

        cycleBuffer->buffer = buffer;
        cycleBuffer->size = size;
        cycleBuffer->header = 0;
        cycleBuffer->tail = 0;
    }while(0U);

    return retVal;
}

/**
 * @brief
 *   insert a buffer into the cycle buffer
 * @param cycleBuffer
 * @param buffer
 * @param size
 * @return
 *  0 : successful
 *  1 : failed
 */
CycleBufferResult CycleBufferInsert(CycleBuffer *cycleBuffer, const uint8_t *buffer, uint32_t size){

    CycleBufferResult retVal = E_CYCLE_BUFFER_OK;
    uint32_t i = 0U;
    do{
        if (NULL == cycleBuffer || NULL == buffer ){
            retVal = E_CYCLE_BUFFER_NULLPTR;
            break;
        }

        for(i = 0U; i < size; i++){
            cycleBuffer->buffer[(cycleBuffer->tail + i) % cycleBuffer->size] = buffer[i];
        }
        cycleBuffer->tail = (cycleBuffer->tail + size) % cycleBuffer->size;
    } while(0U);

    return retVal;
}

/**
 * @brief
 *  pop a buffer from the cycle buffer
 * @param cycleBuffer
 * @param buffer
 * @param size
 * @return
 *  0: success
 *  1: failed
 */
CycleBufferResult CycleBufferPop(CycleBuffer *cycleBuffer, uint8_t *buffer, uint32_t size, uint32_t* popSize){
    CycleBufferResult retVal = E_CYCLE_BUFFER_OK;
    uint32_t currentSize = 0U;
    uint32_t i = 0U;

    do {
        if (NULL == cycleBuffer || NULL == buffer || NULL == popSize){
            retVal = E_CYCLE_BUFFER_NULLPTR;
            break;
        }

        /*
         * If the buffer is empty
         */
        if(cycleBuffer->header == cycleBuffer->tail) {
            retVal = E_CYCLE_BUFFER_EMPTY;
            break;
        }

        currentSize = CycleBufferGetSize(cycleBuffer);
        if(currentSize >= size) {
            *popSize = size;
        }else {
            *popSize = currentSize;
        }

        for(i = 0U; i < *popSize; i++){
            buffer[i] = cycleBuffer->buffer[(cycleBuffer->header + i) % cycleBuffer->size];
        }
        cycleBuffer->header = (cycleBuffer->header + *popSize) % cycleBuffer->size;

    } while(0U);

    return retVal;
}