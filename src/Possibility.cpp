#include <Possibility.h>

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

#ifdef CONFIG_TEST
unsigned int Possibility::get_value() {

    return _value;
}

Possibility* Possibility::next() {

    return _pNext;
}

Possibility* Possibility::prev() {

    return _pPrev;
}

#endif // CONFIG_TEST
