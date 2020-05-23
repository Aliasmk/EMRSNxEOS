#ifndef IO_H
#define IO_H

#define N_BTNS 4

#define PIN_BTN1 19
#define PIN_BTN2 21
#define PIN_BTN3 22
#define PIN_KEY_LED 12

class IO{
public:
    IO();

    bool init();
    void poll();

private:
    int buttonPins[N_BTNS];
    bool buttonStates[N_BTNS];
    void buttonPressedCallback(int button);

};


#ifdef ESP32
void analogWrite(int pin, int val);
#endif

#endif