#include <CheapStepper.h>
CheapStepper down (4,5,6,7); 
CheapStepper up(2,3,18,19);
boolean moveClockwise = false;
int timer=0;
void setup() {
  down.setRpm(17); 
  up.setRpm(18);
  Serial.begin(9600);
}
void loop() {
    timer=millis();
    moveClockwise = true;   
//    up.moveDegrees (moveClockwise, 370);
//    delay(30);
    down.moveDegrees(moveClockwise,370); 
    moveClockwise = false;    
    delay(30);
    down.moveDegrees(moveClockwise,370);
//    up.moveDegrees (moveClockwise, 370);
    timer=millis()-timer;
    Serial.println(timer);
    //delay(30);
}
