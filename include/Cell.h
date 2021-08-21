#define ONE     0b000000001
#define TWO     0b000000010
#define THREE   0b000000100
#define FOUR    0b000001000
#define FIVE    0b000010000
#define SIX     0b000100000
#define SEVEN   0b001000000
#define EIGHT   0b010000000
#define NINE    0b100000000

class Cell {

        unsigned int value;

    public:
        Cell() {}

        Cell(unsigned int);

        void set_value(unsigned int);

        unsigned int get_value();
};