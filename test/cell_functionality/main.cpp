#include <assert.h>
#include <iostream>
#include <exception>
#include <Cell.h>
#include <Encodings.h>

#define ARRAY_MAX 9

#define N_TEST 2
void test_known_functionality();
void test_unknown_functionality();


void (*pTestArray[N_TEST])() = {
    test_known_functionality,
    test_unknown_functionality
};

int main(int argc, char* argv[]) {


    unsigned int i = 0;
    while (i < N_TEST) {
      
        (*pTestArray[i])();
        i++;
    }

    std::cout << i << '/' << N_TEST << " tests passed!!!" << std::endl;

    return 0;
}

void test_known_functionality() {
    KnownCell four(4);
    KnownCell nine(9);

    // get_value()
    assert(four.get_value() == 4);
    assert(nine.get_value() == 9);

    // solved(), initialized()
    assert(four.solved() && four.initialized());

    // comparison 
    assert(four == four);
    assert(!(nine == four));
}

void test_unknown_functionality() {
    UnknownCell *cell = new UnknownCell();
    bool found[ARRAY_MAX];
    for (unsigned int i = 0; i < ARRAY_MAX; i++) { found[i] = 0; }

    // initialize_possibilities()
    assert(!cell->initialized());
    cell->initialize_possibilities(FOUR | SEVEN | TWO);
    assert(cell->initialized());

    unsigned int *pValues = cell->get_possibilities();
    for (unsigned int i = 0; *(pValues + i); i++) {
        found[*(pValues + i) - 1] = 1;
    }
    delete[] pValues;
    pValues = nullptr;
    assert(found[1] && found[3] && found[6]);

    // reduce_possibilities()
    found[1] = found[3] = found[6] = 0;
    cell->reduce_possibilities(FOUR);
    pValues = cell->get_possibilities();
    for (unsigned int i = 0; *(pValues + i); i++) {

        found[*(pValues + i) - 1] = 1;
    }
    delete[] pValues;
    pValues = nullptr;
    assert(found[1] && !found[3] && found[6]);


    // solved()
    assert(!cell->solved());

}