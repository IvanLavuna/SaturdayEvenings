
#include "Wire.h"                    
const int MPU = 0x68;
float accx,accy,accz;


void setup()
{
Wire.begin();  
Serial.begin(9600);
Wire.write(0x6B);                 
Wire.write(0x00);                  
Wire.endTransmission(true); 
}
void loop()
{
Wire.beginTransmission(MPU);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU, 6, true);
accx= (Wire.read()<<8 | Wire.read()) / 16384.0;  
accy = (Wire.read()<<8 | Wire.read()) / 16384.0;  
accz = (Wire.read()<<8 | Wire.read()) / 16384.0;
Serial.print("X= ");
Serial.println(accx);
Serial.print("Y= ");
Serial.println(accy);
Serial.print("Z= ");
Serial.println(accz);
}
