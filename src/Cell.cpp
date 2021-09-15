#ifndef CELL_H
#define CELL_H
#include <Cell.h>
#endif

#ifdef CONFIG_DEBUG

#include <iostream>

#endif //CONFIG_DEBUG

/*  ************
    Constructors
    ************ */
UnknownCell::UnknownCell() {
    _pPossibles = nullptr;
}

KnownCell::KnownCell(unsigned int inVal) {
    _value = inVal;
}

/*  ***********
    Destructors
    *********** */
UnknownCell::~UnknownCell() {
    
    Possibility *next;
    while (_pPossibles) {
        next = _pPossibles->_pNext;
        delete _pPossibles;
        _pPossibles = next;
    }
    _pPossibles = next = nullptr;
}
/*  *******************
    UnknownCell methods
    ******************* */
void UnknownCell::add_possibility(unsigned int inVal) {

    if (!_pPossibles) { 
        _pPossibles = new Possibility(inVal);
        return;
    }
    
    return _pPossibles->push(inVal);
}

void UnknownCell::remove_possibility(unsigned int toRemove) {

    if (!_pPossibles) { 
        // TODO: probably some error to report
        //       return for now..
        return;
    }
    
    Possibility *pPoss;
    pPoss = _pPossibles;

    // reassign head, if necessary
    if (_pPossibles->_value == toRemove) {
        
        _pPossibles = _pPossibles->_pNext;

        pPoss->_pNext = nullptr;
        delete pPoss;
        return;
    }

    // otherwise, delete specific node
    while (pPoss) {
        if (pPoss->_value == toRemove) {
            delete pPoss;
        }
        pPoss = pPoss->_pNext;
    }


}

unsigned int* UnknownCell::get_possibilities() {

    unsigned int *values = new unsigned int[9];
    Possibility *ptr = _pPossibles;

    unsigned int i = 0;
    while (ptr) {

        values[i] = ptr->_value;
        i++;
        ptr = ptr->_pNext;
    }

    return values;
}

#ifdef CONFIG_DEBUG

void UnknownCell::print() {
    std::cout << ' ';
}

#endif //CONFIG_DEBUG

/*  *****************
    KnownCell methods
    ***************** */
unsigned int KnownCell::get_value() {
    return _value;
}

#ifdef CONFIG_DEBUG

void KnownCell::print() {
    std::cout << _value;
}

#endif //CONFIG_DEBUG