/*
        Define a function CoordTransform() that transforms its first two input parameters xVal and yVal into two output parameters xValNew and yValNew. The function returns void. The transformation is new = (old + 1) * 2. Ex: If xVal = 3 and yVal = 4, then xValNew is 8 and yValNew is 10. 
*/

#include <stdio.h>

/* Your solution goes here  */
CoordTransform(int xVal, int yVal, int* xValNew, int* yValNew) {
   *xValNew = ((xVal + 1) * 2);
   *yValNew = ((yVal + 1) * 2);

}

int main(void) {
   int xValNew;
   int yValNew;

   CoordTransform(3, 4, &xValNew, &yValNew);
   printf("(3, 4) becomes (%d, %d)\n", xValNew, yValNew);

   return 0;
}
