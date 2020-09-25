#include <osc.hpp>

#include <display.hpp>

#include <OSCBoards.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <OSCMatch.h>
#include <OSCMessage.h>
#include <OSCTiming.h>

#ifdef BOARD_HAS_USB_SERIAL
#include <SLIPEncodedUSBSerial.h>
SLIPEncodedUSBSerial SLIPSerial(thisBoardsSerialUSB);
#else
#include <SLIPEncodedSerial.h>
SLIPEncodedSerial SLIPSerial(Serial);
#endif

const String HANDSHAKE_QUERY = "ETCOSC?";
const String HANDSHAKE_REPLY = "OK";

OSCState OSC::oscState {0};

void route_getSyntaxLine(OSCMessage& msg, int addressOffset){
    msg.getString(0, OSC::oscState.syntaxLine, 128);    // Store the syntax line data in the syntax line string in oscState
}

void route_refreshPing(OSCMessage& msg, int addressOffset){
    // When we get a ping back, we know we are connected. 
    if(OSC::oscState.status == DISCONNECTED){
        OSC::oscState.status = CONNECTED;
        //bReconnection = true;
    }
    OSC::oscState.lastPingTimeRX = millis();    // Store the time the ping was received
}



void route_loadParameter(OSCMessage& msg, int addressOffset){
    char indexChar[4]; //size 4 to accomodate 3 digits and the /0 null terminator.
    msg.getAddress(indexChar, addressOffset+1,4); //get the parameter number from the last digits in the address +1 because of the leading / after wheel
    int index = atoi(indexChar);
    
    //extract the name and level from the string
    char tempName[P_NAME_LEN];    //Size includes level in square brackets i.e. ' [-100]', so actual max name length is P_NAME_LEN -7.
    msg.getString(0, tempName, P_NAME_LEN);

    //get our first parameter - the name and the level and place it in tempName
    
    //Here we find the element indicies of the square brackets surrounding the level. We assume square brackets aren't in the name itself.
    int levelStart = strcspn(tempName,"[");
    int levelEnd = strcspn(tempName,"]");
    //http://www.cplusplus.com/reference/cstring/strcspn/

    //The name of the channel is all the text up until the first [ symbol, which is at index levelStart. Subtract 2 from this index to remove the 2 spaces after the name
    strncpy(OSC::oscState.params[index].name, tempName, levelStart-2);
    OSC::oscState.params[index].name[levelStart-2] = '\0';

    //Here we extract the level from the rest of the string
    int charsToCopy = levelEnd-levelStart-1;            //get the number of chars to copy
    char tempLevel[charsToCopy+1];                      //create a temp array holding the numbers to copy + 1 for the terminator
    char* levelStartChar = &tempName[levelStart+1];     //create a pointer to the element in tempName that begins the number
    strncpy(tempLevel, levelStartChar, charsToCopy);    //string copy from that element for as many elements to copy, into our temp array
    
    OSC::oscState.params[index].level = atoi(tempLevel);    //convert the temp array into an integer and pass it to the parameter level.

    //Get the group from the second argument, an integer
    int paramGroup = msg.getInt(1);
    OSC::oscState.params[index].group = (PGroup)paramGroup;

    //Count the number of active parameters by looping through the param array and incrementing the count for named parameters (eos unloads parameters by sending empty strings)
    OSC::oscState.fixture.numParams = 0;
    for(int i = 0; i < N_PARAMS; i++){
        if(OSC::oscState.params[i].name[0] != '\0'){
            OSC::oscState.fixture.numParams++;
        }
    }
}

OSC::OSC(){
    oscState.status = DISCONNECTED;
    static int maxbuffsize = 0;
}

void OSC::init(){
    SLIPSerial.begin(115200);
    Serial.setRxBufferSize(1024);   //Required to fix crashes due to buffer overrun with lots of incoming messages and no filters
    // This is a hack around an Arduino bug. It was taken from the OSC library
    // examples
    #ifdef BOARD_HAS_USB_SERIAL
        while (!SerialUSB);
    #else
        while (!Serial);
    #endif
}

void OSC::poll(){
    static int maxbuffsize;
    int currentSize = Serial.available();
    if(currentSize > maxbuffsize){
        maxbuffsize = currentSize;
    }   

    //TODO: drop packets if serial data buffer is exceeded or corrupted, rather than allow incomplete or corrupted SLIP packets through to the OSC routing functions

    int size = SLIPSerial.available();
    
    if(size > 0){
        while(size--) {
            curMsg += (char)(SLIPSerial.read());
        }
    }
    if (SLIPSerial.endofPacket()){
        parseOSCMessage(curMsg);
        curMsg = String();
    }


    long currentTime = millis();

    if(Serial.available()){
        oscState.lastDataTime = currentTime;
    }

    //Check connection while serial is idle
    if(currentTime - oscState.lastDataTime > DATA_WAIT_TIME){
        idle = true;
        
        //Send a ping at a regular rate to test connection
        if(currentTime - oscState.lastPingTimeTX > PING_RATE){
            if(getConnectionState() == DISCONNECTED){
                sendHandshake();
            }
            sendPing();
        } 
        
        //If no ping is recieved after a certain timeout, assume we have disconnected
        if(currentTime - oscState.lastPingTimeRX > PING_TIMEOUT){
            setConnectionState(DISCONNECTED);
        }
    } else {
        idle = false;
    }
}

bool OSC::isIdle(){
    return idle;
}

ConnectionStatus OSC::getConnectionState(){
    return oscState.status;
}

void OSC::setConnectionState(ConnectionStatus status){
    switch(status){
        case DISCONNECTED:
            oscState.status = DISCONNECTED;
        break;
        case CONNECTED:
            oscState.status = CONNECTED;
        break;
    }

    oscState.status = status;
}

void OSC::parseOSCMessage(String &msg){
    // check to see if this is the handshake string
    
    //strcpy(oscState.syntaxLine, (char*)msg.c_str());
   // sprintf(oscState.syntaxLine, ">%s", (char*)msg.c_str() );


    if (msg.indexOf(HANDSHAKE_QUERY) != -1)
    {
        sendHandshake();
    } else {
        OSCMessage oscmsg;                 
        oscmsg.fill((uint8_t*)msg.c_str(), (int)msg.length());
        
        if(oscmsg.route("/eos/out/ping", route_refreshPing))
            return;
        if(oscmsg.route("/eos/out/cmd", route_getSyntaxLine))
            return;
        if(oscmsg.route("/eos/out/active/wheel", route_loadParameter)) 
            return;
    }
}

void OSC::sendHandshake(){
    SLIPSerial.beginPacket();
    SLIPSerial.write((const uint8_t*)HANDSHAKE_REPLY.c_str(), (size_t)HANDSHAKE_REPLY.length());
    SLIPSerial.endPacket();
}

void OSC::sendPing(){
    OSCMessage ping("/eos/ping");
    ping.add("keepalive");
    SLIPSerial.beginPacket();
    ping.send(SLIPSerial);
    SLIPSerial.endPacket();
    oscState.lastPingTimeTX = millis();
}


void OSC::sendWheelMove(int wheelNumber, int delta){
    char wheelCommand[32];
    snprintf(wheelCommand, 32, "/eos/active/wheel/%d", wheelNumber);
    OSCMessage wheel(wheelCommand);
    wheel.add((float)delta);
    SLIPSerial.beginPacket();
    wheel.send(SLIPSerial);
    SLIPSerial.endPacket();
}

