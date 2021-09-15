#ifndef SECTION_H
#define SECTION_H
#include <Section.h>
#endif // SECTION_H


#ifdef CONFIG_DEBUG
#include <iostream>
#endif

Section::Section() {
	_filledValues = 0;

}

Section::~Section() {

	for (unsigned int i = 0; i < 9; i++) {
		//delete _pCells[i];
	}
}

void Section::add_cell(Cell* pNewCell) {

	unsigned int i = 0;


	while (_pCells[i])
		i++;

	_pCells[i] = pNewCell;
}


#ifdef CONFIG_DEBUG
#include <iostream>

void Section::print() {

	for (unsigned int i = 0; i < 9; i++) {
        _pCells[i]->print();
        std::cout << " ";
    }
}

#endif //CONFIG_DEBUG