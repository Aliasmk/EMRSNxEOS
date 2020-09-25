#include <U8g2lib.h>

#include <screens/MainScreen.hpp>
#include <osc.hpp>
#include <button.hpp>

extern U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2;
extern Button btn;
extern OSC osc;

// TODO: The display doesn't need to be constantly redraw. If this object can accept event notifications such as when parameters get update or the syntax line is changed, we only need to redraw in those cases.

String groupNames[] = {"None/Test", "Intensity", "Focus", "Color", "Image", "Form", "Custom"};

MainScreen::MainScreen() : params{0} {
    pageNumber = 1;
    maxPages = 1;
    groupNumber = 1;
    tick = 0;
    activeParameter = 0;
    setAllWheelsCoarse();
}

void MainScreen::update(){
    if(OSC::oscState.status != CONNECTED){
        return; // Nothing to do if we aren't connected to EOS
    }
    
    if(btn.buttonClicked(BTN_ENC2)){
        activeParameter = 0;
        nextGroup();
    }
    
    if(btn.buttonClicked(BTN_ENC3)){
        activeParameter++;
        if(activeParameter+1 >= itemsOnPage){
            activeParameter = 0;
            nextPage();
        } 
    }

    if(btn.buttonClicked(BTN_ENC4)){
        params[activeParameter].coarse = !params[activeParameter].coarse;
    }

    int enc = 0;//encoder.getEncoderDelta(ENC4);
    if(enc != 0){
        if(params[activeParameter].coarse){
            enc *= 4;
        }
        osc.sendWheelMove(params[activeParameter].index, enc);
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
    setAllWheelsCoarse();
}

void MainScreen::nextGroup(){
    groupNumber++;
    if(groupNumber >= NUM_GROUPS){
        groupNumber = 1;
    }
    pageNumber = 1;
    setAllWheelsCoarse();
}

void MainScreen::draw(){
    u8g2.setFont(u8g2_font_profont11_tf);
    drawTopBar();
    drawMiddle();
    drawBottomBar();
}

void MainScreen::drawTopBar(){
    char temp[64];
    if(OSC::oscState.status == CONNECTED){
        sprintf(temp, "%s", groupNames[groupNumber].c_str());
        u8g2.drawStr(128-u8g2.getUTF8Width(temp)/2, 8, temp);
        sprintf(temp, "%d/%d", pageNumber, maxPages);  
        u8g2.drawStr(255-u8g2.getUTF8Width(temp), 8, temp);
    } else {
        strncpy(temp, "EOS DISCONNECTED", 64);
        u8g2.drawStr(0, 8, temp);
    }
    
    
    u8g2.drawLine(0,10,255,10);
}

void MainScreen::drawMiddle(){
    char temp[64];
    itemsOnPage = 0;
    for(int i = 0; i<=4; i++){
        if(params[i].title[0] != '\0'){
            itemsOnPage++;
            sprintf(temp, "%.9s", params[i].title);
            u8g2.drawStr(9 + (i)*64, 22, temp);
            sprintf(temp, "[%d] ", params[i].level);
            u8g2.drawStr(7 + (i)*64, 32, temp);
            if(i == activeParameter){
                u8g2.drawLine(i*64 + 4, 13, i*64 + 4, 35);
                u8g2.drawLine(i*64 + 5, 13, i*64 + 5, 35);
                sprintf(temp, "%c", params[i].coarse ? 'C' : 'F');
                u8g2.drawStr(i*64 + 4, 45, temp);
            }
        }
        u8g2.drawLine((i+1)*64,10,(i+1)*64,53);
    }
    u8g2.drawLine(0,53,255,53);
}

void MainScreen::drawBottomBar(){
    u8g2.drawStr(0,63, OSC::oscState.syntaxLine);
}

void MainScreen::setAllWheelsFine(){
    for(int i = 0; i < 4; i++){
        params[i].coarse = false;
    }
}

void MainScreen::setAllWheelsCoarse(){
    for(int i = 0; i < 4; i++){
        params[i].coarse = true;
    }
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
