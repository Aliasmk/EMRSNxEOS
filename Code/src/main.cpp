#include <Arduino.h>

#define TEST
#define VERSION "0.1"

#include <io.hpp>
#include <osc.hpp>
#include <display.hpp>


IO io;
OSC osc;
Display display;

IO* io_p;

void setup() {
  io_p = &io;
  osc.init();
  display.init();
}

void loop() {
  osc.poll();
  io.tick();

  //Do lower priority tasks while serial is idle
  if(osc.isIdle() || OSC::oscState.status == ERROR){
    display.tick();
  }
}

