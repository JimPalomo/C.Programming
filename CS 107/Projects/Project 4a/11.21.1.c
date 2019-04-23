// DEVELOP HEADER

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

void LocAdd(Location* headLoc, double newLong, double newLat, double newElev){
   //DEVELOP FUNCTIONALITY HERE
    
    Location* newLocation = (Location*)malloc(sizeof(Location));
    LocCreate(newLocation, newLong, newLat, newElev, NULL);
 
    Location* currLocation = headLoc;
    while (currLocation->next != NULL){
        currLocation = currLocation->next;
    }
    currLocation->next = newLocation;
    
}

int countLocs(Location* headLoc){
   //DEVELOP FUNCTIONALITY HERE
   int count = 1;
   
   // Transverse Linked List -- Not Finished
    Location* currLocation = headLoc;
   //  Location* prevLocation = headLoc; 
    
   while(currLocation->next != NULL) {
      // prevLocation = currLocation; 
      // currLocation = currLocation-> next;
      count++;
      currLocation = currLocation -> next;
   }
   
   // if (prevLocation != NULL) {
   //    prevLocation->next = NULL;
   //    count++;
   // }  
   
    return count;
}

void Location_PrintList(Location* headLoc){
    Location* currLocation = headLoc;
    while (currLocation != NULL){
       printf("%.1lf\n",currLocation->elevation);
       currLocation = currLocation->next;
    }
    printf("\n");
}

double findMaxElev(Location* headLoc){
   // DEVELOP FUNCTIONALITY HERE
   double max = 0.0;
   
   // Transverse Linked List -- Not Finished
    Location* currLocation = headLoc;
    
   while(currLocation != NULL) {
      if(currLocation->elevation > max) {
         max = currLocation->elevation;  
      }
      currLocation = currLocation -> next;

   }
   
    return max;
}

double LocsToDist(double lat1, double long1, double lat2, double long2){
   //DEVELOP FUNCTIONALITY HERE
   double d = 0;
   double pi = 3.14;
   
   lat1 = lat1 * pi/180;
   long1 = long1 * pi/180;
   lat2 = lat2 * pi/180;
   long2 = long2 * pi/180;
   
   d = RADIUS_EARTH * acos(cos(lat1)*cos(lat2)*cos(long2-long1) + sin(lat1)*sin(lat2));
   
   return d;
}

//WRITE THE FUNCTION
void convertTime(int totalSeconds, int *hours, int *minutes, int *seconds ) {
 
   *hours = totalSeconds / 3600;  

   *minutes = (totalSeconds - (*hours * 3600)) / 60;   

   *seconds = totalSeconds - (*hours * 3600) - (*minutes * 60);
   
   
 

   
}

int main() {
   //DEVELOP YOUR OWN TEST CASES HERE
   //DO NOT PASS TEST CASE #1!!! we will use the failed test case to see your output...
   
   // Location_PrintList( headLoc);
   
   // printf("");
   
    printf("\n\n");
    return 0;
}
