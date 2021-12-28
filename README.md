# Sudoku Solver #

C++ project to solve a Sudoku puzzle.

# Design #

## Board ##
The main driving class of the solver. 
```c++
class Board {};
```


## Cells ##
A representation of a single cell on the puzzle board. For traditional 9x9 Sudoku board, there are 81 total cells.
```c++
    class Cell {};
```

## Possibility ##
A representation of a possible value for a cell  in a sudoku puzzle.
```c++
class Possibility {

    Possibility *_pNext;
    Possibility *_pPrev;
    struct Encoding { /* various bitfields */ } _encoding;

    void decode();

public:
    Possibility(unsigned int, bool);
    ~Possibility();

    /* 
    Inputs:
        inputValue_: (unsigned int) a number [1-9] of a possible value to add to the linked list

    Output:
        n/a

    Behavior:
        Dynamically allocates a Possibility with inputValue_ and adds it to the linked list.
        If the list is unsorted, the new Possibility is appended to the end of the list.
        If the list is sorted, the new Possibility is placed by increasing numerical value.
    */
    void push(unsigned int inputValue_);

    /* 
    Inputs:

    Output:

    Behavior:

    */
    Possibility* remove(unsigned int);

};
```



# Personal Goals #
1. Brush up on C++ & Makefiles
2. Practice model-based approach to solve a problem (OOP).
3. Learn more advanced Sudoku solving algorithms