#include <SCoop.h>
#include <CheapStepper.h>
CheapStepper down (4, 5, 6, 7);
CheapStepper up(2, 3, 18, 19);
defineTask(up_task);
void up_task::setup() {
  up.setRpm(18);
}
void up_task::loop() {
  up.moveDegrees (0, 360);
  up.moveDegrees (1, 360);
}
defineTask(down_task);
void down_task::setup() {
  down.setRpm(18);
}
void down_task::loop() {
  down.moveDegrees (1, 360);
  down.moveDegrees (0, 360);
}
void setup() {
  mySCoop.start();
}
void loop() {
  yield();
}
