#ifndef CELL_H
#define CELL_H
#include <Cell.h>
#endif // CELL_H

/* Class: Section
    Any combination of 9 cells that are related in some way
    
    Row:    9 continuous cells, moving from left to right
    Column: 9 continuous cells, moving from top to bottom
    Square: a 3x3 collection of cells
*/
class Section {

protected:
    Cell *cells[9];
    int _filledValues;

    void reduce_possibilities(Section*, Section*);

public:

    virtual void solve();
};

/* Class: ArraySection
    A representation of either a row or a column
*/
class ArraySection: public Section {

private:
    // ArraySection *_prev, *_next;
};

/* Class: SquareSection
    A representation of a 3x3 cell square
*/
class SquareSection: public Section {

private:
    // SquareSection *_up, *_down, *_left, *_right;
};
