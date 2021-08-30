# Test Cases #

## *classname*_functionality ##
Tests to ensure the simple class methods work as expected. These tests are not for solving specific Sudoku scenarios, but for basic sanity validation.

### possibility_functionality ###
Possibility methods tested

    Possibility(unsigned int) // constructor
    ~Possibility()            // destructor
    push(unsigned int);


### cell_functionality ###
Cell methods tested

    // Constructors
    GivenCell();
    UnknownCell();

    // methods
    KnownCell::get_value();
    UnknownCell::add_possibility();
    UnknownCell::remove_possibility();
    UnknownCell::get_possibilities();