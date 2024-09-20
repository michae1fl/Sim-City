#include "residential.h"

Residential::Residential() {

    power = false;
    residents = 0;

}

void Residential::incResidents() {
    residents ++;
}

void Residential::decResidents() {
    residents --;
}

int Residential::getResidents() const {
    return residents;
}

void Residential::setPower() {
    power = true;
}

bool Residential::hasPower() const {
    return power;
}
