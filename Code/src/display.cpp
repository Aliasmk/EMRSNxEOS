#include <display.hpp>

#include <U8g2lib.h>

#include <pins.hpp>

// TODO: This system may benefit from a Model-View-Presenter design pattern if the number of useful pages increases in the future.

DisplayState Display::displayState = {0}; // Initialize static displayState object to zero

U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2(U8G2_R0, PIN_OLED_CS, PIN_OLED_DC, PIN_OLED_RESET);    // Enable U8G2_16BIT in u8g2.h

Display::Display() : 
    TARGET_REFRESH_RATE_MICROS(50000), 
    DRAW_TILE_WIDTH(4), 
    DRAW_TILE_HEIGHT(1) {  
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
    static int numDrawCalls = (NUM_TILES / (DRAW_TILE_WIDTH * DRAW_TILE_HEIGHT));   // The number of draw calls to refresh the whole screen
    static int drawRate = (int)(TARGET_REFRESH_RATE_MICROS / (float)numDrawCalls);  // The time between each call. The time between when the draw finishes and the next call is free for the rest of the program.

    displayState.tickNum++;
    long currentTime = micros();

    // Initial transition from the boot screen
    // TODO: implement state machine with transitions
    if(currentScreen == &bootScreen && currentTime-startTime > SPLASH_DISPLAY_TIME_MICROS){
        switchScreen(SCREEN_MAIN);
    } 

    // Run state updates, like IO processing etc. No drawing methods should be present 
    currentScreen->update();
    
    // Run a draw call if the time since the last draw call exceeds a threshold
    if(currentTime - displayState.lastRefresh > drawRate){
        // The screen is drawn in small pieces over a number of draw calls.
        // This is to avoid a full screen refresh from hanging the program for long periods

        // Screens may be partially refreshed using multiples of 8x8 pixel tiles

        // Calculate the XY coordinate of the current tile to refresh
        int tx = DRAW_TILE_WIDTH * (drawCall % (TILES_X / DRAW_TILE_WIDTH ));
        int ty = DRAW_TILE_HEIGHT * (drawCall / (TILES_X / DRAW_TILE_WIDTH));

        // Update the screen within the tile
        u8g2.updateDisplayArea(tx,ty,DRAW_TILE_WIDTH,DRAW_TILE_HEIGHT);
        
        // Increment the draw call index
        drawCall = drawCall + 1;
        if(drawCall > numDrawCalls){
            drawCall = 0;
            u8g2.clearBuffer();
            currentScreen->draw();    // We only refresh the framebuffer on the first draw call to avoid tearing
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
    
    displayState.currentScreen = newScreen; // Store the index of the new screen in the displaystate object

    // currentScreen is a pointer to the currently active screen. That means we can act on currentScreen, and it will pass along our instructions to the screen it points to at the time.
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

