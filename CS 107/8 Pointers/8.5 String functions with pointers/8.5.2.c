/*
      Assign movieResult with the first instance of The in movieTitle. 
*/

#include <stdio.h>
#include <string.h>

int main(void) {
   char movieTitle[100] = "The Lion King";
   char* movieResult = NULL;

   /* Your solution goes here  */
   movieResult = strstr(movieTitle, "The");

   printf("Movie title contains The? ");
   if (movieResult != NULL) {
      printf("Yes.\n");
   }
   else {
      printf("No.\n");
   }

   return 0;
}
