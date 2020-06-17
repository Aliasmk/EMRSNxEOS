#include <U8g2lib.h>

#include <screens/MainScreen.hpp>
#include <osc.hpp>
#include <io.hpp>

extern U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2;
extern IO io;


String groupNames[] = {"None/Test", "Intensity", "Focus", "Color", "Image", "Form", "Custom"};

MainScreen::MainScreen(){
    clicked = false;
    held = false;
}

void MainScreen::update(){
    if(io.buttonDown(BTN_ENC2)){
        clicked = true;
    } else {
        clicked = false;
    }

    if(io.buttonHeld(BTN_ENC2, 2000)){
        held = true;
    }
}

void MainScreen::draw(){
    u8g2.clearBuffer();

    char temp[64];
    u8g2.setFont(u8g2_font_profont11_tf);

    sprintf(temp, "Group: %s", groupNames[0].c_str());
    u8g2.drawStr(0,8, temp);
    u8g2.drawLine(0,10,255,10);

    for(int i = 1; i<=4; i++){
        sprintf(temp, "%s", OSC::oscState.params[i].name);
        u8g2.drawStr(5 + (i-1)*64, 22, temp);
        sprintf(temp, "[%d]", OSC::oscState.params[i].level);
        u8g2.drawStr(5 + (i-1)*64, 32, temp);
        sprintf(temp, "G: %d", (int)OSC::oscState.params[i].group);
        u8g2.drawStr(5 + (i-1)*64, 42, temp);
        u8g2.drawLine(i*64,10,i*64,53);
    }

    if(clicked){
        u8g2.drawStr(100,8, "CLICKED");
    }
    if(held){
        u8g2.drawStr(160,8, "HELD");
    }

    u8g2.drawLine(0,53,255,53);

    u8g2.drawStr(0,63, OSC::oscState.syntaxLine);

    u8g2.sendBuffer();
}

void MainScreen::getParameterInfo(int group, int page, int offset, char *paramName, int *value){

}
