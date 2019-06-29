/*
        Write a function PrintShampooInstructions(), with int parameter numCycles, and void return type. If numCycles is less than 1, print "Too few.". If more than 4, print "Too many.". Else, print "N: Lather and rinse." numCycles times, where N is the cycle number, followed by "Done.". End with a newline. Example output for numCycles = 2:
        1: Lather and rinse.
        2: Lather and rinse.
        Done.

        Hint: Declare and use a loop variable. 
*/

#include <stdio.h>

/* Your solution goes here  */
void PrintShampooInstructions(int numCycles) {
   if (numCycles < 1) {
      printf("Too few.\n");  
   } else if (numCycles > 4) {
      printf("Too many.\n");  
   } else {
      for (int i = 1; i < numCycles + 1; i++) {
         printf("%d: Lather and rinse.\n", i = i++);  
      }
      printf("Done.\n");
   }

   return;
}

int main(void) {
   PrintShampooInstructions(2);

   return 0;
}
