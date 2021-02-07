#ifndef IO_HPP
#define IO_HPP


#include "mcp23017.hpp"

#define BTN_ACTIVE_HIGH

#define DEBOUNCE_TIME_MIN_MS 50
#define CLICK_TIME_MAX_MS 750

typedef enum ButtonEnum{
    BTN_A1,
    BTN_A2,
    BTN_A3,
    BTN_B1,
    BTN_B2,
    BTN_B3,
    BTN_ENC1,
    BTN_ENC2,
    BTN_ENC3,
    BTN_ENC4,
    NUM_BUTTONS
} ButtonEnum;

typedef struct ButtonMap{
    ButtonEnum btn;
    uint16_t pin;
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
    uint16_t pinStates;
    bool newData();

    void init();

    bool buttonHeld(ButtonEnum btn, int delay);
    bool buttonClicked(ButtonEnum btn);
    bool buttonDown(ButtonEnum btn);
    bool buttonUp(ButtonEnum btn);

private:
    MCP23017 ioxp;

    ButtonStatus btnStatus[NUM_BUTTONS];
    ButtonStatus* getButtonStatus(ButtonEnum btn);
    
    const ButtonMap btnMap[10] = {
        {BTN_B1,   0},
        {BTN_B2,   1},
        {BTN_B3,   2},
        {BTN_A3,   3},
        {BTN_A2,   4},
        {BTN_A1,   5},
        {BTN_ENC4, 8},
        {BTN_ENC3, 9},
        {BTN_ENC2, 10},
        {BTN_ENC1, 11}
    };
    uint8_t getPin(ButtonEnum btn);

    bool pressedValue;


};

#endif