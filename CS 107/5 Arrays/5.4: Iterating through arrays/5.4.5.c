/*
      Write a for loop to print all NUM_VALS elements of array hourlyTemp. Separate elements with a comma and space. Ex: If hourlyTemp = {90, 92, 94, 95}, print:
      90, 92, 94, 95
      Your code's output should end with the last element, without a subsequent comma, space, or newline. 
*/

#include <stdio.h>

int main(void) {
   const int NUM_VALS = 4;
   int hourlyTemp[NUM_VALS];
   int i;

   hourlyTemp[0] = 90;
   hourlyTemp[1] = 92;
   hourlyTemp[2] = 94;
   hourlyTemp[3] = 95;

   /* Your solution goes here  */
   for (i = 0; i < NUM_VALS - 1; i++) {
      printf("%d, ", hourlyTemp[i]);   
   }
   printf("%d", hourlyTemp[i]);

   printf("\n");

   return 0;
}
