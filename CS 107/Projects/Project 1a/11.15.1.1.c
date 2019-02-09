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
   
   char  userChar;
   int   userInt;

   printf("Enter the seat row letter: \n");
   scanf(" %c ", &userChar);
   
   if (userChar > 'K') {      // Checks row availability 
      printf("Not a valid row!\n");
   }
   
   printf("Enter the seat number: \n");
   scanf("%d", &userInt);
  
  if (userInt < 0 || userInt > 16) {   //Checks seat number
      printf("Not a valid seat number!\n");  
   }
   else if (userChar == 'A' || userChar == 'D' || userChar == 'J' || userChar == 'G') {
      
      if (userInt%2 == 0) {
         printf("Seat %c%d is open!", userChar, userInt); 
         
      } else {
         printf("Seat %c%d is taken!", userChar, userInt);
      }
   } 
   
   else if (userChar == 'B' || userChar == 'E' || userChar == 'H' || userChar == 'K') {
      if (userInt%3 == 0) {
         printf("Seat %c%d is open!", userChar, userInt); 
         
      } else {
         printf("Seat %c%d is taken!", userChar, userInt);
      }
   } 
   
   else if (userChar == 'C' || userChar == 'F' || userChar == 'I') {
      if (userInt == 1 || userInt == 4 || userInt == 5 || userInt == 8 || userInt == 9 || userInt == 12 || userInt == 13 || userInt == 16 ) {
         printf("Seat %c%d is open!", userChar, userInt); 
         
      } else {
         printf("Seat %c%d is taken!", userChar, userInt);
      }
   }
   
   return 0;
   
   }
