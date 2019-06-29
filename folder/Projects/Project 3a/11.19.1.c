/** -----------------------------------------------
* This program creates a topographic elevation map
* based on the given data on several hills. (Note 
* Scale might be different based on display size)
* Class: CS 107, Spring 2019
* Author: Jim Palomo
* Date: Apr. 2, 2019
* ------------------------------------------------- **/ 

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
   int i, j, k;
   
   // Creates an array hill and sets variables for each hill by calling setHill
   Hill newHill[5];
   
   newHill[0] = setHill("Ada's Apex ", 12, 9, 20.0, .25);
   newHill[1] = setHill("Turing's Top ", 4, 3, 20.0, .33);
   newHill[2] = setHill("Babbage's Bluff ", 6, 13, 15.0, .33);
   newHill[3] = setHill("Hopper's Hill ", 14, 2, 15.0, .5);
   newHill[4] = setHill("Katherine's Cliff ", 1, 9, 10.0, .5);
   
   for(k = 0; k < 15; k++) {
      for(j = 0; j < 19; j++) {
         elev[j][k] = 0;
         
      }
   }
   
   // Stores data in 2d Array (i = hill : j = x : k = y)
   for(k = 1; k < 14; k++) {
      for(j = 1; j < 18; j++) {
         for(i = 0; i < 5; i++) {
            elev[j][k] += newHill[i].height*exp(-pow(newHill[i].slope,2)*(pow((j-newHill[i].loc[0]),2) + pow((k-newHill[i].loc[1]),2)));
         }
      }
   }
   
   // Prints stored data
   printf("Elevations for Innovation Island:\n");
   for(k = 14; k > -1; k--) {
      for(j = 0; j < 19; j++) {
         printf("%4.1lf ", elev[j][k]);

         if (j == 18) {
            printf("\n");
         }
      }
   }
   
   // Scans for user input (x,y)
   int xloc;
   int yloc;
   
   printf("Enter your x-location (1-17): ");
   scanf("%d", &xloc);
   
   printf("Enter your y-location (1-13): ");
   scanf("%d", &yloc);
   
   printf("\n");
   
   printf("The elevation for the point (%d,%d) is %.4lf\n", xloc, yloc, elev[xloc][yloc]);
   
   // Checks to see if user input (location) is at the peak of a hill
   if (elev[xloc][yloc] == elev[12][9]) {
      printf("You are at the peak of Ada's Apex!");  
      
   } else if (elev[xloc][yloc] == elev[4][3]) {
      printf("You are at the peak of Turing's Top!");
      
   } else if (elev[xloc][yloc] == elev[6][13]) {
      printf("You are at the peak of Babbage's Bluff!");
      
   } else if (elev[xloc][yloc] == elev[14][2]) {
      printf("You are at the peak of Hopper's Hill!");
      
   } else if (elev[xloc][yloc] == elev[1][9]) {
      printf("You are at the peak of Katherine's Cliff!");
      
   } else {
      printf("You are not at the peak of a hill.");
      
   }
   
   return 0;
}
