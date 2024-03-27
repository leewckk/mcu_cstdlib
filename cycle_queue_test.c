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
#include "cycle_queue.h"

#pragma pack(1)
typedef struct {
    uint16_t index;
    float32_t value;
}TestStruct;
#pragma pack()

void test_02(void) {

    uint8_t buffer[sizeof(TestStruct)*6];
    memset(buffer, 0, sizeof(buffer));
    CycleQueueType queue;
    CycleQueueInit(&queue, buffer, sizeof(TestStruct), sizeof(buffer)/sizeof(TestStruct));
    for (uint32_t i = 1; i <16; i++) {
        TestStruct  node;
        node.index = i;
        node.value = 3.14*i;
        CycleQueueInsert(&queue,&node);

        for(uint32_t j = 0; j < 6; j++){

            TestStruct *p = (TestStruct*)buffer;
            printf("%d, %.2f ", p[j].index, p[j].value);
        }
        printf("\r\n----------------------------------------------------------------\r\n");
    }

}

void test_01(void){
     int buffer[16];
    const unsigned elementSize = sizeof(buffer) / sizeof(buffer[0]);
    memset(buffer, 0, sizeof(buffer));
    CycleQueueType queue;
    CycleQueueInit(&queue, buffer, sizeof(int), sizeof(buffer) / sizeof(int));


    for(uint32_t i = 0; i < 32; i++) {
        int insertValue = i*2;
        CycleQueueInsert(&queue, &insertValue);

        const uint32_t desireSize = (uint32_t)(i + i) > elementSize ? elementSize : (i + 1);

        printf("Desire queue size: %02d, get size %02d, front : %02d, rear : %02d, capacity : %02d \r\n",
               desireSize, CycleQueueGetSize(&queue), queue.front, queue.rear, queue.capacity);

        for(uint32_t j = 0; j < desireSize ; j++) {
            int value = 0;
            CycleQueueGetElement(&queue, j, &value);
            printf("(%02d,%02d) ", j, value);
        }
        printf("\r\n");

        for(unsigned j = 0; j < elementSize; j ++) {
            printf("%02d ", buffer[j]);
        }
        printf("\r\n-------------------------------------\r\n\r\n");
    }
}

int main(void)
{
    test_02();
//    test_01();
}
