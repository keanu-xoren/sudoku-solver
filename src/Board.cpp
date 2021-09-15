#ifndef BOARD_H
#define BOARD_H
#include <Board.h>
#endif // BOARD_H

#ifndef ENCODINGS_H
#define ENCODINGS_H
#include <Encodings.h>
#endif // ENCODINGS_H

#ifdef CONFIG_DEBUG
#include <iostream>
#endif

#include <fstream>
#include <sstream>
#include <queue>

#define FILLED_ROW 0
#define FILLED_COL 1
#define FILLED_SQR 2

unsigned int get_square_index(unsigned int row, unsigned int col) {

    /*
                c
                012   345   678

        r   0   ###   ###   ###
            1   -0-   -1-   -2-
            2   ###   ###   ###
            
            3   ###   ###   ###
            4   -3-   -4-   -5-
            5   ###   ###   ###
            
            6   ###   ###   ###
            7   -6-   -7-   -8-
            8   ###   ###   ###


    */
    return row + (col / 3) - (row % 3);
}

Board::Board(std::string filename) {

    std::ifstream inFile(filename);
    std::string line;

    if (!inFile.is_open()) {
        std::cerr << "Error opening " << filename << std::endl;
        exit(1);
    }

    for (unsigned int i = 0; i < 9; i++) {
        _filled[FILLED_ROW][i] = _filled[FILLED_COL][i] = _filled[FILLED_SQR][i] = 0;
    }

    Cell *pCell;
    unsigned int rowIndex, colIndex;
    unsigned int cellValue, cellValueBin;
    rowIndex = 0;

    for (rowIndex = 0; rowIndex < 9; rowIndex++) {

        getline(inFile, line);

        std::istringstream iss(line);


        for (colIndex = 0; colIndex < 9; colIndex++) {
            iss >> cellValue;

            if (!cellValue) {
                pCell = new EmptyCell;
            }
            else {
                pCell = new GivenCell(cellValue);

                cellValueBin = (1 << (cellValue - 1));

                _filled[FILLED_ROW][rowIndex] |= cellValueBin;
                _filled[FILLED_COL][colIndex] |= cellValueBin;
                _filled[FILLED_SQR][get_square_index(rowIndex, colIndex)] |= cellValueBin;
            }

            _cells[rowIndex][colIndex] = pCell;
        }
    }

    pCell = nullptr;
    inFile.close();
}

Board::~Board() {

    for (unsigned int i = 0; i < 9; i++) {
        for (unsigned int j = 0; j < 9; j++) {
            delete _cells[i][j];
            _cells[i][j] = nullptr;
        }
    }

}

void Board::solve() {

    //std::queue<CellGrouping> main_queue;
}


#ifdef CONFIG_DEBUG
void Board::print() {

    std::string horizontal = "-----";

    for (unsigned int i = 0; i < 9; i++) {
        for (unsigned int j = 0; j < 9; j++) {
            _cells[i][j]->print();
            
            if (j == 2 || j == 5) {
                std::cout << '|';
            }
            else {
                std::cout << ' ';
            }
            
        }
        std::cout << std::endl;
        if (i == 2 || i == 5) {
            std::cout << horizontal << "|" << horizontal << "|" << horizontal << "\n";
        }
    }

    std::cout << std::endl;
}
#endif //CONFIG_DEBUG