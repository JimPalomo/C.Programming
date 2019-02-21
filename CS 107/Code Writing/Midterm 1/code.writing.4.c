/*
          (Code	Writing	4) Write	a	complete	C	program	to	input	two	integers	from	the	user,	and	output	
          every	other	integer	in	that	range,	inclusive.		For	example,	if	the	inputs	are	10	and	20,	then	your	
          program	should	output:
          10,	12,	14,	16,	18,	20
          If	the	inputs	are	11	and	20,	then	your	program	should	output:
          11,	13,	15,	17,	19
          Notice	that	the numbers	appear	on	the	same	line,	followed	by	a	comma,	except for	the	last	
          number	— the	last	number	is	*not*	followed	by	a	comma.		Assume	the	user	will	input	2	values	
          such	that	the	first	value	is	less	than	the	second	value.	
*/

#include <stdio.h>
#include <math.h>

int main()
{

   int a;
   int b;
   scanf("%d", &a);
   scanf("%d", &b);
   
      printf("%d, ", a);
      for (int i = a + 2; i < b; i = i + 2) {
         printf("%d, ", i);
      }
      printf("%d ", b);
      

      




    return 0;
}
