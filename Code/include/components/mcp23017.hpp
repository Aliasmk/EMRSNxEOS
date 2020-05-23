#ifndef MCP23017_H
#define MCP23017_H

#include <stdint.h>


//Uncomment to use 16-bit mode
#define MODE16BIT

#ifdef MODE16BIT

#define IODIRA      0x00
#define IODIRB      0x01
#define IPOLA       0x02
#define IPOLB       0x03
#define GPINTENA    0x04
#define GPINTENB    0x05
#define DEFVALA     0x06
#define DEFVALB     0x07
#define INTCONA     0x08
#define INTCONB     0x09
#define IOCON_1     0x0A
#define IOCON_2     0x0
#define GPPUA       0x0C
#define GPPUB       0x0D
#define INTFA       0x0E
#define INTFB       0x0F
#define INTCAPA     0x10
#define INTCAPB     0x11
#define GPIOA       0x12
#define GPIOB       0x13
#define OLATA       0x14
#define OLATB       0x15

#else

#define IODIRA      0x00
#define IODIRB      0x10
#define IPOLA       0x01
#define IPOLB       0x11
#define GPINTENA    0x02
#define GPINTENB    0x12
#define DEFVALA     0x03
#define DEFVALB     0x13
#define INTCONA     0x04
#define INTCONB     0x14
#define IOCON_1     0x05
#define IOCON_2     0x15
#define GPPUA       0x06
#define GPPUB       0x16
#define INTFA       0x07
#define INTFB       0x17
#define INTCAPA     0x08
#define INTCAPB     0x18
#define GPIOA       0x09
#define GPIOB       0x19
#define OLATA       0x0A
#define OLATB       0x1A

#endif


#define BIT15   0x8000
#define BIT14   0x4000
#define BIT13   0x2000
#define BIT12   0x1000
#define BIT11   0x0800
#define BIT10   0x0400
#define BIT9    0x0200
#define BIT8    0x0100

#define BIT7    0x0080
#define BIT6    0x0040
#define BIT5    0x0020
#define BIT4    0x0010
#define BIT3    0x0008
#define BIT2    0x0004
#define BIT1    0x0002
#define BIT0    0x0001

#define BANK    0x80
#define MIRROR  0x40
#define SEQOP   0x20
#define DISSLW  0x10
#define HAEN    0x08
#define ODR     0x04
#define INTPOL  0x02
#define NOOP    0x01



//typedef uint8_t __UINT8_TYPE__

class MCP23017{
public:
    MCP23017(uint8_t pinIntA_, uint8_t pinIntB_);
    MCP23017(uint8_t pinIntA_);
    MCP23017();

    bool init();

/*
    void pinMode(int bank, int pin, int pinmode);
    void pinMode(int bank, int regValue);

    void pinPolarity(int bank, int pin, int polarity);
    void pinPolarity(int bank, int regValue);

    void pintInterruptMode(int bank, int pin, int intmode);
    void pinInterruptMode(int bank, int regValue);
*/

    void writeRegister(uint8_t reg, uint8_t value);
    uint8_t readRegister(uint8_t reg);
private:
    const int pinIntA, pinIntB;

    

};



#endif