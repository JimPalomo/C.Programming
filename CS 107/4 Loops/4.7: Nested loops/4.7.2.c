/*
      Given numRows and numCols, print a list of all seats in a theater. Rows are numbered, columns lettered, as in 1A or 3E. Print a space after each seat, including after the last. Ex: numRows = 2 and numCols = 3 prints:
      1A 1B 1C 2A 2B 2C 
*/

#include <stdio.h>

int main(void) {
   int numRows = 2;
   int numCols = 3;

   // Note: You'll need to declare more variables

   /* Your solution goes here  */
   for (int i = 1; i <= numRows; ++i) {
      for (int j = 0; j < numCols; ++j) {
         printf("%d%c ", i, 'A' + j);
      }
   }
   printf("\n");

   return 0;
}
