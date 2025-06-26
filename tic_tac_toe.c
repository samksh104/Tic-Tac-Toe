#include <stdio.h>

char board[3][3];
char current_marker;
int current_player;

void initializeBoard() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (slot < 1 || slot > 9 || board[row][col] != ' ') {
        return 0;
    }

    board[row][col] = current_marker;
    return 1;
}

int checkWinner() {
    // Rows & Columns
    for(int i = 0; i < 3; i++) {
        if ((board[i][0] == current_marker && board[i][1] == current_marker && board[i][2] == current_marker) ||
            (board[0][i] == current_marker && board[1][i] == current_marker && board[2][i] == current_marker)) {
            return 1;
        }
    }

    // Diagonals
    if ((board[0][0] == current_marker && board[1][1] == current_marker && board[2][2] == current_marker) ||
        (board[0][2] == current_marker && board[1][1] == current_marker && board[2][0] == current_marker)) {
        return 1;
    }

    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
        current_player = 2;
    } else {
        current_marker = 'X';
        current_player = 1;
    }
}

int main() {
    printf("TIC TAC TOE GAME\nPlayer 1 [X] --- Player 2 [O]\n");
    initializeBoard();

    current_marker = 'X';
    current_player = 1;

    int move_count = 0;
    while (move_count < 9) {
        printBoard();
        int slot;
        printf("Player %d, enter your move (1-9): ", current_player);
        scanf("%d", &slot);

        if (!placeMarker(slot)) {
            printf("Invalid move. Try again!\n");
            continue;
        }

        move_count++;

        if (checkWinner()) {
            printBoard();
            printf("Player %d wins!\n", current_player);
            return 0;
        }

        swapPlayerAndMarker();
    }

    printBoard();
    printf("It's a draw!\n");
    return 0;
}
