/** ------------------------------------------------------
* This program uses data from the National Academy of  
* Engineering website  and determines which factors are true 
* based on the hability or inhability of several exoplanets.
* Class: CS 107, Spring 2019
* Author: Jim Palomo
* Date: Mar. 12, 2019
* -------------------------------------------------------- **/ 

//
//  TODO: this header, formatting, proper variable names, 
//        comment functions and main code blocks, etc.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <float.h>

//Global variables: DO NOT REMOVE, DO NOT MODIFY, DO NOT ADD ANY MORE
double const RADIUS_JUPITER = 43441.0; //miles
double const RADIUS_EARTH = 3959.0; //miles

// calcDistToStar: calculates planet distance to its star
// [in] starRadius: radius of star in units of Solar radii
// [in] planetRatio: ratio of (planet distance to star)/(star radius)
// [out] returns double: planet distance to star in units of AU
double calcDistToStar(double starRadius, double planetRatio){
   //TODO: write the code to obtain the required functionality for this function
   
   return starRadius * planetRatio / 215.0;                                                                                                                                                           // Returns planet distance in units of AU.
}

// countDataInInterval: "bins" the input data by counting entries in the specified interval
// [in] lowerBound: lower value of interval
// [in] upperBound: upper value of interval
// [in] data[size]: array of doubles to be binned (counted)
// [in] size: array size of data[]
// [out] returns int: count of values in data[] that fall in the specified interval
int countDataInInterval(double lowerBound, double upperBound, double data[], int size){
   //TODO: write the code to obtain the required functionality for this function
   int count = 0;
   
   for (int i = 0; i < size; i++) {    
      if ((data[i] >= lowerBound) && (data[i] <= upperBound)) {                                                                                                                                    // If the data value is between each habitable factors  
         count++;                                                                                                                                                                                  // If the data array (radius, orbital period, temperature, or distance) is within the bounds, variable count adds + 1 to itself to keep track of the number of planets that are in the bounds.
      }
   }
   
   return count;
}

// isItHabitable: apply conditions for "Habitable Exoplanet" to check if the planet is "habitable"
// [in] radius: planet radius (in miles)
// [in] orbitPer: orbital period for planet (in days)
// [in] temperature: equilibrium temperature of the planet (in K)
// [in] distance: to the star (in AU)
// [out] returns bool: true only if planet passes all the "habitable" tests, otherwise false

bool isItHabitable(double radius, double orbitPer, double temperature, double distance){
   //TODO: write the code to obtain the required functionality for this function
   
      if (((radius >= 792.6) && (radius <= 19815.0)) && ((orbitPer >= 91) && (orbitPer <= 801)) && ((temperature >= 183) && (temperature <= 294)) && ((distance >= 0.4) && (distance <= 2.35))) {       // Determines if the exoplanet is potentially habitable by agreeing with four factors (radius is [792.6-19815 Mi], orbital period [91-801 Days], temperature [183-294 Kelvin], distance [.4-2.35 AU].
         return true;                                                                                                                                                                                   // If all four factors of an exoplanet are met, then return true.
      } else {
         return false;                                                                                                                                                                                  // If any factor of an exoplanet is not met, then return false.
      }
   
}

//TODO: WRITE THE FUNCTION isItVeryUnhabitable(), 
//      which takes in identical input argruments 
//      (numebr, type, etc.) as isItHabitable()
//      (make sure to include a description similar
//      to those in the provided code template)

bool isItVeryUnhabitable(double radius, double orbitPer, double temperature, double distance){
   //TODO: write the code to obtain the required functionality for this function
  
      if (((radius < 792.6) || (radius > 19815.0)) && ((orbitPer < 91) || (orbitPer > 801)) && ((temperature < 183) || (temperature > 294)) && ((distance < 0.4) || (distance > 2.35))) {              // Determines if an exoplanet is very unhabitable if a factor is within the habitable range (habitable bounds is given in instructions and in comment above).
         return true;                                                                                                                                                                                  // If the factors exoplanet of an unhabitable exoplanet is met, then return true. 
      } else {
         return false;                                                                                                                                                                                 // If at least one factor of an exoplanet is considered habitable, then the planet is not considered very unhabitable; therefore, returning false.
      }
}

int main() {
// ~~~~~~~~~~~~~~ START OF PROVIDED TEMPLATE CODE ~~~~~~~~~~~~~~~~~~~`    
// DO NOT MODIFY THE PROVIDED TEMPLATE CODE
// instead, add your code in main() below the provided code.
// The following provided template code...
//   1) allows the user to enter an integer, np
//   2) reads in data from a file for np planets
//   3) stores the planet data in 7 arrays

    FILE *inFile = NULL; // File pointer
    const int n = 300;  //max. number of data
    const int m = 20;  //buffer size
    
    //Arrays to store planet info
    char planetNames[n][m];  //planet names
    int planetIDs[n]; //planet IDs (from NASA)
    double planetRadiiJ[n]; //planet radius (units: # of Jupiter radii)
    double planetOrbPeriod[n]; //planet orbital period (units: days)
    double starRadii[n]; //star radius (units: solar radii)
    double planetEqTemp[n]; //planet equilibrium temperature (units: K)
    double planetDistOverRadius[n]; //ratio (distance planet to star)/(star radius)
    
    int np = 0;
    printf("How many planets would you like to read in: ");
    scanf("%d",&np);
    int counter = 0;
    
    inFile = fopen("planets2.txt","r");
    if (inFile == NULL) {
        printf("Could not open file.\n");
        return -1; // -1 indicates error
    }
    while (counter < np){
        fscanf(inFile,"%d",&planetIDs[counter]);                                                                                                                                                       // Scans and obtains data from .txt file provided by instructor to fill arrays with data.
        fscanf(inFile,"%s",planetNames[counter]);
        fscanf(inFile,"%lf",&planetOrbPeriod[counter]);
        fscanf(inFile,"%lf",&planetRadiiJ[counter]);
        fscanf(inFile,"%lf",&starRadii[counter]);
        fscanf(inFile,"%lf",&planetEqTemp[counter]);
        fscanf(inFile,"%lf",&planetDistOverRadius[counter]);
        counter++;
    }
    
    fclose(inFile);
    
    
    // ~~~~~~~~~~~~~~ END OF PROVIDED TEMPLATE CODE ~~~~~~~~~~~~~~~~~~~`
    // **** Enter your code below this comment ****
    // TODO: implement calculations and functions calls to acheive the required programming tasks

   double planetDistToStar[300];
   double planetRadiiMi[300];
   int radiusCheck;
   int orbitalCheck;
   int tempCheck;
   int distToStarCheck;
   
   // Calculates planetDistToStar in mi.
      for(int i; i < np; i++) {
         planetDistToStar[i] = calcDistToStar(starRadii[i], planetDistOverRadius[i]);
      }
      
   // Converts planetRadii in J to Mi.
       for(int i; i < np; i++) {
          planetRadiiMi[i] = planetRadiiJ[i] * 43441;
       }
        
   // Calls the function countDataInterval based on each habitable factor which is given in an array. This is done to make the code more legible.
   radiusCheck = countDataInInterval(792.6, 19815.0, planetRadiiMi, np);
   orbitalCheck = countDataInInterval(91.0, 801.0, planetOrbPeriod, np);
   tempCheck = countDataInInterval(183.0, 294.0, planetEqTemp, np);
   distToStarCheck = countDataInInterval(0.4, 2.35, planetDistToStar, np);
   
   // Prints hability of planets by habilitable factors provided in comments above and in instructions.
   printf("\nTotal number of planets passing the radius check: %d\n", radiusCheck);
   printf("Total number of planets passing the orbital period check: %d\n", orbitalCheck);
   printf("Total number of planets passing the equilibrium temperature check: %d\n", tempCheck);
   printf("Total number of planets passing the distance to star check: %d\n\n", distToStarCheck);

   // Prints potential habitable planets and initializes checkHabitable to 0.
   printf("Potentially Habitable Planets: \n");
   int checkHabitable = 0;

   // Calls the function isItHabitable which determines if each planet is habitable by confirming four habitable checks of an exoplanet and prints out the planets name.
   for (int i; i < np; i++) {
      if (isItHabitable(planetRadiiMi[i], planetOrbPeriod[i], planetEqTemp[i], planetDistToStar[i])) {
         printf("%s\n", planetNames[i]); 
         checkHabitable++;                                                                                                                                                                           // Function keeps track of the number of habitable planets. The number of habitable exoplanets is then printed below.
      }
   }
  
   // Prints the number of habitable planets.
   printf("Total number of Potentially Habitable Planets: %d\n\n", checkHabitable);
   
   // Prints very unhabitable planets and initializes checkVeryUnhabitable to 0.
   printf("Very Unhabitable Planets: \n");
   int checkVeryUnhabitable = 0;

   // Calls the function isItVeryUnhabitable which determines if each planet is very unhabitable by checking four factors of unhabitablility and then prints the name of the planets
   for (int i = 0; i < np; i++) {
      if (isItVeryUnhabitable(planetRadiiMi[i], planetOrbPeriod[i], planetEqTemp[i], planetDistToStar[i])) {
         printf("%s\n", planetNames[i]); 
         checkVeryUnhabitable++;                                                                                                                                                                   // Function keeps track of the number of very unhabitable planets. The number of unhabitable exoplanets is then printed below.
      } 
   }
   
   // Prints the number of very unhabitable planets
   printf("Total number of Very Unhabitable Planets: %d\n", checkVeryUnhabitable);
       
   return 0;
}
