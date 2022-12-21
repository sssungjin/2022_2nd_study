#include <stdio.h>

int main(void)
{
 int i, j;
 int count=0;
 for(i = 0;i < 3; i++) {
    printf("     %d단      ", 3*i+1);
    printf("    %d단       ", 3*i+2);
    printf("    %d단\n", 3*i+3);

  for(j =0; j<9; j++) {

   printf("%2d X%2d = %2d   ", 3*i+1, j+1, (3*i+1)*(j+1));
   printf("%2d X%2d = %2d   ", 3*i+2, j+1, (3*i+2)*(j+1));
   printf("%2d X%2d = %2d \n", 3*i+3, j+1, (3*i+3)*(j+1));
  }
  printf("========================================\n");
 }
 return 0;
}