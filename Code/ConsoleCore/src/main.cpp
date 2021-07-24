#include <Arduino.h>

#define TEST
#define VERSION "0.1"

#include <button.hpp>
#include <osc.hpp>
#include <display.hpp>
#include <encoder.hpp>
#include <fader.hpp>
#include <driver/dac.h>
#include <console_wifi.hpp>

//#include <U8g2lib.h>

Encoder encoder;
Fader fader;
Button btn;
OSC osc;
Display display;
ConsoleWiFi wifi;

#include <pins.hpp>

void setup() {
  pinMode(PIN_LED, OUTPUT);
  osc.init();
  display.init();
  btn.init();
  encoder.init();
  wifi.initHotspot();

  // Enable MVC keypad backlight
  ledcSetup(0, 5000, 8);
  ledcAttachPin(PIN_LED_PWM, 0);
  for(int i = 0; i <= 8; i++){
    ledcWrite(0, pow(2,i));
    delay(35);
  }
}


void loop() {
  osc.poll();
  btn.tick();
  encoder.tick();
  fader.tick();
  
  //Do potentially long-running tasks while serial is idle so we don't miss serial data
  if(osc.isIdle() || OSC::oscState.status == ERROR){
    display.tick();
  }
}

