cmake_minimum_required(VERSION 3.29)
project(real_time_sudoku_solver)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(real_time_sudoku_solver src/main.cpp
        src/SudokuGUI.cpp
        src/SudokuGUI.h
        src/SudokuSolver.cpp
        src/SudokuSolver.h)

target_link_libraries(real_time_sudoku_solver sfml-graphics sfml-window sfml-system)