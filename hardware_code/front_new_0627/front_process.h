#include <SoftwareSerial.h>
#include "Wire.h"
#include <MPU6050_light.h>
MPU6050 mpu(Wire);
SoftwareSerial BT(8, 9);
SoftwareSerial mySerial(12, 13);
int target;
int now;
int angle;
char cmd[3]; //存放bt得到的command
void get_cmd() {
  //look for commands
  for (int i = 0; i < 3; i++)
  {
    if (BT.available()) //如果有指令傳過來
    {
      cmd[i] = BT.read();
    }
  }
  mySerial.write(cmd[0]);
  angle = (cmd[1] - '0') * 10 + (cmd[2] - '0');
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
}
void check_angle() {
  if (cmd[0] == '+')
  {
    while (1)
    {
      mpu.update();
      if (mpu.getAngleZ() >= target)
      {
        mySerial.write('S');
        Serial.println("stop");
        break;
      }
    }
  }
}
