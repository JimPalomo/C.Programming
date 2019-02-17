#include <stdio.h>

int
main (void)
{
  int numRows;			// Row x Cols
  int numCols;
  char seatNum;
  int takenSeats;
  int check = 1;

//  printf ("Enter number of rows: \n");
  scanf ("%d", &numRows);
  
  if (numRows > 26) {
        printf ("Too many rows! Max. number of rows is 26. \n");
        check = 0;
    } else if (numRows <= 0) {
        printf ("Number of rows must be at least 1. \n");
        check = 0;
    }
  
  
  if (check == 1) {
//      printf ("Enter number of seats per row: \n");
      scanf ("%d", &numCols);
      printf ("\n");

    if (numCols >= 30) {
	  printf("Too many seats per row! Max. number of seats per row is 30. \n");
	  check = 0;
	} else if (numCols <= 0) {
	  printf ("Number of seats per rows must be at least 1.");
	  check = 0;
	}
    }
    
  if (check == 1) {
  printf ("Empty Classroom Seating Chart: \n");

  for (int i = 0; i < numRows; i++)
    {				                                // Creates an empty classroom
      for (int j = 1; j < numCols + 1; j++)
	{
	  char seatNum = '@' + numRows;

	  printf ("%c%02d ", seatNum - i, j);
	}
      seatNum = seatNum + 1;
      printf ("\n");
    }

  printf ("\n");
  printf ("Every other seating chart: \n");

  for (int i = 0; i < numRows; i++)
    {				// Creates an empty classroom
      for (int j = 1; j < numCols + 1; j++)
	{
	  char seatNum = '@' + numRows;

	  if (i % 2 == 1)
	    {			// Odd row
	      if (j % 2 == 1)
		{		// Odd col
		  printf ("%c%02d ", seatNum - i, j);
		}
	      else
		{		// Even Col
		  printf (" X ");
		  seatNum = seatNum - i;
		  takenSeats++;
		}
	    }
	  else
	    {
	      if (i % 2 == 0)
		{		// Even row
		  if (j % 2 == 0)
		    {		// Even col
		      printf ("%c%02d ", seatNum - i, j);
		    }
		  else
		    {		// Odd col
		      printf (" X ");
		      seatNum = seatNum - i;
		      takenSeats++;
		    }
		}
	    }

	}
      seatNum = seatNum + 1;
      printf ("\n");
    }

  printf ("*%d students have seats in this arrangement*", takenSeats);
  printf ("\n\n");

  printf ("More-Complicated Seating Chart: \n");

  for (int i = 0; i < numRows; i++)
    {				// Creates an empty classroom
      for (int j = 1; j < numCols + 1; j++)
	{
	  char seatNum = '@' + numRows;

	  if (i % 3 == 1)
	    {			// 1st set row
	      if ((j % 4 == 2) || (j % 4 == 3))
		{
		  printf (" X ");
		  seatNum = seatNum - i;
		  takenSeats++;
		}
	      else
		{
		  printf ("%c%02d ", seatNum - i, j);
		}

	    }
	  else if (i % 3 == 2)
	    {	
	      if (j % 3 == 0)
		{	
		  printf ("%c%02d ", seatNum - i, j);
		}
	      else
		{
		  printf (" X ");
		  seatNum = seatNum - i;
		  takenSeats++;

		}

	    }
	  else
	    {
	      if (i % 3 == 0)
		{
		  if (j % 2 == 0)
		    {
		      printf (" X ");
		      seatNum = seatNum - i;
		      takenSeats++;
		    }
		  else
		    {
		      printf ("%c%02d ", seatNum - i, j);
		    }


		}
	    }

	}
      seatNum = seatNum + 1;
      printf ("\n");
    }
    
    if ((numRows % 2 == 1) && (numCols % 2 == 1)) {
        printf ("*%d students have seats in this arrangement*", (takenSeats / 2));
        printf ("\n\n");
    } else if ((numRows % 2 == 0) && (numCols % 2 == 1)) {
        printf ("*%d students have seats in this arrangement*", (takenSeats / 2));
    } else {
        printf ("*%d students have seats in this arrangement*", (takenSeats / 2) + 1);
        printf ("\n\n");
    }
}
  return 0;
}
