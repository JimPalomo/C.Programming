/*
      Assign isTeenager with true if kidAge is 13 to 19 inclusive. Otherwise, assign isTeenager with false. 
*/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
   bool isTeenager;
   int kidAge;

   scanf("%d", &kidAge);

   /* Your solution goes here  */
   if ((kidAge >= 13) && (kidAge <= 19)) { 
      isTeenager = true;
   }
   if (isTeenager) {
      printf("Teen\n");
   }
   else {
      printf("Not teen\n");
   }

   return 0;
}
