#ifndef GETERODINEMODULE_H
#define GETERODINEMODULE_H

#include "hardwaredevice.h"

class GeterodineModule : public hardwareDevice
{

public:
    GeterodineModule();
    GeterodineModule(GeterodineModule *module);
    ~GeterodineModule();

    double getFreq(int way);
    bool getAmpState(int way);
    float getAtt(int way);
    bool getSup();

    void setFreq(double freq, int way);
    void setAmpState(bool amp, int way);
    void setAtt(float att, int way);
    void setSup(bool sup);

private:
    double          freq1;
    double          freq2;

    bool            amp1;
    bool            amp2;
    bool            main_5V;

    float           att1;
    float           att2;

signals:

public slots:
};

#endif // GETERODINEMODULE_H
