# Sudoku Solver #

C++ project to solve a Sudoku puzzle.

# Design #

## Cells ##

    class Cell {};

## Cell Groups ##

    class CellGrouping {};

### Rows & Columns ###

    class CellArray: public CellGrouping {};

### Squares ###

    class CellSquare: public CellGrouping {};

## Board ##

    class Board {};

# Testing #

# Personal Goals #
1. Brush up on C++ & Makefiles
2. Practice model-based approach to solve a problem (OOP).
3. Learn more advanced Sudoku solving algorithms