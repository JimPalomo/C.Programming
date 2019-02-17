// Broken

#include <stdio.h>

int main (void) {
   
   int numRows;
   int numCols;
   char seatNum;
   int takenSeatsOther;
   int takenSeatsComplicated;
   int check = 1;

   printf ("Enter number of rows: \n");
   scanf ("%d", &numRows);
  
   if (numRows > 26) {
      printf ("Too many rows! Max. number of rows is 26. \n");
      check = 0;
   } else if (numRows <= 0) {
      printf ("Number of rows must be at least 1. \n");
      check = 0;
   }
  
  
   if (check == 1) {
      printf ("Enter number of seats per row: \n");
      scanf ("%d", &numCols);
      printf ("\n");

   if (numCols > 30) {
      printf("Too many seats per rows! Max. number of seats per row is 30. \n");
      check = 0;
	} else if (numCols <= 0) {
      printf ("Number of seats per rows must be at least 1.");
	   check = 0;
	}
   }
    
   if (check == 1) {
      printf ("Empty Classroom Seating Chart: \n");

   for (int i = 0; i < numRows; i++) {				                                // Creates an empty classroom
      for (int j = 1; j < numCols + 1; j++) {
         char seatNum = '@' + numRows;
         printf ("%c%02d ", seatNum - i, j);
	}
      seatNum = seatNum + 1;
      printf ("\n");
    }

  printf ("\n");
  printf ("Every-Other Seating Chart: \n");

   for (int i = 0; i < numRows; i++) {				// Creates an empty classroom
      for (int j = 1; j < numCols + 1; j++) {
      char seatNum = '@' + numRows;

   if (numRows % 2 == 0) {
	  if (i % 2 == 1) {			// Odd row
	      if (j % 2 == 1) {		// Odd col
		      printf (" X  ");
		      seatNum = seatNum - i;
		      takenSeatsOther++;
		} else {		            // Even Col
		      printf ("%c%02d ", seatNum - i, j);
		}
	 } else {
	      if (i % 2 == 0) {		// Even row
		      if (j % 2 == 0) {		// Even col
		         printf (" X  ");
		         seatNum = seatNum - i;
		         takenSeatsOther++;
		    } else {		// Odd col
               printf ("%c%02d ", seatNum - i, j);
		    }
		}
	}
   } else {
	  if (i % 2 == 0) {			// Odd row
	      if (j % 2 == 1) {		// Odd col
		      printf (" X  ");
		      seatNum = seatNum - i;
		      takenSeatsOther++;
		} else {		            // Even Col
		      printf ("%c%02d ", seatNum - i, j);
		}
	 } else {
	      if (i % 2 == 1) {		// Even row
		      if (j % 2 == 0) {		// Even col
		         printf (" X  ");
		         seatNum = seatNum - i;
		         takenSeatsOther++;
		    } else {		// Odd col
               printf ("%c%02d ", seatNum - i, j);
		    }
		}
	}
      
      
      
      
      
   }

	}
      seatNum = seatNum + 1;
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
