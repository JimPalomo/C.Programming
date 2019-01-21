/*
    Declare a character variable letterStart. Write a statement to read a letter from the user into letterStart, followed by statements that output that letter and the next letter in the alphabet. End with a newline. Hint: A letter is stored as its ASCII number, so adding 1 yields the next letter. Sample output assuming the user enters 'd': de 
*/

#include <stdio.h>

int main(void) {

   /* Your solution goes here  */
   char letterStart;
   char nextLetter;
   
   scanf("%c", &letterStart);
   nextLetter = letterStart + 1;
  
   printf("%c%c\n", letterStart, nextLetter);
   return 0;
}
