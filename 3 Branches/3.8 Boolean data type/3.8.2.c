/*
          Write an if-else statement to describe an object. Print "Balloon" if isBalloon is true and isRed is false. Print "Red balloon" if isBalloon and isRed are both true. Print "Not a balloon" otherwise. End with newline. (Notes) 
*/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
   bool isRed;
   bool isBalloon;

   isRed = false;
   isBalloon = false;

   /* Your solution goes here  */
   if ((isBalloon == true) && (isRed == false)) {
      printf("Balloon\n");
   } 
   else if ((isBalloon == true) && (isRed == true)) {
      printf("Red balloon\n");
   }
   else {
      printf("Not a balloon\n");
   }
   
   return 0;
}
