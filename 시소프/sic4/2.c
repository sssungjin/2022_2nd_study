#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARR_SIZE 12

int* toHex(const char* str) {
    int tmp = 0;
    int idx = 0;
    int *arr = (int *)malloc(sizeof(int) * ARR_SIZE);

    if (arr != NULL) {
        for(int i = 0; i < strlen(str); i++) {
            if ('0' <= str[i] && str[i] <= '9') {
                tmp = tmp * 16 + str[i] - '0';
            }
            else if ('A' <= str[i] && str[i] <= 'F') {
                tmp = tmp * 16 + str[i] - '0' - 7;
            }
            else
                continue;
            if (i % 2 == 1)
            {
                arr[idx] = tmp;
                tmp = 0;
                idx++;
            }
        }
    }
    return arr;
}

int main()
{

    int* arr = toHex("0010030C1006000005FFFFFF?");

    int i = 0;
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%0.2X ", arr[i]);
    }
}