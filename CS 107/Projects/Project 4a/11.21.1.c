/** --------------------------------------------
* This program is created to aid pre-define 
* a program for Project 4b. The function of the 
* program will allow the user to approximate the 
* distance between two coordinates of two cities. 
* Moreover allowing the user to get the time it 
* takes to get from one place to another. 
* Class: CS 107, Spring 2019
* Author: Jim Palomo
* Date: Apr. 11, 2019
* ---------------------------------------------- **/ 

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
      printf("%.1lf\n",currLocation->elevation);
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
   double pi = 3.14;
   
   lat1 = lat1 * pi/180;
   long1 = long1 * pi/180;
   lat2 = lat2 * pi/180;
   long2 = long2 * pi/180;
   
   d = RADIUS_EARTH * acos(cos(lat1)*cos(lat2)*cos(long2-long1) + sin(lat1)*sin(lat2));
   
   return d;
}

// Function converts the total seconds traveled into its appropriate hours, minutes, and seconds representation
void convertTime(int totalSeconds, int *hours, int *minutes, int *seconds ) {
 
   *hours = totalSeconds / 3600;  

   *minutes = (totalSeconds - (*hours * 3600)) / 60;   

   *seconds = totalSeconds - (*hours * 3600) - (*minutes * 60);
   
}

int main() {
   //DEVELOP YOUR OWN TEST CASES HERE
   //DO NOT PASS TEST CASE #1!!! we will use the failed test case to see your output...
   
   printf("\n\n");
   return 0;
}
