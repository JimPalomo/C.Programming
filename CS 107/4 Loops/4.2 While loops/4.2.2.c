/*
        Write a while loop that prints userNum divided by 2 (integer division) until reaching 1. Follow each number by a space. Example output for userNum = 40: 
        20 10 5 2 1
*/

#include <stdio.h>

int main(void) {
   int userNum;

   userNum = 40;

   /* Your solution goes here  */

   while (userNum > 1) {
      userNum = userNum / 2;
      printf("%d ", userNum);
   }

   printf("\n");

   return 0;
}
