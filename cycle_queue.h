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
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
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
#pragma once

#include "std_typedef.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

    typedef struct {
        void* data;
        uint32 elemSize;
        uint32 capacity;
        int32 front;
        int32 rear;
    } CycleQueue;

    StdResult InitCycleQueue(CycleQueue* q, void* buffer, uint32 elemSize, uint32 capacity);
    StdResult InsertCycleQueue(CycleQueue* q, const void* element);
    uint32 GetCycleQueueSize(const CycleQueue* queue);
    StdResult GetCycleQueueElement(const CycleQueue *queue , uint32 index, void* out);

    /* typedef void(*CycleQueueAssignProc)(CycleQueue* q, const uint32 index, const void* value); */
    /* typedef void (*CycleQueueMapProc)(CycleQueue* q, const void* p, void* result, CycleQueueAssignProc assign); */
    /* typedef void (*CycleQueueReduceProc)(const CycleQueue* q, const void* p1, const void* p2, void* result); */

    /* void CycleQueueMapProcess(CycleQueue *q, CycleQueueMapProc proc); */
    /* void CycleQueueReduceProcess(const CycleQueue *q, CycleQueueReduceProc proc); */


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
