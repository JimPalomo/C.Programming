/* 
    This is the 1st version using random # based on time instead of seedVal user input. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int main () {
 
   int numRolls = 0;
   int die1;
   int die2;
   int die3;
   int total;
   
   // Random #
   srand((int)time(0));

   // User input
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
   printf("The two dice has a value of %d and %d, for a total of %d\n", die1, die2, total);
   
   }
   else if (numRolls == 3) {
   die1 = ((rand() % 6) + 1);
   die2 = ((rand() % 6) + 1);
   die3 = ((rand() % 6) + 1);
   total = die1 + die2 + die3;
   printf("The three dice has a value of %d, %d, and %d, for a total of %d\n", die1, die2, die3, total);   
   }
   else if (numRolls > 3) {
      printf("We can only roll at most 3 dice\n");
   }
   else if (numRolls < 3) {
    printf("Numer of dice must be greater than 0\n");  
   }

   
return 0;

}



