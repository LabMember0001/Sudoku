#include <cstdio>

using namespace std;

int sudokuChecker(int board[9][9]) {
    // Check rows and columns
    for (int i = 0; i < 9; i++) {
        int rowCheck[10] = {0}; // Index 0 is unused
        int colCheck[10] = {0};

        for (int j = 0; j < 9; j++) {
            // Check row
            if (board[i][j] != 0) {
                if (rowCheck[board[i][j]] == 1) {
                    return 0;
                }
                rowCheck[board[i][j]]++;
            }

            // Check column
            if (board[j][i] != 0) {
                if (colCheck[board[j][i]] == 1) {
                    return 0;
                }
                colCheck[board[j][i]]++;
            }
        }
    }

    // Check 3x3 subgrids
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            int boxCheck[10] = {0}; // Index 0 is unused

            for (int i = row; i < row + 3; i++) {
                for (int j = col; j < col + 3; j++) {
                    if (board[i][j] != 0) {
                        if (boxCheck[board[i][j]] == 1) {
                            return 0;
                        }
                        boxCheck[board[i][j]]++;
                    }
                }
            }
        }
    }

    return 1;
}

// Main function
int main() {
    // Initialize the Sudoku
    int sudoku[9][9] = {
        {9, 6, 4, 0, 0, 7, 8, 0, 0},    // Row 1
        {0, 0, 8, 0, 0, 5, 6, 0, 0},    // Row 2
        {0, 0, 0, 0, 0, 0, 7, 9, 2},    // Row 3
        {0, 0, 0, 4, 2, 6, 0, 0, 7},    // Row 4
        {0, 4, 5, 8, 0, 9, 0, 3, 0},    // Row 5
        {0, 0, 0, 7, 5, 0, 0, 0, 0},    // Row 6
        {0, 9, 0, 0, 6, 0, 1, 0, 0},    // Row 7
        {0, 8, 3, 0, 7, 0, 0, 0, 4},    // Row 8
        {5, 0, 0, 0, 4, 1, 3, 0, 0}     // Row 9
    };

    if (sudokuChecker(sudoku) == 1) {
        printf("Sudoku solution\n");
    } else {
        printf("No solution\n");
    }
}
