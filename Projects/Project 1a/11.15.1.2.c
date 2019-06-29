/** -----------------------------------------------
* This program determines the availability of seats
* through use of if-statements, pattern recognition, 
* modular calculations
* Class: CS 107, Spring 2019
* Author: Jim Palomo
* Date: Feb. 5, 2019
* ------------------------------------------------- **/ 

/* 
         11.15.1: Project 1a - Finding Patterns in a Seating Chart
        
      Checks seat availability according to seating pattern on Zybooks
        ---------------------- Back of Classroom -----------------------
         X   X  K03  X   X  K06  X   X  K09  X   X  K12  X   X  K15  X  
        J01  X  J03  X  J05  X  J07  X  J09  X  J11  X  J13  X  J15  X  
        I01  X   X  I04 I05  X   X  I08 I09  X   X  I12 I13  X   X  I16 
         X   X  H03  X   X  H06  X   X  H09  X   X  H12  X   X  H15  X  
        G01  X  G03  X  G05  X  G07  X  G09  X  G11  X  G13  X  G15  X  
        F01  X   X  F04 F05  X   X  F08 F09  X   X  F12 F13  X   X  F16 
         X   X  E03  X   X  E06  X   X  E09  X   X  E12  X   X  E15  X  
        D01  X  D03  X  D05  X  D07  X  D09  X  D11  X  D13  X  D15  X  
        C01  X   X  C04 C05  X   X  C08 C09  X   X  C12 C13  X   X  C16 
         X   X  B03  X   X  B06  X   X  B09  X   X  B12  X   X  B15  X  
        A01  X  A03  X  A05  X  A07  X  A09  X  A11  X  A13  X  A15  X  
        ---------------------- Front of Classroom ----------------------
*/

#include <stdio.h>
#include <stdlib.h>

   int main () {
   
   char  rowLetter; 
   int   seatNumber;
   int   checkRow = 1;

   printf("Enter the seat row letter: \n");                                                                // Gather's user input for seat row letter
   scanf(" %c ", &rowLetter);
   
   if (rowLetter > 'K' || rowLetter == '!' || rowLetter == '@' || rowLetter == '#' || rowLetter == '$') {  // Determines validity of row, makes sure user input for row is A-K (also checks for first four symbols on the keyboard).
      printf("Not a valid row!\n");
      checkRow = 0;
   }
   
   if (checkRow == 1) {                                                                                    // Gather's user input for seat number only if the row input is valid (validity is indicated by checkRow == 1 ; true). (*Note: End bracket for the if-statement is at the end of the code, right before return 0;) 
      printf("Enter the seat number: \n");
      scanf("%d", &seatNumber);
   
  
  if (seatNumber <= 0 || seatNumber > 16) {                                                                // Validates seat number from user input, makes sure seat number is between 1-16
      printf("Not a valid seat number!\n");  
   }
         
   else if (rowLetter == 'A' || rowLetter == 'D' || rowLetter == 'J' || rowLetter == 'G') {               // If the rowLetter is a valid row, an if-statement initiates for A, D, J, or G from user input (rowLetter) 
      
      if (seatNumber%2 == 0) {                                                                            // If-statement determines if seat number is even, signifying unavailability of seats by molular operator (%2). Modular operator is based off of patterns of A, D, J, and G.
            if (seatNumber <= 9) {                                                                        // If-statement adds a 0 in front of an integer less than 10. A 0 in front of integer represents a seat number (ex. A01). 
               printf("Seat %c0%d is taken!", rowLetter, seatNumber);
            } else {                                                                                      // If the user input for seat number is >9, then the 0 is taken off from the inputted integer value
               printf("Seat %c%d is taken!", rowLetter, seatNumber); 
            }
      } else {
            if (seatNumber <= 9) {                                                                  
               printf("Seat %c0%d is open!", rowLetter, seatNumber);
            } else {
               printf("Seat %c%d is open!", rowLetter, seatNumber);                                 
            }
      }
   } 
   
   else if (rowLetter == 'B' || rowLetter == 'E' || rowLetter == 'H' || rowLetter == 'K') {              // If-statement initiates scan for B, E, H, or K only after scanning for A, D, J, G from user input (rowLetter) returns false.    
      
      if (seatNumber%3 == 0) {                                                                           // If-statement determines if seat number is divisible by 3, signifying unavailability of seats by molular operator (%3). If the seat number is divisible by 3, then the seat is open. Modular operator is based off of patterns of B, E, H, and K.
         if (seatNumber <= 9) {	                                                                           
               printf("Seat %c0%d is open!", rowLetter, seatNumber);
            } else {
               printf("Seat %c%d is open!", rowLetter, seatNumber);                                 
            }
      } else {
            if (seatNumber <= 9) {
               printf("Seat %c0%d is taken!", rowLetter, seatNumber);
            } else {
               printf("Seat %c%d is taken!", rowLetter, seatNumber);
            }
      }
   } 
   
   else if (rowLetter == 'C' || rowLetter == 'F' || rowLetter == 'I') {                                // If-statement initiates scan for C, F, or I after scanning for A, D, J, G, B, E, H, K from user input (rowLetter)
         
      if (seatNumber == 1 || seatNumber == 4 || seatNumber == 5 || seatNumber == 8 || seatNumber == 9 || seatNumber == 12 || seatNumber == 13 || seatNumber == 16 ) {         // If user inputs a number specified (1, 4, 5, 8, 9, 12, 13, 16) then the seat is open in rows C, F, and I. 
         if (seatNumber <= 9) {
            printf("Seat %c0%d is open!", rowLetter, seatNumber); 
         } else {
            printf("Seat %c%d is open!", rowLetter, seatNumber); 
         }
      } else {
         if (seatNumber <= 9) {
            printf("Seat %c0%d is taken!", rowLetter, seatNumber);
         } else {
            printf("Seat %c%d is taken!", rowLetter, seatNumber);  
         }
      }
   }
   
   }
   return 0;
   
   }
