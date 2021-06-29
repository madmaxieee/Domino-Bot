#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13);
void setup()  
{
  mySerial.begin(9600);
} 
void loop()  
{ 
  mySerial.write("rrrrr");
  delay (100);
}
