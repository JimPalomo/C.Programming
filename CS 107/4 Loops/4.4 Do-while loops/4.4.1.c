/*
      Complete the do-while loop to output 0 to countLimit using printVal. Assume the user will only input a positive number. 
*/

#include <stdio.h>

int main(void) {
   int countLimit;
   int printVal;

   // Get user input
   scanf("%d", &countLimit);

   printVal = 0;
   do {
      printf("%d ", printVal);
      printVal = printVal + 1;
   } while ( printVal <= countLimit );
   printf("\n");

   return 0;
}
