/*
          Write an expression that prints "Special number" if specialNum is -99, 0, or 44. 
*/

#include <stdio.h>

int main(void) {
   int specialNum;

   scanf("%d", &specialNum);

   if ((specialNum == -99) || (specialNum == 0) || (specialNum == 44)) {
      printf("Special number\n");
   }
   else {
      printf("Not special number\n");
   }

   return 0;
}
