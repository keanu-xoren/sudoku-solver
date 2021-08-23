#include <Cell.h>
#include <assert.h>
#include <iostream>

int main(int argc, char* argv[]) {


    // Cell::Cell
    Cell null_cell;
    Cell my_cell(4);

    assert(!null_cell.get_value());
    assert(my_cell.get_value() == 4);



    std::cout << "All tests passed!!!" << std::endl;

    return 0;
}
