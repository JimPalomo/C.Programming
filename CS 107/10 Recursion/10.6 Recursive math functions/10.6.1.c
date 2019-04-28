/*
      Write code to complete RaiseToPower(). Sample output if userBase is 4 and userExponent is 2 is shown below. Note: This example is for practicing recursion; a non-recursive function, or using the built-in function pow(), would be more common.
      4^2 = 16
*/

#include <stdio.h>

int RaiseToPower(int baseVal, int exponentVal){
   int resultVal;

   if (exponentVal == 0) {
      resultVal = 1;
   }
   else {
      resultVal = baseVal *  RaiseToPower(baseVal, exponentVal-1);
   }

   return resultVal;
}

int main(void) {
   int userBase;
   int userExponent;

   userBase = 4;
   userExponent = 2;
   printf("%d^%d = %d\n", userBase, userExponent, RaiseToPower(userBase, userExponent));

   return 0;
}
