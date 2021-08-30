#include <assert.h>
#include <iostream>

#ifndef CELL_H
#define CELL_H
#include <Cell.h>
#endif // CELL_H

#define MAX_SIZE 9


int main(int argc, char* argv[]) {


    // Given Cells
    GivenCell my_cell(4);

    assert(my_cell.get_value() == 4);

    UnknownCell *cell = new UnknownCell();
    bool found[MAX_SIZE];
    for (unsigned int i = 0; i < MAX_SIZE; i++) { found[i] = 0; }


    // UnknownCell::add_possibility
    cell->add_possibility(4);
    cell->add_possibility(7);
    cell->add_possibility(2);

    unsigned int *pValues = cell->get_possibilities();
    for (unsigned int i = 0; *(pValues + i); i++) {

        found[*(pValues + i) - 1] = 1;
    }
    delete[] pValues;
    pValues = nullptr;
    assert(found[1] && found[3] && found[6]);

    // UnknownCell::remove_possibility
    found[1] = found[3] = found[6] = 0;
    cell->remove_possibility(4);
    pValues = cell->get_possibilities();
    for (unsigned int i = 0; *(pValues + i); i++) {

        found[*(pValues + i) - 1] = 1;
    }
    delete[] pValues;
    pValues = nullptr;
    assert(found[1] && !found[3] && found[6]);

    std::cout << "All tests passed!!!" << std::endl;

    return 0;
}
