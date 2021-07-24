#ifndef FADER_HPP
#define FADER_HPP

#include "pins.hpp"
#include "stdint.h"

#define NUM_FADERS 3

class Fader{
public:
    Fader();

    void tick();
    int getFaderValue(int faderIndex) { return faderValue[faderIndex]; };

private:
    int faderValue[NUM_FADERS];
    int faderPinMap[NUM_FADERS] = { PIN_SLD1, PIN_SLD2, PIN_SLD3 };

};

#endif