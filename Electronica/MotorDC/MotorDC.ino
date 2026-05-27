//pines motor DC
int motorIN1Pin=3;//pin 3  capacidad de generar pwm
int motorIN2Pin=4;// pin 4 capacidad de generar pwm

//pines de control
int wheel;
int acceleration = 120;//0-255 depende de su resolucion
String chain = "1"; //1- adelante 0-atras // desde el volante


void setup() {
  // put your setup code here, to run once:

}

void loop() {
 ControlDCMotor();
}

void ControlDCMotor(){
  if(chain == "0") //atras
  {
    analogWrite(motorIN1Pin,acceleration);//pin 1 acelera
    analogWrite(motorIN2Pin,0);//se queda quieto
  }
  else if (chain == "1") //Adelante
  {
    analogWrite(motorIN1Pin,0);//se queda quieto
    analogWrite(motorIN2Pin,acceleration);//pin 2 acelera
  }
}
