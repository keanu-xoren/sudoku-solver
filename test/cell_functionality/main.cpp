#ifndef CELL_H
#define CELL_H
#include <Cell.h>
#endif // CELL_H
#include <assert.h>
#include <iostream>

int main(int argc, char* argv[]) {


    // Given Cells
    GivenCell my_cell(4);

    assert(my_cell.get_value() == 4);



    std::cout << "All tests passed!!!" << std::endl;

    return 0;
}
