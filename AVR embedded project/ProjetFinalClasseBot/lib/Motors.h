#pragma once
#include <avr/io.h>
#include <util/delay.h>


class Motors {
    public:
        Motors();
        void moveForwardRight(uint8_t vD);
        void moveBackwardRight(uint8_t vD);
        void moveForwardLeft(uint8_t vG);
        void moveBackwardLeft(uint8_t vG);
        void setVelocity(int percentLeft, int percentRight);
        void stopMotors();
    private:
        uint8_t convertPercentage(uint8_t percentage);
};
