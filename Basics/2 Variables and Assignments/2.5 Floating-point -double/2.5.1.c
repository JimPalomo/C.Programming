/*
    Given sphereRadius and piVal, compute the volume of a sphere and assign sphereVolume with the result. Use (4.0 / 3.0) to perform floating-point division, instead of (4 / 3) which performs integer division.
    Volume of sphere = (4.0 / 3.0) π r3 (Hint: r3 can be computed using *) 
*/

#include <stdio.h>

int main(void) {
   double piVal = 3.14159;
   double sphereVolume;
   double sphereRadius;

   scanf("%lf", &sphereRadius);

   /* Your solution goes here  */
   sphereVolume = (4.0/3.0) * 3.14159265358979323846 * (sphereRadius * sphereRadius * sphereRadius);

   printf("%lf\n", sphereVolume);

   return 0;
}
