# Sudoku Solver in C

This repository contains a simple Sudoku solver implemented in C. The program uses a backtracking algorithm to solve a hardcoded Sudoku puzzle. It showcases basic C programming concepts and algorithm design.

## Features

- Hardcoded Sudoku puzzle input.
- Backtracking algorithm to find a solution.
- Displays both the input puzzle and the solution.

## Prerequisites

- C compiler (e.g., `gcc` or `clang`)

## Input Format

Before compiling, you need to enter the Sudoku puzzle in the `main` function of the code. The Sudoku puzzle should be a 9x9 grid represented as a 2D array, where:
- `0` represents an empty cell.
- Numbers `1` to `9` are the Sudoku values.

### Example Hardcoded Puzzle

You can modify the following grid in `main`:

```c
int grid[9][9] = {
    {0, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 6, 0, 0, 0, 0, 3},
    {0, 7, 4, 0, 8, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 3, 0, 0, 2},
    {0, 8, 0, 0, 4, 0, 0, 1, 0},
    {6, 0, 0, 5, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 7, 8, 0},
    {5, 0, 0, 0, 0, 9, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 4, 0}
};
