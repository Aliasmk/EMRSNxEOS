#include <Arduino.h>

#define TEST
#define VERSION "0.1"

#include <button.hpp>
#include <osc.hpp>
#include <display.hpp>
//#include <console_wifi.hpp>

#include <U8g2lib.h>

Button btn;
OSC osc;
Display display;
//ConsoleWiFi wifi;

#include <pins.hpp>

void setup() {
  osc.init();
  display.init();
  btn.init();
  //wifi.initHotspot();
  ledcSetup(0, 5000, 8);
  ledcAttachPin(PIN_LED_PWM, 0);
  ledcWrite(0, 200);

}


void loop() {
  osc.poll();
  btn.tick();
  
  //Do potentially long-running tasks while serial is idle so we don't miss serial data
  if(osc.isIdle() || OSC::oscState.status == ERROR){
    display.tick();
  }


  
  
}

