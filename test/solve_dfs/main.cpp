#include <Board.h>
#include <string>
#include <assert.h>
#include <iostream>

int main(int argc, char* argv[]) {

    std::string puzzleName = "../samples/hard_sample.txt";
    std::string solutionName = "../samples/hard_sample.solved";

    Board puzzle(puzzleName);
    Board solution(solutionName);

    puzzle.print();
    solution.print();

    puzzle.solve();

    assert(solution == puzzle);

    std::cout << "All tests passed!!!" << std::endl;
    return 0;
}
