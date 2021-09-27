#include <Cell.h>
#include <Encodings.h>

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
void delete_possibilities(Possibility *head) {
    Possibility *next;

    while (head) {
        next = head->_pNext;
        delete head;
        head = next;
    }
    head = next = nullptr;
}

UnknownCell::~UnknownCell() {

    delete_possibilities(_pPossibles);
    _pPossibles = nullptr;
}

/*  *******************
    UnknownCell methods
    ******************* */

unsigned int UnknownCell::initialize_possibilities(unsigned int possibleCode) {

    unsigned int numPossibles = 0;

    for (unsigned int i = 0; i < 9; i++) {
        if (possibleCode & (1 << i)) {
            add_possibility(i + 1);
            numPossibles++;
        }
    }

    return numPossibles;
}

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
        pPoss = nullptr;
        return;
    }

    // otherwise, delete specific node
    while (pPoss) {
        if (pPoss->_value == toRemove) {
            delete pPoss;
            pPoss = nullptr;
            return;
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

bool UnknownCell::initialized_possibilities() {

    return _pPossibles == nullptr;
}

void UnknownCell::remove_current_possibility() {

#ifdef CONFIG_DEBUG
    std::cerr << "ERROR: Cannot remove possibilities from an EmptyCell" << std::endl; 
#endif // CONFIG_DEBUG

    exit(1);
}


#ifdef CONFIG_DEBUG
void UnknownCell::print() {
    std::cout << ' ';
}

#endif //CONFIG_DEBUG

/*  *****************
    KnownCell methods
    ***************** */

void KnownCell::remove_current_possibility() {

#ifdef CONFIG_DEBUG
    std::cerr << "ERROR: Cannot remove possibilities from a KnownCell" << std::endl; 
#endif // CONFIG_DEBUG

    exit(1);
}

#ifdef CONFIG_DEBUG
void KnownCell::print() {
    std::cout << _value;
}
#endif //CONFIG_DEBUG
