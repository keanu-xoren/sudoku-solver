#include <Cell.h>

#ifdef DEBUG
#include <iostream>
using namespace std;
#endif

Cell::Cell(unsigned int x) {

    value = x;
}

void Cell::set_value(unsigned int x) {

#ifdef DEBUG
    cout << "Assigning cell value to " << x << endl;
#endif
    this->value = x;
}

unsigned int Cell::get_value() {

#ifdef DEBUG
    cout << "Yo bro, here's some code" << endl;
#endif

    return value;
}