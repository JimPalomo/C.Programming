/** --------------------------------------------------
* This program displays a racer's data from Le Tour 
* de France which is recorded in a text file. Displayed 
* data includes: total length of time traveled, total 
* distance traveled, GPS data points (faulty / regular), 
* and elevation gained. 
* Class: CS 107, Spring 2019
* Author: Jim Palomo
* Date: May. 03, 2019
* ---------------------------------------------------- **/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

const double RADIUS_EARTH = 6368.0; //in km

typedef struct Location_struct {
   double longitude;
   double latitude;
   double elevation;
   struct Location_struct* next; //pointer to the next Location
} Location;

//Location Constructor
void LocCreate(Location* thisLoc, double thisLong, double thisLat, double thisElev, Location* nextLoc) {
   thisLoc->longitude = thisLong;
   thisLoc->latitude = thisLat;
   thisLoc->elevation = thisElev;
   thisLoc->next = nextLoc;
}

// Function adds a new node to the linked list and adds new data values (longitude, latitude, and elevation)
void LocAdd(Location* headLoc, double newLong, double newLat, double newElev){    
   Location* newLocation = (Location*)malloc(sizeof(Location));
   LocCreate(newLocation, newLong, newLat, newElev, NULL);
 
   Location* currLocation = headLoc;
   while (currLocation->next != NULL){
      currLocation = currLocation->next;
   }
   currLocation->next = newLocation;
}

int countLocs(Location* headLoc){
   // Sets count to 1 with the head node accounted for
   int count = 1;
   
   // Traverses the linked list by starting at the head node 
   Location* currLocation = headLoc;
   
   // Linked list is traversed and nodes are counted through the use of an increment count variable
   while(currLocation->next != NULL) {
      count++;
      currLocation = currLocation -> next;
   }
   
   return count;
}

// Function used to print linked lists
void Location_PrintList(Location* headLoc){
   Location* currLocation = headLoc;
    
   while (currLocation != NULL){
      printf("\t%.1lf m\n",currLocation->elevation);
      currLocation = currLocation->next;
   }
    
   printf("\n");
}

// Finds the max elevation out of each node in a linked list
double findMaxElev(Location* headLoc){
   double max = headLoc->elevation;
   
   // Transverse Linked List by starting at head node
   Location* currLocation = headLoc;
    
   // Linked List is traversed to find the maximum elevation stored in each node
   while(currLocation->next != NULL) {
      if(currLocation->elevation > max) {
         max = currLocation->elevation;  
      }
      currLocation = currLocation -> next;
   }
   
   return max;
}

// Function that calculates for the distance between two points of longitude and latitude
double LocsToDist(double lat1, double long1, double lat2, double long2){
   double d = 0;
   double pi = 3.14159265359;
   
   lat1 = lat1 * pi/180;
   long1 = long1 * pi/180;
   lat2 = lat2 * pi/180;
   long2 = long2 * pi/180;
   
   d = RADIUS_EARTH * acos(cos(lat1)*cos(lat2)*cos(long2-long1) + sin(lat1)*sin(lat2));
   
   
   return d;
}

// Function converts the total seconds traveled into its appropriate hours, minutes, and seconds representation
void convertTime(int totalSeconds, int *hours, int *minutes, int *seconds) {
 
   *hours = totalSeconds / 3600;  

   *minutes = (totalSeconds - (*hours * 3600)) / 60;   

   *seconds = totalSeconds - (*hours * 3600) - (*minutes * 60);
}

int main() {   
   // Declares all variables
   char file_name[25];
   char firstName[10];
   char lastName[10];
   char raceDate[10];
   char raceStage[10];
   char temp[10];
   int timeInt = 0;
   int regDPS = 0;
   int faultyDPS = 0;
   int hours = 0;
   int mins = 0;
   int secs = 0;
   int totalDPS;  
   double prevLong = 0.0;
   double prevLat = 0.0;
   double prevElev = 0.0;
   double newLong = 0.0;
   double newLat = 0.0;
   double newElev = 0.0;
   double maxElev = 0.0;
   double gainedElev = 0.0;
   double totalDist = 0.0;
   
   // Creates linked list
   Location* headLoc = NULL;  // Sets headLoc node to NULL for link list
   headLoc = (Location*)malloc(sizeof(Location));  // Allocates enough memory for headLoc
   LocCreate(headLoc, newLong, newLat, newElev, NULL);
   
   // Sets file pointer to null
   FILE *fp = NULL;
   
   // Scans for file name
   printf("Enter the filename:\n\n"); 
   scanf("%s", file_name);
   fp = fopen(file_name, "r"); // read mode
   
   // Tests if file is valid if not exit program completely
   if (fp == NULL)
   {
      printf("Could not open file.\n");
      exit(EXIT_FAILURE);
      return -1;
   }
      
   // Scans first 6 lines and places the data in a separate variable
   fscanf(fp, "%s %s", firstName, lastName);
   fscanf(fp, "%s %s", raceDate, raceStage);
   fscanf(fp, "%d", &timeInt);
   fscanf(fp, "%s %s %s", temp, temp, temp);    // Sets longitude, latitude, and elevation as a temp variable b/c no functionality is necessary for these strings
   
   // Scans for first longitude, latitude, and elevation and sets these values to the previous longitude, latitude, and elevation variables 
	fscanf(fp, "%lf %lf %lf", &newLong, &newLat, &newElev);	   
	   prevLong = newLong;
	   prevLat = newLat;
	   prevElev = newElev;

   // While loop to keep reading each line in .txt file until it reaches the end
   while(!(feof(fp))) {
	   
	   // Scans for new set of longitude, latitude, and elevation
	   fscanf(fp, "%lf %lf %lf", &newLong, &newLat, &newElev);	
      
      // Checks for faulty data and if faulty data persists, then count for the faulty data
      if(newElev < 0) {
         faultyDPS++;
      } 
      
      // If faulty data does not persist then continue first by incrementing regDPS (regular datapoints) by 1
      else {
         regDPS++;    
      
      // Checks for max variable
      if(newElev > maxElev) {
         maxElev = newElev;  
      }
      
      // Calculates for gained elevation if elevation gain occurs
      if(((newElev - prevElev) > 0) && (newElev - prevElev < 90000)) {
         gainedElev = gainedElev + (newElev - prevElev);
      }
      
      // Calculates for total distance traveled
      totalDist = totalDist + LocsToDist(newLat, newLong, prevLat, prevLong);
      
      // Adds new node to linked list for every new GPS data point
      LocAdd(headLoc, newLong, newLat, newElev);
   	
   	// Updates previous longitude, latitude, and elevation with new values of longitude, latitude, and elevation before looping again
   	prevLong = newLong;
   	prevLat = newLat;
   	prevElev = newElev;
	
      }
   }
   
   // Closes file
   fclose(fp); 
   
   // Creates totalDPS (DPS = datapoints) variable
   totalDPS = regDPS + faultyDPS + 1;  
   
   // Converts time given seconds
   convertTime((regDPS + faultyDPS) * timeInt, &hours, &mins, &secs);
   
   // Displays calculated information
   printf("Rider: %s %s\n", firstName, lastName);
   printf("Race: %s %s\n", raceDate, raceStage);
   printf("Time Interval is %d seconds\n\n", timeInt);
   
   printf("Total GPS Datapoints: %d\n", totalDPS);
   printf("Total Faulty GPS Datapoints: %d\n", faultyDPS);
   printf("Linked List Total GPS Datapoints: %d\n", countLocs(headLoc));
   printf("Total Time: %d s\n", timeInt* (regDPS + faultyDPS));
   printf("Max Elevation: %.1lf m\n", maxElev);
   printf("Linked List Max Elevation: %.1lf m\n", findMaxElev(headLoc));
   printf("Elevation Gained: %.1lf m\n", gainedElev);
   printf("Distance Biked: %.1lf km\n", totalDist);
   printf("Formatted Total Time: %02d:%02d:%02d\n", hours, mins, secs);

   return 0;
}
