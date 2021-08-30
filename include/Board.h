#ifndef SECTION_H
#define SECTION_H
#include <Section.h>
#endif // SECTION_H
#include <string>

class Board {

private:
    ArraySection  **_rows;
    ArraySection  **_columns;
    SquareSection **_squares;

public:
    Board(std::string);


    void solve();
};
