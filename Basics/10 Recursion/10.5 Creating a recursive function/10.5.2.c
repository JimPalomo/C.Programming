/*
      Write code to complete PrintFactorial()'s recursive case. Sample output if userVal is 5:
      5! = 5 * 4 * 3 * 2 * 1 = 120
*/

#include <stdio.h>

void PrintFactorial(int factCounter, int factValue){
   int nextCounter;
   int nextValue;

   if (factCounter == 0) {            // Base case: 0! = 1
      printf("1\n");
   }
   else if (factCounter == 1) {       // Base case: Print 1 and result
      printf("%d = %d\n", factCounter, factValue);
   }
   else {                             // Recursive case
      printf("%d * ", factCounter);
      nextCounter = factCounter - 1;
      nextValue = nextCounter * factValue;

      /* Your solution goes here  */
      PrintFactorial(nextCounter,nextValue);

   }
}

int main(void) {
   int userVal;

   userVal = 5;
   printf("%d! = ", userVal);
   PrintFactorial(userVal, userVal);

   return 0;
}
