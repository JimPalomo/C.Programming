#include <stdio.h>
#include <stdbool.h>

//readData() function provided to read in data from user input (DO NOT REMOVE or MODIFY)
void readData(int data[], int size) {
    for (int i=0; i<size; ++i) {
        scanf("%d",&data[i]);
    }
}

//printData() function provided to print integer data array, 
//    reseving 4 spots for each int and a space in between (DO NOT REMOVE or MODIFY)
void printData(int data[], int size) {
    for (int i=0; i<size; ++i) {
        printf("%-4d ",data[i]);
    }
    printf("\n");
}

//LEVEL 1
bool checkData(int data[], int size, int badValue){
   for(int i = 0; i < size; i++) {
      if(data[i] == badValue) {
         return false;
      }
   }
   return true;
}

//developed for LEVEL 1, and extended in LEVELS 2 and 3
int fixData(int data[], int size, int badValue){   
   int i, j;

   int count = 0;
   
   for(i = 0; i < size; i++) {
      if(data[i] == badValue) {
         count++; 
      } 
      if(data[i] == data[i+1]) {
         return -1;
      } 
   }
   
   if(count == 0) {
      return 0; 
   } 
   if(data[0] == badValue && data[1] != badValue) {
      data[0] = data[1];
   }   

   if(data[size-1] == badValue && data[size-2] != badValue) {
      data[size-1] = data[size-2];
   }


   for(int i = 1; i < size-1; i++) {
      if(data[i] == badValue) {
         data[i] = (data[i-1] + data[i+1]) / 2;
      }
   }

      
   // if(data[1] == badValue) {
   //    data[1] = (data[0] + data[2]) / 2;
   // }
   
   // if(data[size] == badValue && data[size-1] != badValue) {
   //    data[size] == data[size -1]
   // }
   
   
   // if(count == size) {
   //    return 0;  
   // } else {
        
   // }
   
   // Return -1 if badValue is consecutive 
   // for(int i = 0; i < size; i++) {
   //    for(int j = i + 1; j < size; j++) {
   //       if(data[i] == data[j]) {
   //          return -1;
   //       }
   //    }
   // }
   

   return count;
} 

void printStars(int data[], int size, int badValue, char ast[]) {
   for(int i = 0; i < size; i++) {
      ast[i] = ' ';  
   }  
   
   if(data[0] == badValue && data[1] != badValue) {
      ast[0] = '*';
   }  
   
   if(data[size-1] == badValue && data[size-2] != badValue) {
      ast[size-1] = '*';
   }
   
   for(int i = 0; i < size; i++) {
   if(data[i] == badValue && i != size - 1 && i != 1) {
     ast[i] = '*';
   }
   
   }
   
}

int main() { 
    
    //start of provided code to read in data and print it
    int n;
    int temps[100];
    
    printf("Enter size of data: ");
    scanf("%d",&n);
    printf("\nEnter data: ");
    readData(temps,n);
    
    printf("\nInputted data: \n");
    printData(temps,n);
    //end of provided code to read in data and print it
    
    //DEVELOP YOUR main() CODE HERE
   int check;
   int fix;
   char star[100];
   
   check = checkData(temps, n, 9999);
   
   printStars(temps, n, 9999, star);
   

   if (check == false) {
      printf("Fixing Faulty Data...\n");
      printf("Fixed Data: \n");
      // fixData(temps, n, 9999);
   
      int adjacentCheck = fixData(temps, n, 9999);
   
      if (adjacentCheck == -1) {
         printf("Adjacent elements are faulty. Data cannot be fixed!");
         exit(0);
      
      }
      
   for(int i = 0; i < n; i++) {
      printf("%-4c ", star[i]);  
   }
      printData(temps, n);

   } else if (check == true) { 
         printf("No Faulty Data!\n"); 
         
   }
   
 
 
   // printData(temps, n);

   
   printf("\n");
   
   // int adjacentCheck = fixData(temps, n, 9999);
   
   // if (adjacentCheck == -1) {
   //    printf("Adjacent elements are faulty. Data cannot be fixed!");
   //    return 0;
   // }
   

   
   
   return 0;
}
