/* 
          Define a function PrintFeetInchShort, with int parameters numFeet and numInches, that prints using ' and " shorthand. End with a newline. Ex: PrintFeetInchShort(5, 8) prints:
          5' 8"
          Hint: Use \" to print a double quote. 
*/
#include <stdio.h>

/* Your solution goes here  */
void PrintFeetInchShort(int numFeet, int numInches) {
      printf("%d' %d\"\n", numFeet, numInches);
   } 
   
int main(void) {
   PrintFeetInchShort(5, 8);   // Will be run with (5, 8), then (4, 11)

   return 0;
}
