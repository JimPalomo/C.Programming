/*
      (Code	Writing	2) The	Pythagorean	
      theorem	states	that	given	a	right	triangle,	the	
      square	of	the	hypotenuse	c is	equal	to	the	sum	
      of	the	squares	of	the	other	two	sides	a and	b.		
      Solving for	the	hypotenuse.
      
      Write	a	C	program	that	inputs	a and	b,	solves	
      and	outputs	c.		For	example:		given	the	inputs	
      3.2	and	4.0,	the	output	is	5.1225.		  
*/

#include <stdio.h>
#include <math.h>

int main()
{

   double a;
   double b;
   double c;
   
   scanf("%lf", &a);
   scanf("%lf", &b);
   scanf("%lf", &c);

   c = sqrt(pow(a,2)+pow(b,2));
   
   printf("a: %.1lf \nb: %.1lf \nc: %.4lf \n", a, b, c);

    return 0;
}
