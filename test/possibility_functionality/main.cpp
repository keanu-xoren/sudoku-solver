#include <assert.h>
#include <iostream>
#include <Possibility.h>

int main(int argc, char* argv[]) {

#ifndef CONFIG_DEBUG
    std::cerr << "DEBUG compiler flag not set. Test will not function properly" << std::endl;
    assert(false);
#endif // CONFIG_DEBUG

    Possibility *ptr = new Possibility(1);
    Possibility *other;

    ptr->push(2);
    ptr->push(9);

    assert(ptr->get_value() == 1);
    assert(ptr->next()->get_value() == 2);
    assert(ptr->next()->next()->get_value() == 9);
    assert(!ptr->next()->next()->next());
    assert(!ptr->prev());
    assert(ptr->next()->prev()->get_value() == 1);

    other = ptr->next();
    delete ptr;
    ptr = nullptr;

    assert(other->get_value() == 2);
    assert(!other->prev());
    assert(other->next()->get_value() == 9);


    std::cout << "All tests passed!!!" << std::endl;
    return 0;
}
