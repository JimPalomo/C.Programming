/*
    Modulo Calculator, determines the remainder of an integer
*/
#include <stdio.h>

int main()
{
    int userInt;
    
    printf("Enter an integer\n");
    scanf("%d", &userInt);
    printf("%d", userInt%3);  // Change the number after "%" to change divisor
    
    return 0;
}
