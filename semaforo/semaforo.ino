int VERMELHO_CARRO = 13;
int AMARELO_CARRO = 12;
int VERDE_CARRO = 11;

int VERMELHO_PEDESTRE = 10;
int VERDE_PEDESTRE = 9;

void setup() {
  //Configurar portas do semáforo
  pinMode(VERMELHO_CARRO, OUTPUT); //LED Vermelho carros
  pinMode(AMARELO_CARRO, OUTPUT); //LED Amarelo
  pinMode(VERDE_CARRO, OUTPUT); //LED Verde carros

  pinMode(VERMELHO_PEDESTRE, OUTPUT); //LED Vermelho pedestres
  pinMode(VERDE_PEDESTRE, OUTPUT); //LED Verde pedestres
}

void loop() {
  mudarParaVerde(5000);
  mudarParaAmarelo(1500);
  mudarParaVermelho(5000); 
}

void mudarParaVerde(int tempoDeEspera) {
  digitalWrite(VERDE_CARRO, HIGH);
  digitalWrite(AMARELO_CARRO, LOW);
  digitalWrite(VERMELHO_CARRO, LOW);

  //Sinal vermelho para pedestres
  digitalWrite(VERMELHO_PEDESTRE, HIGH);
  digitalWrite(VERDE_PEDESTRE, LOW);
  
  delay(tempoDeEspera);
}

void mudarParaAmarelo(int tempoDeEspera) {
  digitalWrite(VERDE_CARRO, LOW);
  digitalWrite(AMARELO_CARRO, HIGH);
  digitalWrite(VERMELHO_CARRO, LOW);

  //Sinal vermelho para pedestres
  digitalWrite(VERMELHO_PEDESTRE, HIGH);
  digitalWrite(VERDE_PEDESTRE, LOW);
  
  delay(tempoDeEspera);
}

void mudarParaVermelho(int tempoDeEspera) {
  int tempoNormal = tempoDeEspera * 0.50;
  int tempoPiscando = tempoDeEspera * 0.50;
  
  digitalWrite(VERDE_CARRO, LOW);
  digitalWrite(AMARELO_CARRO, LOW);
  digitalWrite(VERMELHO_CARRO, HIGH);

  //Sinal vermelho para pedestres
  digitalWrite(VERMELHO_PEDESTRE, LOW);
  digitalWrite(VERDE_PEDESTRE, HIGH);
  
  delay(tempoNormal);

  int horaInicial = millis();
  
  do {
    digitalWrite(VERDE_PEDESTRE, LOW);
    delay(50);
    digitalWrite(VERDE_PEDESTRE, HIGH);
    delay(50);    
  } while( millis() - horaInicial < tempoPiscando);
  
}
