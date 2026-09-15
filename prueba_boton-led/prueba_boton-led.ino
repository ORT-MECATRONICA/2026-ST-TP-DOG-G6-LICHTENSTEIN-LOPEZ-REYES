// Prueba: botón controla LEDs en pines 18 y 19

#define PIN_LED_ROJO   18
#define PIN_LED_VERDE  19
#define PIN_BOTON      4    

void setup() {
  pinMode(PIN_LED_ROJO, OUTPUT);
  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_BOTON, INPUT_PULLUP);  
}

void loop() {
  int estadoBoton = digitalRead(PIN_BOTON);

  if (estadoBoton == LOW) {  // con INPUT_PULLUP, presionado = LOW
    digitalWrite(PIN_LED_ROJO, HIGH);
    digitalWrite(PIN_LED_VERDE, LOW);
  } else {
    digitalWrite(PIN_LED_ROJO, LOW);
    digitalWrite(PIN_LED_VERDE, HIGH);
  }
}