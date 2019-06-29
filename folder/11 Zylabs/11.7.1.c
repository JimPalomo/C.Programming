/*
       11.7 Week 9 Lab: Functions
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNumAlpha(const char usrStr[]) {

int count=0;
int i = 0;

while(usrStr[i]!='\0') {

    if((usrStr[i]>='a' && usrStr[i]<='z') || (usrStr[i]>='A'&& usrStr[i]<='Z')) {

      count++;
    }
    i++;
}

return count;

}

char encodeChar(const char thisChar, const char thatChar, const char replaceChar) {

if (thisChar == thatChar){

    return replaceChar;

} else {

    return thisChar;

    }

}


void encodeString(char usrStr[]) {


for(int i = 0; i < strlen(usrStr); i++) {

    switch(usrStr[i]) {

      case '0':

      case '1':

      case '2':

      case '3':

      case '4':

      case '5':

      case '6':

      case '7':

      case '8':

      case '9':
      

        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '#');

        break;

      case 'O':
        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '0');
        
        break;

      case 'I':
        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '1');

        break;

      case 'Z':
        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '2');

        break;

      case 'E':
        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '3');

        break;

      case 'H':
        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '4');

        break;

      case 's':
        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '5');

        break;
        
      case 'b':
        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '6');

        break;
        
      case 'L':
        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '7');

        break;

      case 'B':
        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '8');

        break;

      case 'g':
        usrStr[i] = encodeChar(usrStr[i], usrStr[i], '9');

        break;

    }

}

}


// Main
int main(void) {

char usrStr[101];
int strLen;

printf("Enter a message: ");

fgets(usrStr, sizeof usrStr, stdin); // When sizeof() is used with the data types such as int, float, char… etc it simply return amount of memory is allocated to that data types. 

printf("You entered: %s", usrStr);  // https://www.geeksforgeeks.org/sizeof-operator-c/

int letter = getNumAlpha(usrStr);
printf("\n");

strLen = strlen(usrStr);

printf("Number of characters: %d", strLen);
printf("\n");

printf("Number of letters: %d", letter);

encodeString(usrStr);
printf("\n\n");

printf("Encoded message: %s\n", usrStr);

return 0;

}
