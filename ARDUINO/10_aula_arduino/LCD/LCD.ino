#include <LiquidCrystal.h>

// Pinos conectados ao LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // Inicializa o LCD com 16 colunas e 2 linhas
  lcd.print("Teste LCD 16x2"); // Escreve na primeira linha
  delay(2000); // Aguarda 2 segundos
  lcd.clear(); // Limpa o display
}

void loop() {
  lcd.setCursor(0, 0); // Linha 1, coluna 1
  lcd.print("Contando:"); // Mensagem fixa

  for (int i = 0; i < 10; i++) {
    lcd.setCursor(0, 1); // Linha 2, coluna 1
    lcd.print("Numero: ");
    lcd.print(i);
    lcd.print("    "); // Apaga lixo na tela
    delay(1000); // Aguarda 1 segundo
  }

  lcd.clear(); // Limpa após a contagem
  delay(1000);
}