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

// Function which takes in 2 double parameters and returns the maximum elevation of the 2
double max2(double num1, double num2) {
   if (num2 > num1) {
      return num2;  
   }
   return num1;
}

// Function which takes in 4 double parameters and returns the maximum elevation of the 4
double max4(double num1, double num2, double num3, double num4) {
   double max12 = max2(num1, num2);
   double max34 = max2(num3, num4);
   
   double max1234 = 0.0;
   
   if(max12 > max34) {
      max1234 = max12;
   } else {
      max1234 = max34;
   }
   
   return max1234;
}

// Function which takes in 2 double parameters and returns the minimum elevation of the 2
double min2(double num1, double num2) {
   if (num2 < num1) {
      return num2;  
   }
   return num1;
}

// Function which takes in 4 double parameters and returns the minimum elevation of the 4
double min4(double num1, double num2, double num3, double num4) {
   double min12 = min2(num1, num2);
   double min34 = min2(num3, num4);
   
   double min1234 = 0.0;
   
   if(min12 < min34) {
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
   int xloc;
   int yloc;
   int userResponse;   
   int count = 0;
   double origElev = 0.0;
   
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
   
   
   // Scans for user input (x,y) to determine the elevation of which the user is at 
   printf("Enter your x-location (1-17): ");
   scanf("%d", &xloc);
   
   printf("Enter your y-location (1-13): ");
   scanf("%d", &yloc);
   
   // Stores user input of elevation to a temp variable
   origElev = elev[xloc][yloc];
   
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
   
   // Gathers user's response to hike up or down
   printf("Do you want to hike up or down? (1 = uphill, 2 = downhill): ");
   scanf("%d", &userResponse);
   
   printf("\n");
   
   // Going uphill if user enters 1 and downhill if user enters 2
   if (userResponse == 1) {
      
      // Uphill conditional while loop - while current elevation is less than the neighboring elevations keep looping
      printf("(%d,%d)   elev: %.4lf\n", xloc, yloc, elev[xloc][yloc]); 
      
      while(elev[xloc][yloc] < fabs(max4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1]))) {  
         
         // Conditional statements that occur if a neighboring elevation is picked. For example if the left elevation is greater than the current then xloc becomes x-coord moves 1 to the left 
         if (elev[xloc-1][yloc] ==  max4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1])) {
            elev[xloc][yloc] = elev[xloc-1][yloc];
            xloc = xloc - 1;
            printf("(%d,%d)   elev: %.4lf\n", xloc, yloc, elev[xloc][yloc]);  
            count++;
            
         } 
         
         else if (elev[xloc+1][yloc] ==  max4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1])) {
            elev[xloc][yloc] = elev[xloc-1][yloc];
            xloc = xloc + 1;
            printf("(%d,%d)   elev: %.4lf\n", xloc, yloc, elev[xloc][yloc]);   
            count++;
               
         } 
         
         else if (elev[xloc][yloc-1] ==  max4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1])) {
            elev[xloc][yloc] = elev[xloc][yloc-1];
            yloc = yloc - 1;
            printf("(%d,%d)   elev: %.4lf\n", xloc, yloc, elev[xloc][yloc]);   
            count++;
               
         } 
         
         else if (elev[xloc][yloc+1] ==  max4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1])) {
            elev[xloc][yloc] = elev[xloc][yloc+1];
            yloc = yloc + 1;
            printf("(%d,%d)   elev: %.4lf\n", xloc, yloc, elev[xloc][yloc]);   
            count++;
               
         }
      }
      
   } else {
      
      // Downhill conditional while loop - while current elevation is greater than the neighboring elevations keep looping
      printf("(%d,%d)   elev: %.4lf\n", xloc, yloc, elev[xloc][yloc]); 
      
      while(elev[xloc][yloc] > fabs(min4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1]))) {

         if (elev[xloc-1][yloc] ==  min4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1])) {
            elev[xloc][yloc] = elev[xloc-1][yloc];
            xloc = xloc - 1;
            printf("(%d,%d)   elev: %.4lf\n", xloc, yloc, elev[xloc][yloc]);  
            count++;
            
         } 
         
         else if (elev[xloc+1][yloc] ==  min4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1])) {
            elev[xloc][yloc] = elev[xloc-1][yloc];
            xloc = xloc + 1;
            printf("(%d,%d)   elev: %.4lf\n", xloc, yloc, elev[xloc][yloc]);   
            count++;
               
         } 
         
         else if (elev[xloc][yloc-1] ==  min4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1])) {
            elev[xloc][yloc] = elev[xloc][yloc-1];
            yloc = yloc - 1;
            printf("(%d,%d)   elev: %.4lf\n", xloc, yloc, elev[xloc][yloc]);   
            count++;
               
         } 
         
         else if (elev[xloc][yloc+1] ==  min4(elev[xloc-1][yloc],elev[xloc+1][yloc],elev[xloc][yloc-1],elev[xloc][yloc+1])) {
            elev[xloc][yloc] = elev[xloc][yloc+1];
            yloc = yloc + 1;
            printf("(%d,%d)   elev: %.4lf\n", xloc, yloc, elev[xloc][yloc]);   
            count++;
               
         } 

      }
   }
   
   printf("\nYou hiked %d squares, with elevation change %.4lf\n", count, elev[xloc][yloc] - origElev);
   
   // Checks where user hiked up or down to. Options are the peaks of hills, the ocean, or the bottom of a lake
   if (elev[xloc][yloc] == elev[12][9]) {
      printf("You hiked to the top of Ada's Apex!");  
      
   } 
   
   else if (elev[xloc][yloc] == elev[4][3]) {
      printf("You hiked to the top of Turing's Top!");
      
   } 
   
   else if (elev[xloc][yloc] == elev[6][13]) {
      printf("You hiked to the top of Babbage's Bluff!");
      
   } 
   
   else if (elev[xloc][yloc] == elev[14][2]) {
      printf("You hiked to the top of Hopper's Hill!");
      
   } 
   
   else if (elev[xloc][yloc] == elev[1][9]) {
      printf("You hiked to the top of Katherine's Cliff!");
      
   } 
   
   else if (elev[xloc][yloc] == elev[5][8]){  
      printf("Your hike ended at a lake on the island.");

   }
   
   else {
      
      printf("You hiked to the ocean.");
      
   }
      
   return 0;
}
