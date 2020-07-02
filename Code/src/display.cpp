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



Display::Display() : 
    TARGET_REFRESH_RATE_MICROS(50000), 
    DRAW_TILE_WIDTH(4), 
    DRAW_TILE_HEIGHT(1) {
    pinMode(16, OUTPUT);
    pinMode(26, OUTPUT);    
    drawCall = 0;
}

void Display::init(){
    displayState.tickNum = 0;
    
    u8g2.begin();
    u8g2.setFont(u8g2_font_profont11_tf);
    u8g2.setDrawColor(1);
    
    switchScreen(SCREEN_BOOT);
    startTime = micros();
}

void Display::tick(){
    static int numDrawCalls = (NUM_TILES / (DRAW_TILE_WIDTH * DRAW_TILE_HEIGHT));
    static int drawRate = (int)(TARGET_REFRESH_RATE_MICROS / (float)numDrawCalls); 

    displayState.tickNum++;
    long currentTime = micros();

    if(currentScreen == &bootScreen && currentTime-startTime > SPLASH_DISPLAY_TIME_MICROS){
        switchScreen(SCREEN_MAIN);
    } 
    
    /*
    if(currentScreen != &bootScreen) {
        if(OSC::oscState.status == DISCONNECTED){
           switchScreen(SCREEN_CONNECT);
        } else if( OSC::oscState.status == ERROR){
            switchScreen(SCREEN_SETTINGS);
        } else {
           switchScreen(SCREEN_MAIN);
        }
    
    }*/
      
    currentScreen->update();
      
    if(currentTime - displayState.lastRefresh > drawRate){
        int tx = DRAW_TILE_WIDTH * (drawCall % (TILES_X / DRAW_TILE_WIDTH ));
        int ty = DRAW_TILE_HEIGHT * (drawCall / (TILES_X / DRAW_TILE_WIDTH));

        
        u8g2.updateDisplayArea(tx,ty,DRAW_TILE_WIDTH,DRAW_TILE_HEIGHT);
        

        drawCall = drawCall + 1;
        if(drawCall > numDrawCalls){
            drawCall = 0;
            u8g2.clearBuffer();
            digitalWrite(16, HIGH);
            currentScreen->draw();
            digitalWrite(16, LOW);   
            displayState.needsRefresh = false;
        }

        displayState.lastRefresh = currentTime;
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

