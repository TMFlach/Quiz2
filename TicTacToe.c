//Tic Tac Toe game between 2 players or player vs computer.
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

char board[3][3];
bool makeMove(int row, int col, char player);
void playerMove(char player);
void computerMove(char marker);
void displayBoard();
bool gameOver(char player);
void PVPGame();
void singleGame();

int main() {
    //prompt user for game they wish to play.
    char play = 'Y';
    while (play == 'y' || play == 'Y') {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        printf("Which game do you wish to play? 1. Single player 2. Two player.\n");
        //read information from console

        int select;
        scanf("%i", &select);
        //start a game vs players or vs computer based on input.
        printf("You entered %d\n", select);
        if(select == 1) {
            singleGame();
        } else if(select == 2) {
            PVPGame();
        }
        printf("Do you wish to play again? (y/n)\n");
        scanf(" %c", &play);
    }
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

void computerMove(char marker) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while(!makeMove(row, col, 'O'));
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
void PVPGame() {
    displayBoard();
    while(true) {
        playerMove('X');
        displayBoard();
        if(gameOver('X')) {
            break;
        }
        playerMove('O');
        displayBoard();
        if(gameOver('O')) {
            break;
        }
    }
}
//create function to run human vs random computer game.
void singleGame() {
    time_t t;
    srand((unsigned) time(&t));
    displayBoard();
    while(true) {
        playerMove('X');
        displayBoard();
        if(gameOver('X')) {
            break;
        }
        computerMove('O');
        displayBoard();
        if(gameOver('O')) {
            break;
        }
    }
}

//create function to check end game condition.
bool gameOver(char player) {
    //check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && 
            board[i][1] == player &&
            board[i][2] == player) {
                printf("Game Over. Player %c Wins!\n", player);
                return true;
            }
    }
    //check columns
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == player && 
            board[1][j] == player &&
            board[2][j] == player) {
                printf("Game Over. Player %c Wins!\n", player);
                return true;
            }
    }
    //check diagonals
    if((board[0][0] == player && // checks for \ diagonal.
        board[1][1] == player &&
        board[2][2] == player) ||
        (board[0][2] == player && // checks for / diagonal.
        board[1][1] == player &&
        board[2][0] == player)) {
            printf("Game Over. Player %c Wins!\n", player);
            return true;
        }
    //Check for draw.
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') { //if not a draw, continue game.
                return false;
            }
        }
    }
    //No winner and no moves left.
    printf("Game Over. Draw!\n");
    return true;
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
