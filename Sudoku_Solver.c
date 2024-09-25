#include <stdio.h>

int N = 9;
int iterations = 0;

void displaySudoku(int grid[9][9]) {

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
            if (((col + 1) % 3) == 0)
                printf("| "); 
        }
        printf("\n");
        if (((row + 1) % 3) == 0)
            printf("-----------------------\n"); 
    } 
    printf("\n");
}

int isNumberValid(int num, int row, int col, int grid[9][9]) {

    for (int i = 0; i < 9; i++) {
        if ((grid[row][i] == num) || (grid[i][col] == num))
            return 0;
    }

    int gridRow = row - row % 3;
    int gridCol = col - col % 3;

    for (int i = gridRow; i < (gridRow + 3); i++) {
        for (int j = gridCol; j < (gridCol + 3); j++) {
            if (grid[i][j] == num)
                return 0;
        }
    }
    
    return 1;
}

int solveSoduku(int grid[9][9]) {

    int isEmpty = 0;
    int row;
    int col;

    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                isEmpty = 1;
                break;
            }
        }
        if (isEmpty == 1)
            break;
    }

    if (isEmpty == 0)
        return 1;

    for (int num = 1; num <= 9; num ++) {
        if (isNumberValid(num, row, col, grid)) {
            grid[row][col] = num;
            iterations++;

            if (solveSoduku(grid) == 1)
                return 1;
            grid[row][col] = 0;
        }
    }

    return 0;
}

int main() {

    int grid[9][9] = {
    {0, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 6, 0, 0, 0, 0, 3},
    {0, 7, 4, 0, 8, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 3, 0, 0, 2},
    {0, 8, 0, 0, 4, 0, 0, 1, 0},
    {6, 0, 0, 5, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 7, 8, 0},
    {5, 0, 0, 0, 0, 9, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 4, 0}};

    printf("The input Sudoku puzzle:\n");
    displaySudoku(grid);
    
    if (solveSoduku(grid)) {
        printf("Solution found after %d iterations:\n", iterations);
        displaySudoku(grid);
    }
    
    else
        printf("No Solution exists.\n");
}