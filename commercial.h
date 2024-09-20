#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "cell.h"

class Commercial : public Cell {

    public:

        //DEFAULT CLASS
        Commercial();

        //FUNCTION TO DETERMINE POPULATION GROWTH
        void incWorkers();
        void decWorkers();
        int getWorkers() const;

        //FUNCTIONS TO DETERMINE IF IT IS ADJACENT TO POWERLINES
        void setPower();
        bool hasPower() const;


    private:
        int workers;
        bool power;

};

#endif  //COMMERCIAL_H