// Prueba de LDR
const int pinLDR = 34;  // Pin ADC del ESP32 (32-39 son ideales, no usan wifi)

void setup() {
  Serial.begin(115200);
}

void loop() {
  int lecturaCruda = analogRead(pinLDR);           // 0 a 4095 en ESP32
  int luzPorcentaje = map(lecturaCruda, 0, 4095, 0, 100);

  Serial.print("Lectura cruda: ");
  Serial.print(lecturaCruda);
  Serial.print(" | Luz: ");
  Serial.print(luzPorcentaje);
  Serial.println("%");

  delay(500);
}

