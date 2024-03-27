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
        uint32_t elemSize;
        uint32_t capacity;
        int32_t front;
        int32_t rear;
    } CycleQueueType;

    StdResult CycleQueueInit(CycleQueueType* q, void* buffer, uint32_t elemSize, uint32_t capacity);
    StdResult CycleQueueInsert(CycleQueueType* q, const void* element);
    uint32_t CycleQueueGetSize(const CycleQueueType* queue);
    StdResult CycleQueueGetElement(const CycleQueueType *queue , uint32_t index, void* out);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
