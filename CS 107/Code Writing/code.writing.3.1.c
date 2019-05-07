// Get sum in array

#include <stdio.h>

int getSum(int array[], int size) { // Size = size - 1 due to array

  if (size == 0) {
      return array[0];
  } else {
      printf("%d\n", array[size]);
      return array[size] + getSum(array, size-1);
  }

}

int main() {
  int myInts[5] = {1,3,8,12,16};
  printf("%d", getSum(myInts,4));


  return 0;
}
