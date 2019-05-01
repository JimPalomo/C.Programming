/*
      Enter a filename: 

      There were 16 values read in
      of which 15 postive, 0 negative, and 1 zero
      AND 9 even, 7 odd.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   // char ch;
   char file_name[25];
   int numList[17];
   
   int valCount = 0;
   int posCount = 0;
   int negCount = 0;
   int zeroCount = 0;
   int evenCount = 0;
   int oddCount = 0;
      
   int currInt = 0;
   int i = 0;
   
   FILE *fp;
   printf("Enter a filename:\n");
   scanf("%s", file_name);
 
   fp = fopen(file_name, "r"); // read mode
 
   if (fp == NULL)
   {
      printf("could not open file\n");
      exit(EXIT_FAILURE);
   }
 
   printf("\nFile %s includes:\n", file_name);
 
   // while((ch = fgetc(fp)) != EOF) {    // Prints file 
   //    printf("%c", ch);
   // }
   
   while(!(feof(fp))) {
      fscanf(fp, "%d ", &currInt);
      
      numList[i] = currInt;
      valCount++;
   
      if (numList[i] > 0) {
         posCount++;
      } 
      
      else if (numList[i] < 0){
          negCount++;
      }
      
      else if (numList[i] == 0) {
         zeroCount++;   
      } 
      
      
      if (numList[i] % 2 == 0) {
         evenCount++;  
      } 
      
      else if (numList[i] % 2 == 1) {
         oddCount++;
      }
   }
   
   valCount--;  
   evenCount--;
   zeroCount--;
   
   printf("\n");
   
   printf("There were %d values read in\n", valCount);
   
   printf("of which %d positive, %d negative, and %d zero\n", posCount, negCount, zeroCount);
   
   printf("AND %d even, %d odd.", evenCount, oddCount);
   
   fclose(fp);
   
   
   return 0;
}
