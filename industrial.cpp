#include "industrial.h"

Industrial::Industrial() {

    goods = 0;
    power = false;

}

void Industrial::incGoods() {
    goods ++;
}

void Industrial::decGoods() {
    goods --;
}

int Industrial::getGoods() const {
    return goods;
}

int Industrial::getGoods() const {
    return goods;
}

void Industrial::setPower() {
    power = true;
}

bool Industrial::hasPower() const {
    return power;
}