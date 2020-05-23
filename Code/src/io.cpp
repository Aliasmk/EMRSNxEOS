#include <io.hpp>

#include <Arduino.h>
#include <display.hpp>

IO::IO() : 
    buttonPins({PIN_BTN1, PIN_BTN2, PIN_BTN3})
{

}

bool IO::init(){
    for(int i = 0; i < N_BTNS; i++){
        pinMode(buttonPins[i], INPUT);
    }

    pinMode(PIN_KEY_LED, OUTPUT);
    #ifdef ESP32
    ledcSetup(0, 5000, 8);
    ledcAttachPin(PIN_KEY_LED, 0);
    #endif
    
    for(int i = 0; i < 8; i++){
        analogWrite(PIN_KEY_LED, 1<<i);
        delay(75);
    }

    for(int i = 7; i >= 0; i--){
        analogWrite(PIN_KEY_LED, 1<<i);
        delay(75);
    }
    analogWrite(PIN_KEY_LED, 33);
    return true;
}

#ifdef ESP32
void analogWrite(int pin, int val){
    ledcWrite(0, val);
}
#endif

void IO::poll(){
    for(int i = 0; i < N_BTNS; i++){
        bool currentReading = digitalRead(buttonPins[i]);
        if(currentReading != buttonStates[i]){
            //Button State Changed
            buttonStates[i] = currentReading;
            if(currentReading == HIGH){
                buttonPressedCallback(i);
            }

        }
    }
}

void IO::buttonPressedCallback(int button){
    if(button == 0){
     
    }
}