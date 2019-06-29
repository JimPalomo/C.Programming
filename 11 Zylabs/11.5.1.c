#include <stdio.h>
#include <string.h>

int main() {

   /* Type your code here. */
   char userString[200];
   char stringToInt[200];
   int  shift;
   
   printf("My Name: Jim Palomo\n");
   printf("My Lab Time: 9:00 AM\n");
   
   printf("Enter a string of at least 3 characters (no whitespace): \n\n");
   scanf("%s", userString);
   
   
   while (strlen(userString) < 3) {
      printf("Enter a string of at least 3 characters (no whitespace): \n");
      scanf("%s", userString);  
   }
   
   
   printf("Your message in ints: ");
   for (int i = 0, j = 0; i < (strlen(userString)); i++) {
      j = (int)userString[i];
      stringToInt[i] = j;
      printf("%d ", stringToInt[i]);
   }
   
   printf("\n\n");
      
   printf("Enter a positive integer to shift: \n");
   scanf("%d", &shift);
   
   if (strlen(userString) % 2 == 1) {
      shift = -1 * shift;
   }
   
   for(int i = 0; i < (strlen(stringToInt)); i++) {
      //  stringToInt[i] = stringToInt[i] + shift;
      if ((stringToInt[i] + shift) > 126) { 
         stringToInt[i] = stringToInt[i] + (shift - 1) - 126 + 32;
      
      } else { 
         stringToInt[i] = stringToInt[i] + shift;
      
      }
   }
   
   printf("\n");
   
   printf("Your message in ints shifted by %d: ", shift);
   for (int i = 0; i < (strlen(userString)); i++) {
      printf("%d ", stringToInt[i]);  
   
   }
   
   printf("\n");
   
   printf("Your encoded message: ");
   for (int i = 0; i < (strlen(userString)); i++) {
      printf(" %c ", stringToInt[i]);   
   
   }
   
   return 0;
}
