// The MIT License (MIT)
//
// Copyright (c) 2023 leewckk@126.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//
//
//

#include "cycle_queue.h"
#include "std_typedef.h"
#include "std_common.h"


static StdResult setQueueElement(CycleQueueType *queue, uint32_t index, void* element);

/// @brief CycleQueueInit
///
/// @param q
/// @param buffer
/// @param elemSize
/// @param capacity
///
/// @return
StdResult CycleQueueInit(CycleQueueType *q, void *buffer, uint32_t elemSize,
                          uint32_t capacity) {

    if (NULL == q || NULL == buffer) {
        return E_NOT_OK;
    }
    q->data = buffer;
    q->elemSize = elemSize;
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;

    return E_OK;
}


/// @brief CycleQueueInsert
///
/// @param q
/// @param element
///
/// @return
//
StdResult CycleQueueInsert(CycleQueueType* q, const void* element){

    STD_ASSERT_NULL_RETURN(q, E_NOT_OK);
    const uint32_t size = CycleQueueGetSize(q);
    if(0U == size) {
        /*
         * check if queue is empty
         * */
        q->front = 0U;
        q->rear = 0u;
    }else {

        /*
         * check if this queue is full .
         * */
        if (CycleQueueGetSize(q) == q->capacity) {
            q->front = (q->front + 1u) % q->capacity;
        }
        q->rear = (q->rear + 1u) % q->capacity;

    }
    MEMCPY((void *)((uint8_t *)q->data + (q->elemSize * q->rear)),
           element, q->elemSize);

    return E_OK;

}


/// @brief CycleQueueGetSize
///
/// @param q
///
/// @return
uint32_t CycleQueueGetSize(const CycleQueueType* queue){

    STD_ASSERT_NULL_RETURN(queue, 0U);

    if(-1 == queue->front && -1 == queue->rear) {
        /*
         * current queue is empty
         * */
        return 0U;
    }

    return (((queue->rear + queue->capacity - queue->front) % queue->capacity) + 1U);
}


StdResult CycleQueueGetElement(const CycleQueueType *queue, uint32_t index, void* out){

    STD_ASSERT_NULL_RETURN(queue, E_NOT_OK);
    STD_ASSERT_NULL_RETURN(out, E_NOT_OK);

    if(CycleQueueGetSize(queue) < index) {
        return  E_NOT_OK;
    }

    MEMCPY(out,
           (void*)((uint8_t*)queue->data + (queue->elemSize * ((queue->front + index + queue->capacity) % queue->capacity))),
           queue->elemSize);

    return E_OK;
}


/* /// @brief CycleQueueMapProcess */
/* /// */
/* /// @param queue */
/* /// @param proc */
/* void CycleQueueMapProcess(CycleQueueType *queue, CycleQueueMapProc proc){ */

/*     STD_ASSERT_NULL(queue); */
/*     STD_ASSERT_NULL(proc); */

/*     uint32_t size = CycleQueueGetSize(queue); */
/*     for(uint32_t index = 0; index < size; index ++){ */
/*         setQueueElement(queue, index, ) */
/*     } */

/* } */


/* /// @brief CycleQueueReduceProcess */
/* /// */
/* /// @param queue */
/* /// @param proc */
/* void CycleQueueReduceProcess(const CycleQueueType *queue, CycleQueueReduceProc proc){ */

/*     STD_ASSERT_NULL(queue); */
/*     STD_ASSERT_NULL(proc); */
/* } */



/// @brief setQueueElement
///
/// @param queue
/// @param index
/// @param element
///
/// @return
static StdResult setQueueElement(CycleQueueType *queue, uint32_t index, void* element){

    STD_ASSERT_NULL_RETURN(queue, E_NOT_OK);
    STD_ASSERT_NULL_RETURN(element, E_NOT_OK);

    if(CycleQueueGetSize(queue) < index) {
        return  E_NOT_OK;
    }

    return E_OK;
}
