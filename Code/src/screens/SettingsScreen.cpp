#include <screens/SettingsScreen.hpp>
#include <U8g2lib.h>

extern U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2;




void SettingsScreen::update(){

}

void SettingsScreen::draw(){  
    u8g2.setFont(u8g2_font_profont15_tf);
    u8g2.drawStr(0,16, "Settings");
    u8g2.drawHLine(0, 20, 256);

    // Draw settings objects on the left and parameter on the right
    u8g2.drawVLine(128, 20, 44);

}