/*
         Using the CelsiusToKelvin function as a guide, create a new function, changing the name to KelvinToCelsius, and modifying the function accordingly. 
*/

include <stdio.h>

double CelsiusToKelvin(double valueCelsius) {
   double valueKelvin;

   valueKelvin = valueCelsius + 273.15;

   return valueKelvin;
}

/* Your solution goes here  */
  double KelvinToCelsius(double valueCelsius) {
   double valueKelvin = 0.0;
   
   valueKelvin = valueCelsius - 273.15;
   
   return valueKelvin;
}

int main(void) {
   double valueC;
   double valueK;

   valueC = 10.0;
   printf("%lf C is %lf K\n", valueC, CelsiusToKelvin(valueC));

   valueK = 283.15;
   printf("%lf is %lf C\n", valueK, KelvinToCelsius(valueK));

   return 0;
}
