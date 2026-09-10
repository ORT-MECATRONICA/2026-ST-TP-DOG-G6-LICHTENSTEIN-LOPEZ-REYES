#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  Serial.println("Prueba BMP280");

  if (!bmp.begin(0x76)) {  // Dirección I2C típica: 0x76 o 0x77
    Serial.println("No se encontró el sensor BMP280. Revisá el cableado o la dirección I2C.");
    while (1) delay(10);
  }

  // Configuración opcional de muestreo
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                   Adafruit_BMP280::SAMPLING_X2,
                   Adafruit_BMP280::SAMPLING_X16,
                   Adafruit_BMP280::FILTER_X16,
                   Adafruit_BMP280::STANDBY_MS_500);
}

void loop() {
  Serial.print("Temperatura: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" °C");

  Serial.print("Presión: ");
  Serial.print(bmp.readPressure() / 100.0F);  // convierte a hPa
  Serial.println(" hPa");

  Serial.print("Altitud aprox: ");
  Serial.print(bmp.readAltitude(1013.25));  // presión a nivel del mar en hPa
  Serial.println(" m");

  Serial.println();
  delay(2000);
}