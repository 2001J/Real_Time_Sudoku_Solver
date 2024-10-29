//SudokuSolver.h
#ifndef REAL_TIME_SUDOKU_SOLVER_SUDOKUSOLVER_H
#define REAL_TIME_SUDOKU_SOLVER_SUDOKUSOLVER_H

class SudokuSolver {
public:
    SudokuSolver();
    bool solve(int board[9][9]);
    static void printBoard(int board[9][9]);
private:
    static bool isSafe(int board[9][9], int row, int col, int num);
    static bool findEmptyLocation(int board[9][9], int &row, int &col);
};


#endif //REAL_TIME_SUDOKU_SOLVER_SUDOKUSOLVER_H
