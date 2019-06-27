/*
      Simple geometry can compute the height of an object from the object's shadow length and shadow angle using the formula: tangent(angleElevation) = treeHeight / shadowLength. 
      1. Using simple algebra, rearrange that equation to solve for treeHeight. (Note: Don't forget tangent). 
      2. Complete the below code to compute treeHeight. For tangent, use the tan() function, described in the "math functions" link above. 
*/

#include <stdio.h>
#include <math.h>

int main(void) {
   double treeHeight;
   double shadowLength;
   double angleElevation;

   scanf("%lf", &angleElevation);
   scanf("%lf", &shadowLength);

   /* Your solution goes here  */
   treeHeight = shadowLength * tan(angleElevation);

   printf("%lf\n", treeHeight);

   return 0;
}
