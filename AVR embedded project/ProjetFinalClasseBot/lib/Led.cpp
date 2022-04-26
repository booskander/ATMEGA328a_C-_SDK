#include "Led.h"

Led::Led() {
    DDRA |= (1 << PORTA0) | (1 << PORTA1);
};

void Led::setColor(Color color) {
    switch (color) {
    case Green:
        PORTA &= ~(1 << PORTA1);
        PORTA |= (1 << PORTA0);
        break;

    case Red:
        PORTA &= ~(1 << PORTA0);
        PORTA |= (1 << PORTA1);
        break;

    case Amber:                     // Amber needs to be in a loop.
        setColor(Red);
        _delay_ms(RED_RATIO);
        setColor(Green);
        _delay_ms(GREEN_RATIO);
        break;

    case Off:
        PORTA &= ~(1 << PORTA1 | 1 << PORTA0);
        break;
    }
}

void Led::blink(Color color, uint8_t iteration) {
    switch (color) {
        case Green:
            for (uint8_t i = 0; i < iteration; i++) {
                setColor(Green);
                _delay_ms(BLINK_DURATION);
                setColor(Off);
                _delay_ms(BLINK_DURATION);
            }
            break;

        case Red:
            for (uint8_t i = 0; i < iteration; i++) {
                setColor(Red);
                _delay_ms(BLINK_DURATION);
                setColor(Off);
                _delay_ms(BLINK_DURATION);
            }
            break;

        case Amber:
            for (uint8_t i = 0; i < iteration; i++) {
                for (uint8_t i = 0; i < (BLINK_DURATION / AMBER_FACTOR); i++) {
                    setColor(Amber);
                }
                setColor(Off);
                _delay_ms(BLINK_DURATION);
            }
            break; 

        case Off:
            break;
    }
}