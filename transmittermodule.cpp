#include "transmittermodule.h"

TransmitterModule::TransmitterModule() : hardwareDevice("Передатчик")
{
    amp1 = false;
    amp2 = false;

    att1 = 31.5;
    att2 = 31.5;

    dac1 = -5;
    dac2 = -5;

    det1 = false;
    det2 = false;

    setStatus("Ok");
}

TransmitterModule::TransmitterModule(TransmitterModule *module)
{
    amp1 = module->amp1;
    amp2 = module->amp2;

    att1 = module->att1;
    att2 = module->att2;

    dac1 = module->dac1;
    dac2 = module->dac2;

    det1 = module->det1;
    det2 = module->det2;
}

bool TransmitterModule::getAmpState(int way)
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

float TransmitterModule::getAtt(int way)
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

double TransmitterModule::getDac(int way)
{
    double result = 0;
    switch (way) {
        case 0:
            result = dac1;
        break;
        case 1:
            result = dac2;
        break;
        default:
            result = 0xFF;
            setStatus("Way Error");
        break;
    }
    return result;
}

bool TransmitterModule::getDet(int way)
{
    bool result = 0;
    switch (way) {
        case 0:
            result = det1;
        break;
        case 1:
            result = det1;
        break;
        default:
            result = 0xFF;
            setStatus("Way Error");
        break;
    }
    return result;
}

bool TransmitterModule::getSup()
{
    return main_5V;
}

void TransmitterModule::setAmpState(bool amp, int way)
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

void TransmitterModule::setAtt(float att, int way)
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

void TransmitterModule::setDac(double dac, int way)
{
    switch (way) {
        case 0:
            dac1 = dac;
        break;
        case 1:
            dac2 = dac;
        break;
        default:
            setStatus("Way Error");
        break;
    }
}

void TransmitterModule::setDet(bool det, int way)
{
    switch (way) {
        case 0:
            det1 = det;
        break;
        case 1:
            det2 = det;
        break;
        default:
            setStatus("Way Error");
        break;
    }
}

void TransmitterModule::setSup(bool sup)
{
    main_5V = sup;
}

TransmitterModule::~TransmitterModule()
{

}
