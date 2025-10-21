#include <DHT.h>

#define DHTPIN 2      // Pino de dados do DHT11
#define DHTTYPE DHT11

#define LED_VERMELHO 8
#define LED_AZUL 7

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
}

void loop() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  // Verifica se a leitura falhou
  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("{\"error\":\"Falha na leitura do sensor\"}");
  } else {
    // Controle dos LEDs
    if (temperatura > 20) {
      digitalWrite(LED_VERMELHO, HIGH);
      digitalWrite(LED_AZUL, LOW);
    } else {
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(LED_AZUL, HIGH);
    }

    // Envia dados via Serial em JSON
    Serial.print("{\"temperatura\":");
    Serial.print(temperatura);
    Serial.print(",\"umidade\":");
    Serial.print(umidade);
    Serial.println("}");
  }

  delay(3000); // Espera 3 segundos antes da próxima leitura
}
