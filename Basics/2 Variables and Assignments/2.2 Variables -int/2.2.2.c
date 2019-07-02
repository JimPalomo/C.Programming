/*
      Write a statement that assigns numCoins with numNickels + numDimes. Ex: 5 nickels and 6 dimes results in 11 coins.
      Note: These activities may test code with different test values. This activity will perform two tests: the first with nickels = 5 and dimes = 6, the second with nickels = 9 and dimes = 0.
*/

#include <stdio.h>

int main(void) {
   int numCoins;
   int numNickels;
   int numDimes;

   numNickels = 5;
   numDimes = 6;

   /* Your solution goes here  */
   numCoins = numNickels + numDimes;
   printf("There are %d coins\n", numCoins);

   return 0;
}
