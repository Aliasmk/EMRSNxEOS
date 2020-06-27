#ifndef OSC_H
#define OSC_H

#include <WString.h>
#include <OSCMessage.h>



#define F_NAME_LEN (uint8_t)64
#define P_NAME_LEN (uint8_t)64
#define N_PARAMS 128
#define DATA_WAIT_TIME 5 //ms
#define PING_RATE 1000 //ms
#define PING_TIMEOUT 5000 //ms

enum PGroup{ P_TEST = 0, INTENS = 1, FOCUS = 2, COLOR = 3, IMAGE = 4, FORM = 5, CUSTOM = 6, NUM_GROUPS = 7 }; //order derived from EOS param outputs

enum ConnectionStatus { DISCONNECTED, CONNECTED, ERROR };

typedef struct Fixture{
  int channel;
  int level;
  char name[F_NAME_LEN];
  int startingChannel;
  int numParams;

} Fixture;

typedef struct Parameter{         //32-bit
  char name[P_NAME_LEN];          //name of parameter, max of 32 characters (8-bit)
  int level;
  PGroup group;                   //which group the parameter belongs to, of type pgroup (enum) (16-bit)
  int offset;                     //increments with each new parameter in a group

} Parameter;

typedef struct OSCState{
    char syntaxLine[128];
    char lastCommand[128];
    Fixture fixture;
    Parameter params[N_PARAMS];
    long lastDataTime;
    long lastPingTimeRX;
    long lastPingTimeTX;
    ConnectionStatus status;
    
} OSCState;

class OSC{
public:
    OSC();
    void init();
    void poll();

    void test();

    bool isIdle();

    ConnectionStatus getConnectionState();
    void setConnectionState(ConnectionStatus status);

    void parseOSCMessage(String &msg);

    void sendHandshake();
    void sendPing();

    void sendWheelMove(int wheelNumber, int delta);

    static OSCState oscState;


private:
    bool idle;
    String curMsg;
    
};




#endif  //OSC_H