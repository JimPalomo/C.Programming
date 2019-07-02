/*
      Write a statement that calls the recursive function BackwardsAlphabet() with parameter startingLetter. 
*/

#include <stdio.h>

void BackwardsAlphabet(char currLetter){
   if (currLetter == 'a') {
      printf("%c\n", currLetter);
   }
   else{
      printf("%c ", currLetter);
      BackwardsAlphabet(currLetter - 1);
   }
}

int main(void) {
   char startingLetter;

   startingLetter = 'z';

   /* Your solution goes here  */
   BackwardsAlphabet(startingLetter);

   return 0;
}
