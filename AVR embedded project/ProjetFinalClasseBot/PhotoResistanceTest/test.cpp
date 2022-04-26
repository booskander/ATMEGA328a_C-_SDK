#define F_CPU 8000000
#include "uart.h"
#include "PhotoResistance.h"

int main()
{
    PhotoResistance photo = PhotoResistance();
    Uart uart = Uart();
    

//     while(true){
//        // uint8_t mesure = photo.readValue(6);
//         uint8_t mesure = photo.readValue(6);
//         uart.transmettreByte(mesure);
//        // uart.transmettreByte(mesure1);
//    }

    while (true) {
    //uart.transmettreByte(photo.getLeft());
    uart.transmettreByte(photo.getRight());
    }




    return 0;
}