#include <assert.h>
#include <iostream>
#include <Possibility.h>

#define N_TEST 7
void test_init();
void test_push_unsorted();
void test_push_sorted();
void test_push_duplicate();
void test_remove_unsorted();
void test_remove_sorted();
void test_remove_self();

void (*pTestArray[N_TEST])() = {
    test_init,
    test_push_unsorted,
    test_push_sorted,
    test_push_duplicate,
    test_remove_unsorted,
    test_remove_sorted,
    test_remove_self
};

int main(int argc, char* argv[]) {

#ifndef CONFIG_DEBUG
    std::cerr << "DEBUG compiler flag not set. Tests will not function properly" << std::endl;
    assert(false);
#endif // CONFIG_DEBUG

    unsigned int i = 0;
    while (i < N_TEST) {
      
        (*pTestArray[i])();
        i++;
    }

    std::cout << i << '/' << N_TEST << " tests passed!!!" << std::endl;

    return 0;
}

void cleanup(Possibility *ptr) {

    Possibility *next, *left;

    left = ptr->prev();

    while (ptr) {
        next = ptr->next();
        delete ptr;
        ptr = next;
    }

    while (left) {
        next = left->prev();
        delete left;
        left = next;
    }


    ptr = next = left = nullptr;
}

void test_init() {
    Possibility *pPoss;
    unsigned int testValues[4] = {1, 3, 6, 9};

    for (unsigned int i = 0; i < 4; i++) {

        pPoss = new Possibility(testValues[i], false);
        assert(pPoss->get_value() == testValues[i]);
        delete pPoss;
    }

    pPoss = nullptr;
}

void test_push_unsorted() {
    Possibility *pPoss = new Possibility(5, false);

    // unsorted 
    assert(!(pPoss->prev() || pPoss->next()));

    pPoss->push(4);
    pPoss->push(9);
    pPoss->push(2);
    
    assert(pPoss->next()->get_value() == 4);
    assert(pPoss->next()->next()->get_value() == 9);
    assert(pPoss->next()->next()->prev()->next()->get_value() == 9);
    assert(pPoss->next()->next()->next()->get_value() == 2);
    assert(pPoss->next()->prev()->get_value() == 5);

    cleanup(pPoss);
    pPoss = nullptr;
}

void test_push_sorted() {
    Possibility *pPoss = new Possibility(5, true);

    // left push
    pPoss->push(2);
    assert(pPoss->prev()->get_value() == 2);

    pPoss->push(4);

    assert(pPoss->prev()->get_value() == 4);
    assert(pPoss->prev()->prev()->get_value() == 2);

    // right push
    pPoss->push(9);
    pPoss->push(7);
    pPoss->push(8);
    
    assert(pPoss->next()->get_value() == 7);
    assert(pPoss->next()->next()->get_value() == 8);
    assert(pPoss->next()->next()->next()->get_value() == 9);
    assert(!pPoss->next()->next()->next()->next());

    // pointer confirmation
    assert(pPoss->next()->next()->next() // 7, 8, 9
                ->prev()->prev()->prev()->prev()->prev() // 8, 7, 5, 4, 2
                ->next()->next()->get_value() == 5);

    cleanup(pPoss);
    pPoss = nullptr;
}

void test_push_duplicate() {
    Possibility *pPoss = new Possibility(3, false);

    for (unsigned int i = 0; i < 100; i++) {
        pPoss->push(3);
    }

    assert(!pPoss->next());
    assert(!pPoss->prev());

    cleanup(pPoss);

    pPoss = new Possibility(4, true);
    pPoss->push(2);
    pPoss->push(6);

    for (unsigned int i = 0; i < 50; i++) {
        pPoss->push(2);
        pPoss->push(6);
    }

    assert(!pPoss->next()->next());
    assert(!pPoss->prev()->prev());

    cleanup(pPoss);
    pPoss = nullptr;
}

void test_remove_unsorted() {

    Possibility *pPoss = new Possibility(2, false);

    pPoss->push(1);
    pPoss->push(8);

    pPoss = pPoss->remove(1);
    
    assert(pPoss->next()->get_value() == 8);
    assert(pPoss->next()->prev()->get_value() == 2);
    assert(!pPoss->next()->next());

    pPoss = pPoss->remove(8);
    assert(!pPoss->next());

    cleanup(pPoss);
    pPoss = nullptr;
}

void test_remove_sorted() {

    Possibility *pPoss = new Possibility(5, true);

    pPoss->push(1);
    pPoss->push(8);
    pPoss->push(2);
    pPoss->push(6);

    pPoss = pPoss->remove(2);

    assert(pPoss->prev()->get_value() == 1);
    assert(pPoss->prev()->next()->get_value() == 5);
    assert(!pPoss->prev()->prev());

    pPoss = pPoss->remove(1);

    assert(!pPoss->prev());

    // checking removed item from rhs validated in test_remove_unsorted()

    cleanup(pPoss);
    pPoss = nullptr;
}

void test_remove_self() {

    Possibility *pPoss = new Possibility(3, true);

    pPoss->push(2);
    pPoss->push(1);
    pPoss->push(5);
    pPoss->push(8);

    pPoss = pPoss->remove(3);
    assert(pPoss->get_value() == 2);
    assert(pPoss->prev()->get_value() == 1);
    assert(pPoss->next()->get_value() == 5);

    pPoss = pPoss->remove(2);
    assert(pPoss->get_value() == 1);
    assert(!pPoss->prev());
    assert(pPoss->next()->get_value() == 5);

    pPoss = pPoss->remove(1);
    assert(!pPoss->prev());
    assert(pPoss->get_value() == 5);
    assert(pPoss->next()->get_value() == 8);

    pPoss = pPoss->remove(5);
    pPoss = pPoss->remove(8);

    assert(!pPoss);

    pPoss = nullptr; // sanity
}
