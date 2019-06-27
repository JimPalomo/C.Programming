/*
          Write a function so that the main() code below can be replaced by the simpler code that calls function MphAndMinutesToMiles(). Original main(): 

          int main(void) {
             double milesPerHour = 70.0;
             double minutesTraveled = 100.0;

             double hoursTraveled;
             double milesTraveled;

             hoursTraveled = minutesTraveled / 60.0;
             milesTraveled = hoursTraveled * milesPerHour;

             printf("Miles: %lf\n", milesTraveled);

             return 0;
          }
*/

#include <stdio.h>

/* Your solution goes here  */
double MphAndMinutesToMiles(double milesPerHour, double minutesTraveled) {
   milesPerHour = milesPerHour / 60;
   minutesTraveled = minutesTraveled * milesPerHour;
   
   return milesPerHour, minutesTraveled;
}

int main(void) {
   double milesPerHour = 70.0;
   double minutesTraveled = 100.0;

   printf("Miles: %lf\n", MphAndMinutesToMiles(milesPerHour, minutesTraveled));

   return 0;
}Write a function so that the main() code below can be replaced by the simpler code that calls function MphAndMinutesToMiles(). Original main(): 

int main(void) {
   double milesPerHour = 70.0;
   double minutesTraveled = 100.0;

   double hoursTraveled;
   double milesTraveled;

   hoursTraveled = minutesTraveled / 60.0;
   milesTraveled = hoursTraveled * milesPerHour;

   printf("Miles: %lf\n", milesTraveled);

   return 0;
}
