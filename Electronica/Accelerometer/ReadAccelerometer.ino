int16_t ax;
int16_t ay;
float xAcceleration;
float yAcceleration;

void InitializeAccelerometer(){

  Wire.beginTransmission(0x69);
  Wire.write(0x7E);
  Wire.write(0x11);
  Wire.endTransmission();
  delay(100);
}

void ConfigureAccelerometer(){

  Wire.beginTransmission(0x69);
  Wire.write(0x40);
  Wire.write(0x0C);
  Wire.endTransmission();
}

void ReadAccelerometer()
{
  Wire.beginTransmission(0x69);
  Wire.write(0x12);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,4);

  if(Wire.available()==4){
    ax=(int16_t)(Wire.read()|(Wire.read()<<8));
    ay=(int16_t)(Wire.read()|(Wire.read()<<8));

    xAcceleration = ax/16384.0;
    yAcceleration = ay/16384.0;

  }
}


void ButterworthFilter()
{
  xFiltered = b0*xAcceleration + b1*inputXn1 + b2*inputXn2 - a1*outputXn1 - a2*outputXn2;
  yFiltered = b0*yAcceleration + b1*inputYn1 + b2*inputYn2 - a1*outputYn1 - a2*outputYn2;

  inputXn2 = inputXn1;
  inputYn2 = inputYn1;

  inputXn1 = xAcceleration;
  inputYn1 = YAcceleration;

  outputXn2 = outputXn1;
  outputYn2 = outputYn1;

  outputXn1 = xFiltered;
  outputYn2 = yFiltered;

}