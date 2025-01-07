/* 
  Main function for my project 
  MyProject Bootcamp Session 3: 
  - Pemeriksaan Suhu dan Kelembapan udara
  - Sensor LDR
  - Sensor Soil Moisture
*/

#include "MyProjectBootcamp.h"

void setup() {
  /* Melakukan pengaturan awal dari sistem */
  setupComponent ();
}

void loop() {
  /* Loading seluruh data sensor */
  loadingAllSensorData();
}

