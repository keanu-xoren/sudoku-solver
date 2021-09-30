#include <Possibility.h>
#include <assert.h>
#include <iostream>

/*  ***********
    Constructor
    *********** */
Possibility::Possibility(unsigned int inVal, bool sorted) {

    assert(inVal && (inVal < 10));


    _encoding = 0;
    _encoding.value = inVal;
    _encoding.sorted = sorted;
    _pNext = nullptr;
    _pPrev = nullptr;
}

/*  **********
    Destructor
    ********** */
Possibility::~Possibility() {

    if (_pPrev) {
        _pPrev->_pNext = _pNext;
    }

    if (_pNext) {
        _pNext->_pPrev = _pPrev;
    }

    _pNext = _pPrev = nullptr;

}
/*  ******************
    operator overloads
    ****************** */
Possibility Possibility::operator=(const Possibility& other) {

    _encoding = other._encoding;
    _pNext = other._pNext;
    _pPrev = other._pPrev;

    return *this;
}

/*  ***************
    private methods
    *************** */
void Possibility::decode() {

}

/*  **************
    public methods
    ************** */
void Possibility::push(unsigned int inVal) {
    assert(inVal && (inVal < 10));

    if (inVal == _encoding.value)
        return;

    Possibility *ptr = this;

    if (_encoding.sorted) {
        Possibility *toInsert = new Possibility(inVal, true);
        bool inserted = false;

        if (inVal < _encoding.value) {
            while (ptr->_pPrev) {
                if (inVal == ptr->_pPrev->_encoding.value)
                    return;

                else if (inVal > ptr->_pPrev->_encoding.value) {

                    ptr->_pPrev->_pNext = toInsert;

                    toInsert->_pPrev = ptr->_pPrev;
                    toInsert->_pNext = ptr;

                    ptr->_pPrev = toInsert;

                    inserted = true;
                    break;
                }
                ptr = ptr->_pPrev;
            }
            
            if (!inserted) {
                toInsert->_pNext = ptr;
                ptr->_pPrev = toInsert;
            }

        }
        else {
            while (ptr->_pNext) {
                if (inVal == ptr->_pNext->_encoding.value)
                    return;

                if (inVal < ptr->_pNext->_encoding.value) {

                    toInsert->_pPrev = ptr;
                    toInsert->_pNext = ptr->_pNext;
                    

                    toInsert->_pNext->_pPrev = toInsert;
                    ptr->_pNext = toInsert;

                    inserted = true;
                    break;
                }
                ptr = ptr->_pNext;
            }
            if (!inserted) {
                toInsert->_pPrev = ptr;
                ptr->_pNext = toInsert;
            }
        }

    }
    else {
        while (ptr->_pNext)
            ptr = ptr->_pNext;

        ptr->_pNext = new Possibility(inVal, false);
        ptr->_pNext->_pPrev = ptr;
    }

    
}
Possibility* Possibility::remove(unsigned int inVal) {

    Possibility *ptr;
    if (inVal == _encoding.value) {
        
        if (!(_pPrev || _pNext)) {
            delete this;
            return nullptr;
        }

        if (_pPrev) {
            ptr = _pPrev;
            ptr->_pNext = _pNext;
        }
        else {
            ptr = _pNext;
            ptr->_pPrev = _pPrev;
        }

        ptr = _pPrev ? _pPrev : _pNext;
        *this = *ptr;
        delete ptr;
        ptr = nullptr;
    } 
    else {

        
        bool backward = _encoding.sorted && (inVal < _encoding.value);

        ptr = backward ? _pPrev : _pNext;
        while (ptr) {
            if (ptr->_encoding.value == inVal) {
                delete ptr;
                ptr = nullptr;
                break;
            }
            ptr = backward ? ptr->_pPrev : ptr->_pNext;
        }

    }

    
    return this;
}

/*  ********************
    CONFIG_TEST methods
    ******************** */
#ifdef CONFIG_TEST
unsigned int Possibility::get_value() {

    return _encoding.value;
}

Possibility* Possibility::next() {

    return _pNext;
}

Possibility* Possibility::prev() {

    return _pPrev;
}

#endif // CONFIG_TEST
