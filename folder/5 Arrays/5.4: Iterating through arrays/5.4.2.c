/*
      Assign numMatches with the number of elements in userValues that equal matchValue. userValues has NUM_VALS elements. Ex: If userValues is {2, 2, 1, 2} and matchValue is 2 , then numMatches should be 3. 

      Your code will be tested with the following values: 
      * NUM_VALS: 4, userValues: {2, 2, 1, 2}, matchValue: 2 (as in the example program above) 
      * NUM_VALS: 5, userValues: {0, 0, 0, 0, 0}, matchValue: 0 
      * NUM_VALS: 2, userValues: {10, 20}, matchValue: 50 
*/

#include <stdio.h>

int main(void) {
   const int NUM_VALS = 4;
   int userValues[NUM_VALS];
   int i;
   int matchValue;
   int numMatches = -99; // Assign numMatches with 0 before your for loop

   userValues[0] = 2;
   userValues[1] = 2;
   userValues[2] = 1;
   userValues[3] = 2;

   matchValue = 2;

   /* Your solution goes here  */
   numMatches = 0;
   
   for (i = 0; i < NUM_VALS; i++) {
      if (userValues[i] == matchValue) {
         numMatches = numMatches + 1;
      }
   }
   
   printf("matchValue: %d, numMatches: %d\n", matchValue, numMatches);

   return 0;
}
