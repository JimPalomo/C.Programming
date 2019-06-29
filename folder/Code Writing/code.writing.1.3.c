/*
        (Code	Writing	3) Extension of previous problem… What	if	the	inputs	are	invalid?		Rewrite	the	
        Pythagorean	program	from	the	previous	page	to	compute	and	output	c only	if	both	inputs	are	
        positive.		If	either	input	is	0,	do	not	perform	the	computation	and	output	“Not	a	triangle!”	instead.		
        If	either	input	is	negative,	do	not	perform	the	computation	and	output	“Invalid	input!”	instead.		
        Your	program	should	produce	exactly	one	output:		either	c,	“Not	a	triangle!”,	or	“Invalid	input!”.		
        Rewrite	the	program	below,	do	not	refer	to	the	previous	page.			[	What if one input is 0 and the other
        is negative — which output should the program produce? Output “Invalid input!”. ]
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
   
   if (a == 0 || b == 0) {
      printf("Not a triangle!");  
   } else if (a < 0 || b < 0) {
      printf("Invalid input!");
   } else {
      c = sqrt(pow(a,2)+pow(b,2));
      printf("a: %.1lf \nb: %.1lf \nc: %.4lf \n", a, b, c);
   }

    return 0;
}
