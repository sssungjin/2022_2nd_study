#include <stdio.h>

int main()
{
    int i = 10;
    switch(i) {
        case 20:
            printf("%d", i);
            break;
        default :
            printf("%d", i+i); break;
    }
}
