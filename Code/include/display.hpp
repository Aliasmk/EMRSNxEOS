#ifndef DISPLAY_H
#define DISPLAY_H


#define SPLASH_DISPLAY_TIME_MICROS 3000000
#define NUM_TILES 256
#define TILES_X 32
#define TILES_Y 8

#include <osc.hpp>
#include <screen.hpp>

#include <screens/BootScreen.hpp>
#include <screens/MainScreen.hpp>
#include <screens/ConnectScreen.hpp>
#include <screens/SettingsScreen.hpp>

typedef enum DisplayScreenEnum { SCREEN_BOOT, SCREEN_CONNECT, SCREEN_MAIN, SCREEN_SETTINGS, SCREEN_SAVER, NUM_SCREENS } DisplayScreenEnum;

typedef struct DisplayState{
    long lastRefresh;
    long idleTimer; //for counting down screen saver
    bool needsRefresh;
    DisplayScreenEnum currentScreen;
    long tickNum;
} DisplayState;

class Display{
public:
    Display();
    void init();
    void switchScreen(DisplayScreenEnum newScreen);
    void changeBrightness(int b);
    void tick();

    void test();

    static DisplayState displayState;

private: 
    void draw();
    
    int drawCall;
    long startTime;
    bool clearEnabled;

    Screen *currentScreen;

    
    const int TARGET_REFRESH_RATE_MICROS;
    // TILE WIDTH AND HEIGHT MUST BE POWER OF TWO
    const int DRAW_TILE_WIDTH;
    const int DRAW_TILE_HEIGHT; 

    BootScreen bootScreen;
    ConnectScreen connectScreen;
    MainScreen mainScreen;
    SettingsScreen settingsScreen;
};

#endif  //DISPLAY_H