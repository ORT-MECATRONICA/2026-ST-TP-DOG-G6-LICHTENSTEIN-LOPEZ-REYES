// Grupo 9 - REYES LICHTENSTEIN LOPEZ
// Prueba pantalla LCD I2C 16x2

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección típica 0x27, si no anda probá 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hola CHOPITO");
  lcd.setCursor(0, 1);
  lcd.print("LCD funcionando");
}

void loop() {
  // Prueba simple: contador en la segunda línea
  static int contador = 0;

  lcd.setCursor(0, 1);
  lcd.print("Contador: ");
  lcd.print(contador);
  lcd.print("   ");  // espacios para borrar dígitos viejos si el número se achica

  contador++;
  delay(1000);
}