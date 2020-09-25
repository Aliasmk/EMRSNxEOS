#include <Arduino.h>

#include "fader.hpp"
#include "encoder.hpp"
#include "Wire.h"

#define I2C_ADDRESS 0xA3

void receiveEvent(int numBytes);

/* This code handles the four encoders and runs on a dedicated ATMega328PB, communicating with the main processor by serial. 
 * By dedicating a second processor to the encoders we allow for maximum input responsiveness and free ESP32 I/O
 * at the cost of additional complexity during board bringup or firmware update.  
*/

Encoder encoder;
Fader fader;

void setup() {
  Wire.begin(I2C_ADDRESS);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent);           // register event
}

void loop() {
  encoder.tick();
}


/* This device has n+1 address, where n is the number of encoders. 
 * Address 0 simply returns how many encoders are present
 * Then, each encoder has an address to report it's knob delta.
 */

void receiveEvent(int numBytes)
{
  uint8_t addr;
  // The only reason for the host to write is to query an address. Respond to as many address requests as received
  while(Wire.available()) 
  {
    addr = Wire.read(); // receive address
    if(addr == 0){
      Wire.write(NUM_ENCODERS); 
    } else if(addr == 1){
      Wire.write(NUM_FADERS);
    } else if(addr > 1 + NUM_ENCODERS + NUM_FADERS) {
      Wire.write(0);
    } else {
      signed int delta = encoder.getEncoderDelta((EncoderEnum)addr);
      Wire.write(delta);
    }
  }
  

}