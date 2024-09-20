#include "cell.h"
#include "residential.h"
#include "commercial.h"
#include "industrial.h"
#include <fstream>
#include <string>
#include <sstream>

class Map {

    public:

        //CELL SPECIFIC FUNCTIONS
        void addCell(int x, int y, char symbol);

        Cell* getCell(int x, int y);
        Industrial* getIndCell(int x, int y);
        Residential* getResCell(int x, int y);
        Commercial* getCommCell(int x, int y);
        

        //MAP SPECIFIC FUNCTIONS
        bool setMaps(const string& filename);
        void printMap(int x1=-1, int x2=-1, int y1=-1, int y2=-1);
        void printPollutionMap(int x1=-1, int x2=-1, int y1=-1, int y2=-1);        

        //OTHER FUNCTIONS
        void validAdjCells(Cell);
        void getPriorty(Cell);

        int getTotalGoods() const;
        int getTotalWorkers() const;
        int getTotalPollution() const;    
        int getTotalPopulation() const;
        


    private:
        int width = 0;
        int height = 0;

        int totalGoods;
        int totalWorkers;
        int totalPollution;
        int totalPopulation;
        
        vector<Cell> allCells;
        vector<Industrial> indCells;
        vector<Residential> resCells;
        vector<Commercial> commCells;


};


/**
 * TO BE ADDED
 * A FUNCTION THAT RUNS THROUGH THE MAP OF ADJACENT CELLS AND DETERMINES WHICH
 * CELLS ARE VALID ON THE MAP AND CREATES A NEW VECTOR OF ADJACENT VALID CELLS
 * TO THE CELL IN QUESTION ON THE MAP
 * 
 * A FUNCTION TO SET THE PRORITY DEPENDING ON THE SYMBOL, STEMMING OFF OF THE 
 * MAP ADJACENT CELL FUNCTION (SINCE THE SYMBOL CAN ONLY BE GOTTEN AFTER IT IS 
 * SET IN THE MAP FUNCTION)
 *   SEE RESIDENTIAL PRIORITY TO PROPERLY IMPLEMENT RESIDENTIAL SECTION
 */
