#ifndef SCREEN_H
#define SCREEN_H

/* Base class for screens */

class Screen {
public:
    virtual void update() = 0;
    virtual void draw() = 0;

};


#endif