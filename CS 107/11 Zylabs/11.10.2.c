// Not Finished

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
         return 1;
      }
   }
   return 0;
}


//developed for LEVEL 1, and extended in LEVELS 2 and 3
int fixData(int data[], int size, int badValue){   
   int i, j;
   char ast[size];
   
   for(i = 0; i < size; i++) {
      ast[i] = ' ';  
   }
   
   for(int i = 1; i < size-1; i++) {
      if(data[i] == badValue) {
         data[i] = (data[i-1] + data[i+1]) / 2;
         ast[i] = '*';
      }
   }
   
   if(data[0] == badValue && data[1] != badValue) {
      data[0] = data[1];
   }
   
   if(data[size-1] == badValue && data[size-2] != badValue) {
      data[size-1] = data[size-2];
      ast[size-1] = '*';
   }
   
   for(int i = 0; i < size; i++) {
      for(int j = i + 1; j < size; j++) {
         if(data[i] == data[j]) {
            return -1;
         }
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
   
   check = checkData(temps, n, 9999);
   
   
   if (check == 1) {
      printf("Fixing Faulty Data...\n");
      printf("Fixed Data: \n");
      fixData(temps, n, 9999);
   
   } else if (check == 0) { 
      printf("No Faulty Data!\n"); 
   } 
   
   printData(temps, n);
   
   int adjacentCheck = fixData(temps, n, 9999);
   
   if (adjacentCheck == -1) {
      printf("Adjacent elements are faulty. Data cannot be fixed!");  
   }
   
   
   return 0;
}
