
#include "Wire.h"                    // Подключение библиотеки WireCdev
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
accx= (uint16_t) Wire.read() << 8;
accy= (uint16_t) Wire.read() << 8;
accz= (uint16_t) Wire.read() << 8;
Serial.println(accx);
Serial.println(accy);
Serial.println(accz);

}
