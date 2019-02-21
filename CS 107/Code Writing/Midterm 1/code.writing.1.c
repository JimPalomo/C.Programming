/*
      (Code	Writing	1) The	Heat	Index is	what	the	temperature	feels	like	in	the	context	of	humidity.		For	
      example,	if	the	temperature	is	90° F	and	the	relative	humidity	is	70%,	then	it	feels	much	warmer	—
      closer	to	105° F.		Here’s	the	formula	for	computing	the	Heat	Index	HI:

      where	T is	the	temperature	in	° F	and	R is	the	relative	humidity	(a	percentage	
      in	the	range	0-100	inclusive).		Write	a	complete	C	program	that	inputs	a	
      temperature	T,	and	outputs	the	Heat	Index	for	the	relative	humidity	values	
      10,	20,	30,	…,	100.		Assume	the	constants	c1 through	c9 are	predefined	in	C,	
      so	you	can	simply	refer	to	these	by	name.		Also	assume	valid	input.
*/


#include <stdio.h>
#include <math.h>

int main()
{

   const double c1=0.01,c2=0.02,c3=0.03,c4=0.04,c5=0.05,c6=0.06,c7=0.07,c8=0.08,c9=0.09; 
   double T;
   double HI;
   
   scanf("%lf", &T);

   for (int R = 10; R == 100; R = R + 10) {
   
   HI = c1 + c2*T + c3*R + c4*T*R + c5*pow(T,2) + c6*pow(R,2) + c7*pow(T,2)*R + c8*T*pow(R,2) + c9*pow(T,2)*pow(R,2);
   
   printf("%d: %lf\n", R, HI);
   
}
   

    return 0;
}
