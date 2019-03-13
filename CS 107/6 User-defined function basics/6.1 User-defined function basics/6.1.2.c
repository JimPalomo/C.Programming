/*
          Complete the function definition to output the hours given minutes. Output for sample program:
          3.500000
*/


#include <stdio.h>

void OutputMinutesAsHours(double origMinutes) {

   /* Your solution goes here  */
   printf("%lf", origMinutes / 60);
}

int main(void) {

   OutputMinutesAsHours(210.0); // Will be run with 210.0, 3600.0, and 0.0.
   printf("\n");

   return 0;
}
