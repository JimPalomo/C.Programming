#include <stdio.h>

int main (void) {
   
   int numRows;
   int numCols;
   char seatNum;
   int takenSeatsOther;
   int takenSeatsComplicated;
   int check = 1;

   printf ("Enter number of rows: \n");				// Scans user values for number of rows.
   scanf ("%d", &numRows);
  
   if (numRows > 26) {						// Checks to see if user input for numRow is valid (valid rows <=26). If row is invalid, int check becomes 0 and does not run the rest of the code.
      printf ("Too many rows! Max. number of rows is 26. \n");
      check = 0;
   } else if (numRows <= 0) {
      printf ("Number of rows must be at least 1. \n");
      check = 0;
   }
  
  
   if (check == 1) {						// Checks to see if row is a valid number before proceeding to scan for the number of columns. 
      printf ("Enter number of seats per row: \n");
      scanf ("%d", &numCols);
      printf ("\n");

   if (numCols > 30) {						// Checks to see if column is a valid number, else check becomes 0.
      printf("Too many seats per rows! Max. number of seats per row is 30. \n");
      check = 0;
	} else if (numCols <= 0) {
      printf ("Number of seats per rows must be at least 1.");
	   check = 0;
	}
   }
    
   if (check == 1) {						// If user input for row and column are valid, code proceeds as normal.
      printf ("Empty Classroom Seating Chart: \n");

   for (int i = 0; i < numRows; i++) {				 // Creates Empty Classroom Seating Chart.
      for (int j = 1; j < numCols + 1; j++) {
         char seatNum = '@' + numRows;
         printf ("%c%02d ", seatNum - i, j);
	}
      seatNum = seatNum + 1;
      printf ("\n");
    }

  printf ("\n");
  printf ("Every-Other Seating Chart: \n");

   for (int i = 0; i < numRows; i++) {				// Creates an Every-Other Seating Chart.
      for (int j = 1; j < numCols + 1; j++) {			// Creates this chart based on every other pattern on each line.
      char seatNum = '@' + numRows;

   if (numRows % 2 == 0) {					// If the number of rows is even, then proceed.
	  if (i % 2 == 1) {					// If row is even proceed.
	      if (j % 2 == 1) {					// If column is odd then print an "X" instead of a seat number.
		      printf (" X  ");
		      seatNum = seatNum - i;
		      takenSeatsOther++;
		} else {		            		// If column is not odd; therefore even then print seat number.
		      printf ("%c%02d ", seatNum - i, j);
		}
	 } else {						// If the number of rows is not even and therefore odd, then proceed.  
	  if (i % 2 == 0) {					// If row is even proceed.
	      if (j % 2 == 0) {					// If column is odd then print an "X" instead of a seat number.
		         printf (" X  ");
		         seatNum = seatNum - i;
		         takenSeatsOther++;
		    } else {					// If column is not even; therefore odd then print seat number.
               printf ("%c%02d ", seatNum - i, j);
		    }
		}
	}
   } else {							// If the number of rows is not even; therefore odd then proceed.
	  if (i % 2 == 0) {					// If row is even then proceed.
	      if (j % 2 == 1) {					// If column is odd then print an "X" instead of a seat number.
		      printf (" X  ");
		      seatNum = seatNum - i;
		      takenSeatsOther++;
		} else {		         		// If column is not odd; therefore even then print seat number.
		      printf ("%c%02d ", seatNum - i, j);
		}
	 } else {
	      if (i % 2 == 1) {					// If row is odd and not even then proceed.
		      if (j % 2 == 0) {				// If column is even then print an "X" instead of a seat number.
		         printf (" X  ");
		         seatNum = seatNum - i;
		         takenSeatsOther++;
		    } else {					// If column is not even; therefore odd then print seat number.
               printf ("%c%02d ", seatNum - i, j);
		    }
		}
	}  
   }

	}
      seatNum = seatNum + 1;					// After each iteration, sets new row letter (ex. K > J > I > H > F > ...). 
      printf ("\n");
    }

   printf ("*%d students have seats in this arrangement*", takenSeatsOther);
   printf ("\n\n");

   printf ("More-Complicated Seating Chart: \n");

   for (int i = 0; i < numRows; i++) {				
      for (int j = 1; j < numCols + 1; j++) {
      char seatNum = '@' + numRows;
                               
	  if (i % 3 == 0) {			// B 
	     if (j % 3 == 0)  {
            printf ("%c%02d ", seatNum - i, j);
		} else {
            printf (" X  ");
		      seatNum = seatNum - i;
		      takenSeatsComplicated++;
		}

   } else if (i % 3 == 2) {	      // C
	      if ((j % 4 == 0) || (j % 4 == 1)) {	
            printf ("%c%02d ", seatNum - i, j);
	    	} else {
            printf (" X  ");
            seatNum = seatNum - i;
            takenSeatsComplicated++;
		}
	    } else {                  // A
         if (i % 3 == 1) {
		   if (j % 2 == 0) {
		      printf (" X  ");
		      seatNum = seatNum - i;
		      takenSeatsComplicated++;
		    } else {
		      printf ("%c%02d ", seatNum - i, j);
		   }
		}
	 }
   
	}
      seatNum = seatNum + 1;
      printf ("\n");
    }
    
    printf ("*%d students have seats in this arrangement*", takenSeatsComplicated);

}
  return 0;
}
