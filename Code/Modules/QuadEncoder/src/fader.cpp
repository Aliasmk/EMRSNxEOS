#include "fader.hpp"

#include "Arduino.h"

Fader::Fader(){
    for(int i = 0; i < NUM_FADERS; i++){
        pinMode(faderPinMap[i], INPUT);
    }
}

void Fader::tick(){
    for(int i = 0; i < NUM_FADERS; i++){
        faderValue[i] = analogRead(faderPinMap[i]);
    }
}