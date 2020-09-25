#ifndef FADER_HPP
#define FADER_HPP

#include "pins.hpp"
#include "stdint.h"

#define NUM_FADERS 3

class Fader{
public:
    Fader();

    void tick();
    void getFaderValue(int faderIndex);

private:
    uint8_t faderValue[NUM_FADERS];
    uint8_t faderPinMap[NUM_FADERS] = { PIN_SLD_1, PIN_SLD_2, PIN_SLD_3 };

};

#endif