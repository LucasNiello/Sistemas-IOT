int led = 9;      // pino PWM do LED
int pot = A0;     // pino analógico do potenciômetro
int valor = 0;    // variável para armazenar a leitura

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  valor = analogRead(pot);        // lê o potenciômetro (0 a 1023)
  int brilho = map(valor, 0, 1023, 0, 255); // converte para PWM (0 a 255)
  analogWrite(led, brilho);       // aplica o valor no LED
}
