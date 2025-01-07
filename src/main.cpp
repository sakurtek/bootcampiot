/* 
  Fungsi utama untuk Project Smart Farming
  Final Project yang dikembangkan dari Tutorial Edspert.Id
  BootCamp IoT Sesion 3:
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

