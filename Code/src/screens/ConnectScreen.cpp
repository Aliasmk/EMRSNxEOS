#include <screens/ConnectScreen.hpp>

#include <display.hpp>

#include <U8g2lib.h>

extern U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2;

void ConnectScreen::update(){
    ;
}

void ConnectScreen::draw(){
    u8g2.clearBuffer();
    char temp[64];
    u8g2.setFont(u8g2_font_profont15_tf);
            
    char dots[4];
    int nDots = ((int)(Display::displayState.tickNum / 100000) % 4);
    for(int i = 0; i < nDots; i++){
        dots[i] = '.';
    }
    dots[nDots] = '\0';
    
    sprintf(temp, "Connecting to EOS%s", dots);
    u8g2.drawStr(0,16,temp);
    u8g2.sendBuffer();


}