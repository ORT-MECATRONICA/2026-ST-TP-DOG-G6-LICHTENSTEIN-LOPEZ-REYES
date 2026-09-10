#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Arrancando...");  // <-- agregá esta línea

  if (!ina219.begin()) {
    Serial.println("No se encontró el INA219. Revisá el cableado I2C.");
    while (1) delay(10);
  }

  Serial.println("INA219 conectado, iniciando lectura...");
}
void loop() {
  float voltajeBus = ina219.getBusVoltage_V();
  float corriente_mA = ina219.getCurrent_mA();
  float potencia_mW = ina219.getPower_mW();
  float voltajeShunt = ina219.getShuntVoltage_mV();
  float voltajeCarga = voltajeBus + (voltajeShunt / 1000);

  Serial.print("Voltaje bus: "); Serial.print(voltajeBus); Serial.println(" V");
  Serial.print("Corriente: "); Serial.print(corriente_mA); Serial.println(" mA");
  Serial.print("Potencia: "); Serial.print(potencia_mW); Serial.println(" mW");
  Serial.print("Voltaje carga: "); Serial.print(voltajeCarga); Serial.println(" V");
  Serial.println();

  delay(1000);
}