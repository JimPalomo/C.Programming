// NOT FINISHED

#include <stdio.h>
#include <math.h>
#include <string.h>

// Struct Hill
typedef struct Hill_struct {
   char name[20];
   int xloc;
   int yloc;
   double height;
   double slope;
} Hill;

// Function setHill
Hill setHill(char hillName[20], int xlocation, int ylocation, double hillHeight, double hillSlope) {
   
   Hill currentHill;
   strcpy(currentHill.name, hillName);
   
   
   
   return currentHill;
  
}

int main() {
   double elev[14] = {0.0};
   int xi[5] = {12, 4, 6, 14, 1};
   int yi[5] = {9, 3, 13, 2, 9};
   double hi[5] = {20.0, 20.0, 15.0, 15.0, 10.0}; 
   double si[5] = {.25, .33, .33, .5, .5};
   
   // Creates an array hill and sets variables for each hill by calling setHill
   // Hill hillOne = setHill("Ada's Apex ", 12, 9, 20.0, .25);
   // Hill hillTwo = setHill("Turing's Top ", 4, 3, 20.0, .33);
   // Hill hillThree = setHill("Babbage's Bluff ", 6, 13, 15.0, .33);
   // Hill hillFour = setHill("Hopper's Hill ", 14, 2, 15.0, .5);
   // Hill hillFive = setHill("Katherine's Cliff ", 1, 9, 10.0, .5);
   
   //int array[19][15];
   
   int i, j, k;
   
   // Stores data in 2d Array (i = hill : j = x : k = y)
   for(i = 0; i < 1; i++) {
      for(j = 0; j < 19; j++) {
         for(k = 0; k < 15; k++) {
            printf("%4.1f",elev[j] += hi[i]*exp(-pow(si[i],2)*(pow((j-xi[i]),2) + pow((k-yi[i]),2))));
         }
      }
   }
   

      // for(j = 0; j < 19; j++) {
      //    for(k = 0; k < 15; k++) {
      //       printf(" %lf ", array[j][k]);
      //    }
      // }
   

   return 0;
}

