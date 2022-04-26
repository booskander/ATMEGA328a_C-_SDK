#include "Motors.h"
uint8_t MINIMUM_PWM = 155;
uint8_t MAX_PWM = 255;

Motors::Motors() {
    DDRB |= (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5);
}

void Motors::setVelocity(int velocityLeft, int velocityRight) {
    if(velocityLeft < -MAX_PWM) { 
        velocityLeft = -MAX_PWM;
    } 
    else if(velocityLeft > MAX_PWM) { 
        velocityLeft = MAX_PWM; 
    }

    if(velocityRight < -MAX_PWM) { 
        velocityRight = -MAX_PWM; 
    }
    else if(velocityRight > MAX_PWM) { 
        velocityRight = MAX_PWM; 
    }

    if(velocityLeft < 0) { 
        moveBackwardLeft(-velocityLeft); 
    }
    else { 
        moveForwardLeft(velocityLeft); 
    }

    if(velocityRight < 0) { 
        moveBackwardRight(-velocityRight); 
    } 
    else { 
        moveForwardRight(velocityRight); 
    }
}

void Motors::moveForwardRight(uint8_t velocityRight) {
    OCR0B = velocityRight;
    TCCR0A |= (1 << WGM00) | (1 << COM0B1);
    TCCR0A &= ~(1 << COM0B0);
    TCCR0B |= (1 << CS01);
    DDRB |= (1 << PB4);
    PORTB &= ~(1 << PB5);
}

void Motors::moveBackwardRight(uint8_t velocityRight) {
    OCR0B = velocityRight;
    TCCR0A |= (1 << WGM00) | (1 << COM0B1);
    TCCR0A &= ~(1 << COM0B0);
    TCCR0B |= (1 << CS01);
    DDRB |= (1 << PB4) | (1 << PB5);
    PORTB |= (1 << PB5);
}

void Motors::moveForwardLeft(uint8_t velocityLeft) {
    OCR0A = velocityLeft;
    TCCR0A |= (1 << WGM00) | (1 << COM0A1);
    TCCR0A &= ~(1 << COM0A0);
    TCCR0B |= (1 << CS01);
    DDRB |= (1 << PB3);
    PORTB &= ~(1 << PB2);
}

void Motors::moveBackwardLeft(uint8_t velocityLeft) {
    OCR0A = velocityLeft;
    TCCR0A |= (1 << WGM00) | (1 << COM0A1);
    TCCR0A &= ~(1 << COM0A0);
    TCCR0B |= (1 << CS01);
    DDRB |= (1 << PB2) | (1 << PB3);
    PORTB |= (1 << PB2);
}

void Motors::stopMotors() {
    OCR0A = 0;
    OCR0B = 0;
}
