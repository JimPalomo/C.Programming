/*
      Write the nothingInCommon() function, whose parameters include two one-dimensional arrays of integers,
      arr1[] and arr2[], with sizes size1 and size2, respectively. The function should return true if no two
      parallel elements in the arrays are the same. The function should return false in all other cases. The two arrays can
      have a different number of elements, where the extra elements in the longer array cannot possibly match the nonexistent elements in the other array. For example, when arr1 is {1, 2, 3, 4} and arr2 is {2, 3, 4, 5, 6}, there are
      no parallel element matches and the function should return true. Conversely, when arr1 is {1, 2, 3, 4} and arr2
      is {2, 3, 4, 4, 6}, there is a parallel element match at index 3, so the function should return false

      Write a main() function that tests your nothingInCommon() function. Perform the testing of your function by
      creating two test cases, the first should return true and the second should return false. Both test cases should involve
      a call to your function and clearly indicate the result of the function using output printed to the screen.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool nothingInCommon(int arr1[20], int size1, int arr2[20], int size2) {
   // Are they the same?
   int arraySize = size1;
   
   if (size2 > size1) {
      arraySize = size2;   
   }
   
   for(int i = 0; i < arraySize; i++) {
      if (arr1[i] == arr2[i]) {
         return 0;
      }
   }
   
   return 1;
}

int main() {
   int arrayOne[5] = {1, 2, 3, 4, 5};
   int arrayTwo[5] = {2, 3, 4, 5, 6};
   
   int check;
   
   check = nothingInCommon(arrayOne, 5, arrayTwo, 5);
   
   printf("%d", check);
   
   return 0;
}
   
