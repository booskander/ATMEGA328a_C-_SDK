#pragma once
#include <avr/io.h>
#include "memoire_24.h"

class Uart {
    public:
        Uart();
        uint8_t recevoirByte();
        void transmettreByte(uint8_t donnee);
};