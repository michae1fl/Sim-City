#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "cell.h"

class Residential : public Cell {

    public:

        //DEFAULT CLASS
        Residential();

        //FUNCTION TO DETERMINE POPULATION GROWTH
        void incResidents();
        void decResidents();
        int getResidents() const;

        //FUNCTION TO DETERMINE IF IT IS ADJACENT TO POWERLINES
        void setPower();
        bool hasPower() const;



    private:
        int residents;
        bool power;


};


#endif // RESIDENTIAL_H