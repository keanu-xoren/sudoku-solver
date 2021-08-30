// #ifndef VALUE_MASK
// #define VALUE_MASK 0b0111111111
// #define ONE     0b0000000001
// #define TWO     0b0000000010
// #define THREE   0b0000000100
// #define FOUR    0b0000001000
// #define FIVE    0b0000010000
// #define SIX     0b0000100000
// #define SEVEN   0b0001000000
// #define EIGHT   0b0010000000
// #define NINE    0b0100000000
// #endif

#ifndef POSSIBILITY_H
#define POSSIBILITY_H
#include <Possibility.h>
#endif // POSSIBILITY_H

class Cell {

public:
    
};

class UnknownCell : public Cell {

protected:
    Possibility *_possibilePtr;

public:

    void add_possibility(unsigned int);
    // /*
    //     reduce_possible_values()
    //     Inputs:
    //         groupValues -> 9-bit number representing filled numbers of a group

    //     Outputs:
    //         n/a
    // */
    // void reduce_possible_values(unsigned int);

};

class EmptyCell : public UnknownCell {

};

class GuessedCell : public UnknownCell {
    //unsigned int _value;
};

class KnownCell : private Cell {

protected:
    unsigned int _value;

public:
    unsigned int get_value();
};

class GivenCell : public KnownCell {

public:
    GivenCell(unsigned int);
};

class SolvedCell : public KnownCell {

public:
    SolvedCell(unsigned int);
};
