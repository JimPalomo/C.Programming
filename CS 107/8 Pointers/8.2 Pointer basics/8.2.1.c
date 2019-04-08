/* 
      Assign numItems' address to numItemsPtr, then print the shown text followed by the value to which numItemsPtr points. End with newline.
      Items: 99
*/

#include <stdio.h>

int main(void) {
   int* numItemsPtr = NULL;
   int numItems;

   numItems = 99;

   /* Your solution goes here  */
   numItemsPtr = &numItems;
   
   printf("Items: %d\n", *numItemsPtr);
   
   return 0;
}
