/*
      Assign searchResult with a pointer to any instance of searchChar in personName. Hint: Use strchr(). 
*/

#include <stdio.h>
#include <string.h>

int main(void) {
   char personName[100] = "Albert Johnson";
   char searchChar;
   char* searchResult = NULL;

   searchChar = 'J';

   /* Your solution goes here  */
   searchResult = strchr(personName, searchChar);


   if (searchResult != NULL) {
      printf("Character found.\n");
   }
   else {
      printf("Character not found.\n");
   }

   return 0;
}
