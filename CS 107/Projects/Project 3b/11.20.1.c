/** --------------------------------------------
* This program allows the user to navigate uphill
* or downhill on a topographic map created in 3a.
* The hiking path is determined by the elevation,
* whether the elevation is max or a min.
* Class: CS 107, Spring 2019
* Author: Jim Palomo
* Date: Apr. 11, 2019
* ---------------------------------------------- **/ 

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

// Function used to assign hill variables (later called in main)
Hill setHill(char hillName[20], int xlocation, int ylocation, double hillHeight, double hillSlope) {
   
   Hill currentHill;
   strcpy(currentHill.name, hillName);
   
   currentHill.loc[0] = xlocation;
   currentHill.loc[1] = ylocation;
   currentHill.height = hillHeight;
   currentHill.slope = hillSlope;
   
   return currentHill;
  
}

// Checkpoint 1-4

// Function which takes in 2 double parameters and returns the maximum value of the 2
double max2(double num1, double num2) {
   if (num2 > num1) {
      return num2;  
   }
   return num1;
}

// Function which takes in 4 double parameters and returns the maximum value of the 4
double max4(double num1, double num2, double num3, double num4) {
   double max12 = max2(num1, num2);
   double max34 = max2(num1, num2);
   
   double max1234 = 0.0;
   
   if(max12 > max34) {
      max1234 = max12;
   } else {
      max1234 = max34;
   }
   
   return max1234;
}

// Function which takes in 2 double parameters and returns the minimum value of the 2
double min2(double num1, double num2) {
   if (num2 < num1) {
      return num2;  
   }
   return num1;
}

// Function which takes in 4 double parameters and returns the minimum value of the 4
double min4(double num1, double num2, double num3, double num4) {
   double min12 = min2(num1, num2);
   double min34 = min2(num1, num2);
   
   double min1234 = 0.0;
   
   if(min12 > min34) {
      min1234 = min12;
   } else {
      min1234 = min34;
   }
   
   return min1234;
}




int main() {
   
   // Creates 2D Array to represent the topographic elevation map
   double elev[19][15];
   int i, j, k;
   
   // Creates array hill and sets variables for each hill by calling setHill function (data on hills is given by instructor)
   Hill newHill[5];
   
   newHill[0] = setHill("Ada's Apex ", 12, 9, 20.0, .25);
   newHill[1] = setHill("Turing's Top ", 4, 3, 20.0, .33);
   newHill[2] = setHill("Babbage's Bluff ", 6, 13, 15.0, .33);
   newHill[3] = setHill("Hopper's Hill ", 14, 2, 15.0, .5);
   newHill[4] = setHill("Katherine's Cliff ", 1, 9, 10.0, .5);
   
   // Assigns each value in elevation array to 0 (19 rows x 15 columns) 
   for(k = 0; k < 15; k++) {
      for(j = 0; j < 19; j++) {
         elev[j][k] = 0;
         
      }
   }
   
   // Calculates data within the 2D Array by using a given summation equation (i = hill : j = x : k = y). Done by setting up a triple loop (hill, rows, columns)
   for(k = 1; k < 14; k++) {
      for(j = 1; j < 18; j++) {
         for(i = 0; i < 5; i++) {
            elev[j][k] += newHill[i].height*exp(-pow(newHill[i].slope,2)*(pow((j-newHill[i].loc[0]),2) + pow((k-newHill[i].loc[1]),2)));
         }
      }
   }
   
   // // Prints stored data in the 2D Array (Not needed for part 3b)
   // printf("Elevations for Innovation Island:\n");
   // for(k = 14; k > -1; k--) {
   //    for(j = 0; j < 19; j++) {
   //       printf("%4.1lf ", elev[j][k]);

   //       if (j == 18) {
   //          printf("\n");
   //       }
   //    }
   // }
   
   // Scans for user input (x,y) to determine the elevation of which the user is at 
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
      
   } 
   
   else if (elev[xloc][yloc] == elev[4][3]) {
      printf("You are at the peak of Turing's Top!");
      
   } 
   
   else if (elev[xloc][yloc] == elev[6][13]) {
      printf("You are at the peak of Babbage's Bluff!");
      
   } 
   
   else if (elev[xloc][yloc] == elev[14][2]) {
      printf("You are at the peak of Hopper's Hill!");
      
   } 
   
   else if (elev[xloc][yloc] == elev[1][9]) {
      printf("You are at the peak of Katherine's Cliff!");
      
   } 
   
   else {
      printf("You are not at the peak of a hill.");
      
   }
   
   printf("\n\n");
   
   // Checkpoint 5
   int userResponse;   

   printf("Do you want to hike up or down? (1 = uphill, 2 = downhill)\n");
   scanf("%d", &userResponse);
   
   // Checkpoint 6
   
   // Going uphill
   double newCoord[19][15];
   // double newLoc[19][15];
   int newx;
   int newy;

   
   if (userResponse == 1) {
      for(i = 0; i < 15; i++) {
         for(j = 0; j < 19; i++) {
            newCoord[i][j] = max4(elev[i-1][j],elev[i+1][j],elev[i][j-1],elev[i][j+1]);
            newx = i;
            newy = j;
            printf("(%d,%d)   elev: %lf", newx, newy, newCoord[i][j]);
         }
      }
      
      // newCoord = max4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1]);

      
      // Needs fixing (fix i & j)
   //    if (newLoc[i][j] > elev[xloc][yloc]) {
   //       newLoc[i][j] == elev[xloc][yloc];
   //    }
         
   }
   
   
   
   return 0;
}
