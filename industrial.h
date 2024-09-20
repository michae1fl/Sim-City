#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "cell.h"

class Industrial : public Cell {

    public:

        //DEFAULT CLASS
        Industrial();

        //FUNCTION TO DETERMINE POPULATION GROWTH
        void incGoods();
        void decGoods();
        int getGoods() const;

        //FUNCTION TO DETERMINE IF IT IS ADJACENT TO POWERLINES
        void setPower();
        bool hasPower() const;



    private:
        int goods;
        bool power;

};

#endif //INDUSTRIAL_H