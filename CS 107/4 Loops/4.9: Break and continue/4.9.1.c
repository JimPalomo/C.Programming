/*
      "Simon Says" is a memory game where "Simon" outputs a sequence of 10 characters (R, G, B, Y) and the user must repeat the sequence. Create a for loop that compares the two strings starting from index 0. For each match, add one point to userScore. Upon a mismatch, exit the loop using a break statement. Assume simonPattern and userPattern are always the same length. Ex: The following patterns yield a userScore of 4:
      simonPattern: RRGBRYYBGY
      userPattern:  RRGBBRYBGY
*/

#include <stdio.h>
#include <string.h>

int main(void) {
   char simonPattern[50];
   char userPattern[50];
   int userScore;
   int i;

   userScore = 0;
   strcpy(simonPattern, "RRGBRYYBGY");
   strcpy(userPattern, "RRGBBRYBGY");

   /* Your solution goes here  */
   while (userPattern[i] == simonPattern[i]) {
      userScore = userScore + 1;
      ++i;
      if (userPattern[i] != simonPattern[i]) {
         break;
      }
   }
   printf("userScore: %d\n", userScore);

   return 0;
}
