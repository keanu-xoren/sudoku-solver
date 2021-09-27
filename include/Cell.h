#include <Possibility.h>

#ifndef CELL_H
#define CELL_H
class Cell {

protected:
    unsigned int _value;

public:
    virtual ~Cell() {};
    virtual bool solved() { return false; }
    virtual bool initialized_possibilities() { return true; }
    virtual unsigned int get_value() { return 0; }
    virtual void remove_current_possibility() = 0;

#ifdef CONFIG_DEBUG
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

public:
    UnknownCell();
    ~UnknownCell();
    unsigned int initialize_possibilities(unsigned int);
    void add_possibility(unsigned int);
    void remove_possibility(unsigned int);
    unsigned int * get_possibilities();
    bool initialized_possibilities();

    void remove_current_possibility();

#ifdef CONFIG_DEBUG
    void print();
#endif //CONFIG_DEBUG
};

/*  **********************************
    KNOWN CELLS

    Representation of a cell with an
    assigned value.

    ********************************** */
class KnownCell : public Cell {

public:
    KnownCell(unsigned int);
    KnownCell(UnknownCell &);


    unsigned int get_value() { return _value; }
    bool solved() { return true; }


    void remove_current_possibility();

#ifdef CONFIG_DEBUG
    void print();
#endif //CONFIG_DEBUG
};

#endif // CELL_H
