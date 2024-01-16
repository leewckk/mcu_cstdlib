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



#include "search.h"
#include "stdio.h"


int compare_int(const VOID* p1, const VOID* p2) {
    return (*(int*)p1 - *(int*)p2);
}


int main(int argc, char** argv){

    int array1[100];
    int array2[99];
    int target[] = { 0, 99, -1, 20, 50, 40, 22, 46, 88, 91  };

    const int size1 = sizeof(array1) / sizeof(array1[0]);
    const int size2 = sizeof(array2) / sizeof(array2[0]);

    for(int i = 0; i < size1; i ++) {
        array1[i] = i;
    }

    for(int i = 0; i < size2; i++) {
        array2[i] = i;
    }

    for(unsigned i = 0; i < sizeof(target)/sizeof(target[0]); i++) {
        printf("[ARR1] target: %d, find result: %d\n", target[i], BinarySearch(array1, size1, sizeof(int), &target[i], compare_int));
        printf("[ARR2] target: %d, find result: %d\n", target[i], BinarySearch(array2, size2, sizeof(int), &target[i], compare_int));
    }




    return 0;
}
