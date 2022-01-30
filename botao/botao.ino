int PIN_BOTAO = 8;
int PIN_LED = 13;

void setup() {
  pinMode(PIN_BOTAO, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  
/* Este bloco condicional foi substituido pela linha abaixo
 *  
  if (digitalRead(PIN_BOTAO) == HIGH) {
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
*/

  digitalWrite(PIN_LED, digitalRead(PIN_BOTAO));
}
