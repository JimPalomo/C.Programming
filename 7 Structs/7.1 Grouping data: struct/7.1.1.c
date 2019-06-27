/*
    Define a struct named PatientData that contains two integer data members named heightInches and weightPounds. Sample output for the given program:
    Patient data: 63 in, 115 lbs
*/

#include <stdio.h>

typedef struct PatientData_struct {
   int heightInches;
   int weightPounds;
   
} PatientData;

int main(void) {
   PatientData lunaLovegood;

   lunaLovegood.heightInches = 63;
   lunaLovegood.weightPounds = 115;

   printf("Patient data: %d in, %d lbs\n", lunaLovegood.heightInches, lunaLovegood.weightPounds);

   return 0;
}
