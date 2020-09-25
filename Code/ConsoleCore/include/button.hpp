#ifndef IO_HPP
#define IO_HPP

// Adapted from HapticEye IO class, check it out! 
// https://github.com/Aliasmk/HapticEye-Clock

#include "pins.hpp"

#define BTN_ACTIVE_HIGH

#define DEBOUNCE_TIME_MIN_MS 50
#define CLICK_TIME_MAX_MS 750

typedef enum ButtonEnum{
    BTN_ENC1,
    BTN_ENC2,
    BTN_ENC3,
    BTN_ENC4,
    NUM_BUTTONS
} ButtonEnum;

typedef struct ButtonMap{
    ButtonEnum btn;
    uint8_t pin;
} ButtonMap;

typedef struct ButtonStatus{
    long timeSwitched;
    ButtonEnum btn;
    bool lastState;
    bool clicked;
    bool holdLock;
} ButtonStatus;

class Button{
public:
    Button();
    
    void tick();

    bool buttonHeld(ButtonEnum btn, int delay);
    bool buttonClicked(ButtonEnum btn);
    bool buttonDown(ButtonEnum btn);
    bool buttonUp(ButtonEnum btn);

private:
    ButtonStatus btnStatus[NUM_BUTTONS];
    ButtonStatus* getButtonStatus(ButtonEnum btn);
    
    const ButtonMap btnMap[4] = {
        {BTN_ENC1, PIN_ENCBTN1},
        {BTN_ENC2, PIN_ENCBTN2},
        {BTN_ENC3, PIN_ENCBTN3},
        {BTN_ENC4, PIN_ENCBTN4}
    };
    uint8_t getPin(ButtonEnum btn);

    bool pressedValue;
};


#endif