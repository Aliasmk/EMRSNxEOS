#include <Arduino.h>

#include "io.hpp"

// NOTE: Assumes buttons ACTIVE HIGH

IO::IO(){
    
    pinMode(PIN_ENCBTN1, INPUT);
    pinMode(PIN_ENCBTN2, INPUT);
    pinMode(PIN_ENCBTN3, INPUT);
    pinMode(PIN_ENCBTN4, INPUT);

    for(int i = 0; i < NUM_BUTTONS; i++){
        btnStatus[i].btn = (Button)i;
        btnStatus[i].clicked = false;
        btnStatus[i].lastState = LOW; //Buttons start out low
        btnStatus[i].timeSwitched = 0;
        btnStatus[i].holdLock = false;
    }

}

void IO::tick(){
    long now = millis();
    
    // Poll the states of each button in the button list
    for(int i = 0; i < NUM_BUTTONS; i++){
        
    
        int buttonPin = getPin((Button)i);
        bool currentButtonState = digitalRead(buttonPin);
        
        // Check for state changes
        if(currentButtonState != btnStatus[i].lastState){
            // Button state has changed
            
            if((now - btnStatus[i].timeSwitched) > DEBOUNCE_TIME_MIN_MS){
                // State change probably wasn't a bounce
                
                if(currentButtonState == LOW){
                    // Button has been released
                    btnStatus[i].holdLock = false;
                    
                    if((now - btnStatus[i].timeSwitched) < CLICK_TIME_MAX_MS){
                        // Button was clicked
                        btnStatus[i].clicked = true;
                    } else {
                        //Serial.print(F("(held "));
                        //Serial.print(now - btnStatus[i].timeSwitched);
                        //Serial.print(F(" ms)"));
                    }
                } else {
                    // Button has been pressed
                    btnStatus[i].clicked = false;
                }

                // Store this state change information
                btnStatus[i].lastState = currentButtonState;
                btnStatus[i].timeSwitched = now;
            }
        }

       
    }


}

bool IO::buttonHeld(Button btn, int delay){
    long now = millis();
    // Check if the button was held longer than the delay, the button is currently not pressed, and we haven't tested for this hold before.
    if((now - btnStatus[(int)btn].timeSwitched) > delay && btnStatus[(int)btn].lastState == HIGH && btnStatus[(int)btn].holdLock == false){
        btnStatus[(int)btn].holdLock = true;    // Set the hold lock so that we don't trigger multiple times in different places while the button stays held
        return true;
    } else {
        return false;
    }
}

bool IO::buttonClicked(Button btn){
    // Check if the button was clicked and there is no hold lock in place
    if(btnStatus[(int)btn].clicked == true && btnStatus[(int)btn].holdLock == false){
        btnStatus[(int)btn].clicked = false;
        return true;
    } else {
        return false;
    }
}

bool IO::buttonDown(Button btn){
    // Return true if the button is currently pressed
    if(btnStatus[(int)btn].lastState == HIGH){
        return true;
    } else {
        return false;
    }
}

bool IO::buttonUp(Button btn){
    // Return true if the button is currently not pressed
    if(btnStatus[(int)btn].lastState == LOW){
        return true;
    } else {
        return false;
    }
}

uint8_t IO::getPin(Button btn){
    for(int i = 0; i < NUM_BUTTONS; i++){
        if(btnMap[i].btn == btn){
            return btnMap[i].pin;
        }
    }
    return 0;
}

ButtonStatus* IO::getButtonStatus(Button btn){
    for(int i = 0; i < NUM_BUTTONS; i++){
        if(btnStatus[i].btn == btn){
            return &btnStatus[i];
        }
    }
    return nullptr;
}