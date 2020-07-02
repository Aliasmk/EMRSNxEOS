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

    lastCheckTimeMillis = 0;
}

void Encoder::tick(){
    int now = millis();

    if(now - lastCheckTimeMillis < MIN_ENC_PERIOD_MILLIS){
        return;
    }
    
    digitalWrite(26, HIGH);
    getEncoderStates();
    
    for(int i = 0; i < NUM_ENCODERS; i++){
        EncoderState* thisEnc = &encStates[i];
        int delta = 0;
        if(thisEnc->lastStateA != thisEnc->currentStateA && thisEnc->currentStateA == false){
            
            /*if(thisEnc->lastStateA == thisEnc->lastStateB){
                delta = -1;
            } else {
                delta = 1;
            }*/

            if(thisEnc->currentStateB == false){
                delta = 1;
            } else {
                delta = -1;
            }

        }
        thisEnc->delta += delta;
        
        
        //if((now - thisEnc->lastChangeTimeMillis) > MIN_ENC_PERIOD_MILLIS){
        /*   
            int oldState = stateToValue(thisEnc->lastStateA, thisEnc->lastStateB);
            int newState = stateToValue(thisEnc->currentStateA, thisEnc->currentStateB);

            delta = encoderMatrix[oldState][newState];
            if(delta != ENC_INVALID && delta != 0){
                thisEnc->delta += delta;          
            }
        */
            
    //}
    }
    digitalWrite(26, LOW);
    lastCheckTimeMillis = now;
   
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