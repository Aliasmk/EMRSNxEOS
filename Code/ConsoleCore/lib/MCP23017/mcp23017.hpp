#ifndef MCP23017_HPP
#define MCP23017_HPP

// This is not a complete driver for the MCP23CX17. 
// At this time it only implements the subset of functionality required for EMRSNxEOS.
// Assumptions: Single Bank, Active INT pin, INT active High, Input only
#include <cstdint>


class MCP23017{
public:
    MCP23017(uint8_t i2cAddress);

    void enableInterrupt(uint16_t bitmask);
    void connectInterrupts(bool b);
    void setInterruptPolarityHigh(bool b);

    bool digitalRead(int pin);
    uint16_t getPinStates();

    void readAll();

private:
    uint8_t i2cAddress_;
    uint8_t iocon_shadow_;

    void readRegister(uint8_t* destination, const uint8_t address, const int size);
    void writeRegister(const uint8_t address, uint8_t* source, const int size);
};











#endif