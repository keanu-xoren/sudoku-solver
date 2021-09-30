#include <Cell.h>
#include <Encodings.h>
#include <assert.h>

#ifdef CONFIG_DEBUG
#include <iostream>
#endif // CONFIG_DEBUG

/*  ************
    Constructors
    ************ */
UnknownCell::UnknownCell() : _pPossibles(nullptr),  _solved(false) {
    _value = 0;
}

KnownCell::KnownCell(unsigned int inVal) { 
    _value = inVal;
}

/*  ***********
    Destructors
    *********** */
UnknownCell::~UnknownCell() {
    Possibility *next;

    if (_solved) {

    }

    while (_pPossibles) {
        next = _pPossibles->_pNext;
        delete _pPossibles;
        _pPossibles = next;
    }
    _pPossibles = next = nullptr;
}

/*  ******************
    operator overloads
    ****************** */
bool Cell::operator==(const Cell& other) {
    return _value == other._value;
}

/*  ***************
    private methods
    *************** */
void UnknownCell::add_possibility(unsigned int inVal) {

    if (!_pPossibles) { 
        _pPossibles = new Possibility(inVal, false);
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
    
    _pPossibles = _pPossibles->remove(toRemove);
}

void KnownCell::bad_access() {
    assert(0);
}

/*  **************
    public methods
    ************** */
unsigned int Cell::get_value() { return _value; }


bool UnknownCell::initialized() { return _pPossibles; }
bool KnownCell::initialized() { return true; }

bool UnknownCell::solved() { return _solved; }
bool KnownCell::solved() { return true; }

void UnknownCell::initialize_possibilities(unsigned int code) {

    unsigned int i = 0;
    while (code >> i) {
        if ((code >> i) & 0b01) {
            add_possibility(i+1);
        }
        i++;
    }
}

void KnownCell::initialize_possibilities(unsigned int) {
    return bad_access();
}

void UnknownCell::reduce_possibilities(unsigned int code) {

    unsigned int i = 0;
    while (code >> i) {
        if ((code >> i) & 0b01) {
            remove_possibility(i+1);
        }
        i++;
    }
}

void KnownCell::reduce_possibilities(unsigned int code) {
    return bad_access();
}

void UnknownCell::remove_current_possibility() {

    return;
}

void KnownCell::remove_current_possibility() {

    bad_access();
}

/*  ********************
    CONFIG_DEBUG methods
    ******************** */
#ifdef CONFIG_DEBUG
void UnknownCell::print() {
    std::cout << ' ';
}

void KnownCell::print() {
    std::cout << _value;
}

#endif // CONFIG_DEBUG

/*  *******************
    CONFIG_TEST methods
    ******************* */
#ifdef CONFIG_TEST
unsigned int* UnknownCell::get_possibilities() {

    unsigned int *values = new unsigned int[9];
    Possibility *ptr = _pPossibles;

    unsigned int i = 0;
    while (ptr) {

        values[i] = ptr->_encoding.value;
        i++;
        ptr = ptr->_pNext;
    }

    return values;
}

#endif // CONFIG_TEST
