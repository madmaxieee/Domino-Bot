#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 12);
char ip;
void setup()  
{
  mySerial.begin(9600);
  Serial.begin(9600);
} 
void loop()  
{ 
  if (mySerial.available())
  {
    ip=mySerial.read();
    Serial.println(ip);
  }
}
