/*
      Set hasDigit to true if the 3-character passCode contains a digit. 
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void) {
   bool hasDigit;
   char passCode[50];

   hasDigit = false;
   scanf("%s", &passCode);

   /* Your solution goes here  */

   if (hasDigit) {
      printf("Has a digit.\n");
   }
   else {
      printf("Has no digit.\n");
   }

   return 0;
}
