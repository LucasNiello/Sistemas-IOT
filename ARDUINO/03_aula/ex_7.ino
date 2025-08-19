void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13, HIGH); //Liga o LED
  delay(500); //Espera 1 Seg
  digitalWrite(13, LOW); //Desliga o LED
  
  digitalWrite(12, HIGH); //Liga o LED
  delay(500); //Espera 1 Seg
  digitalWrite(12, LOW); //Desliga o LED
  
  digitalWrite(11, HIGH); //Liga o LED
  delay(500); //Espera 1 Seg
  digitalWrite(11, LOW); //Desliga o LED

   digitalWrite(10, HIGH); //Liga o LED
  delay(500); //Espera 1 Seg
  digitalWrite(10, LOW); //Desliga o LED

 digitalWrite(9, HIGH); //Liga o LED
  delay(1000); //Espera 1 Seg
  digitalWrite(9, LOW); //Desliga o LED

}
