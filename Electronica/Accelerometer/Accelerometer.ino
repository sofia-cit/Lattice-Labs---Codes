//librerias
#include <Wire.h>

//Pines I2C
int sdaPin=6;
int sc1Pin=7;

//tiempos
int timeToFilter=10;
float counterForFilter;
unsigned long time1=0;
unsigned long time2=0;
unsigned long deltaTime=0;

//filtro Butterworth
float b0 = 0.0675;
float b1 = 0.1349;
float b2 = 0.0675;
float a1 = -1.1430;
float a2 = 0.4128;
float inputXn1 = 0,inputXn2=0;
float outputXn1=0,outputXn2=0;
float inputYn1=0, intputYn2=0;
float outputYn1=0, outputYn2=0;

void setup() {
  Serial.begin(115200);
  //I2C
  Wire.begin(sdaPin, sc1Pin);
  //Acelerometro
  InitializeAccelerometer();
  ConfigureAccelerometer();
}

void loop() {
  time1=millis();
  ReadAccelerometer();
  delay(2);
  time2=millis();
  deltaTime = time2-time1;
  counterForFilter += deltaTime;

  if(counterForFilter >= timeToFilter)
  {
   counterForFilter=0;
   ButterworthFilter();
   Serial.print(xFiltered);
   Serial.print("");
   Serial.println(yFiltered); 
  }
}
