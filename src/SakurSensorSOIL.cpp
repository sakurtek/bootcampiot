#include "SakurSensorSOIL.h"

SakurSensorSOIL::SakurSensorSOIL () {
    // constructor
}

SakurSensorSOIL::~SakurSensorSOIL () {
    // destructor 
}

void SakurSensorSOIL::setupComponent ()
{   
    Serial.begin ( BOUNDRATESOIL );
    analogSetAttenuation ( ADC_11db );
}

void SakurSensorSOIL::readSensorSOIL () 
{
    this->m_sensor_value = analogRead ( PIN_SOIL );
}

int SakurSensorSOIL::dataSOIL ()
{
    return this->m_sensor_value; 
}

void SakurSensorSOIL::loadingDataSOIL ()
{
    // baca data sensor 
    this->readSensorSOIL();

    // tampilkan data dalam seria
    Serial.print ("SOIL-Moisture value:");
    Serial.println (this->dataSOIL());
}