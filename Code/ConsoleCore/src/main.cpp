#include <Arduino.h>

#define TEST
#define VERSION "0.1"

#include <button.hpp>
#include <osc.hpp>
#include <display.hpp>
//#include <console_wifi.hpp>

//#include <U8g2lib.h>

Button btn;
OSC osc;
Display display;
//ConsoleWiFi wifi;

#include <pins.hpp>

void setup() {
  pinMode(12, OUTPUT);
  osc.init();
  display.init();
  btn.init();
  //wifi.initHotspot();*/

  ledcSetup(0, 5000, 8);
  ledcAttachPin(PIN_LED_PWM, 0);
  ledcWrite(0, 1);
  delay(30);
  ledcWrite(0, 2);
  delay(30);
  ledcWrite(0, 4);
  delay(30);
  ledcWrite(0, 8);
  delay(30);
  ledcWrite(0, 16);
  delay(30);
  ledcWrite(0, 32);
  delay(30);
  ledcWrite(0, 64);
  delay(30);
  ledcWrite(0, 128);
  delay(30);
  ledcWrite(0, 255);
  delay(30);
  ledcWrite(0, 128);
  delay(30);
  ledcWrite(0, 64);
  delay(30);
   ledcWrite(0, 32);
  delay(30);
   ledcWrite(0, 16);
  delay(30);
ledcWrite(0, 8);
  delay(30);
   ledcWrite(0, 4);
  delay(30);
  ledcWrite(0, 2);
  delay(30);
    ledcWrite(0, 1);
  delay(30);
}


void loop() {
  osc.poll();
  btn.tick();
  
  //Do potentially long-running tasks while serial is idle so we don't miss serial data
  if(osc.isIdle() || OSC::oscState.status == ERROR){
    display.tick();
  }
}

