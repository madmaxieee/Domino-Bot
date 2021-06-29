#include <CheapStepper.h>
#include"front_process.h"
CheapStepper down (4, 5, 6, 7);
boolean moveClockwise = false;
int in=0;
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  BT.begin(9600);
  Wire.begin();
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { } // stop everything if could not connect to MPU6050
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
  down.setRpm(17);
}
void loop() {
  moveClockwise = true;
  down.moveDegrees(moveClockwise, 430-in);
  moveClockwise = false;
  delay(120);
  down.moveDegrees(moveClockwise, 430);
  get_cmd();
  if(cmd[0]=='-')
  {
    in=180;
    down.moveDegrees(1, 180);
  }
  else
  {
    in=0;
  }
//  while (!BT.available())
//  {
//  }
//  char cmdd = BT.read();
//  Serial.println(cmdd);
  check_angle();
}
