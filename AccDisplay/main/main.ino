
#include "Wire.h"                    
const int MPU = 0x68;
float accx,accy,accz;


void setup()
{
Wire.begin();  
Serial.begin(9600);

}
void loop()
{
Wire.beginTransmission(MPU);
Wire.write(0x3B);
Wire.requestFrom(MPU, 6, true);
accx= Wire.read()<<8 | Wire.read();  
accy = Wire.read()<<8 | Wire.read();  
accz = Wire.read()<<8 | Wire.read();
Serial.println(accx);
Serial.println(accy);
Serial.println(accz);
}
