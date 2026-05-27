#include <Wire.h>

//Pines de I2C
int sdaPin = 6; //MPU6050 //6-21
int sc1Pin = 7; //MPU6050 //7-22

//Variables
float voltage;
float current;
float busVoltage;
float shuntVoltage;
float shuntResistor=0.5;


void setup() {
  Wire.begin(sdaPin,sc1Pin);
  Serial.begin(150200);

}

void loop() {
  ReadEnergy();
  Serial.print(voltage);
  Serial.print("");
  Serial.print(current);
  Serial.print ("");
  Serial.print(busVoltage);
  Serial.print("");
  Serial.println(shuntVoltage);
}
