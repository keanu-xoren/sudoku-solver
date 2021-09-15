#ifndef CELL_H
#define CELL_H
#include <Cell.h>
#endif // CELL_H


#ifndef CPPSTRING_H
#define CPPSTRING_H
#include <string>
#endif //CPPSTRING_H

class Board {

private:
    Cell *_cells[9][9];
    unsigned int _filled[3][9];

public:
    Board(std::string);

    ~Board();

    unsigned int at(unsigned int, unsigned int);

    void solve();

#ifdef CONFIG_DEBUG

    void print();

#endif //CONFIG_DEBUG
};
