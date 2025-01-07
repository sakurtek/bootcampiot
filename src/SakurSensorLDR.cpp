#include "SakurSensorLDR.h"

SakurSensorLDR::SakurSensorLDR () {
    // constructor jika ada
}

SakurSensorLDR::~SakurSensorLDR() {
    // destructor 
    // jika ada
}

void SakurSensorLDR::readDataLDR () {
    this->m_data_ldr = analogRead (PIN_LDR);
}

int SakurSensorLDR::dataLDR () const {
    return this->m_data_ldr;
}

void SakurSensorLDR::setAdcToLux () {

    int adcValue = this->dataLDR();

    const float GAMMA = 0.7;
    const float RL10 = 33;
    float voltage = adcValue / 4096. * 3.3;
    float resistance = 2000 * voltage / (1 - voltage / 3.3);
    float luxValue = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));
    //luxValue;
    this->m_adc_lux = luxValue;
}

float SakurSensorLDR::adcToLux() const
{
    return this->m_adc_lux;
}

void SakurSensorLDR::loadingDataLDR ()
{
    // set data analog read
    this->readDataLDR ();

    // konversi kan data
    this->setAdcToLux ();

    String data = static_cast<String>(this->dataLDR());
    String strLux = static_cast<String>(this->adcToLux());
    Serial.println("LDR-ADC:" + data + ", Lux:" + strLux);
    // delay
    delay (1000);

}

void SakurSensorLDR::displayDataLDR ()
{
    // tampilkna data
    String strLux = static_cast<String>(this->adcToLux());
    String vAllData = "Lux:" + strLux;

    SakurBaseComponent::plotTextToOLED (vAllData, 2, 40, 0);
    SakurBaseComponent::displayText();

    Serial.println("Lux: " + strLux);
}