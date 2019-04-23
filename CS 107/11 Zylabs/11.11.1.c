/*
          Enter a username: 
          The username CS107@E1orSEL2249! has 10 non-alpha characters 
          1 is at address 0x7ffeefbff5e2 
          0 is at address 0x7ffeefbff5e3 
          7 is at address 0x7ffeefbff5e4 
          @ is at address 0x7ffeefbff5e5 
          1 is at address 0x7ffeefbff5e7 
          2 is at address 0x7ffeefbff5ed 
          2 is at address 0x7ffeefbff5ee 
          4 is at address 0x7ffeefbff5ef 
          9 is at address 0x7ffeefbff5f0 
          ! is at address 0x7ffeefbff5f1 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFERSIZE 26 // 25 characters plus end of string

// [IN] charArray[]: array of chars
// [OUT] *ptrsToChars[]: array of pointers to non-alpha chars in charArray
// [OUT] returns number of non-alpha chars in charArray
int getPointers(char charArray[], char *ptrsToChars[]){  // https://www.youtube.com/watch?v=5BpYD7TxvKU
   int i = 0;
   int count = 0;
   
   
   
   while (charArray[i] != '\0') {
      if (!(isalpha(charArray[i]))) {
         (ptrsToChars)[count] = &charArray[i];  // https://cboard.cprogramming.com/c-programming/144366-assignment-makes-pointer-integer-without-cast.html
         count++;
      }
      i++;
   }
   
   return count; //This line can be modified...
}

int main() {
    char userInput[BUFFERSIZE];
    char *ptrsToChars[BUFFERSIZE];
    printf("Enter a username: \n");
    scanf("%s",userInput);
    //End of template
    
    int i = 0;
    int nonAlpha = getPointers(userInput, ptrsToChars);
    
    printf("The username %s has %d non-alpha characters\n", userInput, nonAlpha);
    
    for(i = 0; i < BUFFERSIZE; i++) {
      printf("%c is at address %p\n", (*ptrsToChars)[i], &ptrsToChars[i]);  
    }
    
    return 0;
}
