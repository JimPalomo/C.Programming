/*
      Write code to complete DoublePennies()'s base case. Sample output for below program:
      Number of pennies after 10 days: 1024
*/

#include <stdio.h>

// Returns number of pennies if pennies are doubled numDays times
long long DoublePennies(long long numPennies, int numDays){
   long long totalPennies;

   /* Your solution goes here  */
   if(numDays==0) {
      return numPennies;
   } else {
     totalPennies = DoublePennies((numPennies * 2), numDays - 1);
   }

   return totalPennies;
}

// Program computes pennies if you have 1 penny today,
// 2 pennies after one day, 4 after two days, and so on
int main(void) {
   long long startingPennies;
   int userDays;

   startingPennies = 1;
   userDays = 10;
   printf("Number of pennies after %d days: %lld\n", userDays, DoublePennies(startingPennies, userDays));

   return 0;
}
