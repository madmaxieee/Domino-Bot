#include <CheapStepper.h>
CheapStepper down (4,5,6,7); 
CheapStepper up(2,3,18,19);
boolean moveClockwise = false;
void setup() {
  down.setRpm(18); 
  up.setRpm(18);
}
void loop() {
    moveClockwise = false;   
    up.moveDegrees (moveClockwise, 370);
    delay(30);
    down.moveDegrees(moveClockwise,370); 
    moveClockwise = true;
    up.moveDegrees (moveClockwise, 370);
    down.moveDegrees(moveClockwise,370);
    delay(30);
}
