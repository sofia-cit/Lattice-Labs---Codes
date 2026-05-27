int pulses=0; //variable para contar los pulsos
int resolution=16;//resolucion del encoder numero de pulsos por revolucion
float wheelRadius = 0.035;//radio en metros
float rps; // variable para almacenar el calculo de la velocidad en rps
float tangentialSpeed;

void ReadEncoder(){
  pulses++;
}

void ReadRotationalSpeed(){
  rps=((float)pulses/resolution)/(timeToCalculateSpeed/1000.0);//cantidad de vueltas / tiempo en segundos
  tangentialSpeed=rps*2*PI*wheelRadius;//vueltas por segundo a velocidad tangencial
  pulses=0;//pulsos, terminando de hacer el calculo, se hace uno nuevo cada 100 ms
}