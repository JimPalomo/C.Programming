/*
      Write a loop that sets newScores to oldScores shifted once left, with element 0 copied to the end. Ex: If oldScores = {10, 20, 30, 40}, then newScores = {20, 30, 40, 10}. 
*/

#include <stdio.h>

int main(void) {
   const int SCORES_SIZE = 4;
   int oldScores[SCORES_SIZE];
   int newScores[SCORES_SIZE];
   int i;

   oldScores[0] = 10;
   oldScores[1] = 20;
   oldScores[2] = 30;
   oldScores[3] = 40;

   /* Your solution goes here  */
   for (i = 0; i < SCORES_SIZE - 1; i++) {
      newScores[i] = oldScores[i + 1];
   }
   newScores[SCORES_SIZE - 1] = oldScores[0];
   
   for (i = 0; i < SCORES_SIZE; ++i) {
      printf("%d ", newScores[i]);
   }
   printf("\n");

   return 0;
}
