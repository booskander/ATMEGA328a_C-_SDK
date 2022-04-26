/*
Configuration:    
    A0: LED (Green to -)
    A1: LED (Red to +)
    A6: Right Photoresistance
    A7: Left Photoresistance
                  A3-A7: Suiveur de ligne (A7=Cal)
                  AVCC-AGRND: Capteur distance droit
                  B0-B1: VCC-GRN suiveur de ligne (respectivement)
                  B2 et B4: Moteur droit (B2=Dir/B4=PWM)
                  B3 et B5: Moteur gauche (B5=Dir/B3=PWM)
                  B6-B7: Piezo-electrique
                  BVCC-BGRND: Capteur distance gauche
                  C en entier: Ecran LCD
                  D0-D1: Libre pour transmit UART
                  D2: Libre pour interrupteur
                  D3: Libre
                  D4: Libre pour timer 2 (interruptions)
                  D5 et D7: LED
                  D6: Libre
                  DVCC-DGRND: Libres
                  Potentiometre a 2.8V
*/

#define F_CPU 8000000
#include <Robot.h>

int main() {
    Robot robot;
    robot.followLight();
    return 0;
}
