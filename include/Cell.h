#ifndef CELL_H
#define CELL_H
#include <Possibility.h>

/*  **********************************
    CELLS

    Prototype class representing a
    single space in a Sudoku puzzle,
    eventually filled with a value.

    ********************************** */
class Cell {

protected:
    unsigned int _value;

    // struct CellValue {
    //     unsigned short value    : 4; // 00000000 0000xxxx
    //     unsigned short solved   : 1;
    //     unsigned short nPossible : 4
    // } _value;

public:
    virtual ~Cell() {};

    // inherited methods
    unsigned int get_value();

    // pure virtual methods
    virtual bool solved() = 0;
    virtual bool initialized() = 0;
    virtual unsigned int initialize_possibilities(unsigned int) = 0;
    virtual unsigned int reduce_possibilities(unsigned int) = 0;
    virtual void remove_current_possibility() = 0;
    

    


    // operator overloads
    virtual bool operator==(const Cell&);




#ifdef CONFIG_DEBUG
    // debug methods 
    virtual void print() = 0;
#endif //CONFIG_DEBUG    
};

/*  **********************************
    UNKNOWN CELLS

    Representation of a cell that has
    not yet been solved.

    ********************************** */
class UnknownCell : public Cell {

    Possibility *_pPossibles;
    bool _solved;

    void add_possibility(unsigned int);
    void remove_possibility(unsigned int);



public:
    UnknownCell();
    ~UnknownCell();

    bool initialized();
    bool solved();

    unsigned int initialize_possibilities(unsigned int);
    unsigned int reduce_possibilities(unsigned int);
    void remove_current_possibility();

#ifdef CONFIG_DEBUG
    void print();
#endif //CONFIG_DEBUG

#ifdef CONFIG_TEST

    unsigned int * get_possibilities();
#endif
};

/*  **********************************
    KNOWN CELLS

    Representation of a cell with an
    assigned value.

    ********************************** */
class KnownCell : public Cell {

public:
    KnownCell(unsigned int);

    bool solved();
    bool initialized();

    unsigned int initialize_possibilities(unsigned int);
    unsigned int reduce_possibilities(unsigned int);
    void remove_current_possibility();

#ifdef CONFIG_DEBUG
    void print();
#endif //CONFIG_DEBUG
};

#endif // CELL_H
