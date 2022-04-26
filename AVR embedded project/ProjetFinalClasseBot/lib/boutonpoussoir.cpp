#define F_CPU 8000000UL
#include <avr/io.h> 
#include <util/delay.h>
#include "boutonpoussoir.h"

bool BoutonPoussoir::appuye() {
    if (PIND & (1 << PD2)) {
        _delay_ms(10); //Delai de rebond
        if(PIND & (1 << PD2))
            return true;
    }
    return false;
}
