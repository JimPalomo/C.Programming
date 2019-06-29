/*
      Write an expression that will cause the following code to print "Equal" if the value of sensorReading is "close enough" to targetValue. Otherwise, print "Not equal". Ex: If targetValue is 0.3333 and sensorReading is (1.0/3.0), output is:
      Equal
*/

#include <stdio.h>
#include <math.h>

int main(void) {
   double targetValue;
   double sensorReading;

   scanf("%lf", &targetValue);
   scanf("%lf", &sensorReading);

   if (fabs(sensorReading - targetValue) < 0.0001) {
      printf("Equal\n");
   }
   else {
      printf("Not equal\n");
   }

   return 0;
}
