#ifndef IO_HPP
#define IO_HPP

// Adapted from HapticEye IO class, check it out! 
// https://github.com/Aliasmk/HapticEye-Clock

#include "pins.hpp"

#define BTN_ACTIVE_HIGH

#define DEBOUNCE_TIME_MIN_MS 100
#define CLICK_TIME_MAX_MS 500

typedef enum Button{
    BTN_ENC1,
    BTN_ENC2,
    BTN_ENC3,
    BTN_ENC4,
    NUM_BUTTONS
} Button;

typedef struct ButtonMap{
    Button btn;
    uint8_t pin;
} ButtonMap;

typedef struct ButtonStatus{
    long timeSwitched;
    Button btn;
    bool lastState;
    bool clicked;
    bool holdLock;
} ButtonStatus;

class IO{
public:
    IO();
    
    void tick();

    bool buttonHeld(Button btn, int delay);
    bool buttonClicked(Button btn);
    bool buttonDown(Button btn);
    bool buttonUp(Button btn);

private:
    ButtonStatus btnStatus[NUM_BUTTONS];
    ButtonStatus* getButtonStatus(Button btn);
    
    const ButtonMap btnMap[4] = {
        {BTN_ENC1, PIN_ENCBTN1},
        {BTN_ENC2, PIN_ENCBTN2},
        {BTN_ENC3, PIN_ENCBTN3},
        {BTN_ENC4, PIN_ENCBTN4}
    };
    uint8_t getPin(Button btn);

    bool pressedValue;
};


#endif