
#include <fstream>
#include <queue>

#ifndef BOARD_H
#define BOARD_H
#include <Board.h>
#endif // BOARD_H

Board::Board(std::string filename) {

    std::ifstream inFile(filename);

    std::string line;

    _rows = new CellArray*[9];
    _columns = new CellArray*[9];
    _squares = new CellSquare*[9];

    while (getline(inFile, line)) {
        //TODO populate contents from a file
        
    }

    inFile.close();
}

void Board::solve() {

    //std::queue<CellGrouping> main_queue;
}