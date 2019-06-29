/*
        Write	a	complete	C	program	to	input	3	exam	scores,	drop	the	lowest	score,	
        and	output	the	average	of	the	remaining	2	scores.		For	example,	if	the	inputs	are	0,	100,	and	80,	the	
        average	is	90.0.		If	the	inputs	are	0,	0,	and	100,	the	average	is	50.0.		If	the	inputs	are	80,	90,	and	95,	
        the	average	is	92.5.
*/

#include <stdio.h>
#include <math.h>

int main()
{

   double test1;
   double test2;
   double test3;
   
   scanf("%lf", &test1);
   scanf("%lf", &test2);
   scanf("%lf", &test3);

   if ((test1 <= test2) && (test1 <= test3)) {
      printf("The average is: %.1lf", (test2 + test3) / 2);
      
   } else if ((test2 <= test1) && (test2 <= test3)) {
      printf("The average is: %.1lf", (test1 + test3) / 2);
   
   } else {
      printf("The average is: %.1lf", (test1 + test2) / 2);
   }



   return 0;
}
