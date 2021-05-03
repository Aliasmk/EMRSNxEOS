#ifndef ENCODER_HPP
#define ENCODER_HPP

#include "pins.hpp"
#include "stdint.h"

#define ENC_INVALID 99

#define MIN_ENC_PERIOD_MILLIS 1

// Note: this class does not handle encoder pushbuttons, only the quadrature sampling and decoding.

typedef enum EncoderEnum{
    ENC1,
    ENC2,
    ENC3,
    ENC4,
    NUM_ENCODERS
} EncoderEnum;

typedef struct EncoderMapItem{
    EncoderEnum enc;
    uint8_t pinA;
    uint8_t pinB;
} EncoderMapItem;

typedef struct EncoderState{
    EncoderEnum enc;
    bool lastStateA;
    bool lastStateB;
    bool currentStateA;
    bool currentStateB;
    int delta;
} EncoderState;


class Encoder{
public:
    Encoder();
    void init();
    void tick();
    int getEncoderDelta(EncoderEnum encoderIndex);


private:
    void getEncoderStates();
    EncoderState encStates[NUM_ENCODERS];
    int lastCheckTimeMillis;

    uint8_t stateToValue(bool channelA, bool channelB);

    EncoderMapItem encoderMap[NUM_ENCODERS] = {
        {ENC1, PIN_ENC1_A, PIN_ENC1_B},
        {ENC2, PIN_ENC2_A, PIN_ENC2_B},
        {ENC3, PIN_ENC3_A, PIN_ENC3_B},
        {ENC4, PIN_ENC4_A, PIN_ENC4_B}
    };

    const int encoderMatrix[4][4] = {
        {0, -1, 1, ENC_INVALID},
        {1, 0,  ENC_INVALID, -1},
        {-1, ENC_INVALID, 0, 1},
        {ENC_INVALID, 1, -1, 0}
    };
};


#endif