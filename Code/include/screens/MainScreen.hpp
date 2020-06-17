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
    int groupNumber;
    int pageNumber;
    void getParameterInfo(int group, int page, int offset, char *paramName, int *value);
    bool clicked;
    bool held;
    ParamView params[4];
};

#endif