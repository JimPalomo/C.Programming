#include<stdio.h>
#include<stdlib.h>

int win(char board[7][5], char player) {
   
   for(int i = 0; i < 7; i++) { 
      for(int j = 0; j < 5; j++) {
         if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player) {
            return 1;  
         } else if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player) {
            return 1;  
         } 
      }
   }
   
   return 0;
}


int main() {

//initialize the array

char board[7][5];
int i,j;
char user;
int gameresult;

//read in the board 
printf("Enter 36 values for the 6x6 game board\n");
   for(i=0;i<7;i++){
     for(j=0;j<5;j++) {
         scanf("%c ",&(board[i][j]));
        }
   }
   
   // print the board
   for(i=0;i<7;i++){
     for(j=0;j<5;j++) {
         printf("%c ",(board[i][j]));
        }
        printf("\n");
   }


printf("Enter the uesr's token to see if they won the game!");
scanf("%c",&user);
printf("\n\n");

gameresult = win(board,user);

if (gameresult == 1) 
   printf("Player %c won the game!",user);
else if (gameresult == 0)
   printf("Player %c didn't win.",user);
else
   printf("invalid response from win()\n");
   


return 0;

}
