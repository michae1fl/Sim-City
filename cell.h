// COMPLETED

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Cell {

    public:

        // DEFAULT CLASS
        Cell();

        //SETTER FUNCTIONS
        void setX(int);
        void setY(int);

        void setPriority(int value);

        void incPollution(int value);

        void setSymbol(char);

        void setAdjCells(vector<Cell> cell);
        
        //GETTER FUNCTIONS
        int  getX() const;
        int  getY() const;

        int getPriority() const;

        int  getPollution() const;

        char getSymbol() const;

        const vector<Cell> &getAdjCells() const;

    private:

        int x;
        int y;

        char symbol;

        int priority;
        int cellPollution;

        vector<Cell> adjCells;


};

#endif // CELL_H