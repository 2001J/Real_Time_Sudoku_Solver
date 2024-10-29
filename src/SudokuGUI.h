//sudokuGUI.h
#ifndef REAL_TIME_SUDOKU_SOLVER_SUDOKUGUI_H
#define REAL_TIME_SUDOKU_SOLVER_SUDOKUGUI_H

#include <SFML/Graphics.hpp>
#include "SudokuSolver.h"

class SudokuGUI {
public:
    enum Difficulty { EASY, MEDIUM, HARD };
    SudokuGUI();
    void run();
private:
    void drawBoard(sf::RenderWindow &window);
    void handleMouseClick(int x, int y);
    void handleKeyPress(sf::Keyboard::Key key);
    void initializeBoard(Difficulty difficulty);
    void showMenu(sf::RenderWindow &window);
    bool isBoardFilled();
    SudokuSolver solver;
    int board[9][9];
    int selectedRow, selectedCol;
    bool isSolved;
    Difficulty selectedDifficulty;
};

#endif //REAL_TIME_SUDOKU_SOLVER_SUDOKUGUI_H
