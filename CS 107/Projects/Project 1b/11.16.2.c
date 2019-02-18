#include <stdio.h>

int main (void) {
   
   int numRows;
   int numCols;
   char seatNum;
   int takenSeatsOther;
   int takenSeatsComplicated;
   int check = 1;

   printf ("Enter number of rows: \n");				// Asks for user input for number of rows and stores this value under numRows..
   scanf ("%d", &numRows);
  
   if (numRows > 26) {						// Checks to see if user input for numRow is valid (numRows <= 26 && numRows > 0). If row is invalid, variable check becomes 0 and does not run the rest of the code.
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

   if (numCols > 30) {						// Checks to see if column is a valid number (numCols < 30 && numCols > 0) , else variable check becomes 0.
      printf("Too many seats per rows! Max. number of seats per row is 30. \n");
      check = 0;
	} else if (numCols <= 0) {
      printf ("Number of seats per rows must be at least 1.");
	   check = 0;
	}
   }
    
   if (check == 1) {						// If user input for row, column, and check value are valid, code proceeds as normal.
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
      for (int j = 1; j < numCols + 1; j++) {			// Creates this chart based on patterns of each row and column on each line.
      char seatNum = '@' + numRows;

   if (numRows % 2 == 0) {					// If the number of rows is even, then proceed. This is needed because the total number of rows can change depending on user input. If the numRows changes then the pattern changes; therefore, this function is needed to assess this issue.
	  if (i % 2 == 1) {					// If the current row is odd proceed.
	      if (j % 2 == 1) {					// If the row is odd and column is odd then print an "X" instead of a seat number. Based on every-other seating pattern.
		      printf (" X  ");
		      seatNum = seatNum - i;			// Sets the row letter for the specified condition. Since the seating chart starts at the user input (ex. K) then the seat number assess this issue by subtracting the userInput for numRows by the current row. Therefore, after each iteration, the compiler outputs the next row (ex. K -> J -> I).
		      takenSeatsOther++;			// If seat is taken then add +1 to takenSeatsOther. This functions adds up each seat that is taken by each iteration.
		} else {		            		
		      printf ("%c%02d ", seatNum - i, j);	// If column is not odd; therefore even then print seat number (row letter & column number).
		}
	 } else {						// If the number of rows is not even and therefore odd, then proceed.  
	  if (i % 2 == 0) {					// If the current row is even proceed.
	      if (j % 2 == 0) {					// If column is even and current row is even then print an "X" instead of a seat number.
		         printf (" X  ");
		         seatNum = seatNum - i;
		         takenSeatsOther++;
		    } else {					// If column is not even; therefore odd then print seat number (current row & current column).
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
