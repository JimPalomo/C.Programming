/*
      Write an expression that continues to bid until the user enters 'n'. 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char keepGoing;
   int nextBid;

   srand(5);
   nextBid = 0;
   keepGoing = 'y';

   while (keepGoing != 'n') {
      nextBid = nextBid + (rand()%10 + 1);
      printf("I'll bid $%d!\n", nextBid);
      printf("Continue bidding? (y/n) ");
      scanf("%c", &keepGoing);
   }
   printf("\n");

   return 0;
}
