#ifndef POSSIBILITY_H
#define POSSIBILITY_H
#include <Possibility.h>
#endif 

#ifndef POSSIBILITY_ENCODINGS
// TODO: create encodings for specific patterns
// examples -> value is constrained to a row/column in a square
//          -> value only possible in 2 of 3 rows/columns in a square
//          -> value is part of a tuple (2 values are only possibilities in 2 cells in a group)


#endif // POSSIBILITY_ENCODINGS

Possibility::Possibility(unsigned int inVal) {

    _value = inVal;
    _encoding = 0;
    _pNext = nullptr;
    _pPrev = nullptr;
}

Possibility::~Possibility() {

    if (_pPrev) {
        _pPrev->_pNext = _pNext;
        _pNext = nullptr;
    }

    if (_pNext) {
        _pNext->_pPrev = _pPrev;
        _pPrev = nullptr;
    }

}

void Possibility::decode() {

}

void Possibility::push(unsigned int inVal) {
    Possibility *ptr = this;

    while (ptr->_pNext)
        ptr = ptr->_pNext;

    ptr->_pNext = new Possibility(inVal);
    ptr->_pNext->_pPrev = ptr;
}

#ifdef DEBUG
unsigned int Possibility::get_value() {

    return _value;
}

Possibility* Possibility::next() {

    return _pNext;
}

Possibility* Possibility::prev() {

    return _pPrev;
}

#endif 