//Tic Tac Toe game between 2 players or player vs computer.
#include <stdio.h>
#include <stdbool.h>

char board[3][3] = {' ', ' ', ' ',
                    ' ', ' ', ' ',
                    ' ', ' ', ' '};
bool makeMove(int row, int col, char player);
void playerMove(char player);
void displayBoard();
bool gameOver(char player);


int main() {
    //prompt user for game they wish to play.
    printf("Which game do you wish to play? 1. Single player 2. Two player.\n");
    //read information from console

    //int select;
    //scanf("%i", &select);
    //printf("You entered %d", select);
    displayBoard();
    for(int i = 0; i < 3; i++) {
        playerMove('X');
        displayBoard();
    }
    gameOver('X');
    
    //start a game vs players or vs computer based on input.

    //display end game message. Win, lose, or tie.
    return 0;
}

void playerMove(char player) {
    int nextMove[2];
    do {
        printf("%c player:\n", player);
        printf("Make your move (0 - 2) (0 - 2): \n");
        scanf("%i %i", &nextMove[0], & nextMove[1]);
    } while (!makeMove(nextMove[0], nextMove[1], player));
}

//create function for reading player input format: #row #column
bool makeMove(int row, int col, char player) {
    if(board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    } else {
        return false;
    }
}
//create function to run 2 player game.

//create function to run human vs random computer game.

//create function to check end game condition.
bool gameOver(char player) {
    //check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && 
            board[i][1] == player &&
            board[i][2] == player) {
                printf("Game Over. Player %c Wins!", player);
                return true;
            }
    }
    //check columns
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == player && 
            board[1][j] == player &&
            board[2][j] == player) {
                printf("Game Over. Player %c Wins!", player);
                return true;
            }
    }
    //all checks failed
    return false;
}
//create function to display the board to player(s).
void displayBoard() {
    printf("-----------\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
        printf("-----------\n");
    }
}
