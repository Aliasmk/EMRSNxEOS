#include <Arduino.h>

#define TEST
#define VERSION "0.1"

#include <button.hpp>
#include <osc.hpp>
#include <display.hpp>
#include <console_wifi.hpp>


Button btn;
OSC osc;
Display display;
ConsoleWiFi wifi;

void setup() {
  osc.init();
  display.init();
  wifi.initHotspot();
}

void loop() {
  osc.poll();
  btn.tick();
  
  //Do potentially long-running tasks while serial is idle so we don't miss data
  if(osc.isIdle() || OSC::oscState.status == ERROR){
    display.tick();
  }
}

