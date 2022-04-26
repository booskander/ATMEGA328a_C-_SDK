#pragma once
#include "Led.h"
#include "PhotoResistance.h"
#include "Motors.h"
#include "uart.h"
#include "capteurdistance.h"
#include "boutonpoussoir.h"


class Robot {
public:
   Robot();
   void followLight();
   void initISR();
   bool detectWall();
   // void blinkRed();
   // void blinkGreen();
   // void blinkAmbre();
   // void setRed();
   // void setGreen();
   // void setAmbre();
   // void setGreen();
   void followWall();
   void makeUTurn();
   void setAmbre();
   BoutonPoussoir getBouton();
   PhotoResistance getPhoto();


private:
   Led led_;
   PhotoResistance photoResistance_;
   Motors motors_;
   CapteurDistance cd_;
   BoutonPoussoir boutonBlanc_;
   
};
