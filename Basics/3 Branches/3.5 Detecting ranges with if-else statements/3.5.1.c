/*
            Write an if-else statement with multiple branches. If givenYear is 2101 or greater, print "Distant future" (without quotes). Else, if givenYear is 2001 or greater (2001-2100), print "21st century". Else, if givenYear is 1901 or greater (1901-2000), print "20th century". Else (1900 or earlier), print "Long ago". Do NOT end with newline.
*/

#include <stdio.h>

int main(void) {
   int givenYear;

   scanf("%d", &givenYear);

   /* Your solution goes here  */
   if (givenYear >= 2101) {
      printf("Distant future");
   }
   else if (givenYear >= 2001) {
      printf("21st century");
   }
   else if (givenYear >= 1901) {
      printf("20th century");  
   }
   else if (givenYear <= 1900) {
      printf("Long ago");
   }
   return 0;
}
