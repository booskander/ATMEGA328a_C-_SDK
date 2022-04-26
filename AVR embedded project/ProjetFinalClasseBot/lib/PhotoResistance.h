#pragma once
#include "Can.h"
#include "Led.h"
//const uint8_t GREEN_BORDER = 0b11000000;
//const uint8_t RED_BORDER = 0b0111000;
//const uint16_t LIGHT_BORDER = 1000;
const uint16_t ITERATIONS = 250;

class PhotoResistance {
public:
   PhotoResistance();
   uint8_t readValue(uint8_t pin);
   uint8_t getRight() { return averageRightLight_; }
   uint8_t getLeft() { return averageRightLight_; }

   
private:
   uint8_t averageRightLight_ = 0;
   uint8_t averageLeftLight_ = 0;
};
