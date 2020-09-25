#include "encoder.hpp"

#include "Arduino.h"

// Note: Clockwise = +'ve delta

Encoder::Encoder(){
    // Initialize each encoder in our list
    for(int i = 0; i < NUM_ENCODERS; i++){
        EncoderState* thisEnc = &encStates[i]; // For readability

        // Set the encoder pins to input. Redundant because pins are inputs by default, but assert anyways.
        pinMode(encoderMap[thisEnc->enc].pinA, INPUT);
        pinMode(encoderMap[thisEnc->enc].pinB, INPUT);
        
        // Set encoder object details to initial values
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

    // We only care about sampling once every couple of milliseconds. The tick function is called much faster
    // If we aren't ready to sample, just return out of the function.
    if(now - lastCheckTimeMillis < MIN_ENC_PERIOD_MILLIS){
        return;
    }

    getEncoderStates();
    
    // Check the state changes for each encoder in our list
    for(int i = 0; i < NUM_ENCODERS; i++){
        EncoderState* thisEnc = &encStates[i];  // For readability, store the address of the current encoder state object.

        // Because the encoder changes state four times per 'click', we only care about picking up one of the transitions.
        // Check for a transition of A from high to low. 
        if(thisEnc->lastStateA != thisEnc->currentStateA && thisEnc->currentStateA == false){
            // If during the transition, B is low, we've turned clockwise, otherwise we've turned counterclockwise.
            if(thisEnc->currentStateB == false){
                thisEnc->delta += 1;
            } else {
                thisEnc->delta += -1;
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