/*
      Define a function UpdateTimeWindow() with parameters timeStart, timeEnd, and offsetAmount. Each parameter is of type int. The function adds offsetAmount to each of the first two parameters. Make the first two parameters pass by pointer. Sample output for the given program:
      timeStart = 3, timeEnd = 7
      timeStart = 5, timeEnd = 9
*/

#include <stdio.h>

// Define void UpdateTimeWindow(...)

/* Your solution goes here  */
void UpdateTimeWindow(int* timeStart, int* timeEnd, int offsetAmount) {
     *timeStart = *timeStart + offsetAmount;
     *timeEnd = *timeEnd + offsetAmount;
}

int main(void) {
   int timeStart;
   int timeEnd;
   int offsetAmount;

   timeStart = 3;
   timeEnd = 7;
   offsetAmount = 2;
   printf("timeStart = %d, timeEnd = %d\n", timeStart, timeEnd);

   UpdateTimeWindow(&timeStart, &timeEnd, offsetAmount);
   printf("timeStart = %d, timeEnd = %d\n", timeStart, timeEnd);

   return 0;
}
