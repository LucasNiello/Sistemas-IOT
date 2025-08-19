// LED RGB - Catodo Comum
int redPin   = 9;   // PWM
int greenPin = 10;  // PWM
int bluePin  = 11;  // PWM

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);   // Vermelho
  delay(1000);
  setColor(0, 255, 0);   // Verde
  delay(1000);
  setColor(0, 0, 255);   // Azul
  delay(1000);
  setColor(255, 255, 0); // Amarelo (R+G)
  delay(1000);
  setColor(0, 255, 255); // Ciano (G+B)
  delay(1000);
  setColor(255, 0, 255); // Magenta (R+B)
  delay(1000);
  setColor(255, 255, 255); // Branco (R+G+B)
  delay(1000);
  setColor(0, 0, 0);     // Desliga
  delay(1000);
}

// Função que define a cor pelo valor RGB
// valores: 0 (apagado) até 255 (máximo brilho)
void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}
