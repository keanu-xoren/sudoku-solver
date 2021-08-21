#include <Cell.h>
#include <iostream>

using namespace std;

int main() {

    cout << "Hello World!" << endl;
    Cell random_cell;
    random_cell.set_value(3);

    cout << random_cell.get_value() << endl;

    return 0;
}