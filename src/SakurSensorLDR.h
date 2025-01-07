#ifndef SAKURSENSORLDR_H
#define SAKURSENSORLDR_H

#include <iostream>
#include "SakurBaseComponent.h"
#include "SakurDefineComponent.h"

using namespace std;

class SakurSensorLDR : public SakurBaseComponent
{
    public:
        SakurSensorLDR ();
        ~SakurSensorLDR ();

        void readDataLDR ();
        int dataLDR () const;
        void setAdcToLux ();
        float adcToLux () const;

        void loadingDataLDR ();

        /* tampil data ke layar */
        void displayDataLDR ();

    private:
        int m_data_ldr;
        float m_adc_lux;

};

# endif