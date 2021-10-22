#include "geterodinemodule.h"

GeterodineModule::GeterodineModule() : hardwareDevice("Гетеродин")
{
    freq1 = 1150;
    freq2 = 1345;

    amp1 = false;
    amp2 = false;

    att1 = 31.5;
    att2 = 31.5;

    setStatus("Ok");
}

GeterodineModule::GeterodineModule(GeterodineModule *module)
{
    freq1 = module->freq1;
    freq1 = module->freq1;
    amp1 = module->amp1;
    amp2 = module->amp2;
    att1 = module->att1;
    att2 = module->att2;
}

double GeterodineModule::getFreq(int way)
{
    double result = 0;
    switch (way) {
        case 0:
            result = freq1;
        break;
        case 1:
            result = freq2;
        break;
        default:
            result = 0xFF;
            setStatus("Way Error");
        break;
    }
    return result;
}

bool GeterodineModule::getAmpState(int way)
{
    bool result = 0;
    switch (way) {
        case 0:
            result = amp1;
        break;
        case 1:
            result = amp2;
        break;
        default:
            result = 0xFF;
            setStatus("Way Error");
        break;
    }
    return result;
}

float GeterodineModule::getAtt(int way)
{
    float result = 0;
    switch (way) {
        case 0:
            result = att1;
        break;
        case 1:
            result = att2;
        break;
        default:
            result = 0xFF;
            setStatus("Way Error");
        break;
    }
    return result;
}

bool GeterodineModule::getSup()
{
    return main_5V;
}

void GeterodineModule::setFreq(double freq, int way)
{
    switch (way) {
        case 0:
            freq1 = freq;
        break;
        case 1:
            freq2 = freq;
        break;
        default:
            setStatus("Way Error");
        break;
    }
}

void GeterodineModule::setAmpState(bool amp, int way)
{
    switch (way) {
        case 0:
            amp1 = amp;
        break;
        case 1:
            amp2 = amp;
        break;
        default:
            setStatus("Way Error");
        break;
    }
}

void GeterodineModule::setAtt(float att, int way)
{
    switch (way) {
        case 0:
            att1 = att;
        break;
        case 1:
            att2 = att;
        break;
        default:
            setStatus("Way Error");
        break;
    }
}

void GeterodineModule::setSup(bool sup)
{
    main_5V = sup;
}

GeterodineModule::~GeterodineModule()
{

}
