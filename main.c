#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool all_three(int arr[]) {
    return (arr[0] == arr[1]) && (arr[1] == arr[2]);
}

bool is_in(int element, int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }

    return false;
}

bool check_win(int board[][3]) {
    // Checks if the board is in a win state!


    for (int i = 0; i < 3; i++) {
        // Check for rows
        if (!(is_in(0, board[i], 3)) && all_three(board[i])) {
            printf("Row win\n");
            return true;  
	}

        // Check for columns
        int cols[3] = {board[0][i], board[1][i], board[2][i]};
        if (!(is_in(0, cols, 3)) && all_three(cols)) {
            for (int jung; jung < 3; jung++) {
                printf("iteration number %d\n", jung);
                printf("%d", cols[jung]);
            }
            return true;
        }
    }

    // Check for topleft-bottomright diagonal
    int topleft_bottomright[3] = {board[0][0], board[1][1], board[2][2]};
    if (!(is_in(0, topleft_bottomright, 3)) 
        && all_three(topleft_bottomright)) {
        printf("Topleft bottomright win\n");
        return true;
    }
    // Check for topright-bottomleft diagonal
    int topright_bottomleft[3] = {board[0][2], board[1][1], board[2][0]}; 
    if (!(is_in(0, topright_bottomleft, 3))
        && all_three(topright_bottomleft)) {
        printf("Topright bottomleft win\n");
        return true;
    }

    return false;

}

void replace_board(int board[][3], int input[], bool player) {
    int value;
    if (player) {
        value = 1;
    } else {
        value = 2;
    }
    board[input[0]][input[1]] = value;
}

int *obtain_input(bool player, int *input, int flat_board[]) {
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

    if (flat_board[chance - 1] != 0) {
        printf("Piece already exists in that position!");
        exit(1);
    }

    // Make input after all checking is done
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
        int *input_ptr = obtain_input(player, input, flat_board);
        replace_board(board, input_ptr, player);

        if (check_win(board)) {
            if (player) {
                printf("Player X is the winner!\n");
            } else {
                printf("Player O is the winner!\n");                
            }

            draw_board(board);
            return 0;
        }

        if (!(is_in(0, flat_board, 9))) {
            printf("It's a tie!\n");
            draw_board(board);
            return 0;
        }
    }
    return 0;
}

