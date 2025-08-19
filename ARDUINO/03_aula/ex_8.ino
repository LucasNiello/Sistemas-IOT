// Barra de LED VU Meter com potenciômetro

// Pinos dos LEDs (8 no exemplo, pode mudar)
int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
int numLeds = 8;

// Pino do potenciômetro
int potPin = A0;

void setup() {
  // Configura LEDs como saída
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Lê valor do potenciômetro (0 a 1023)
  int valor = analogRead(potPin);

  // Mapeia para número de LEDs acesos (0 a numLeds)
  int nivel = map(valor, 0, 1023, 0, numLeds);

  // Acende os LEDs até o nível
  for (int i = 0; i < numLeds; i++) {
    if (i < nivel) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }

  delay(50); // Pequena pausa para estabilidade
}
