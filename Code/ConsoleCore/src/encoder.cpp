#include "encoder.hpp"

#include "Arduino.h"

// Note: Clockwise = +'ve delta

Encoder::Encoder(){
    lastCheckTimeMillis = 0;
}

void Encoder::init(){
    // Initialize each encoder in our list
    for(int i = 0; i < NUM_ENCODERS; i++){
        // Set the encoder pins to input. Redundant because pins are usually inputs by default, but assert anyways.
        pinMode(encoderMap[i].pinA, INPUT);
        pinMode(encoderMap[i].pinB, INPUT);
        
        // Set encoder object details to initial values
        EncoderState* thisEnc = &encStates[i]; // For readability
        thisEnc->enc = (EncoderEnum)i;
        thisEnc->currentStateA = true;
        thisEnc->currentStateB = true;
        thisEnc->lastStateA = true;
        thisEnc->lastStateB = true;
        thisEnc->delta = 0;
        
    }
}

void Encoder::tick(){
    int now = millis();

    // We only care about sampling once every couple of milliseconds. The tick function is called much faster
    // If we aren't ready to sample, just return out of the function.
    if(now - lastCheckTimeMillis < MIN_ENC_PERIOD_MILLIS){
        return;
    }

    getEncoderStates();
    
    // Check the state changes for each encoder in our list
    for(int i = 0; i < NUM_ENCODERS; i++){
        EncoderState* thisEnc = &encStates[i];  // For readability, store the address of the current encoder state object.

        if((thisEnc->currentStateA != thisEnc->lastStateA || thisEnc->currentStateB != thisEnc->lastStateB) && (thisEnc->currentStateA != thisEnc->currentStateB)){
            // Only evaluate when the encoder A and B states change and become different values
            if(thisEnc->currentStateA != thisEnc->lastStateA){
                // A is the leader, move one way
                thisEnc->delta += 1;
            } else if(thisEnc->currentStateB != thisEnc->lastStateB){
                // B is the leader, move the other way
                thisEnc->delta -= 1;
            }
        }
    }

    lastCheckTimeMillis = now;
   
}

// Returns the delta of the encoder rotation since the last time this function was called
int Encoder::getEncoderDelta(EncoderEnum encIndex){
    int delta = encStates[encIndex].delta;
    encStates[encIndex].delta = 0;  // Reset the delta after it's been read
    return delta;
}

void Encoder::getEncoderStates(){
    // In the future, this function will get values from the IO expander or a multiplexer.
    for(int i = 0; i < NUM_ENCODERS; i++){
        EncoderState* thisEnc = &encStates[i];
        
        thisEnc->lastStateA = thisEnc->currentStateA;
        thisEnc->lastStateB = thisEnc->currentStateB;
        thisEnc->currentStateA = digitalRead(encoderMap[thisEnc->enc].pinA);
        thisEnc->currentStateB = digitalRead(encoderMap[thisEnc->enc].pinB);        
    }
    

}