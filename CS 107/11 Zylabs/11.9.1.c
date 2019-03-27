#include<stdio.h>
#include<stdlib.h>

int win(char board[7][5], char player) {
   for (int i = 0; i < 7; i++) { 
      if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
         return 1;  
         
      } else if (board[i][1] == player && board[i][2] == player && board[i][3] == player) {
         return 1;
         
      } else if (board[i][2] == player && board[i][3] == player && board[i][4] == player) {
         return 1;
         
      }  
   }

   for(int j = 0; j < 5; j++) {
      if (board[0][j] == player && board [1][j] == player && board[2][j] == player) {
         return 1; 
         
      } else if (board[1][j] == player && board[2][j] == player && board[3][j] == player) {
         return 1;  
         
      } else if (board[2][j] == player && board[3][j] == player && board[4][j] == player) {
         return 1; 
      
      } else if (board[3][j] == player && board[4][j] == player && board[5][j] == player) {
         return 1;  
         
      } else if (board[4][j] == player && board[5][j] == player && board[6][j] == player) {
         return 1;  
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
