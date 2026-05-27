void ReadEnergy()
{
  Wire.beginTransmission(0x40);//Direccion del INA219
  Wire.write(0x01);//Registro del shunt
  Wire.endTransmission(false);
  Wire.requestFrom(0x40,2);

  int16_t shuntRaw = (int16_t)((Wire.read()<<8)|Wire.read());

  Wire.beginTransmission(0x40);
  Wire.write(0x02);
  Wire.endTransmission(false);
  Wire.requestFrom(0x40,2);

  int16_t busRaw=(int16_t)((Wire.read()<<8)|Wire.read());
  busRaw >>= 3;

  shuntVoltage = shuntRaw*0.01;
  busVoltage=busRaw*0.004;
  voltage = busVoltage + (shuntVoltage/1000);
  current = (shuntVoltage/1000)/shuntResistor;//obtener la corriente

}