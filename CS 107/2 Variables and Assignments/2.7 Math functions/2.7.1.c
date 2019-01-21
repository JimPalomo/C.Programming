/*
      Determine the distance between point (x1, y1) and point (x2, y2), and assign the result to pointsDistance. The calculation is: 
      Ex: For points (1.0, 2.0) and (1.0, 5.0), pointsDistance is 3.0. 
*/

#include <stdio.h>
#include <math.h>

int main(void) {
   double x1;
   double y1;
   double x2;
   double y2;
   double xDist;
   double yDist;
   double pointsDistance;

   xDist = 0.0;
   yDist = 0.0;
   pointsDistance = 0.0;

   scanf("%lf", &x1);
   scanf("%lf", &y1);
   scanf("%lf", &x2);
   scanf("%lf", &y2);

   /* Your solution goes here  */
   double temp1 = (x2 - x1);
   double temp2 = (y2 - y1); 
   double temp1Power = pow(temp1, 2);
   double temp2Power = pow(temp2, 2);
   pointsDistance = sqrt(temp1Power + temp2Power);
   
   printf("%lf\n", pointsDistance);

   return 0;
}
