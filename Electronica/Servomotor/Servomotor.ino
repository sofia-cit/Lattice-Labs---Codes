//Servomotor 

int servoPin = 10; //pin designado en PCB
int pwmChannel = 1;//canal
int freq = 50;//frecuencia, 50 porque requiere un pulso de 50 Hz
int pulseMin = 205;//ciclo de trabajo a posicion de 0, 1ms
int pulseMax = 410;//a posicion de 180,2ms


void setup() {
  ledcSetup(pwmChannel, freq, servoResolution);//configuracion del canal para el pwm con frecuencia y resolucion
  ledcAttachPin(servoPin,pwmChannel);//indica que el pin 10 es la salida del canal
  MoveServomotor(90)//funcion para convertir de grados a pulso
  //funciones derivadas a no poder utilizar la libreria del servomotor
}

void loop() {
  // put your main code here, to run repeatedly:

}

void MoveServomotor(int angle){//recibe el angulo

  angle=constrain(angle,0,180);//limita el valor a 0 y 180
  int duty = map(angle,0,180,pulseMin,pulseMax);//mapeo, si se recibe 0 se genera 205, se recibe 180 y se genera 410
  ledcWrite(pwmChannel,duty);
}