
#ifndef CELL_H
#define CELL_H
#include <Cell.h>
#endif

#ifndef VALUE_MASK
#define VALUE_MASK 0b0111111111
#define ONE     0b0000000001
#define TWO     0b0000000010
#define THREE   0b0000000100
#define FOUR    0b0000001000
#define FIVE    0b0000010000
#define SIX     0b0000100000
#define SEVEN   0b0001000000
#define EIGHT   0b0010000000
#define NINE    0b0100000000
#endif

/* Class: CellGrouping
    Any combination of 9 cells that are related in some way
    
    Row:    9 continuous cells, moving from left to right
    Column: 9 continuous cells, moving from top to bottom
    Square: a 3x3 collection of cells
*/
class CellGrouping {

private:
    Cell _cells[9];
    int _filledValues;


public:
    void findTuple(unsigned int);

    virtual CellGrouping* get_adjacent();
};

/* Class: CellArray
    A representation of either a row or a column
*/
class CellArray: public CellGrouping {

private:
    CellArray *_prev, *_next;
};

/* Class: CellGrouping
    A representation of a 3x3 cell square
*/
class CellSquare: public CellGrouping {

private:
    CellSquare *_up, *_down, *_left, *_right;
};
