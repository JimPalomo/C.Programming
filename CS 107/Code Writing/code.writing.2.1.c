/*
      The formula for computing windchill, where T is temperature and W is wind speed, is:
      windchill = 35.7 + 0.6T – 35.7W0.16 + 0.43TW0.16
      Write a function called windChill() that accepts T and W as parameters, and returns the computed windchill.
      Assume that the appropriate libraries have been included (i.e. #include <math.h> is at the top of the file).
      
      double windchill(double T, double W){

      }
      
      Write main(), which takes input from the user for the temperature and wind speed, calls the windChill()
      function above, and outputs the result. Assume all necessary libraries have been included at the top of the file. 
*/

#include <stdio.h>
#include <math.h>

double windChill(double T, double W) {
   int calculations;
   
   calculations = 35.7 + .6*T - 35.7*pow(W,.16) + .43*T*pow(W,.16);
   
   return calculations;
}

int main() {
   int check;
   check = windChill(90,5);
   
   printf("%d", check);
   
   return 0;
}
