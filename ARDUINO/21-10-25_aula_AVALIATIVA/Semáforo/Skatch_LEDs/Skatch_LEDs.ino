#include <Arduino.h>

// Define os pinos para os LEDs
const int ledVerde = 7;    // LED 1 - Verde
const int ledAmarelo = 8;  // LED 2 - Amarelo
const int ledVermelho = 9; // LED 3 - Vermelho

void setup() {
  Serial.begin(9600); // Mesmo baud rate do Flask
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch (command) {
      // LED 1 (Verde)
      case 'A': digitalWrite(ledVerde, HIGH); break;
      case 'a': digitalWrite(ledVerde, LOW);  break;

      // LED 2 (Amarelo)
      case 'B': digitalWrite(ledAmarelo, HIGH); break;
      case 'b': digitalWrite(ledAmarelo, LOW);  break;

      // LED 3 (Vermelho)
      case 'C': digitalWrite(ledVermelho, HIGH); break;
      case 'c': digitalWrite(ledVermelho, LOW);  break;

      default:
        // Ignora comandos desconhecidos
        break;
    }
  }
}