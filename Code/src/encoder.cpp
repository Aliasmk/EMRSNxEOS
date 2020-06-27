#include "encoder.hpp"

#include "Arduino.h"

// Encoders can be sampled without interrupts, as long as the sample rate is four times the tick rate expected. 
// (https://electronics.stackexchange.com/questions/121564/encoder-sampling-rate-realization)

// Quadrature Decoding inspired from https://cdn.sparkfun.com/datasheets/Robotics/How%20to%20use%20a%20quadrature%20encoder.pdf

// Note: Clockwise = +'ve delta

Encoder::Encoder(){
    for(int i = 0; i < NUM_ENCODERS; i++){
        EncoderState* thisEnc = &encStates[i];
        pinMode(encoderMap[thisEnc->enc].pinA, INPUT);
        pinMode(encoderMap[thisEnc->enc].pinB, INPUT);
        
        thisEnc->enc = (EncoderEnum)i;
        thisEnc->currentStateA = true;
        thisEnc->currentStateB = true;
        thisEnc->lastStateA = true;
        thisEnc->lastStateB = true;
        thisEnc->delta = 0;
    }
}

void Encoder::tick(){
    getEncoderStates();

    for(int i = 0; i < NUM_ENCODERS; i++){
        EncoderState* thisEnc = &encStates[i];
        
        uint8_t oldState = stateToValue(thisEnc->lastStateA, thisEnc->lastStateB);
        uint8_t newState = stateToValue(thisEnc->currentStateA, thisEnc->currentStateB);

        int delta = encoderMatrix[oldState][newState];
        if(delta != ENC_INVALID){
            thisEnc->delta += delta;
        }
    }
}

int Encoder::getEncoderDelta(EncoderEnum encIndex){
    int delta = encStates[encIndex].delta;
    encStates[encIndex].delta = 0;
    return delta;
}

uint8_t Encoder::stateToValue(bool channelA, bool channelB){
    uint8_t state = 0;
    state |= (channelA == true ? 0x2 : 0x0);
    state |= (channelB == true ? 0x1 : 0x0);
    return state;
}

void Encoder::getEncoderStates(){
    // In the future, this function will get values from i2c (from the IO expander).
    for(int i = 0; i < NUM_ENCODERS; i++){
        EncoderState* thisEnc = &encStates[i];
        
        thisEnc->lastStateA = thisEnc->currentStateA;
        thisEnc->lastStateB = thisEnc->currentStateB;
        thisEnc->currentStateA = digitalRead(encoderMap[thisEnc->enc].pinA);
        thisEnc->currentStateB = digitalRead(encoderMap[thisEnc->enc].pinB);
    }

}