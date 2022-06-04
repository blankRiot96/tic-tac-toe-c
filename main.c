#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void replace_board(int board[][3], int input[], bool player) {
    int value;
    if (player) {
        value = 1;
    } else {
        value = 2;
    }
    board[input[0]][input[1]] = value;
}

int* obtain_input(bool player, int *input) {
    if (player) {
        printf("Player X's move: ");
    } else {
        printf("Player O's move: ");
    }

    int chance;
    scanf("%d", &chance);

    // Make sure chance is a valid input
    if (!(chance > 0 && chance < 10)) {
        printf("Input range out of bounds!");
        exit(1);
    }

    for (int i = 0; i < 9; i++) {
        if ((i + 1) == chance) {
            if (i < 3) {
                input[0] = 0;
            } else if (i < 6) {
                input[0] = 1;
            } else if (i < 9) {
                input[0] = 2;
            }
            input[1] = i % 3;
            break;
        }
    }

    return input;
}

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
    bool player = false;

    while (true) {
        player = !player;
        int flat_board[9];

        int index = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                flat_board[index] = board[i][j];
                index ++;
            }
        }
        draw_board(board);
        int input[2];
        int *input_ptr = obtain_input(player, input);
        replace_board(board, input_ptr, player);
    }
    return 0;
}

