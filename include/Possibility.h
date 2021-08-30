// representation of a possible value in a sudoku cell
class Possibility {

    unsigned int _value;

    void decode();

public:
    Possibility(unsigned int);
    ~Possibility();
};
