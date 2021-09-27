#include <Encodings.h>

#ifndef POSSIBILITY_H
#define POSSIBILITY_H

// representation of a possible value in a sudoku cell
class Possibility {

    friend class UnknownCell;

public:
    Possibility *_pNext;
    Possibility *_pPrev;

private:

    unsigned int _value;

    struct Encoding {
        unsigned int rowPairedCell  : 3; // 00000000 00000000 00000000 00000xxx
        unsigned int rowPairExists  : 1; // 00000000 00000000 00000000 0000x000
        unsigned int colPairedCell  : 3; // 00000000 00000000 00000000 0xxx0000
        unsigned int colPairExists  : 1; // 00000000 00000000 00000000 x0000000
        unsigned int sqrPairedCell  : 3; // 00000000 00000000 00000xxx 00000000
        unsigned int sqrPairExists  : 1; // 00000000 00000000 0000x000 00000000 
        unsigned int rowLimited     : 1; // 00000000 00000000 000x0000 00000000
        unsigned int colLimited     : 1; // 00000000 00000000 00x00000 00000000
        unsigned int unused         : 18;// xxxxxxxx xxxxxxxx xx000000 00000000

        Encoding operator=(const int& rhs) {
            Encoding out;
            
            out.rowPairedCell = rhs & P_ROW_PAIRED_CELL;
            out.rowPairExists = (rhs & P_ROW_PAIR) >> 3;
            out.colPairedCell = (rhs & P_COL_PAIRED_CELL) >> 4;
            out.colPairExists = (rhs & P_COL_PAIR) >> 7;
            out.sqrPairedCell = (rhs & P_SQR_PAIRED_CELL) >> 8;
            out.sqrPairExists = (rhs & P_SQR_PAIR) >> 11;
            out.rowLimited = (rhs & P_ROW_PAIRED_CELL) >> 12;
            out.colLimited = (rhs & P_ROW_PAIRED_CELL) >> 13;
            out.unused = 0;

            return out;
        }

    } _encoding;

    void decode();

public:
    Possibility(unsigned int);
    ~Possibility();
    void push(unsigned int);

#ifdef CONFIG_TEST 
    // following methods are only for functionality testing
    unsigned int get_value();

    Possibility* next();
    Possibility* prev();
#endif // CONFIG_TEST
};

#endif // POSSIBILITY_H