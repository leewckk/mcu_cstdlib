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

static tStdResult insertProc(const void *q, const void *element);
static uint32 sizeProc(const void *q);
static void doingReduceProc(const void *q, const void* p1, const void* p2, void* result, CycleQueueReduceProc proc) ;
static void doingMapProc(const void *q, const void* p, void* result, CycleQueueMapProc proc) ;

/// @brief InitCycleQueue
///
/// @param q
/// @param buffer
/// @param elemSize
/// @param capacity
///
/// @return
tStdResult InitCycleQueue(CycleQueue *q, void *buffer, uint32 elemSize,
                          uint32 capacity) {

    if (NULL == q || NULL == buffer) {
        return E_NOT_OK;
    }
    q->data = buffer;
    q->elemSize = elemSize;
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;

    q->insert = insertProc;
    q->getSize = sizeProc;
    q->doMap = doingMapProc ;
    q->doReduce = doingReduceProc;
    return E_OK;
}

/// @brief enqueueProc
///
/// @param q
/// @param element
static tStdResult insertProc(const void *q, const void *element) {

    CycleQueue *queue = (CycleQueue *)q;
    STD_ASSERT_NULL_RETURN(queue, E_NOT_OK);

    /*
     * check if this queue is full .
     * */
    if (queue->getSize(q) == queue->capacity) {
        queue->front = (queue->front + 1u) % queue->capacity;
    }
    queue->rear = (queue->rear + 1u) % queue->capacity;
    MEMCPY((void *)((uint8 *)queue->data + (queue->elemSize * queue->rear)),
           element, queue->elemSize);

    return E_OK;
}

/// @brief sizeProc
///
/// @param q
///
/// @return
static uint32 sizeProc(const void *q) {

    CycleQueue *queue = (CycleQueue *)q;
    STD_ASSERT_NULL_RETURN(queue, 0U);

    if(-1 == queue->front && -1 == queue->rear) {
        /*
         * current queue is empty
         * */
        return 0U;
    }

    return (((queue->rear + queue->capacity - queue->front) % queue->capacity) + 1U);
}




/// @brief doingMapProc
///
/// @param q
/// @param p
/// @param result
/// @param proc
static void doingMapProc(const void *q, const void* p, void* result, CycleQueueMapProc proc) {

    CycleQueue *queue = (CycleQueue *)q;
    STD_ASSERT_NULL(queue);
    STD_ASSERT_NULL(proc);
    proc(queue, p, result);
}

/// @brief doingReduceProc
///
/// @param q
/// @param proc
static void doingReduceProc(const void *q, const void* p1, const void* p2, void* result, CycleQueueReduceProc proc) {

    CycleQueue *queue = (CycleQueue *)q;
    STD_ASSERT_NULL(queue);
    STD_ASSERT_NULL(proc);
    proc(queue, p1, p2, result);
}
