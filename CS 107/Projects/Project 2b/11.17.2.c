#include <stdio.h>

int main() {

   int numPlanets;
   int i;
   char planet[12][20] = {"Earth", "Mars", "Venus", "HAT-P-16", "K2-29", "KELT-4-A", "Kepler-421", "KOI-94", "Kepler-62", "Kepler-46", "PH2", "WASP-82"}; 
   double planetRadius[12] = {0.091135, 0.0475, 0.08465, 1.289, 1.19, 0.699, 0.371, 0.585, 0.144, 0.808, 0.903, 0.999};
   double starRadius[12] = {1.0, 1.0, 1.0, 1.24, 0.86, 1.6, 0.76, 1.52, 0.64, 0.79, 1.0, 0.59};
   double planetDistance[12] = {215.1, 327.8, 154.87, 7.7, 10.51, 5.792, 346.0, 43.1, 144.0, 45.1, 176.7, 12.63};
   
   // Gets user input for the number of planets to display
   printf("Enter the number of planets to categorize (max 12): ");
   scanf("%d", &numPlanets);
   printf("\n");
   
   // Prints out each of the planets based on the numPlanets the user enters
   for (i = 0; i < numPlanets; i++) {
      printf("%s ", planet[i]);
   }
   printf("\n\n");
   
   // Prints planet radii (in miles);
   printf("Planet Radii (in miles): \n");
   for (i = 0; i< numPlanets - 1; i++) {
      printf("%.0lf, ", planetRadius[i] * 43441);
   }
   printf("%.0lf ", planetRadius[i] * 43441);
   printf("\n\n");
   
   // Prints Planet by size histogram ------ Fix
   printf("Planets by size: \n");

   printf("<HalfEarth: ");
   for (i = 0; i < numPlanets; i++) {
      if (((planetRadius[i] * 43441) < (3959/2))) {
         printf("*");
      }
   }
   
   printf("\n    ~Earth: ");
   for (i = 0; i < numPlanets; i++) {
      if (((planetRadius[i] * 43441) > (3959/2)) && ((planetRadius[i] * 43441) < (3959*2))) {
         printf("*");
      }
   }
   
   printf("\n  <Jupiter: ");
   for (i = 0; i < numPlanets; i++) {
      if (((planetRadius[i] * 43441) > (3959*2)) && ((planetRadius[i] * 43441) < 43441)) {
         printf("*");
      }
   }
   
   printf("\n  >Jupiter: ");
   for (i = 0; i < numPlanets; i++) {
      if (((planetRadius[i] * 43441) > 43441)) {
         printf("*");
      }
   }
   printf("\n\n");
   
   // Prints planet distances to their stars (in AU)
   printf("Planet distances to their stars (in AU): \n");
   for (i = 0; i < numPlanets - 1; i++) {
      printf("%.3lf, ", planetDistance[i] * starRadius[i] / 215);
   }
   printf("%.3lf ", planetDistance[i] * starRadius[i] / 215);
   printf("\n");
  
  // Prints histogram for planets by distance to their stars
   printf("\nPlanets by distance to their stars: \n");
   printf("\n<HalfEarth: ");
   for (i = 0; i < numPlanets; i++) {
      if (((planetDistance[i] * starRadius[i] / 215) < .5)) {
         printf("*");
      }
   }
   
   printf("\n    ~Earth: ");
   for (i = 0; i < numPlanets; i++) {
      if (((planetDistance[i] * starRadius[i] / 215) > .5)  && ((planetDistance[i] * starRadius[i] / 215) < 2)) {
         printf("*");
      }
   }
   
   printf("\n  <Jupiter: ");
   for (i = 0; i < numPlanets; i++) {
      if (((planetDistance[i] * starRadius[i] / 215) > 2) && ((planetDistance[i] * starRadius[i] / 215) < 5.2)) {
         printf("*");
      }
   }
   
   printf("\n  >Jupiter: ");
   for (i = 0; i < numPlanets; i++) {
      if (((planetDistance[i] * starRadius[i] / 215) > 5.2)) {
         printf("*");
      }
   }
  
  
  return 0; 
}
