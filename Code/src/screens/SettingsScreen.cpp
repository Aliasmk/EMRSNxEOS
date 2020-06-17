#include <screens/SettingsScreen.hpp>
#include <U8g2lib.h>

extern U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2;




void SettingsScreen::update(){

}

void SettingsScreen::draw(){
    u8g2.clearBuffer();
    
    u8g2.drawStr(0,63, "ERROR: SERIAL EXCEEDED BUFFER");

    u8g2.sendBuffer();
}