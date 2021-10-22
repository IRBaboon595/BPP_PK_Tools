#ifndef RECEIVERMODULE_H
#define RECEIVERMODULE_H

#include "hardwaredevice.h"

class ReceiverModule : public hardwareDevice
{
public:
    ReceiverModule();
    ReceiverModule(ReceiverModule *module);
    ~ReceiverModule();

    bool getAmpState(int way);
    float getAtt(int way);
    bool getSup();

    void setAmpState(bool amp, int way);
    void setAtt(float att, int way);
    void setSup(bool sup);

private:
    bool            amp1_1;
    bool            amp1_2;
    bool            amp2_1;
    bool            amp2_2;
    bool            main_5V;

    float           att1_1;
    float           att1_2;
    float           att2_1;
    float           att2_2;
};

#endif // RECEIVERMODULE_H
