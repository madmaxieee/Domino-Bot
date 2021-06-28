#include <CheapStepper.h>
CheapStepper RF (4,5,6,7); 
CheapStepper RB(2,3,18,19);
CheapStepper LB(14,15,16,17);
CheapStepper LF(8,9,10,11);
boolean moveClockwise = false;
int timer=0;
void setup() {
  RF.setRpm(10); 
  RB.setRpm(10);
  LF.setRpm(10);
  LF.setRpm(10);
  Serial.begin(9600);
}
void loop() {  
    RF.moveDegrees (0, 20);
    RB.moveDegrees(1,20);    
    LF.moveDegrees(1,20);
    LB.moveDegrees (1, 20);

    //delay(30);
}
