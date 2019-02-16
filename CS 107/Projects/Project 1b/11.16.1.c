#include <stdio.h>

int main(void) {
   int numRows;      // Row x Cols
   int numCols;
   char seatNum;
   int takenSeats;
   
   printf("Enter number of rows: \n");
   scanf("%d", &numRows);
   printf("Enter number of seats per row: \n");
   scanf("%d", &numCols);
   printf("\n");
   
   printf("Empty Classroom Seating Chart: \n");
    
    for(int i = 0; i < numRows; i++){                                // Creates an empty classroom
        for(int j = 1; j < numCols + 1; j++){
            char seatNum = '@' + numRows;
            
            printf("%c%02d ", seatNum - i, j);  
        }
        seatNum = seatNum + 1;
        printf("\n");
    }
   
   printf("\n");
   printf("Every other seating chart: \n");
   
    for(int i = 0; i < numRows; i++){                                // Creates an empty classroom
        for(int j = 1; j < numCols + 1; j++){
            char seatNum = '@' + numRows;
            
            if (i % 2 == 1) {                                        // Odd row
                if (j % 2 == 1) {                                    // Odd col
                    printf("%c%02d ", seatNum - i, j); 
                } else {                                             // Even Col
                    printf(" X ");
                    seatNum = seatNum - i;
                }
            } else {                  
                if (i % 2 == 0) {                                    // Even row
                    if (j % 2 == 0) {                                // Even col
                        printf("%c%02d ", seatNum - i, j); 
                    } else {                                         // Odd col
                        printf(" X ");
                        seatNum = seatNum - i;
                    }
                }
            }
            
        }
        seatNum = seatNum + 1;
        printf("\n");
    }
    
    takenSeats = ((numCols * numRows) / 2) + 1;
    printf("*%d students have seats in this arrangement*", takenSeats);
    printf("\n\n");
    printf("More-Complicated Seating Chart: \n");
   
   return 0;
}
