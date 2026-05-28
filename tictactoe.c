#include <stdio.h>

char board[3][3];

void initializeBoard() {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    int i;
    for(i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
}

void playerMove(char mark) {
    int row, col;
    printf("Enter row (1-3) and column (1-3): ");
    scanf("%d %d", &row, &col);
    row--; col--;

    if (board[row][col] == ' ') {
        board[row][col] = mark;
    } else {
        printf("Cell already occupied! Try again.\n");
        playerMove(mark);
    }
}

int checkWin() {
    int i;
    for(i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    return 0;
}

void playGame() {
    int turn;
    initializeBoard();
    for(turn = 0; turn < 9; turn++) {
        displayBoard();
        if(turn % 2 == 0) {
            printf("Player 1 (X) move:\n");
            playerMove('X');
        } else {
            printf("Player 2 (O) move:\n");
            playerMove('O');
        }

        if(checkWin()) {
            displayBoard();
            printf("Player %d wins!\n", (turn % 2) + 1);
            return;
        }
    }
    displayBoard();
    printf("It's a draw!\n");
}

int main() {
    playGame();
    return 0;
}
