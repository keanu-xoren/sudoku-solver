#include <Board.h>
#include <string>
#include <assert.h>
#include <iostream>

int main(int argc, char* argv[]) {

    std::string puzzleName = "../samples/easy_sample.txt";

    Board puzzle = Board(puzzleName);


    assert(puzzle == puzzle);

    puzzle.print();

    std::cout << "All tests passed!!!" << std::endl;
    return 0;
}
