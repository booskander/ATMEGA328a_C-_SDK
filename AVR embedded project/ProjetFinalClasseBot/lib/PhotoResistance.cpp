#include "PhotoResistance.h"

PhotoResistance::PhotoResistance() {
    DDRA &= ~((1 << PORTA6) | (1 << PORTA7));
    Can readCan;

    uint16_t sumRight = 0;
    uint16_t sumLeft = 0;
    
    for (uint16_t i = 0; i < ITERATIONS; i++) {
        sumRight += (readCan.lecture(6) >> 2);
        sumLeft += (readCan.lecture(7) >> 2);
    }

    averageRightLight_ = uint8_t(sumRight / ITERATIONS);
    averageLeftLight_ = uint8_t(sumLeft / ITERATIONS);
}

uint8_t PhotoResistance::readValue(uint8_t pin) {
    Can readCan;
    return (readCan.lecture(pin) >> 2);
}