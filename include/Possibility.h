// representation of a possible value in a sudoku cell
class Possibility {

    friend class UnknownCell;

    Possibility *_pNext;
    Possibility *_pPrev;
    unsigned int _value;
    unsigned int _encoding;

    void decode();

public:
    Possibility(unsigned int);
    ~Possibility();

    void push(unsigned int);

#ifdef TEST_CONFIG 
    // following methods are only for functionality testing
    unsigned int get_value();

    Possibility* next();
    Possibility* prev();
#endif // TEST_CONFIG
};
