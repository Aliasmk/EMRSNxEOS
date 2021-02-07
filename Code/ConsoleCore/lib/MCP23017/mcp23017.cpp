#include "mcp23017.hpp"
#include <Arduino.h>

#include <Wire.h>

#define IOCON 0x0A
#define IOCON_MIRROR 0x40
#define IOCON_MIRROR_CONN 0x40
#define IOCON_MIRROR_DISCONN 0x00
#define IOCON_INTPOL 0x02
#define IOCON_INTPOL_ACTIVEHIGH 0x02
#define IOCON_INTPOL_ACTIVELOW 0x00

#define INTCON 0x08

#define GPINTEN 0x04

MCP23017::MCP23017(uint8_t i2cAddress)
    :   i2cAddress_(i2cAddress),
        iocon_shadow_(0x0){
    Wire.begin();
}

void MCP23017::enableInterrupt(uint16_t bitmask){
    writeRegister(GPINTEN, (uint8_t*)&bitmask, 2);
}

void MCP23017::readAll(){
    uint8_t data[21];
    readRegister(data, 0x00, 0x15);
}

void MCP23017::connectInterrupts(bool b){
    iocon_shadow_ = (iocon_shadow_ & ~(IOCON_MIRROR)) | (b ? IOCON_MIRROR_CONN : IOCON_MIRROR_DISCONN);
    writeRegister(IOCON, &iocon_shadow_, 1);
}

void MCP23017::setInterruptPolarityHigh(bool b){
    iocon_shadow_ = (iocon_shadow_ & ~(IOCON_INTPOL)) | (b ? IOCON_INTPOL_ACTIVEHIGH: IOCON_INTPOL_ACTIVELOW);
    writeRegister(IOCON, &iocon_shadow_, 1);
}

bool MCP23017::digitalRead(int pin){
    return ((getPinStates() & (1 << pin)) > 0) ? true : false;
}

uint16_t MCP23017::getPinStates(){
    uint16_t pinStates;
    readRegister((uint8_t*)&pinStates, 0x12, 2);
    return pinStates;
}

void MCP23017::readRegister(uint8_t* destination, const uint8_t address, const int size){
    while(Wire.available()){
        Wire.read();
    }
    
    Wire.beginTransmission(i2cAddress_);
    Wire.write(address);
    Wire.endTransmission();
    Wire.requestFrom(i2cAddress_, (uint8_t)size);
    int i = 0;
    while(Wire.available()){
        uint8_t value = Wire.read();
        if(address + i == IOCON){
            iocon_shadow_ = value;  // cache the iocontrol register state if we happen to read it
        }
        destination[i++] = value;
    }
}

void MCP23017::writeRegister(const uint8_t address, uint8_t* source, const int size){    

    Wire.beginTransmission(i2cAddress_);
    Wire.write(address);
    for(int i = 0; i < size; i++){
        Wire.write(source[i]);
    }
    Wire.endTransmission(true);
}