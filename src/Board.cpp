#include <Board.h>
#include <fstream>
#include <sstream>
#include <stack>

#ifdef CONFIG_DEBUG
#include <iostream>
#endif

unsigned int calculateSquareIndex(const unsigned int& row, const unsigned int& col) {

    /*
                c
                012   345   678

        r   0   ###   ###   ###
            1   -0-   -1-   -2-
            2   ###   ###   ###
            
            3   ###   ###   ###
            4   -3-   -4-   -5-
            5   ###   ###   ###
            
            6   ###   ###   ###
            7   -6-   -7-   -8-
            8   ###   ###   ###


    */
    return row + (col / 3) - (row % 3);
}

/*  ***********
    Constructor
    *********** */
Board::Board(std::string filename) {

    std::ifstream inFile(filename);
    std::string line;

    if (!inFile.is_open()) {
#ifdef CONFIG_DEBUG
        std::cerr << "Error opening " << filename << std::endl;
#endif // CONFIG_DEBUG
        exit(1);
    }

    UnsolvedCell cell;
    unsigned int sqr_index, value_bit;
    
    cell.possibles = 0x1ff;

    for (unsigned int row_index = 0; row_index < 9; row_index++) {

        getline(inFile, line);
        std::istringstream iss(line);

        for (unsigned int col_index = 0; col_index < 9; col_index++) {
            iss >> _cells[row_index][col_index];
            sqr_index = calculateSquareIndex(row_index, col_index);
            if (!_cells[row_index][col_index]) {
                cell.row = row_index;
                cell.col = col_index;
                cell.sqr = sqr_index;
                _unsolved.push_back(cell);
                continue;
            }

            value_bit = (1 << (_cells[row_index][col_index] - 1));
            _row_sets[row_index] ^= value_bit;
            _col_sets[col_index] ^= value_bit;
            _sqr_sets[sqr_index] ^= value_bit;
        }
    }

    _unsolved.shrink_to_fit();
    inFile.close();
}

/*  **********
    Destructor
    ********** */
// Board::~Board() {}

/*  **************
    Public Methods
    ************** */
void Board::solve() {

    solveViaElimination();
    solveViaDFS();
}

/*  ***************
    Private Methods
    *************** */
unsigned int Board::reduceByAdjacent(const unsigned int &row, const unsigned int &col) {

    unsigned int r1, r2, c1, c2;

    switch (row % 3) {
        case 0:
            r1 = row + 1;
            r2 = row + 2;
            break;

        case 1:
            r1 = row - 1;
            r2 = row + 1;
            break;

        default:
            r1 = row - 1;
            r2 = row - 2;
            break;
    }

    switch (col % 3) {
        case 0:
            c1 = col + 1;
            c2 = col + 2;
            break;

        case 1:
            c1 = col - 1;
            c2 = col + 1;
            break;

        default:
            c1 = col - 1;
            c2 = col - 2;
            break;
    }
    
    return _row_sets[r1] & _row_sets[r2]
         & _col_sets[c1] & _col_sets[c2];  
}

unsigned int Board::findValue(const unsigned int &possible, const unsigned int &row_index,
                              const unsigned int &col_index, const unsigned int &sqr_index) {

    unsigned int val = 0;
    for (unsigned int i = 0; i < 9; i++) {
        if ((possible >> i) == 1) {
            if (possible == (possible & (1 << i))) {
                _sqr_sets[sqr_index] |= possible;
                _col_sets[col_index] |= possible;
                _row_sets[row_index] |= possible;
                val = i+1;
            } 
            break;
        }
    }

    return val;
}

unsigned int Board::guessValue(const unsigned int &possible, const unsigned int &row_index,
                               const unsigned int &col_index, const unsigned int &sqr_index) {

    unsigned int val = 0;
    for (unsigned int i = 0; i < 9; i++) {
        if ((possible >> i) & 1) {
            val = i + 1;
            _row_sets[row_index] |= (1 << i);
            _col_sets[col_index] |= (1 << i);
            _sqr_sets[sqr_index] |= (1 << i);
            break;
        }
    }

    return val;
}

void Board::solveViaElimination() {

    UnsolvedCell cell;
    unsigned int previous_size = _unsolved.size();
    unsigned int attempts = 0;
    unsigned int tmp; // dummy variable

    while (!_unsolved.empty()) {

        cell = _unsolved.front();
        _unsolved.pop_front();

        cell.possibles &= ~(_row_sets[cell.row] |
                            _col_sets[cell.col] |
                            _sqr_sets[cell.sqr]);
        tmp = reduceByAdjacent(cell.row, cell.col);
        cell.possibles = cell.possibles & tmp ?
                         cell.possibles & tmp : cell.possibles;

        tmp = findValue(cell.possibles, cell.row, cell.col, cell.sqr);

        if (tmp) {
            _cells[cell.row][cell.col] = tmp;
        }
        else {
            _unsolved.push_back(cell);
        }

        // check if there was a pass through all unknown cells
        //  without solving any new ones
        attempts++;
        if (attempts == previous_size) {
            if (previous_size == _unsolved.size())
                break;

            previous_size = _unsolved.size();
            attempts = 0;
        }
    }
}

void Board::solveViaDFS() {
    std::stack<UnsolvedCell> guessed_cells;
    UnsolvedCell cell;
    unsigned int tmp_x, tmp_y; // dummies

    while (!_unsolved.empty()) {
        cell = _unsolved.front();
        _unsolved.pop_front();

        tmp_x = ~(_row_sets[cell.row] |
                  _col_sets[cell.col] |
                  _sqr_sets[cell.sqr]);
        tmp_x &= 0x01ff;
        tmp_y = reduceByAdjacent(cell.row, cell.col);
        tmp_x = tmp_x & tmp_y ? tmp_x & tmp_y : tmp_x;

        if (tmp_x) {
            cell.possibles = tmp_x;
            cell.value = guessValue(cell.possibles, cell.row, cell.col, cell.sqr);

            _cells[cell.row][cell.col] = cell.value;
            guessed_cells.push(cell);
            continue;
        }

        while (!tmp_x) {
            // protection from endless loop
            if (guessed_cells.empty())
                return;

            _unsolved.push_front(cell);
            cell = guessed_cells.top();
            guessed_cells.pop();

            tmp_y = 1 << (cell.value - 1);
            tmp_x = cell.possibles ^ tmp_y;
            _row_sets[cell.row] ^= tmp_y;
            _col_sets[cell.col] ^= tmp_y;
            _sqr_sets[cell.sqr] ^= tmp_y;
        }

        cell.possibles = tmp_x;
        cell.value = guessValue(cell.possibles, cell.row, cell.col, cell.sqr);

        _cells[cell.row][cell.col] = cell.value;
        guessed_cells.push(cell);
    }
}

#ifdef CONFIG_DEBUG
void Board::print() {

    std::string horizontal = "-----";

    for (unsigned int i = 0; i < 9; i++) {
        for (unsigned int j = 0; j < 9; j++) {
            std::cout << _cells[i][j];
            
            if (j == 2 || j == 5) {
                std::cout << '|';
            }
            else {
                std::cout << ' ';
            }
            
        }
        std::cout << std::endl;
        if (i == 2 || i == 5) {
            std::cout << horizontal << "|" << horizontal << "|" << horizontal << "\n";
        }
    }

    std::cout << std::endl;
}
#endif //CONFIG_DEBUG

#ifdef CONFIG_TEST
bool Board::operator==(const Board& other) {
    for (unsigned int r = 0; r < 9; r++) {
        for (unsigned int c = 0; c < 9; c++) {

            if (_cells[r][c] != other._cells[r][c])
                return false;
        }
    }

    return true;
}
#endif // CONFIG_TEST
