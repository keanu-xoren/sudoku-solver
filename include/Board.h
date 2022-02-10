#include <string>
#include <deque>

#ifndef BOARD_H
#define BOARD_H

class Board {

private:

    struct UnsolvedCell {
        unsigned int row        : 4;
        unsigned int col        : 4;
        unsigned int sqr        : 4;
        unsigned int            : 4;
        unsigned int value      : 4;
        unsigned int            : 3;
        unsigned int possibles  : 9;
    };

    std::deque<UnsolvedCell> _unsolved;
    unsigned int _cells[9][9];
    unsigned int _row_sets[9] = {0};
    unsigned int _col_sets[9] = {0};
    unsigned int _sqr_sets[9] = {0};

    unsigned int reduceByAdjacent(const unsigned int&, const unsigned int &);
    unsigned int findValue(const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&);
    unsigned int guessValue(const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&);

    void solveViaElimination();
    void solveViaDFS();

public:
    Board(std::string);

    ~Board() {}

    unsigned int at(unsigned int, unsigned int);

    void solve();

#ifdef CONFIG_DEBUG
    void print();
#endif //CONFIG_DEBUG

#ifdef CONFIG_TEST
    bool operator==(const Board&);
#endif // CONFIG_TEST
};

#endif // BOARD_H
