
#ifndef BOARD_H
#define BOARD_H
#include <Board.h>
#endif // BOARD_H

#ifndef CELL_H
#define CELL_H
#include <Cell.h>
#endif

#include <fstream>
#include <sstream>
#include <queue>
#include <iostream>

#ifdef CONFIG_DEBUG
#include <iostream>
#endif

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

    Cell *pCell;
    unsigned int rowIndex, colIndex;
    unsigned int cellValue;
    rowIndex = 0;

    for (rowIndex = 0; rowIndex < 9; rowIndex++) {

        getline(inFile, line);

        std::istringstream iss(line);


        for (colIndex = 0; colIndex < 9; colIndex++) {
            iss >> cellValue;

#ifdef CONFIG_DEBUG
            std::cout << "Creating new cell with value " << cellValue << '\n';
#endif // CONFIG_DEBUG

            if (!cellValue) {
                pCell = new EmptyCell;
            }
            else {
                pCell = new GivenCell(cellValue);
            }

#ifdef CONFIG_DEBUG
            std::cout << "\tstoring at mem[ " << pCell << " ]\n";
#endif // CONFIG_DEBUG


            _rows[rowIndex].add_cell(pCell);
#ifdef CONFIG_DEBUG
            std::cout << "Added new cell to row " << rowIndex << std::endl;
#endif // CONFIG_DEBUG


            _columns[colIndex].add_cell(pCell);
#ifdef CONFIG_DEBUG
            std::cout << "Added new cell to column " << colIndex << std::endl;
#endif // CONFIG_DEBUG



            _squares[get_square_index(rowIndex, colIndex)].add_cell(pCell);
#ifdef CONFIG_DEBUG
            std::cout << "Added new cell to square " << get_square_index(rowIndex, colIndex) << std::endl;
#endif // CONFIG_DEBUG
        }
    }

    pCell = nullptr;
    inFile.close();
}

Board::~Board() {

}

void Board::solve() {

    //std::queue<CellGrouping> main_queue;
}


#ifdef CONFIG_DEBUG
#include <iostream>
void Board::print() {

    for (unsigned int i = 0; i < 9; i++) {
        _rows[i].print();
        std::cout << "\n";
    }

    std::cout << std::endl;
}
#endif //CONFIG_DEBUG