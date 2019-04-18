/*
        Write a single statement that prints outsideTemperature with 2 digits in the fraction (after the decimal point). End with a newline. Sample output:
        103.46
*/

#include <stdio.h>

int main(void) {
   double outsideTemperature;

   outsideTemperature = 103.45632;

   /* Your solution goes here  */
   printf("%.2lf\n", outsideTemperature);

   return 0;
}
