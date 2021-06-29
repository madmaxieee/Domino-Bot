#include <SoftwareSerial.h>
#include "Wire.h"
#include <MPU6050_light.h>
MPU6050 mpu(Wire);
SoftwareSerial BT(8, 9);
SoftwareSerial mySerial(12, 13);
int target;
int now;
int angle;
char cmd[9]; //存放bt得到的command
unsigned long timer=0;
void get_cmd() {
  mpu.update();
  now = mpu.getAngleZ();
  //左正右負
  if (cmd[0] == '+')
  {
    target = now + angle;
  }
  else if (cmd[0] == '-')
  {
    target = now - angle;
  }
  Serial.println(target);
}
void check_angle() {
  if (cmd[0] == '+')
  {
    while (1)
    {
      if (millis()-timer >= 3)
      {
        mpu.update();
        int k = mpu.getAngleZ();
        Serial.println(k);
        if (k >= target)
        {
          mySerial.write('S');
          Serial.println("stop");
          break;
        }
        timer=millis();
      }
    }
  }
  else if (cmd[0] == '-')
  {
    while (1)
    {
      if (millis()-timer >= 3)
      {
        mpu.update();
        int k = mpu.getAngleZ();
        Serial.println(k);
        if (k <= target)
        {
          mySerial.write('S');
          Serial.println("stop");
          break;
        }
        timer=millis();
      }
    }
  }
}
