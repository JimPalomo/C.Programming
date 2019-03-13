/*
      Write a function SwapArrayEnds() that swaps the first and last elements of the function's array parameter. Ex: sortArray = {10, 20, 30, 40} becomes {40, 20, 30, 10}. The array's size may differ from 4. 
*/

#include <stdio.h>

/* Your solution goes here  */
int SwapArrayEnds(int sortArray[], int size) {
   int temp = sortArray[0];
   sortArray[0] = sortArray[size - 1];
   sortArray[size - 1] = temp;
}

int main(void) {
   const int SORT_ARR_SIZE = 4;
   int sortArray[SORT_ARR_SIZE];
   int i;

   sortArray[0] = 10;
   sortArray[1] = 20;
   sortArray[2] = 30;
   sortArray[3] = 40;

   SwapArrayEnds(sortArray, SORT_ARR_SIZE);

   for (i = 0; i < SORT_ARR_SIZE; ++i) {
      printf("%d ", sortArray[i]);
   }
   printf("\n");

   return 0;
}
