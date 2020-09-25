#ifndef WIFI_HPP
#define WIFI_HPP

#include <WiFi.h>

class ConsoleWiFi{
public:
    ConsoleWiFi();

    void initHotspot();


private:
    const char ssid[32];
    const char password[32];
};




#endif