#include "map.h"

////////////////////////////////////////////////////////////////////////////////

//COMPLETE
void Map::addCell(int x, int y, char symbol) {

    Cell addtoAllCells;

    if (symbol == 'I') {
        Industrial cell;

        cell.setX(x);
        cell.setY(y);
        cell.setSymbol(symbol);

        indCells.push_back(cell);
        addtoAllCells = cell;
    }
    else if (symbol == 'R') {
        Residential cell;

        cell.setX(x);
        cell.setY(y);
        cell.setSymbol(symbol);

        resCells.push_back(cell);
        addtoAllCells = cell;

    }
    else if (symbol == 'C') {
        Commercial cell;

        cell.setX(x);
        cell.setY(y);
        cell.setSymbol(symbol);

        commCells.push_back(cell);
        addtoAllCells = cell;

    }
    else {

        addtoAllCells.setX(x);
        addtoAllCells.setY(y);
        addtoAllCells.setSymbol(symbol);
    }
    

    allCells.push_back(addtoAllCells);
}

/*----------------------------------------------------------------------------*/

//COMPLETE
Cell* Map::getCell(int x, int y) {
    
    for (auto& cell : allCells) {

        if (cell.getX() == x, cell.getY() == y) {
            
            return &cell;
        }
    }
    
    return nullptr;
}

//COMPLETE
Industrial* Map::getIndCell(int x, int y) {
    
    for (auto& cell : indCells) {

        if (cell.getX() == x, cell.getY() == y) {
            
            return &cell;
        }
    }
    
    return nullptr;
}

//COMPLETE
Residential* Map::getResCell(int x, int y) {
    
    for (auto& cell : resCells) {

        if (cell.getX() == x, cell.getY() == y) {
            
            return &cell;
        }
    }
    
    return nullptr;
}

//COMPLETE
Commercial* Map::getCommCell(int x, int y) {
    
    for (auto& cell : commCells) {

        if (cell.getX() == x, cell.getY() == y) {
            
            return &cell;
        }
    }
    
    return nullptr;
}

////////////////////////////////////////////////////////////////////////////////

//COMPLETE
bool Map::setMaps(const string& filename) {

    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
            cerr << "Unable to open file" << endl;
            return false;
    }

    string line;
    int YValue = 0; 

    while (getline(file, line)) {

        stringstream ss(line);
        string cellData;
        char symbol;
        int XValue = 0;

        while (getline(ss, cellData, ',')) {
            
            if (cellData.empty()) {
                XValue ++;
            }
            else {

                symbol = cellData[0];
                addCell(XValue, YValue, symbol);
                XValue ++;
            
            } 

        }

        width = max(width, XValue);
        YValue ++;

    }

    height = YValue;
    file.close();
    
    return true;
}

//COMPLETE
void Map::printMap(int x1, int x2, int y1, int y2) {

    if (x1 == -1) {
        x1 = 0;
    }
    if (x2 == -1) {
        x2 = width;
    }
    if (y1 == -1) {
        y1 = 0;
    }
    if (y2 == -1) {
        y2 = height;
    }

    for (int y = y1; y < y2; y ++) {

        //PRINT THE TOP ROW BORDER
        for (int j = x1; j < x2; j++) {
            cout << "+===";
        }
        cout << "+" << endl;

        //PRINTING AN EMPTY ROW FOR PERSONAL DESIGN PURPOSES
        for (int j = x1; j < x2; j++) {
            cout << "|   ";
        }
        cout << "|" << endl;

        //PRINTING THE ACTUAL ROW WITH INFORMATION
        for(int x = x1; x < x2; x++) {
            char symbol;
            
            cout << "| ";

            if (getCell(x, y) != nullptr) {
                cout << getCell(x, y)->getSymbol() << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << "|" << endl;

        //PRINTING ANOTHER EMPTY ROW FOR PERSONAL DESIGN PURPOSES
        for (int j = x1; j < x2; j++) {
            cout << "|   ";
        }
        cout << "|" << endl;

    }

    //PRINT THE BOTTOM ROW BORDER
        for (int j = x1; j < x2; j++) {
            cout << "+===";
        }
        cout << "+" << endl;

}

//COMPLETE
void Map::printPollutionMap(int x1, int x2, int y1, int y2) {

    if (x1 == -1) {
        x1 = 0;
    }
    if (x2 == -1) {
        x2 = width;
    }
    if (y1 == -1) {
        y1 = 0;
    }
    if (y2 == -1) {
        y2 = height;
    }


    for (int y = y1; y < y2; y ++) {

        //PRINT THE TOP ROW BORDER
        for (int j = x1; j < x2; j++) {
            cout << "+===";
        }
        cout << "+" << endl;

        //PRINTING AN EMPTY ROW FOR PERSONAL DESIGN PURPOSES
        for (int j = x1; j < x2; j++) {
            cout << "|   ";
        }
        cout << "|" << endl;

        //PRINTING THE ACTUAL ROW WITH INFORMATION
        for(int x = x1; x < x2; x++) {
            char symbol;
            
            cout << "| ";

            if (getCell(x, y) != nullptr) {
                int pollution = getCell(x, y)->getPollution();

                if (pollution == 0) {
                    cout << getCell(x, y)->getSymbol() << " ";
                }
                else {
                    cout << pollution << " ";
                }

            }
            else {
                cout << "  ";
            }
        }
        cout << "|" << endl;

        //PRINTING ANOTHER EMPTY ROW FOR PERSONAL DESIGN PURPOSES
        for (int j = x1; j < x2; j++) {
            cout << "|   ";
        }
        cout << "|" << endl;

    }

    //PRINT THE BOTTOM ROW BORDER
        for (int j = x1; j < x2; j++) {
            cout << "+===";
        }
        cout << "+" << endl;

}

////////////////////////////////////////////////////////////////////////////////

//COMPLETE
void Map::validAdjCells(Cell cell) {

    int cellX = cell.getX();
    int cellY = cell.getY();

    vector<Cell> adjCells;

    for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {
            
            if (x == 0 && y == 0) {
                continue;
            }

            Cell* adjCell = getCell(cellX+x, cellY+y);

            if(adjCell != nullptr) {

                adjCells.push_back(*adjCell);
            }

        }
    }

    cell.setAdjCells(adjCells);

}

//NEEDS WORK
void Map::getPriorty(Cell cell) {

}

/*----------------------------------------------------------------------------*/

//COMPLETE
int Map::getTotalGoods() const {
    return totalGoods;
}

//COMPLETE
int Map::getTotalWorkers() const {
    return totalWorkers;
}

//COMPLETE
int Map::getTotalPollution() const {
    return totalPollution;
}

//COMPLETE
int Map::getTotalPopulation() const {
    return totalPopulation;
}

////////////////////////////////////////////////////////////////////////////////

//FUTURE CHANGES: OVERLOAD THE >> OPERATOR TO BE ABLE TO READ IN CELLS SOMEHOW