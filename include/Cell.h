#ifndef VALUE_MASK
#define VALUE_MASK 0b0111111111
#define ONE     0b0000000001
#define TWO     0b0000000010
#define THREE   0b0000000100
#define FOUR    0b0000001000
#define FIVE    0b0000010000
#define SIX     0b0000100000
#define SEVEN   0b0001000000
#define EIGHT   0b0010000000
#define NINE    0b0100000000
#endif

class Cell {
    friend class CellGrouping;
    unsigned int _possibleValues;
    unsigned int _value;

public:
    /*
        Constructor
        
        Inputs:
            n/a

        Outputs:
            An empty cell
    */
    Cell();

    Cell(unsigned int);

    /*
        get_value()
        Inputs:
            n/a

        Outputs:
            Assigned value of a cell (1-9)
            If unset, returns 0
    */
    unsigned int get_value();

    /*
        get_possible_values()
            Returns a 9-bit value denoting the possible values of the cell

        Inputs:
            n/a
            
        Outputs:
            9-bit int denoting possible values of the cell
            If set, returns 0
    */
    unsigned int get_possible_values();

    /*
        set_value()
        Inputs:
            inVal -> integer (1-9) 

        Outputs:
            n/a
    */
    void set_value(unsigned int);

    /*
        reduce_possible_values()
        Inputs:
            groupValues -> 9-bit number representing filled numbers of a group

        Outputs:
            n/a
    */
    void reduce_possible_values(unsigned int);
};
