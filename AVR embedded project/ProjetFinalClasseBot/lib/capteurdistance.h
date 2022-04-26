# pragma once

class CapteurDistance {
    public :
        CapteurDistance();
        uint8_t lectureDistance();

    private :
        uint8_t convertisseurAnalogiqueCm(uint8_t valeurAnalogique);
        uint8_t distance;
        uint8_t listeEquivalenceDistance[27] = {174, 185, 184, 183, 172, 146, 129, 127,
                              113, 109, 105, 97, 91, 87, 82, 78, 77,
                              71, 68, 65, 62, 61, 58, 57, 56, 54, 53
                              };
};

