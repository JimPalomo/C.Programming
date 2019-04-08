/*
      Use strlen(userStr) to allocate exactly enough memory for newStr to hold the string in userStr (Hint: do NOT just allocate a size of 100 chars). 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
   char userStr[100];
   char* newStr = NULL;

   strcpy(userStr, "Hello friend!");

   /* Your solution goes here  */
   newStr = (char*)malloc(strlen(userStr) * sizeof(char));

   strcpy(newStr, userStr);
   printf("%s\n", newStr);

   return 0;
}
