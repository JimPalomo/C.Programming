/*
      Enter a character:
      %
      Enter triangle height:
      5

      % 
      % % 
      % % % 
      % % % % 
      % % % % % 
*/

#include <stdio.h>

int main(void) {
   char triangleChar;
   int triangleHeight;

   int i;
   int j;
   
   printf("Enter a character:\n");
   scanf("%c", &triangleChar);
   
   printf("Enter triangle height:\n");
   scanf("%d", &triangleHeight);
      
      for (i = 0; i <= triangleHeight; ++i) 
   {
      
      for (j = 1; j <= i; ++j) {
         printf("%c ",  triangleChar);
      }
         printf("\n"); 
   }
   
   
   return 0;
}
