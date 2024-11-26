# Real Time Sudoku Solver

A interactive Sudoku puzzle game and solver implemented in C++ using SFML graphics library. The application features multiple difficulty levels, real-time input validation, and an automatic solving capability.

## Features

- Interactive graphical user interface using SFML
- Three difficulty levels: Easy, Medium, and Hard
- Real-time number input and validation
- Automatic puzzle solving functionality
- Visual cell selection and highlighting
- Clean and intuitive design

## Prerequisites

To build and run this project, you need:

- C++ compiler with C++11 support or higher
- SFML library (version 2.5 or higher)
- CMake (version 3.10 or higher recommended)
- Roboto-Regular.ttf font file in the project directory

## Building the Project

1. Clone the repository:
```bash
git clone https://github.com/2001J/Real_Time_Sudoku_Solver.git
cd Real_Time_Sudoku_Solver
```

2. Follow the standard CMake build process:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## How to Play

1. Launch the application
2. Select a difficulty level from the menu:
    - Easy: More numbers filled in
    - Medium: Moderate number of filled cells
    - Hard: Minimal numbers provided

3. Game Controls:
    - Click on any cell to select it
    - Type numbers 1-9 to fill the selected cell
    - Press Backspace to clear a cell
    - Press Enter to solve the entire puzzle automatically

## Dependencies

- SFML Graphics Library
- Roboto Regular Font (for text rendering)

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the Apache License - see the LICENSE file for details.
