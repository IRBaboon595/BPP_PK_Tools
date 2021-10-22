#ifndef TRANSMITTERMODULE_H
#define TRANSMITTERMODULE_H

#include "hardwaredevice.h"

class TransmitterModule : public hardwareDevice
{
public:
    TransmitterModule();
    TransmitterModule(TransmitterModule *module);
    ~TransmitterModule();

    bool getAmpState(int way);
    float getAtt(int way);
    double getDac(int way);
    bool getDet(int way);
    bool getSup();

    void setAmpState(bool amp, int way);
    void setAtt(float att, int way);
    void setDac(double dac, int way);
    void setDet(bool det, int way);
    void setSup(bool sup);

private:
    bool            amp1;
    bool            amp2;
    bool            main_5V;

    float           att1;
    float           att2;

    double          dac1;
    double          dac2;

    bool            det1;
    bool            det2;
};

#endif // TRANSMITTERMODULE_H
