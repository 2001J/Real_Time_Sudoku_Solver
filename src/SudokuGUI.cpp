#include "SudokuGUI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

SudokuGUI::SudokuGUI() : selectedRow(-1), selectedCol(-1), isSolved(false), selectedDifficulty(EASY) {
    // Initialize with default difficulty
    initializeBoard(selectedDifficulty);
}

void SudokuGUI::initializeBoard(SudokuGUI::Difficulty difficulty) {
    int easyBoard[9][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int mediumBoard[9][9] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int hardBoard[9][9] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    switch (difficulty) {
        case EASY:
            std::copy(&easyBoard[0][0], &easyBoard[0][0] + 9 * 9, &board[0][0]);
            break;
        case MEDIUM:
            std::copy(&mediumBoard[0][0], &mediumBoard[0][0] + 9 * 9, &board[0][0]);
            break;
        case HARD:
            std::copy(&hardBoard[0][0], &hardBoard[0][0] + 9 * 9, &board[0][0]);
            break;
    }
}

bool SudokuGUI::isBoardFilled() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                return false;
            }
        }
    }
    return true;
}

void SudokuGUI::drawBoard(sf::RenderWindow &window) {
    window.clear(sf::Color::White);
    sf::Font font;
    if (!font.loadFromFile("Roboto-Regular.ttf")) { // Use the relative path to the font file
        std::cerr << "Failed to load font 'Roboto-Regular.ttf'" << std::endl;
        return;
    }

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            sf::Text text;
            text.setFont(font);
            text.setString(board[row][col] == 0 ? "" : std::to_string(board[row][col]));
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(col * 50 + 15, row * 50 + 10);
            window.draw(text);

            if (row == selectedRow && col == selectedCol) {
                sf::RectangleShape rect(sf::Vector2f(50, 50));
                rect.setPosition(col * 50, row * 50);
                rect.setFillColor(sf::Color(0, 0, 255, 50));
                window.draw(rect);
            }
        }
    }

    // Draw grid lines
    for (int i = 0; i <= 9; i++) {
        sf::Vertex line1[] = {
                sf::Vertex(sf::Vector2f(i * 50, 0)),
                sf::Vertex(sf::Vector2f(i * 50, 450))
        };
        sf::Vertex line2[] = {
                sf::Vertex(sf::Vector2f(0, i * 50)),
                sf::Vertex(sf::Vector2f(450, i * 50))
        };
        if (i % 3 == 0) {
            line1[0].color = sf::Color::Black;
            line1[1].color = sf::Color::Black;
            line2[0].color = sf::Color::Black;
            line2[1].color = sf::Color::Black;
        } else {
            line1[0].color = sf::Color(192, 192, 192);
            line1[1].color = sf::Color(192, 192, 192);
            line2[0].color = sf::Color(192, 192, 192);
            line2[1].color = sf::Color(192, 192, 192);
        }
        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
    }

    // Display solved message
    if (isSolved) {
        sf::Text solvedText;
        solvedText.setFont(font);
        solvedText.setString("Puzzle Solved!");
        solvedText.setCharacterSize(30);
        solvedText.setFillColor(sf::Color::Green);
        solvedText.setPosition(100, 200);
        window.draw(solvedText);
    }

    window.display();
}

void SudokuGUI::handleMouseClick(int x, int y) {
    if (!isSolved) {
        selectedRow = y / 50;
        selectedCol = x / 50;
    }
}

void SudokuGUI::handleKeyPress(sf::Keyboard::Key key) {
    if (!isSolved && selectedRow != -1 && selectedCol != -1) {
        if (key >= sf::Keyboard::Num1 && key <= sf::Keyboard::Num9) {
            board[selectedRow][selectedCol] = key - sf::Keyboard::Num0;
        } else if (key == sf::Keyboard::BackSpace) {
            board[selectedRow][selectedCol] = 0;
        } else if (key == sf::Keyboard::Enter) {
            if (isBoardFilled() && solver.solve(board)) {
                isSolved = true;
            }
        }
    }
}

void SudokuGUI::showMenu(sf::RenderWindow &window) {
    sf::Font font;
    if (!font.loadFromFile("Roboto-Regular.ttf")) { // Use the relative path to the font file
        std::cerr << "Failed to load font 'Roboto-Regular.ttf'" << std::endl;
        return;
    }

    sf::Text welcome("Welcome to Sudoku Solver", font, 30);
    welcome.setFillColor(sf::Color::Black);
    welcome.setPosition(50, 20);

    sf::Text title("Select Difficulty Level", font, 24);
    title.setFillColor(sf::Color::Black);
    title.setPosition(50, 80);

    sf::Text easy("1. Easy", font, 24);
    easy.setFillColor(sf::Color::Black);
    easy.setPosition(50, 150);

    sf::Text medium("2. Medium", font, 24);
    medium.setFillColor(sf::Color::Black);
    medium.setPosition(50, 200);

    sf::Text hard("3. Hard", font, 24);
    hard.setFillColor(sf::Color::Black);
    hard.setPosition(50, 250);

    window.clear(sf::Color::White);
    window.draw(welcome);
    window.draw(title);
    window.draw(easy);
    window.draw(medium);
    window.draw(hard);
    window.display();

    bool difficultySelected = false;
    while (!difficultySelected) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            } else if (event.type == sf::Event::MouseButtonPressed) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;

                if (mouseY >= 150 && mouseY < 180) {
                    selectedDifficulty = EASY;
                    difficultySelected = true;
                } else if (mouseY >= 200 && mouseY < 230) {
                    selectedDifficulty = MEDIUM;
                    difficultySelected = true;
                } else if (mouseY >= 250 && mouseY < 280) {
                    selectedDifficulty = HARD;
                    difficultySelected = true;
                }
            }
        }

        // Highlight the button when hovered over
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        if (mouseY >= 150 && mouseY < 180) {
            easy.setFillColor(sf::Color::Red);
        } else {
            easy.setFillColor(sf::Color::Black);
        }

        if (mouseY >= 200 && mouseY < 230) {
            medium.setFillColor(sf::Color::Red);
        } else {
            medium.setFillColor(sf::Color::Black);
        }

        if (mouseY >= 250 && mouseY < 280) {
            hard.setFillColor(sf::Color::Red);
        } else {
            hard.setFillColor(sf::Color::Black);
        }

        window.clear(sf::Color::White);
        window.draw(welcome);
        window.draw(title);
        window.draw(easy);
        window.draw(medium);
        window.draw(hard);
        window.display();
    }

    initializeBoard(selectedDifficulty);
}

void SudokuGUI::run() {
    sf::RenderWindow window(sf::VideoMode(450, 450), "Sudoku Solver");

    // Show the menu to select difficulty
    showMenu(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                handleMouseClick(event.mouseButton.x, event.mouseButton.y);
            } else if (event.type == sf::Event::KeyPressed) {
                handleKeyPress(event.key.code);
            }
        }
        drawBoard(window);
    }
}