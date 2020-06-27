#include <Arduino.h>

#define TEST
#define VERSION "0.1"

#include <io.hpp>
#include <osc.hpp>
#include <display.hpp>
#include <encoder.hpp>


IO io;
Encoder encoder;
OSC osc;
Display display;


void setup() {
  osc.init();
  display.init();
}

void loop() {
  osc.poll();
  io.tick();
  encoder.tick();

  //Do lower priority tasks while serial is idle
  if(osc.isIdle() || OSC::oscState.status == ERROR){
    display.tick();
  }
}

