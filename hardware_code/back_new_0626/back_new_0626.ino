#include <SoftwareSerial.h>
SoftwareSerial mySerial(1, 0); //RX,TX
int timer=0;
bool first=1;
void setup()
{
  Serial.begin(9600);
  //右後輪 逆cw 順ccw
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  //右前輪
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //左前輪 逆cw 順ccw
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  //左後輪
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);

  Serial.begin(9600);
}

void stepBack()
{
  int t = 2;
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(t);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 1);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
}

void stepForward()
{
  int t = 2;
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 1);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delay(t);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(t);
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(t);
}

void loop() {
  if(first==1)
  {
    delay(7534);
    first=0;
  }
  else
  {
    delay(5888);
  }
//  timer=millis();
  for (int i = 1; i <= 100; i++) {
    stepForward();
  }
//  timer=millis()-timer;
//  Serial.println(timer);
}