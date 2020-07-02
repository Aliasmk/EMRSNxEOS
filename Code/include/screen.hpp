#ifndef SCREEN_H
#define SCREEN_H

// Base class for screens

// This is called an 'abstract class', or 'interface'.
// It does nothing by itself, but any class that wants to call itself a 'screen' must implement the functions below with = 0 at the end.
 
class Screen {
public:
    virtual void update() = 0;
    virtual void draw() = 0;

};


#endif