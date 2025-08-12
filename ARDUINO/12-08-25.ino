// Exercicios

// 1)

void setup() {
pinMode(13, OUTPUT); //Define o pino 13 como saída
pinMode(8, OUTPUT) ;

}

void loop() {
digitalWrite(13, HIGH);
delay(1000);
digitalWrite(13, LOW);
delay(1000);
digitalWrite(8, HIGH);
delay(2000);
digitalWrite(8, LOW);
delay(2000);

}


// ##########################   2:

// Semáforo simples
// Vermelho -> 5s
// Verde -> 5s
// Amarelo -> 2s

// Define os pinos dos LEDs
int ledVermelho = 8;
int ledAmarelo  = 9;
int ledVerde    = 10;

void setup() {
  // Configura os pinos como saída
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  // LED Vermelho aceso
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);
  delay(5000); // Espera 5 segundos

  // LED Verde aceso
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, HIGH);
  delay(5000); // Espera 5 segundos

  // LED Amarelo aceso
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, HIGH);
  digitalWrite(ledVerde, LOW);
  delay(2000); // Espera 2 segundos
}







// ##########################   3:

// Botão Liga/Desliga (Toggle)
// Cada clique alterna o LED entre ligado e desligado

int ledPin = 8;        // LED no pino 8
int botaoPin = 2;      // Botão no pino 2

bool estadoLED = false;     // Guarda se o LED está ligado ou não
bool ultimoEstadoBotao = HIGH; // Guarda o último estado do botão
unsigned long debounceDelay = 50; // Tempo para evitar bouncing (ms)
unsigned long ultimoTempo = 0;    // Armazena o último tempo de leitura

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(botaoPin, INPUT_PULLUP); // Usa resistor interno pull-up
}

void loop() {
  bool leitura = digitalRead(botaoPin);

  // Se o estado mudou (e passou tempo suficiente para ignorar bouncing)
  if (leitura != ultimoEstadoBotao && (millis() - ultimoTempo) > debounceDelay) {
    ultimoTempo = millis();

    // Botão foi pressionado (estado LOW)
    if (leitura == LOW) {
      estadoLED = !estadoLED; // Inverte o estado do LED
      digitalWrite(ledPin, estadoLED ? HIGH : LOW);
    }
  }

  ultimoEstadoBotao = leitura;
}

