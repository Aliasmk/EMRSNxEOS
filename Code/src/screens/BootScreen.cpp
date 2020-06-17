#include <U8g2lib.h>

#include <screens/BootScreen.hpp>

#include <gfx/ghost.hpp>

extern U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2;

void BootScreen::update(){
    ;
}

void BootScreen::draw(){  
    u8g2.clearBuffer();
    /*long time = millis();
    displayState.needsRefresh = true;
    static int translate = -20;
    static int frame = 5;
    if(time - startTime > 3000){
            frame++;
            int increment = (int)pow(1.125, (double)frame);
            translate+= (increment > 20 ? 20 : increment);
           
            u8g2.drawXBMP(translate, 0, 84, 64, ghostImg);
    } else {*/
        u8g2.drawXBMP(-20, 0, 84, 64, ghostImg);
        u8g2.setBitmapMode(false);
        u8g2.setFont(u8g2_font_fub14_tr);
        u8g2.drawStr(68, 16,"EMRSN x EOS");
        u8g2.setFont(u8g2_font_mozart_nbp_t_all);
        u8g2.drawStr(70, 54, "Designed by:");
        u8g2.drawStr(70, 62, "Emerson and Michael Kafarowski");
    /*}

    if(millis() - startTime > 4500){
        displayState.currentScreen = SCREEN_CONNECT;
        clearEnabled = true;
    }*/
      u8g2.sendBuffer();
}