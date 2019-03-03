/*
      Write a for loop to print all elements in courseGrades, following each element with a space (including the last). Print forwards, then backwards. End each loop with a newline. Ex: If courseGrades = {7, 9, 11, 10}, print:
      7 9 11 10 
      10 11 9 7 

      Hint: Use two for loops. Second loop starts with i = NUM_VALS - 1. (Notes)
*/

#include <stdio.h>

int main(void) {
   const int NUM_VALS = 4;
   int courseGrades[NUM_VALS];
   int i;

   courseGrades[0] = 7;
   courseGrades[1] = 9;
   courseGrades[2] = 11;
   courseGrades[3] = 10;

   /* Your solution goes here  */
   for (i = 0; i < NUM_VALS; i++) {
      printf("%d ", courseGrades[i]);
      
   }
   printf("\n");
   
   for (i = NUM_VALS - 1; i > -1; i--) {
      printf("%d ", courseGrades[i]);
   }
   printf("\n");

   return 0;
}
