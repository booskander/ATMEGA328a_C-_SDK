#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Robot.h"

enum Etat {
    INIT,  
    EXEC, 
    ATTENTE, 
    REPRISE, 
    DEMITOUR, 
    SUIVILUMIERE
};

volatile Etat gEtat = Etat::INIT;

Robot robot = Robot();



int main(){
    robot.initISR();
    while(true){
        switch (gEtat){
            case Etat::INIT:
                if(robot.getBouton().appuye()){
                    //robot.blinkRed();
                    gEtat = Etat::REPRISE;
                }
                break;
            
            case Etat::EXEC:
                robot.followWall();
                gEtat = Etat::ATTENTE;
                break;

            // case Etat::ATTENTE:
            //     while(robot.getPhoto().readValue(6) <= Photoresistance::VALEUR_AMBIANTE &&
            //           robot.getPhoto().readValue(7) <= Photoresistance::VALEUR_AMBIANTE){
            //         if(robot.getBouton().appuye())
            //             gEtat = Etat::DEMITOUR;
            //     }
            //     gEtat = Etat::SUIVILUMIERE;
            //     break;
            
            case Etat::SUIVILUMIERE:
                robot.followLight();
                gEtat = Etat::EXEC;
                break;

            case Etat::REPRISE:
                gEtat = Etat::ATTENTE;
                break;
            
            case Etat::DEMITOUR:
                robot.makeUTurn();
                gEtat = Etat::EXEC;
                break;
            
            default:
                break;
        }
    }



    return 0;
}

ISR(INT0_vect){
    
    if(gEtat == Etat::INIT){
        //robot.blinkGreen();
        gEtat = Etat::EXEC;
    }    
    else {
        gEtat = Etat::DEMITOUR;
    }
}