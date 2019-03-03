/*
      Write three statements to print the first three elements of array runTimes. Follow each statement with a newline. Ex: If runTimes[5] = {800, 775, 790, 805, 808}, print:
      800 
      775 
      790
*/

#include <stdio.h>

int main(void) {
   int runTimes[5];

   // Populate array
   runTimes[0] = 800;
   runTimes[1] = 775;
   runTimes[2] = 790;
   runTimes[3] = 805;
   runTimes[4] = 808;

   /* Your solution goes here  */
   for (int i = 0; i < 3; i++) {
      printf("%d\n", runTimes[i]);   
   }
   
   return 0;
}
