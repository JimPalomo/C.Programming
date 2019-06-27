/*
                Write an if-else statement that checks patronAge. If 55 or greater, print "Senior citizen", otherwise print "Not senior citizen" (without quotes). End with newline. 
*/

#include <stdio.h>

int main(void) {
   int patronAge;

   scanf("%d", &patronAge);

   /* Your solution goes here  */
   if (patronAge >= 55) {
      printf("Senior citizen\n");
   }
   else {
      printf("Not senior citizen\n");  
   }
   return 0;
}
