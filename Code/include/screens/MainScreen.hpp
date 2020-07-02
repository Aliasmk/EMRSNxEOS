#ifndef SCREENS_MAINSCREEN_H
#define SCREENS_MAINSCREEN_H

#include <screen.hpp>

typedef struct ParamView{
    char title[32];
    int level;
    int index;
    bool coarse;
} ParamView;

class MainScreen : public Screen{
public:
    MainScreen();

    void update();      // State information updating and IO checking (should run quickly)
    void draw();        // Re-draw code (may run slower)

private:
    void nextPage();
    void nextGroup();

    void drawTopBar();
    void drawMiddle();
    void drawBottomBar();

    void setAllWheelsCoarse();
    void setAllWheelsFine();

    int groupNumber;
    int pageNumber;
    int maxPages;

    int tick;

    int activeParameter;
    int itemsOnPage;

    void getParameterInfo();
    ParamView params[4];
};

#endif