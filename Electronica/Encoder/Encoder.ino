//Pines de Entrada
int encoderPin=8; //encoder 8-8, pin obligatorio

//tiempos
int timeToCalculateSpeed=100;//cada 100 milisegundos se registra que tan rapido esta girando
float counterForEncoder;
unsigned long time1=0;
unsigned long time2=0;
unsigned long deltaTime=0;

void setup() {
  //Interrupcion para encoder
  attachInterrupt(digitalPinToInterrupt(encoderPin),ReadEncoder, CHANGE);//comienza interrupcion, para que el ESP32 deje sus tareas en proceso para que se enfoque en esta instruccion
  //cuando hay un cambio en haz de luz se dispara la interrupcion
}

void loop() {
  time1=millis();//tiempo desde que el microcontrolador ha sido conectado
  delay(5);//en este tiempo se miden otras cosas en el ESP
  time2=millis();//toma el tiempo que tomaron las demas tareas
  deltaTime= time2-time1;//diferencial de tiempo (lo menor posible)
  counterForEncoder += deltaTime;

  if(counterForEncoder >= timeToCalculateSpeed){//pasado el tiempo para calcular la velocidad
    counterForEncoder=0;//reinicia a 0 el contador
    ReadRotationalSpeed();//calcula velocidad
  }

}
//complejidad del proceso debido a la secuencialidad del programa, basandose en diferenciales de tiempo