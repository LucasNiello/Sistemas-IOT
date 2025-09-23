#define led1 11
#define led2 10
#define led3 9
#define led4 8
#define led5 7

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  // Liga LEDs em sequência (efeito crescente)
  digitalWrite(led1, HIGH);
  delay(300);

  digitalWrite(led2, HIGH);
  delay(300);

  digitalWrite(led3, HIGH);
  delay(300);

  digitalWrite(led4, HIGH);
  delay(300);

  digitalWrite(led5, HIGH);
  delay(300);

  // Apaga LEDs em sequência (efeito decrescente)
  digitalWrite(led5, LOW);
  delay(300);

  digitalWrite(led4, LOW);
  delay(300);

  digitalWrite(led3, LOW);
  delay(300);

  digitalWrite(led2, LOW);
  delay(300);

  digitalWrite(led1, LOW);
  delay(300);
}
