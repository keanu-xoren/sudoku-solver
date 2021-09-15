#ifndef BOARD_H
#define BOARD_H
#include <Board.h>
#endif // BOARD_H

#ifndef CPPSTRING_H
#define CPPSTRING_H
#include <string>
#endif //CPPSTRING_H

#include <assert.h>
#include <iostream>

int main(int argc, char* argv[]) {

    std::string puzzleName = "easy_sample.txt";

    Board easyPuzzle = Board(puzzleName);


    std::cout << "All tests passed!!!" << std::endl;
    return 0;
}
