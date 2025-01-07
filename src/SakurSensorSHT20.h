#ifndef SAKURSENSORSHT20_H
#define SAKURSENSORSHT20_H

#include <ModbusMaster.h>
#include <iostream>

#include "SakurBaseComponent.h"
#include "SakurDefineComponent.h"

using namespace std;

/* definisi header Sensor SHT20 */
class SakurSensorSHT20 : public SakurBaseComponent
{
    public:
        SakurSensorSHT20 ();
        ~SakurSensorSHT20 ();

        void setModbusMaster ();
        ModbusMaster * modbusMaster() const;

        /* fungsi untuk SHT20 */
        void readRegisterData ();
        void loadingDataSHT20 ();
        void displayDataSHT20 ();

        float dataTemperature () const;
        float dataHumadity () const;

        // set component
        void setupComponent ();
    
    private:
        ModbusMaster * m_modbus;
        SakurBaseComponent mComponent;

        /* member data dari SHT20*/
        uint8_t m_result;
        uint16_t m_data[2];

        float m_data_temp = 0.0;
        float m_data_humadity = 0.0;

};

#endif