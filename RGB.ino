const int led=3;      //Led Rojo
const int led1=5;    //Led Verde
const int led2=10;  //Led Azul
const int pot=A4;   //Potenciometro 1
const int pot1=A5;  //Potenciometro 2
const int pot2=A6;  //Potenciometro 3
int intensidad=0;   //Intensidad led rojo
int intensidad1=0;   //Intensidad led verde
int intensidad2=0;   //Intensidad led azul


void setup() {
  pinMode (led, OUTPUT); //Salida led Rojo
  pinMode (led1, OUTPUT); //Salida led Verde
  pinMode (led2, OUTPUT); //Salida led Azul
}

void loop() {
  intensidad = (analogRead (pot))/4; //Lectura del potenciometro 1 entre 4
  analogWrite(led, intensidad); //Se observa el valor de intensidad en el led Rojo
  delay(20); //tiempo de espera
  
  intensidad1 = (analogRead (pot1))/4;//Lectura del potenciometro 2 entre 4
  analogWrite(led1, intensidad1); //Se observa el valor de intensidad en el led Verde
  delay(20);  //tiempo de espera
  
  intensidad2 = (analogRead (pot2)) /4;//Lectura del potenciometro 3 entre 4
  analogWrite(led2, intensidad2);  //Se observa el valor de intensidad en el led Azul
  delay(20);  //tiempo de espera
}
