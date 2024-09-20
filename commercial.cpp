#include "commercial.h"

Commercial::Commercial() {

    power = false;
    workers = 0;

}

void Commercial::incWorkers() {
    workers ++;
}

void Commercial::decWorkers() {
    workers --;
}

int Commercial::getWorkers() const {
    return workers;
}

void Commercial::setPower() {
    power = true;
}

bool Commercial::hasPower() const {
    return power;
}