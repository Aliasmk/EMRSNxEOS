#include <U8g2lib.h>

#include <screens/MainScreen.hpp>
#include <osc.hpp>
#include <io.hpp>
#include <encoder.hpp>

extern U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2;
extern IO io;
extern OSC osc;
extern Encoder encoder;
// TODO: This system may benefit from a Model View Presenter design pattern if the number of useful pages increases in the future.

String groupNames[] = {"None/Test", "Intensity", "Focus", "Color", "Image", "Form", "Custom"};

MainScreen::MainScreen() : params{0} {
    pageNumber = 1;
    maxPages = 1;
    groupNumber = 1;
    tick = 0;
    encTicks = 0;
}

void MainScreen::update(){
    if(io.buttonClicked(BTN_ENC2)){
        nextGroup();
    }
    
    if(io.buttonClicked(BTN_ENC4)){
        nextPage();
    }

    int enc = encoder.getEncoderDelta(ENC1);
    if(enc != 0){
        osc.sendWheelMove(params[0].index, enc);
    }
    

    if(tick % 15 == 0){
        getParameterInfo();
    }
    
    tick++;
}

void MainScreen::nextPage(){
    pageNumber++;
    if(pageNumber > maxPages){
       pageNumber = 1;
    }
}

void MainScreen::nextGroup(){
    groupNumber++;
    if(groupNumber >= NUM_GROUPS){
        groupNumber = 1;
    }
    pageNumber = 1;
}

void MainScreen::draw(){
    
    
    char temp[64];
    u8g2.setFont(u8g2_font_profont11_tf);

    sprintf(temp, "Group: %s, Page %d/%d, Ticks: %d", groupNames[groupNumber].c_str(), pageNumber, maxPages, encTicks);
    u8g2.drawStr(0,8, temp);
    u8g2.drawLine(0,10,255,10);

    for(int i = 0; i<=4; i++){
        if(params[i].title[0] != '\0'){
            sprintf(temp, "%.9s", params[i].title);
            u8g2.drawStr(5 + (i)*64, 22, temp);
            sprintf(temp, "[%d]", params[i].level);
            u8g2.drawStr(5 + (i)*64, 32, temp);
        }
        u8g2.drawLine((i+1)*64,10,(i+1)*64,53);
    }

    u8g2.drawLine(0,53,255,53);
    u8g2.drawStr(0,63, OSC::oscState.syntaxLine);
}

void MainScreen::getParameterInfo(){
    // When called, scan through the list of osc parameters and populate this screen with the four corresponding to the requested group and page

    // Calculate the number of parameters in the requested group 
    int paramsInGroup = 0;
    for(int i = 0; i < N_PARAMS; i++){
        if(OSC::oscState.params[i].group == (PGroup)groupNumber){
            paramsInGroup++;
        }
    }

    // Calculate the max number of pages in the requested group
    maxPages = ceil(paramsInGroup / 4.0);
    if(pageNumber > maxPages){
        pageNumber = 1;
    }
    
    // Run through the list of parameters and pick up parameters in the requested group, after an offset (dictated by the page number)
    int offset = (pageNumber-1) * 4;
    int paramsMatched = 0;
    for(int i = 0; i < 4; i++){
        params[i].title[0] = '\0';
        paramsMatched = 0;
        for(int j = 0; j < N_PARAMS; j++){
            if(OSC::oscState.params[j].group == (PGroup)groupNumber){
                paramsMatched++;
                if(paramsMatched > offset){
                    strcpy(params[i].title, OSC::oscState.params[j].name);
                    params[i].level = OSC::oscState.params[j].level;
                    params[i].index = j;
                    offset++;
                    break;
                }
                
            }
        }
    }

    
}
