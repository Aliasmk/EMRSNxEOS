#ifndef SCREENS_MAINSCREEN_H
#define SCREENS_MAINSCREEN_H

#include <screen.hpp>

class MainScreen : public Screen{
public:
    void draw();

private:
    int groupNumber;
    int pageNumber;
    void getParameterInfo(int group, int page, int offset, char *paramName, int *value);

};

#endif