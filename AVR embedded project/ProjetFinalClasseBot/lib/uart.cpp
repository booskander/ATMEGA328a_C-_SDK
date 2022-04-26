#include "uart.h"

Uart::Uart() {
    UBRR0H = 0;
    UBRR0L = 0xCF;
    UCSR0A = 0;
    UCSR0B =  (1 << TXEN0)|(1 << RXEN0) ;
    UCSR0C =  (1 << UCSZ01) | (1 << UCSZ00);
    //(0 << UPM01) | (0 << UPM00) | (0 << USBS0) |

}

uint8_t Uart::recevoirByte() {
    while( !( UCSR0A & (1<<RXC0)) );
    return UDR0;
}

void Uart::transmettreByte(uint8_t donnee) {
    while ( !( UCSR0A & (1<<UDRE0)) );
    UDR0 = donnee;
}