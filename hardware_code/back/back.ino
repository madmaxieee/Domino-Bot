// //2, 3, A4, A5      ->     右後輪
// //A0, A1, A2, A3    ->     左後輪 (A0 -> pin 14)
// //4, 5, 6, 7        ->     下推
// //8, 9, 10, 11      ->     上推
// //0, 1              ->     TX, RX
// //12, 13            ->     連接後板

#include <SoftwareSerial.h>
SoftwareSerial mySerial(1, 0); //RX,TX
void setup()
{
  //右前輪
//  delay(3000);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  //左前輪
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);

  Serial.begin(9600);
}

void stepBack()
{
  int t = 1;
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  delay(t);

  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  delay(t);

  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 1);
  delay(t);

  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  delay(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  delay(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 1);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  delay(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  delay(t);

  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  delay(t);
}

void stepForward()
{
  int t = 1;
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  delay(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  delay(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 1);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  delay(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  delay(t);

  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  delay(t);

  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 1);
  delay(t);

  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  delay(t);

  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  delay(t);

}

void pushUpout() {
int t = 3;
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  delay(t);

  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  delay(t);

  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  delay(t);

  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  delay(t);
}

void pushUpin() {
int t = 3;
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  delay(t);

  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  delay(t);

  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  delay(t);

  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  delay(t);
}
void pushDownin() {
int t = 3;
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);

  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(t);

  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delay(t);

  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(t);
}

void pushDownout() {
int t = 3;
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(t);

  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delay(t);

  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(t);

  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
}
void loop() {

  // test
  for (int i = 1; i <= 512; i++) {
    stepForward();
    //pushUpin();
    pushDownout();
    //   Serial.println(String(i));
  }
  for(int i=1;i<=512;i++)
  {
    stepForward();
    //pushUpout();
    pushDownin();
  }
  //Serial.println("One round");
  //delay(200);

//  for (int i = 1; i <= 512; i++) {
//    stepBack();
//    //  Serial.println(String(i));
//  }
  //Serial.println("One round");
  //delay(200);
  
  //測試UART
  // while (!Serial.available()) {}

  // Serial.write(mySerial.read());

  // while (my.Serial.available()>0)
  // {
  //   myserial.read();
  // }

}
