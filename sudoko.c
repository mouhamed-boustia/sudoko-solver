#include <stdio.h>

int main() {
    int grid[9][9];
    int row, col, num;
    int emptyRow, emptyCol;
    int found;
    int i, j;
    int solved;

    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");

    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    printf("\nOriginal Sudoku:\n");
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }

    /* Backtracking */
    solved = 0;
    while (!solved) {
        found = 0;

        for (row = 0; row < 9 && !found; row++) {
            for (col = 0; col < 9 && !found; col++) {
                if (grid[row][col] == 0) {
                    emptyRow = row;
                    emptyCol = col;
                    found = 1;
                }
            }
        }

        if (!found) {
            solved = 1;
            break;
        }

        for (num = 1; num <= 9; num++) {
            int safe = 1;

            /* Check row */
            for (i = 0; i < 9; i++) {
                if (grid[emptyRow][i] == num) {
                    safe = 0;
                    break;
                }
            }

            /* Check column */
            for (i = 0; i < 9 && safe; i++) {
                if (grid[i][emptyCol] == num) {
                    safe = 0;
                    break;
                }
            }

            /* Check 3x3 box */
            for (i = (emptyRow / 3) * 3; i < (emptyRow / 3) * 3 + 3 && safe; i++) {
                for (j = (emptyCol / 3) * 3; j < (emptyCol / 3) * 3 + 3; j++) {
                    if (grid[i][j] == num) {
                        safe = 0;
                        break;
                    }
                }
            }

            if (safe) {
                grid[emptyRow][emptyCol] = num;
                break;
            }
        }

        if (num > 9) {
            grid[emptyRow][emptyCol] = 0;
            printf("\nNo solution exists.\n");
            return 0;
        }
    }

    printf("\nSolved Sudoku:\n");
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }

    return 0;
}
