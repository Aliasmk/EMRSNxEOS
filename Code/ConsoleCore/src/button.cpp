#include <Arduino.h>

#include "button.hpp"
#include "pins.hpp"

bool newState;
void IRAM_ATTR BtnIntISR(){
    newState = true;
}





Button::Button() : ioxp(0x20) {
    newState = false;

    for(int i = 0; i < NUM_BUTTONS; i++){
        btnStatus[i].btn = (ButtonEnum)i;
        btnStatus[i].clicked = false;
        btnStatus[i].lastState = LOW; //Buttons start out low
        btnStatus[i].timeSwitched = 0;
        btnStatus[i].holdLock = false;
    }
}

bool Button::newData(){
    return newState;
}

void Button::init(){
    ioxp.connectInterrupts(true);
    ioxp.setInterruptPolarityHigh(false);
    ioxp.enableInterrupt(0xFFFF);    // Bitmask for GPIOA 0-6 and GPIOB 0-3
    ioxp.getPinStates();
    attachInterrupt(PIN_BTN_INT, BtnIntISR, FALLING);
}

void Button::tick(){
    uint16_t pinStates;
    static int tick = 0;
    if(newState || tick % 50 == 0){
        pinStates = ioxp.getPinStates();
        newState = false;
    } else {
        return;
    }
    

    long now = millis();

    // Poll the states of each button in the button list
    for(int i = 0; i < NUM_BUTTONS; i++){
    
    int buttonPin = getPin((ButtonEnum)i);
    bool currentButtonState = (((~pinStates) & (1 << buttonPin)) > 0) ? true : false;
        
        // Check for state changes
        if(currentButtonState != btnStatus[i].lastState){
            // Button state has changed
            
            if((now - btnStatus[i].timeSwitched) > DEBOUNCE_TIME_MIN_MS){
                // State change probably wasn't a bounce
                Serial.print(F("Button "));
                Serial.print(i);
                Serial.print(": ");
                
                if(currentButtonState == LOW){
                    // Button has been released
                    btnStatus[i].holdLock = false;
                    Serial.print(F("Released"));
                    
                    if((now - btnStatus[i].timeSwitched) < CLICK_TIME_MAX_MS){
                        // Button was clicked
                        Serial.print(F(" (clicked)"));
                        btnStatus[i].clicked = true;
                    } else {
                        Serial.print(F(" (held "));
                        Serial.print(now - btnStatus[i].timeSwitched);
                        Serial.print(F(" ms)"));
                    }
                } else {
                    // Button has been pressed
                    Serial.print(F("Pressed"));
                    btnStatus[i].clicked = false;
                }

                // Store this state change information
                btnStatus[i].lastState = currentButtonState;
                btnStatus[i].timeSwitched = now;
                Serial.println();
            }
            
        }
    }
    tick++;
}



bool Button::buttonHeld(ButtonEnum btn, int delay){
    long now = millis();
    // Check if the button was held longer than the delay, the button is currently not pressed, and we haven't tested for this hold before.
    if((now - btnStatus[(int)btn].timeSwitched) > delay && btnStatus[(int)btn].lastState == HIGH && btnStatus[(int)btn].holdLock == false){
        btnStatus[(int)btn].holdLock = true;    // Set the hold lock so that we don't trigger multiple times in different places while the button stays held
        return true;
    } else {
        return false;
    }
}

bool Button::buttonClicked(ButtonEnum btn){
    // Check if the button was clicked and there is no hold lock in place
    if(btnStatus[(int)btn].clicked == true && btnStatus[(int)btn].holdLock == false){
        btnStatus[(int)btn].clicked = false;
        return true;
    } else {
        return false;
    }
}

bool Button::buttonDown(ButtonEnum btn){
    // Return true if the button is currently pressed
    if(btnStatus[(int)btn].lastState == HIGH){
        return true;
    } else {
        return false;
    }
}

bool Button::buttonUp(ButtonEnum btn){
    // Return true if the button is currently not pressed
    if(btnStatus[(int)btn].lastState == LOW){
        return true;
    } else {
        return false;
    }
}

uint8_t Button::getPin(ButtonEnum btn){
    for(int i = 0; i < NUM_BUTTONS; i++){
        if(btnMap[i].btn == btn){
            return btnMap[i].pin;
        }
    }
    return 0;
}

ButtonStatus* Button::getButtonStatus(ButtonEnum btn){
    for(int i = 0; i < NUM_BUTTONS; i++){
        if(btnStatus[i].btn == btn){
            return &btnStatus[i];
        }
    }
    return nullptr;
}