/*
      This is the 2nd version of 11.2 using seedVal base random #     
*/

#include <stdio.h>
#include <stdlib.h>

 int main () {
 
   int seedVal;
   int die1;
   int die2;
   int die3;
   int total;
    
   // User input
   printf("Please enter the number of dice to be rolled: \n");
   scanf("%d", &seedVal);
   srand(seedVal);

   
   // Dice roll & prompt
   if (seedVal == 0) {
      printf("No Dice!\n");
      
   }
   else if (seedVal == 1) {
      die1 = ((rand() % 6) + 1);
      total = die1;
      printf("The one dice has a value of %d, for a total of %d\n", die1, total);
      
   }
   else if (seedVal == 2) {
   die1 = ((rand() % 6) + 1);
   die2 = ((rand() % 6) + 1);
   total = die1 + die2;
   printf("The two dice has a value of %d and %d, for a total of %d\n", die1, die2, total);
   
   }
   else if (seedVal == 3) {
   die1 = ((rand() % 6) + 1);
   die2 = ((rand() % 6) + 1);
   die3 = ((rand() % 6) + 1);
   total = die1 + die2 + die3;
   printf("The three dice has a value of %d, %d, and %d, for a total of %d\n", die1, die2, die3, total);   
   }
   else if (seedVal > 3) {
      printf("We can only roll at most 3 dice\n");
   }
   else if (seedVal < 3) {
    printf("Numer of dice must be greater than 0\n");  
   }

   
return 0;

}
