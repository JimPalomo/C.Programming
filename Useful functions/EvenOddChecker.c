/*
      Even/Odd Calculator, determines whether an integer is even or odd.
*/

#include <stdio.h>

int main()
{
    int userInt;
    
    printf("Enter an integer\n");
    scanf("%d", &userInt);
   
   if (userInt%2 == 0) {
      printf("Even\n");
      
   } else {
      printf("Odd\n");
   
   }
    return 0;
}
