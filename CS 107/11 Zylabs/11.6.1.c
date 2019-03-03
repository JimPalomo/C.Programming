/*
      (1) Prompt the user to enter an integer for the number of boulders they have (assume the value is always less than 50). Then, prompt the user to enter that many numbers, representing the boulders’ weights. Store the weights in an array of doubles. Output the array's numbers on one line, each number followed by one space. (2 pts)

      (2) Also output the total weight, by summing the array's elements. (1 pt)

      (3) Also output the average weight. (1 pt)

      (4) Also output the maximum weight array element. (2 pts) 
*/

#include <stdio.h>

int main(void) {
   
   int i;
   int numBoulders;
   int count = 0;
   double boulderWeight[50];
   double totalWeight;
   double maxWeight;
   
   printf("How many boulders do you have?: ");
   scanf("%d", &numBoulders);
   
   for (i = 0; i < numBoulders; i++) {
      count++;
      printf("Enter weight %d: ", count);
      scanf("%lf", &boulderWeight[i]);
      if (boulderWeight[i] > maxWeight) {
         maxWeight = boulderWeight[i];
      }
   }
   printf("\n");
   
   printf("You entered: ");
   for (i = 0; i < numBoulders; i++) {
      printf("%lf ", boulderWeight[i]);  
   }
   printf("\n");
   
   for (i = 0; i < numBoulders; i++) {
      totalWeight = totalWeight + boulderWeight[i];
   }
   
   printf("Total weight: %lf\n", totalWeight);
   printf("Average weight: %lf\n", (totalWeight / numBoulders));
   printf("Max weight: %lf", maxWeight);
   
   return 0;
}
