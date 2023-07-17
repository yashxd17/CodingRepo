#include <stdio.h>

#define N 8

int board[N][N];

void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_safe(int row, int col) {
    // Check if there is a queen in the same row
    for (int j = 0; j < col; j++) {
        if (board[row][j]) {
            return 0;
        }
    }

    // Check if there is a queen in the same diagonal (upper left)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    // Check if there is a queen in the same diagonal (lower left)
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    // No conflicts found, safe to place queen
    return 1;
}

int solve(int col) {
    // Base case: All queens have been placed
    if (col == N) {
        return 1;
    }

    // Try to place a queen in each row of the current column
    for (int row = 0; row < N; row++) {
        if (is_safe(row, col)) {
            board[row][col] = 1; // Place queen
            if (solve(col + 1)) { // Recurse to next column
                return 1; // Solution found
            }
            board[row][col] = 0; // Backtrack
        }
    }

    // No solution found
    return 0;
}

int main() {
    if (solve(0)) {
        printf("Solution found:\n");
        print_board();
    }
    else {
        printf("No solution found.\n");
    }

    return 0;
}
