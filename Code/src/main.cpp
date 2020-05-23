#include <Arduino.h>

#define TEST
#define VERSION "0.1"

#include <io.hpp>
#include <osc.hpp>
#include <display.hpp>


IO io;
OSC osc;
Display display;

void setup() {
  io.init();
  osc.init();
  display.init();
}

void loop() {
  osc.poll();
  //io.poll();

  //Do lower priority tasks while serial is idle
  if(osc.isIdle()){
    display.tick();
  }
}

