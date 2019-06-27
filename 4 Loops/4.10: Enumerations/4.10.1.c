/*
      Print either "Fruit", "Drink", or "Unknown" (followed by a newline) depending on the value of userItem. Print "Unknown" (followed by a newline) if the value of userItem does not match any of the defined options. For example, if userItem is GR_APPLES, output should be:
      Fruit
*/

#include <stdio.h>

int main(void) {
   enum GroceryItem {GR_APPLES, GR_BANANAS, GR_JUICE, GR_WATER};
   enum GroceryItem userItem;

   userItem = GR_APPLES;

   /* Your solution goes here  */
   switch (userItem)
   {
   case GR_APPLES:
      printf("Fruit\n");
      break;
   
   
   case GR_BANANAS: 
      printf("Fruit\n");
      break;
      
   case GR_JUICE:
      printf("Drink\n");
      break;
   
   case GR_WATER:
      printf("Drink\n");
      break;
   
   default:
      printf("Unknown\n");
      
   }
   return 0;
}
