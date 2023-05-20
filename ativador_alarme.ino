// PINAGENS DO ARDUÍNO
int pinoBotao     = 2;
int pinoLED       = 3;
int pinoTriger    = 4;
int pinoEcho      = 5;
int pinoLEDAlarme = 6;

// VARIÁVEIS AUXILIARES
int ativarAlarme = 0;
float distancia  = 0;

void setup() {
  // ENTRADA DE DADOS
  pinMode(pinoBotao, INPUT);
  pinMode(pinoEcho, INPUT);

  // SAÍDA DE DADOS
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoTriger, OUTPUT);

  digitalWrite(pinoLED, LOW);
}

void DispararSensorUltrasonico() {
  digitalWrite(pinoTriger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTriger, LOW);
}

void alarmeAtivo() {
  DispararSensorUltrasonico();

  distancia = ((pulseIn(pinoEcho, HIGH) * 0.000340) / 2);

  if(distancia < 0.4) {
    tone(pinoLEDAlarme, 1500);
    delay(100);
    noTone(pinoLEDAlarme);
  }
}

void loop() {
  if(digitalRead(pinoBotao)) {
    ativarAlarme = (ativarAlarme == 0) ? 1: 0;
  }

  if(ativarAlarme) {
    digitalWrite(pinoLED, HIGH);

    alarmeAtivo();
  } else {
    digitalWrite(pinoLED, LOW);
  }

  delay(180);
}
