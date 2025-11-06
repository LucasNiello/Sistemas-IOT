#include <DHT.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// === Configurações ===
#define DHTPIN A0        // Pino do DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// LCD 16x2 (sem I2C): RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

Servo exaustor;

const int buzzerPin = 10;   
const int servoPin = 9;     

// Limites de temperatura (ajustáveis)
const float LIM_IDEAL = 25.0;
const float LIM_QUENTE = 30.0;
const float LIM_MUITO = 35.0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.begin(16, 2);
  lcd.print("CPD MONITOR v3");
  delay(2000);
  lcd.clear();

  exaustor.attach(servoPin);
  exaustor.write(0); // exaustor parado

  pinMode(buzzerPin, OUTPUT);
  noTone(buzzerPin);
}

void loop() {
  float temperatura = dht.readTemperature();

  if (isnan(temperatura)) {
    lcd.setCursor(0
