/** -----------------------------------------------
* This program is created to allow the user to 
* approximate the distance between two coordinates, 
* gathers the time it takes to get from point A to 
* point B, and find the max elevation between each 
* location.
* Class: CS 107, Spring 2019
* Author: Jim Palomo
* Date: Apr. 26, 2019
* ------------------------------------------------- **/ 

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
   double max = 0.0;
   
   // Transverse Linked List by starting at head node
   Location* currLocation = headLoc;
    
   // Linked List is traversed to find the maximum elevation stored in each node
   while(currLocation != NULL) {
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
   
   printf("\n\t\t%d hours, %d minutes, %d seconds\n\n", *hours, *minutes, *seconds);

}

int main() {   
   // Test cases for testing the functionality of each function
   int hours = 0;
   int minutes = 0;
   int seconds = 0;
   
   Location* headLoc = NULL;  // Sets headLoc node to NULL for link list
   headLoc = (Location*)malloc(sizeof(Location));  // Allocates enough memory for headLoc
   
   // Creates and adds nodes to headLoc to create a linked list
   LocCreate(headLoc, 41.8781, 87.6298, 181.0, NULL); // Chicago
   LocAdd(headLoc, 43.0389, 87.9065, 188.0);   // Milwaukee
   LocAdd(headLoc, 43.6532, 79.3832, 76.5);   // Toronto, Canada
   LocAdd(headLoc, 51.5074, 0.1278, 11.0);   // London, England
   
   printf("Number of locations accounted for is %d.\n\n", countLocs(headLoc)); // Counts for number of of locations based on the nodes in link list

   printf("Longitude and Latitude of each location: \n");   // Displays longitude and latitude of each location
   printf("\tChicago: %.4lf° N, %.4lf° W\n", headLoc->latitude, headLoc->longitude);
   printf("\tMilwaukee: %.4lf° N, %.4lf° W\n", headLoc->next->latitude, headLoc->next->longitude);
   printf("\tToronto, Canada: %.4lf° N, %.4lf° W\n", headLoc->next->next->latitude, headLoc->next->next->longitude);
   printf("\tLondon, England: %.4lf° N, %.4lf° W\n\n", headLoc->next->next->next->latitude, headLoc->next->next->next->longitude);

   // Displays the distance from one location to another (in km) by using the LocsToDist function 
   printf("The distance from Chicago to Milwaukee, Toronto, and London: \n");
   printf("\tChicago to Milwaukee is %.4lf km\n", LocsToDist(41.8781, 87.6298, 43.0389, 87.9065)); // Chicago to Milwaukee    
   printf("\tChicago to Toronto, Canada is %.4lf km\n", LocsToDist(41.8781, 87.6298, 43.6532, 79.3832)); // Chicago to Toronto, Canada 
   printf("\tChicago to London, England is %.4lf km\n\n", LocsToDist(41.8781, 87.6298, 51.5074, 0.1278)); // Chicago to London, England
   
   // Calculates for the total time needed to reach each location
   printf("Time frame for traveling from one location to another: \n");
   printf("\tTime it takes to get to Milwaukee from Chicago by car: ");   // Chicago to Milwaukee
   convertTime (8160, &hours, &minutes, &seconds); 
   printf("\tTime it takes to get to Toronto, Canada from Chicago by plane: "); // Chicago to Toronto, Canada
   convertTime (6300, &hours, &minutes, &seconds); 
   printf("\tTime it takes to get to London, England from Chicago by plane: "); // Chicago to London, England
   convertTime (28200, &hours, &minutes, &seconds); 
   
   printf("\n");
   
   // Finds the max elevation between the each location by using the findMaxElev function
   printf("Max elevation among all locations is %.4lf meters!\n\n", findMaxElev(headLoc));
      
   // Prints link list based on the elevation subitem using Location_PrintList function
   printf("Printing Link List subitem | elevations: \n");
   Location_PrintList(headLoc); 
   
   return 0;
}
