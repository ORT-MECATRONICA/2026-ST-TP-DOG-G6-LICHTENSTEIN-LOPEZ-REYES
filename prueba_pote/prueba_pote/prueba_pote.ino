// Prueba pote
const int pinGas = 35; // Pin analógico - simula el MQ-2


void setup() {
  Serial.begin(115200);
  analogReadResolution(12); // 0-4095
}


void loop() {
  int lecturaRaw = analogRead(pinGas);


  // Mapeamos de 0-4095 a 0-100%
  int gasPorcentaje = map(lecturaRaw, 0, 4095, 0, 100);


  Serial.print("Raw: ");
  Serial.print(lecturaRaw);
  Serial.print("  |  Gas: ");
  Serial.print(gasPorcentaje);
  Serial.println("%");


  delay(500);
}
