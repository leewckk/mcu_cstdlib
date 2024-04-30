//
// Created by leewc on 2024/4/30.
//

#include "std_typedef.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "cycle_buffer.h"

void hexdump(const void *buffer, size_t size) {
    const unsigned char *ptr = buffer;
    size_t i, j;

    for (i = 0; i < size; i += 32) {
        printf("%08zx: ", i);

        // 打印每行的十六进制表示
        for (j = 0; j < 32; j++) {
            if (i + j < size) {
                printf("%02x ", ptr[i + j]);
            } else {
                printf("   "); // 如果不足 32 个字节，用空格填充
            }
            if (j % 8 == 7) {
                printf(" "); // 每 8 个字节之后添加额外的空格
            }
        }

        printf("  ");

        // 打印每行的 ASCII 表示
        for (j = 0; j < 32 && i + j < size; j++) {
            char c = ptr[i + j];
            if (c >= 32 && c <= 126) {
                printf("%c", c);
            } else {
                printf(".");
            }
        }

        printf("\n");
    }
}

int main(int argc, char **argv){

    CycleBuffer cycleBuffer;
    uint8_t buffer[128];
    memset(buffer, 0, 128);
    CycleBufferInit(&cycleBuffer,buffer,sizeof(buffer));

    for(uint8_t i = 1; i < 128; i++) {
        uint8_t temp[128];
        memset(temp, 0 + i, 128);
        CycleBufferInsert(&cycleBuffer, temp, i);
        printf("current size: %d\n", CycleBufferGetSize(&cycleBuffer));
        hexdump(buffer, 128);
        printf("\n\n\n");
    }


    return 0;
}