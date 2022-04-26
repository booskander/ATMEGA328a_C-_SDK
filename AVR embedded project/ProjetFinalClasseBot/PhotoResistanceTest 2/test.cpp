#define F_CPU 8000000
#include "uart.h"
#include "PhotoResistance.h"
#include "Can.h"
int main()
{
    PhotoResistance photo = PhotoResistance();
    Uart uart = Uart();
    Can canh;
    while(true){
        //uint8_t mesure = photo.readValue(6);
        uint8_t mesure = canh.lecture(6) >> 2;

        //uint8_t mesure = photo.readValue(6);
        uart.transmettreByte(mesure);
       // uart.transmettreByte(mesure1);
   }

    while (true) {
    //uart.transmettreByte(photo.getLeft());
    //uart.transmettreByte(photo.getRight());
    }




    return 0;
}
