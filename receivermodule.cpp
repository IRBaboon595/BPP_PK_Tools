#include "receivermodule.h"

ReceiverModule::ReceiverModule() : hardwareDevice("Приёмник")
{
    amp1_1 = false;
    amp1_2 = false;
    amp2_1 = false;
    amp2_2 = false;

    att1_1 = 31.5;
    att1_2 = 31.5;
    att2_1 = 31.5;
    att2_2 = 31.5;

    setStatus("Ok");
}

ReceiverModule::ReceiverModule(ReceiverModule *module)
{

    amp1_1 = module->amp1_1;
    amp1_2 = module->amp1_2;
    amp2_1 = module->amp2_1;
    amp2_2 = module->amp2_2;

    att1_1 = module->att1_1;
    att1_2 = module->att1_2;
    att2_1 = module->att2_1;
    att2_2 = module->att2_2;
}

bool ReceiverModule::getAmpState(int way)
{
    bool result = 0;
    switch (way) {
        case 0:
            result = amp1_1;
        break;
        case 1:
            result = amp1_2;
        break;
        case 2:
            result = amp2_1;
        break;
        case 3:
            result = amp2_2;
        break;
        default:
            result = 0xFF;
            setStatus("Way Error");
        break;
    }
    return result;
}

float ReceiverModule::getAtt(int way)
{
    float result = 0;
    switch (way) {
        case 0:
            result = att1_1;
        break;
        case 1:
            result = att1_2;
        break;
        case 2:
            result = att2_1;
        break;
        case 3:
            result = att2_2;
        break;
        default:
            result = 0xFF;
            setStatus("Way Error");
        break;
    }
    return result;
}

bool ReceiverModule::getSup()
{
    return main_5V;
}

void ReceiverModule::setAmpState(bool amp, int way)
{
    switch (way) {
        case 0:
            amp1_1 = amp;
        break;
        case 1:
            amp1_2 = amp;
        break;
        case 2:
            amp2_1 = amp;
        break;
        case 3:
            amp2_2 = amp;
        break;
        default:
            setStatus("Way Error");
        break;
    }
}

void ReceiverModule::setAtt(float att, int way)
{
    switch (way) {
        case 0:
            att1_1 = att;
        break;
        case 1:
            att1_2 = att;
        break;
        case 2:
            att2_1 = att;
        break;
        case 3:
            att2_2 = att;
        break;
        default:
            setStatus("Way Error");
        break;
    }
}

void ReceiverModule::setSup(bool sup)
{
    main_5V = sup;
}

ReceiverModule::~ReceiverModule()
{

}

