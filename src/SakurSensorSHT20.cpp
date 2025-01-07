#include "SakurSensorSHT20.h"

SakurSensorSHT20::SakurSensorSHT20 ()
{
    this->setModbusMaster ();
}

SakurSensorSHT20::~SakurSensorSHT20 ()
{
    delete m_modbus;
}

void SakurSensorSHT20::setModbusMaster ()
{
    this->m_modbus = new ModbusMaster;
}

ModbusMaster * SakurSensorSHT20::modbusMaster() const
{
    return this->m_modbus;
}

void SakurSensorSHT20::setupComponent () 
{
    /* definisi base component */
    SakurBaseComponent::setupComponent();

    /* set default dari sht20 */
    Serial2.begin (BOUNDRATESHT20, SERIAL_8N1, PIN_RX, PIN_TX );
    this->modbusMaster()->begin (1, Serial2);

    /* tampilkan welcome */
    SakurBaseComponent::viewTextWelcome();
    SakurBaseComponent::viewTextKahfiQiana();
    SakurBaseComponent::viewTextToOLED();
}

void SakurSensorSHT20::readRegisterData ()
{
    this->m_result = this->modbusMaster()->readInputRegisters ( 1, 2 );

    if (this->m_result == this->modbusMaster()->ku8MBSuccess)
    {
        // simpan data ke variabel
        this->m_data[0] = this->modbusMaster()->getResponseBuffer ( 0 );
        this->m_data[1] = this->modbusMaster()->getResponseBuffer ( 1 );

        // konversi kan
        this->m_data_temp = this->m_data[0] / 10.0;
        this->m_data_humadity = this->m_data[1] / 10.0;

    }else{
        Serial.print ("Error membaca data registerasi.");
        Serial.print (this->m_result);
    }
}

float SakurSensorSHT20::dataTemperature () const
{
    return this->m_data_temp;
}

float SakurSensorSHT20::dataHumadity () const
{
    return this->m_data_humadity;
}

void SakurSensorSHT20::loadingDataSHT20()
{
    // registerasi data
    this->readRegisterData ();

    String temp = "T:" + static_cast<String>(this->dataTemperature()); //"°C";
    String huma = "H:" + static_cast<String>(this->dataHumadity());
    Serial.println ("SHT20-" + temp + ", " + huma);
    
    delay (1000);
}

void SakurSensorSHT20::displayDataSHT20()
{
    String temp = "T:" + static_cast<String>(this->dataTemperature()) + "C"; //"°C";
    String huma = "H:" + static_cast<String>(this->dataHumadity()) + "%";

    SakurBaseComponent::plotTextToOLED ("Kond.Suhu-Lembab:", 1, 0, 0 );
    SakurBaseComponent::plotTextToOLED (temp, 2, 12, 0);
    SakurBaseComponent::plotTextToOLED (huma, 2, 30, 0);
    SakurBaseComponent::displayText();

    Serial.println ("temp: " + temp +",Hum:" + huma);
}