#ifndef CELL_H
#define CELL_H
#include <Cell.h>
#endif

#ifdef DEBUG
#include <iostream>
using namespace std;
#endif

Cell::Cell() {

    _value = 0;
    _possibleValues = VALUE_MASK;
}

Cell::Cell(unsigned int inVal) {

    _value = inVal;
    _possibleValues = 0;
}

unsigned int Cell::get_value() {

    return _value;
}

unsigned int Cell::get_possible_values() {


    return _possibleValues;
}

void Cell::set_value(unsigned int inVal) {

    _value = inVal;
    _possibleValues = 0;
}

void Cell::reduce_possible_values(unsigned int groupValues) {

    _possibleValues &= (~groupValues) & VALUE_MASK;

    if (!_possibleValues) {
        // TODO: contradiction found
    }

    switch (_possibleValues) {

        case ONE:
            this->set_value(1);
            break;
        case TWO:
            this->set_value(2);
            break;
        case THREE:
            this->set_value(3);
            break;
        case FOUR:
            this->set_value(4);
            break;
        case FIVE:
            this->set_value(5);
            break;
        case SIX:
            this->set_value(6);
            break;
        case SEVEN:
            this->set_value(7);
            break;
        case EIGHT:
            this->set_value(8);
            break;
        case NINE:
            this->set_value(9);
            break;
        default:
            break;
    }
}
