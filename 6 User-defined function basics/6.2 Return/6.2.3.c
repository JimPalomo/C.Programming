/*
        Define a function PyramidVolume with double parameters baseLength, baseWidth, and pyramidHeight, that returns as a double the volume of a pyramid with a rectangular base. Relevant geometry equations: 
        Volume = base area x height x 1/3 
        Base area = base length x base width. 
        (Watch out for integer division). 
*/

#include <stdio.h>

/* Your solution goes here  */
double PyramidVolume(double baseLength, double baseWidth, double pyramidHeight) {
     
     return (baseLength * baseWidth * pyramidHeight) / 3;
}

int main(void) {
   printf("Volume for 1.0, 1.0, 1.0 is: %f\n", PyramidVolume(1.0, 1.0, 1.0) );
   return 0;
}
