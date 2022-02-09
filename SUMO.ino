//Sensores SHARP
int ADC_SHARP = analogRead(A2);
int ADC_SHARP1 = analogRead(A3);
//variables motor
int motorPin1 = 8; // pin 2 on L293D IC
int motorPin2 = 5; // pin 7 on L293D IC
int enablePin = 6; // pin 1 on L293D IC
int state;
int flag = 0;
//sensores de linea
const int QRD1114_PIN = A0;
const int QRD1114_PIN1 = A1;
//variable para numero aleatorio
long numRand;
int n = 15;
//Sensores
int sensorIzq = 0;
int sensorDer = 0;
int cmDer = 0, cmIzq = 0;

void setup()
{
  delay(5000);//tiempo de seguridad
  pinMode(13, OUTPUT);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, HIGH);

  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    state = Serial.read();
    flag = 0;
  }

  if ( (cmDer <= n) && (cmIzq <= n)) {
    buscar();
    Serial.println("BUSCANDO");
    if (digitalRead(QRD1114_PIN) == LOW) {
      Serial.println("LINEA BLANCA ");
      reversa();
      delay(200);
    }
    if (digitalRead(QRD1114_PIN1) == LOW) {
      Serial.println("LINEA BLANCA ");
      adelante();
      delay(200);
    }
  } else {
    parar();
    Serial.println("DETENER");
  }
  if ((cmDer <= n) && (cmIzq <= n)) {
    golpeIzq();
    Serial.println("GOLPE IZQUIERDO");
    if (digitalRead(QRD1114_PIN) == LOW) {
      Serial.println("LINEA BLANCA ");
      reversa();
      delay(200);
    }
    if (digitalRead(QRD1114_PIN1) == LOW) {
      Serial.println("LINEA BLANCA ");
      adelante();
      delay(200);
    }
  }
  if ((cmDer <= n) && (cmIzq <= n)) {
    golpeDer();
    Serial.println("GOLPE DERECHO");
    if (digitalRead(QRD1114_PIN) == LOW) {
      Serial.println("LINEA BLANCA ");
      reversa();
      delay(200);
    }
    if (digitalRead(QRD1114_PIN1) == LOW) {
      Serial.println("LINEA BLANCA ");
      adelante();
      delay(200);
    }
  }
  if ((cmDer <= n) && (cmIzq <= n)) {
    adelante();
    if (digitalRead(QRD1114_PIN) == LOW) {
      Serial.println("LINEA BLANCA ");
      reversa();
      delay(200);
    }
    if (digitalRead(QRD1114_PIN1) == LOW) {
      Serial.println("LINEA BLANCA ");
      adelante();
      delay(200);
    }
  }

  if (digitalRead(QRD1114_PIN) == LOW) {
    Serial.println("LINEA BLANCA ");
    reversa();
    delay(200);
  }
  if (digitalRead(QRD1114_PIN1) == LOW) {
    Serial.println("LINEA BLANCA ");
    adelante();
    delay(200);
  }
  delay(50);
}

void sensores() {

  sensorDer = analogRead(ADC_SHARP); // lectura del sensor 1
  cmDer = pow(3027.4 / sensorDer, 1.2134); // conversión a centímetros
  delay(1);

  sensorIzq = analogRead(ADC_SHARP1); // lectura del sensor 2
  cmIzq = pow(3027.4 / sensorIzq, 1.2134); // conversión a centímetros
  delay(1);
}

void buscar() {
  numRand = random(0, 4);
  if (numRand == 1) {
    adelante();
    delay(400);
  }

  if (numRand == 2) {
    golpeIzq();
    delay(400);

  }
  if (numRand == 3) {
    golpeDer();
    delay(400);
  }
  digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
  digitalWrite(motorPin2, HIGH); // set pin 7 on L293D high
  delay(200);

}
void golpeDer() {
  digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
  digitalWrite(motorPin2, HIGH); // set pin 7 on L293D high
}
void golpeIzq() {
  digitalWrite(motorPin1, HIGH); // set pin 2 on L293D low
  digitalWrite(motorPin2, LOW); // set pin 7 on L293D high
}
void adelante() {

  digitalWrite(motorPin1, HIGH); // set pin 2 on L293D low
  digitalWrite(motorPin2, HIGH); // set pin 7 on L293D high


}
void reversa() {
  digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
  digitalWrite(motorPin2, HIGH);
}
void parar() {

  digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
  digitalWrite(motorPin2, LOW); // set pin 7 on L293D low

}
