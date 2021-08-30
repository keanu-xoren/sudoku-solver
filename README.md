# Sudoku Solver #

C++ project to solve a Sudoku puzzle.

# Design #

## Cells ##

    class Cell {};

### Possibility ###

    class Possibility {};

## Sections ##

    class Section {};

### Rows & Columns ###

    class ArraySection: public Section {};

### Squares ###

    class SquareSection: public Section {};

## Board ##

    class Board {};

# Personal Goals #
1. Brush up on C++ & Makefiles
2. Practice model-based approach to solve a problem (OOP).
3. Learn more advanced Sudoku solving algorithms