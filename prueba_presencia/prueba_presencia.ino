#include <ld2410.h>

ld2410 radar;

// UART2 del ESP32
#define RADAR_RX 16  // va al TX del sensor
#define RADAR_TX 17  // va al RX del sensor

void setup() {
  Serial.begin(115200);
  Serial2.begin(256000, SERIAL_8N1, RADAR_RX, RADAR_TX);

  if (radar.begin(Serial2)) {
    Serial.println("Radar HLK-LD2410 conectado");
  } else {
    Serial.println("No se pudo conectar al radar");
  }
}

void loop() {
  radar.read();

  if (radar.presenceDetected()) {
    Serial.print("Presencia detectada. Distancia: ");
    Serial.print(radar.detectionDistance());
    Serial.println(" cm");
  } else {
    Serial.println("Sin presencia");
  }

  

  delay(500);
}
