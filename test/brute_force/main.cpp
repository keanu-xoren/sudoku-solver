#include <Board.h>
#include <string>
#include <assert.h>
#include <iostream>

int main(int argc, char* argv[]) {

    std::string puzzleName = "../samples/easy_sample.txt";
    std::string solutionName = "../samples/easy_sample.solved";

    Board puzzle(puzzleName);
    Board solution(solutionName);

    puzzle.print();
    solution.print();

    puzzle.solve(10);

    assert(solution == puzzle);

    std::cout << "All tests passed!!!" << std::endl;
    return 0;
}
