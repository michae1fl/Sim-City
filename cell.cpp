//COMPLETED
#include "cell.h"


//SETTING FUNCTIONS
Cell::Cell() {
    x = -1;
    y = -1;
    cellPollution = 0;
    priority = 0;
    symbol = 'U';
}

void Cell::setX(int x) {
    this->x = x;
}

void Cell::setY(int y) {
    this->y = y;
}

void Cell::setPriority(int value) {
    priority = value;
}

void Cell::incPollution(int value) {
    cellPollution += value;
}

void Cell::setSymbol(char symbol) {
    this->symbol = symbol;
}

void Cell::setAdjCells(vector<Cell> cells) {

    for (int i = 0; i < cells.size(); i ++) {
        
        adjCells[i] = cells[i];
    }
}


//GETTING FUNCTIONS
int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
}

int Cell::getPriority() const {
    return priority;
}

int Cell::getPollution() const {
    return cellPollution;
}

char Cell::getSymbol() const {
    return symbol;
}

const vector<Cell>& Cell::getAdjCells() const {
    return adjCells;
}



