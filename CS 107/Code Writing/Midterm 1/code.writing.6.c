/*
Use	the	rand()	function	to	“flip	a	coin” by	attributing	an	odd	number	to	
"heads" and	an	even number	to	"tails". Write	a	complete	C program	that	“flips	a	coin” N	times,	
where	N	is	input	from	the	keyboard.		Count	how	many	heads	and	tails	you	get,	and	output	the	
results	as	percentages.		For	example,	here’s	one	possible	output:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
   int numFlips;
   int seedVal;
   int rate;
   double heads;
   double tails;
   
   srand(time((time_t*)&seedVal));
   
   printf("How many times do you want to flip the coin?: \n");
   scanf("%d",&numFlips);
   
    
   for(int i = 0; i < numFlips; i++){
      rate = rand() % 2;
      
      if(rate == 0){
         heads++;
      
      } else{
         tails++;
      
      }
   }
   
   printf("Heads: %.1f%%\n", ((heads/(heads+tails))*100));
   printf("Tails: %.1f%%\n", ((tails/(heads+tails))*100));
   
   
   return 0;  
}
