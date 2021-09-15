#ifndef SECTION_H
#define SECTION_H
#include <Section.h>
#endif // SECTION_H

#ifndef CPPSTRING_H
#define CPPSTRING_H
#include <string>
#endif //CPPSTRING_H

class Board {

private:
    ArraySection  _rows[9];
    ArraySection  _columns[9];
    SquareSection _squares[9];

public:
    Board(std::string);

    ~Board();

    void solve();

#ifdef CONFIG_DEBUG

    void print();

#endif //CONFIG_DEBUG
};
