/*
      11.1.1: Week 3 Lab: Variables & Data Types

      Enter integer: 99
      Enter double: 3.77
      Enter character: z
      Enter string: Howdy
      99 3.77 z Howdy
      Howdy z 3.77 99
      3.77 cast to an integer is 3
*/

#include <stdio.h>
#include <string.h>      // Supports use of "string" data type

int main(void) {
   int    userInt    = 0;
   double userDouble = 0.0;
   char   userChar;
   char   userString[20];
   // FIXME: Define char and string variables similarly
   
   printf("Enter integer: ");
   scanf("%d", &userInt);
   printf("\n");

   // FIXME (1): Finish reading other items into variables, then output the four values on a single line separated by a space
   printf("Enter double: ");
   scanf("%lf", &userDouble);
   printf("\n");

   printf("Enter character: ");
   scanf(" %c ", &userChar);
   printf("\n");
   
   printf("Enter string: ");
   scanf("%s", userString);
   printf("\n");

   printf("%d %lf %c %s", userInt, userDouble, userChar, userString);    
   printf("\n");
   
   // FIXME (2): Output the four values in reverse
   printf("%s %c %lf %d", userString, userChar, userDouble, userInt);
   printf("\n");

   // FIXME (3): Cast the double to an integer, and output that integer
   printf("%lf cast to an integer is %d\n", userDouble, (int)(userDouble)); 
   
   return 0;
}
