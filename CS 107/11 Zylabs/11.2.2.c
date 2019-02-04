/*
      This is the 2nd version of 11.2 using seedVal base random #     
*/

#include <stdio.h>
#include <stdlib.h>

 int main () {
 
   int seedVal;
   int numRolls;
   int die1;
   int die2;
   int die3;
   int total;
    
   // User input
   scanf("%d", &seedVal);
   srand(seedVal);
   printf("Please enter the number of dice to be rolled: \n");
   scanf("%d", &numRolls);
   
   // Dice roll & prompt
   if (numRolls == 0) {
      printf("No Dice!\n");
      
   }
   else if (numRolls == 1) {
      die1 = ((rand() % 6) + 1);
      total = die1;
      printf("The one dice has a value of %d, for a total of %d\n", die1, total);
      
   }
   else if (numRolls == 2) {
      die1 = ((rand() % 6) + 1);
      die2 = ((rand() % 6) + 1);
      total = die1 + die2;
      printf("The two dice have values of %d and %d, for a total of %d\n", die1, die2, total);
   
   }
   else if (numRolls == 3) {
      die1 = ((rand() % 6) + 1);
      die2 = ((rand() % 6) + 1);
      die3 = ((rand() % 6) + 1);
      total = die1 + die2 + die3;
      printf("The three dice have values of %d, %d, and %d, for a total of %d\n", die1, die2, die3, total);   
      
   }
   else if (numRolls > 3) {
      printf("We can only roll at most 3 dice\n");
   
   }
   else if (numRolls < 3) {
      printf("Number of dice must be greater than 0\n");  
   
   }


return 0;

}
