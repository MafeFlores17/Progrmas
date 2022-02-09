int Sensor = A6 ;             // Pin del sensor
int umbral = 29;            // Indica la temperatura en la que enciende el ventilador
const int control = 2 ;     // Control del ventilador

void setup()
{
    Serial.begin(115200); 
    pinMode(control, OUTPUT) ; //Pin de salida
}

void loop()
{
    int lectura = analogRead(Sensor);  //Se guarda en lectura los valores captados por el sensor
    float voltaje = 5.0 /1024 * lectura ; // Se transforma el valor a voltios 
    float temp = voltaje * 100-5; // Se muestra el valor de la temperatura 
    Serial.print ("Temperatura = "); 
    Serial.println(temp); //Se muestra en Monitor la temperatura sensada
    if (temp >= umbral) 
        digitalWrite(control, HIGH); //Encender ventilador
    else
       digitalWrite(control, LOW); //Apagar ventilador

    delay(200); //Medida de temperatura cada 0.2 segundos
}
