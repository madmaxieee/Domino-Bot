#include <CheapStepper.h>
#include"front_process.h"
CheapStepper down (4,5,6,7); 
CheapStepper up(2,3,18,19);
boolean moveClockwise = false;
void setup() {
  down.setRpm(17); 
  up.setRpm(18);
  Serial.begin(9600);
   Wire.begin();
 byte status = mpu.begin();
   Serial.print(F("MPU6050 status: "));
   Serial.println(status);
   while (status != 0) { } // stop everything if could not connect to MPU6050
 Serial.println(F("Calculating offsets, do not move MPU6050"));
   delay(1000);
   mpu.calcOffsets(); // gyro and accelero
   Serial.println("Done!\n");
}
void loop() {
    moveClockwise = true;   
    down.moveDegrees(moveClockwise,370); 
    moveClockwise = false;    
    delay(30);
    down.moveDegrees(moveClockwise,370);
    get_cmd();
    check_angle();
}
