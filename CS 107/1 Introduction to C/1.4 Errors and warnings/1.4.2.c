/*
      Retype the statements, correcting the syntax errors.
      printf("Num: %d\n", songnum);
      printf("%d\n", int songNum); 
      printf("%d songs\n" songNum);
      Note: These activities may test code with different test values. This activity will perform two tests: the first with songNum = 5, the second with songNum = 9.
*/

#include <stdio.h>

int main(void) {
   int songNum;

   songNum = 5;

   /* Your solution goes here  */
   printf("Num: %d\n", songNum);
   printf("%d\n", songNum); 
   printf("%d songs\n", songNum);
   return 0;
}
