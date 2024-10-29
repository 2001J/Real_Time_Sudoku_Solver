#include "SudokuSolver.h"
#include <iostream>

SudokuSolver::SudokuSolver() {}

bool SudokuSolver::isSafe(int board[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num || board[x][col] == num ||
            board[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

bool SudokuSolver::findEmptyLocation(int board[9][9], int &row, int &col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool SudokuSolver::solve(int board[9][9]) {
    int row, col;
    if (!findEmptyLocation(board, row, col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solve(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void SudokuSolver::printBoard(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            std::cout << board[row][col] << " ";
        }
        std::cout << std::endl;
    }
}