#define F_CPU 8000000L
#include <avr/io.h>
#include <avr/delay.h>
#include "capteurdistance.h"
# include "Can.h"
#include "math.h"

CapteurDistance::CapteurDistance() {
    DDRA &= ~(1 << PA4);
}

uint8_t CapteurDistance::convertisseurAnalogiqueCm(uint8_t valeurAnalogique) {
  uint8_t comparator = fabs(valeurAnalogique - listeEquivalenceDistance[0]);
  uint8_t valeurEnCm = 4;
  for (int i = 0; i < 27; ++i) {
    if (fabs(valeurAnalogique - listeEquivalenceDistance[i]) < comparator) {
      comparator = fabs(valeurAnalogique - listeEquivalenceDistance[i]);
      valeurEnCm = i + 4;
    }
  }
  return valeurEnCm;
}

uint8_t CapteurDistance::lectureDistance() {
    Can can;
    distance = uint8_t(can.lecture(4) >> 2);
    _delay_ms(30);
    
    return convertisseurAnalogiqueCm(distance);
}