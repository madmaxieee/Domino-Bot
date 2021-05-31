#include <Servo.h>
Servo myservo;
void setup() { 
  myservo.attach(4); //伺服馬達的訊號線接Pin4
} 
void loop() {
  for(int i = 0; i <= 90; i=i+1){
    myservo.write(i);
    //delay(5);
  }
  delay(500);
  for(int i = 90; i >= 0; i=i-1){
    myservo.write(i);
    //delay(5);
  }
  delay(500);
}
