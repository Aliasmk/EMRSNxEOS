
#include "console_wifi.hpp"

ConsoleWiFi::ConsoleWiFi() : ssid("ExE LX"), password("EMRSNxEOS")
{
    
}

void ConsoleWiFi::initHotspot(){
    WiFi.enableAP(true);
    delay(100);
    WiFi.softAP(ssid, password, 1, true, 4);
}