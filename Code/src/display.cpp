#include <display.hpp>

#include <U8g2lib.h>
#include <WString.h>

#include <SPI.h>

#include <osc.hpp>

#include <gfx/ghost.hpp>

#define PIN_OLED_CS 17
#define PIN_OLED_DC 2
#define PIN_OLED_RESET 32

DisplayState Display::displayState = {0};

U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2(U8G2_R0, PIN_OLED_CS, PIN_OLED_DC, PIN_OLED_RESET);    // Enable U8G2_16BIT in u8g2.h



Display::Display(){

}

void Display::init(){
    displayState.tickNum = 0;
    
    u8g2.begin();
    u8g2.setFont(u8g2_font_profont11_tf);
    u8g2.setDrawColor(1);
    
    switchScreen(SCREEN_BOOT);
    startTime = millis();
}

void Display::tick(){
    displayState.tickNum++;
    long currentTime = millis();

    if(currentScreen == &bootScreen && currentTime-startTime > 3000){
        switchScreen(SCREEN_CONNECT);
    } 
    
    if(currentScreen != &bootScreen) {
        if(OSC::oscState.status == DISCONNECTED){
           switchScreen(SCREEN_CONNECT);
        } else if( OSC::oscState.status == ERROR){
            switchScreen(SCREEN_SETTINGS);
        } else {
           switchScreen(SCREEN_MAIN);
        }
    
    }

    if(currentTime - displayState.lastRefresh > REFRESH_RATE || displayState.needsRefresh){
      currentScreen->draw();
      displayState.lastRefresh = currentTime;
      displayState.needsRefresh = false;
    }
}

void Display::changeBrightness(int b){
    b = (b > 255 ? 255 : b);
    b = (b < 1 ? 1 : b);
    u8g2.setContrast(b);
}

void Display::switchScreen(DisplayScreenEnum newScreen){
    u8g2.clearBuffer();
    
    displayState.currentScreen = newScreen;

    switch(newScreen){
        case SCREEN_BOOT:
            currentScreen = &bootScreen;
        break;

        case SCREEN_CONNECT:
            currentScreen = &connectScreen;
        break;

        case SCREEN_MAIN:
            currentScreen = &mainScreen;
        break;

        case SCREEN_SETTINGS:
            currentScreen = &settingsScreen;
        break;

        default:
            u8g2.drawStr(0,16,"Undefined Screen!");
        break;
    }
}

