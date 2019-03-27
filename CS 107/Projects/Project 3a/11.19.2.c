#include <stdio.h>
#include <math.h>
#include <string.h>

// Struct Hill
typedef struct Hill_struct {
   char name[20];
   int loc[2];
   double height;
   double slope;
} Hill;

// Function setHill
Hill setHill(char hillName[20], int xlocation, int ylocation, double hillHeight, double hillSlope) {
   
   Hill currentHill;
   strcpy(currentHill.name, hillName);
   
   currentHill.loc[0] = xlocation;
   currentHill.loc[1] = ylocation;
   currentHill.height = hillHeight;
   currentHill.slope = hillSlope;
   
   return currentHill;
  
}

int main() {
   double elev[19][15];
//    int xi[5] = {12, 4, 6, 14, 1};
//    int yi[5] = {9, 3, 13, 2, 9};
//    double hi[5] = {20.0, 20.0, 15.0, 15.0, 10.0}; 
//    double si[5] = {.25, .33, .33, .5, .5};
   
   // Creates an array hill and sets variables for each hill by calling setHill
   Hill newHill[5];
   
   newHill[0] = setHill("Ada's Apex ", 12, 9, 20.0, .25);
   newHill[1] = setHill("Turing's Top ", 4, 3, 20.0, .33);
   newHill[2] = setHill("Babbage's Bluff ", 6, 13, 15.0, .33);
   newHill[3] = setHill("Hopper's Hill ", 14, 2, 15.0, .5);
   newHill[4] = setHill("Katherine's Cliff ", 1, 9, 10.0, .5);
   
   //int array[19][15];
   
   int i, j, k;
   
   // Stores data in 2d Array (i = hill : j = x : k = y)
   for(i = 0; i < 5; i++) {
       for(k = 0; k < 15; k++) {
         for(j = 0; j < 19; j++) {
            elev[j][k] += newHill[i].height*exp(-pow(newHill[i].slope,2)*(pow((j-newHill[i].loc[0]),2) + pow((k-newHill[i].loc[1]),2)));
         }
      }
   }
   
   for(j = 19; j > 0; j--) {
      for(k = 15; k > 0; k--) {
         printf(" %4.1lf ", elev[j][k]);  
      }
   }
   
   return 0;
}
