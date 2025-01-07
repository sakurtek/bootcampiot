/* include all component */

#include "SakurSensorSHT20.h"
#include "SakurSensorLDR.h"
#include "SakurSensorSOIL.h"

SakurBaseComponent dataSensor;
SakurSensorSHT20 sensorSHT20;
SakurSensorLDR sensorLDR;
SakurSensorSOIL sensorSOIL;

/* Prototipe  */
void setupComponent ();
void loadingAllSensorData ();
void displayAllDataSensor ();

/* Implementasi */
void setupComponent ()
{
    /* Info dalam serial */
    Serial.println ("Sistem Sensor Terintegrasi.");
    Serial.println ("1. Sensor Suhu dengan SHT20.");
    Serial.println ("2. Sensor LDR.");
    Serial.println ("3. Sensor Soil Moisture.");
    Serial.println ("Terima kasih\n");

    /* Menginsial Seluruh sensor awal */
    sensorSHT20.setupComponent ();
    sensorLDR.setupComponent ();
    dataSensor.setupComponent ();
    sensorSOIL.setupComponent ();
}

/* Loading all data */
void loadingAllSensorData ()
{
    /* baca senser SHT20  */
    sensorSHT20.loadingDataSHT20 ();

    /* baca sensor LDR */
    sensorLDR.loadingDataLDR ();

    /* baca sensor SOIL */
    sensorSOIL.loadingDataSOIL ();

    /* aktifkan LED */
    sensorSHT20.lightUPTheLED ();

    /* tampilkan seluruh data sensor */
    displayAllDataSensor ();
}

void displayAllDataSensor ()
{
    /* sensor SHT 20 */
    float temperatur = sensorSHT20.dataTemperature();
    float humadity = sensorSHT20.dataHumadity();
    /* Conversi ke string */
    String temp = "T:" + static_cast<String>(temperatur) + "C";
    String huma = "H:" + static_cast<String>(humadity) + "%";

    /* sensor LDR */
    float adc2Lux = sensorLDR.adcToLux();
    int dataLdr = sensorLDR.dataLDR ();

    String ldr = "ADC:" + static_cast<String>(dataLdr) + "; ";
    String lux = "LUX:" + static_cast<String>(adc2Lux);

    /* sensor SOIL */
    int dtSoil = sensorSOIL.dataSOIL ();
    String adcSoil = "SOIL MOISTURE:" + static_cast<String>(dtSoil);

    /* tampilkan data ke OLED */
    dataSensor.plotTextToOLED ("Parameter Sensor:", 1, 0, 0 );
    dataSensor.plotTextToOLED (temp, 2, 10, 0 );
    dataSensor.plotTextToOLED (huma, 2, 26, 0 );
    dataSensor.plotTextToOLED (ldr, 1.5, 42, 0 );
    dataSensor.plotTextToOLED (lux, 1.5, 42, 60 );
    dataSensor.plotTextToOLED (adcSoil, 1.5, 52, 0 );
    dataSensor.displayText ();
  
    delay (1000);
    dataSensor.clearDisplay();
}

