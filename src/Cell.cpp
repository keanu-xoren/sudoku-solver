#ifndef CELL_H
#define CELL_H
#include <Cell.h>
#endif

/*  ************
    Constructors
    ************ */
GivenCell::GivenCell(unsigned int inVal) {
    _value = inVal;
}

SolvedCell::SolvedCell(unsigned int inVal) {
    _value = inVal;
}

/*  *****************
    UnknownCell methods
    ***************** */
void UnknownCell::add_possibility(unsigned int inVal) {

    _possibilePtr = new Possibility(inVal);
    // TODO: make an array 
}

/*  *****************
    KnownCell methods
    ***************** */
unsigned int KnownCell::get_value() {
    return _value;
}