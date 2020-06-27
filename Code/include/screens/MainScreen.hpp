#ifndef SCREENS_MAINSCREEN_H
#define SCREENS_MAINSCREEN_H

#include <screen.hpp>

typedef struct ParamView{
    char title[32];
    int level;
} ParamView;

class MainScreen : public Screen{
public:
    MainScreen();
    void update();
    void draw();

private:
    void nextPage();
    void nextGroup();

    int groupNumber;
    int pageNumber;
    int maxPages;

    int tick;

    int encTicks; //TEMP

    void getParameterInfo();
    ParamView params[4];
};

#endif