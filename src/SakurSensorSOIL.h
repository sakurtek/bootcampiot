#ifndef SAKURSENSORSOIL_H
#define SAKURSENSORSOIL_H

#include <iostream>
#include "SakurBaseComponent.h"
#include "SakurDefineComponent.h"

using namespace std;

class SakurSensorSOIL : public SakurBaseComponent
{

public:
    SakurSensorSOIL ();
    ~SakurSensorSOIL ();

    void readSensorSOIL ();
    void setupComponent ();
    int dataSOIL ();

    void loadingDataSOIL ();

private:
    int m_sensor_value;

};

#endif