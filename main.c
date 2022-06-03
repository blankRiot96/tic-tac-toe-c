#include <stdio.h>

void draw_board(int board[][3]) {
    // The board size, is already known
    // In Tic Tac Toe, we have a board of dimension 3x3

    int index = 0;
    printf("+---+---+---+\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            index++;
            if (j == 0) {
                printf("|");
            }

            if (board[i][j] == 0) {
                printf( " %d |", index);
                continue;
            }

            char output;
            switch (board[i][j]) {
                case 1: 
                    output = 'X';
                    break;
                case 2:
                    output = 'O';
                    break;
            } 
            printf(" %c |", output);
        }
        printf("\n+---+---+---+\n");
    }
}

int main() {
    int board[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    
    draw_board(board);
    return 0;
}

