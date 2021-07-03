#include <CheapStepper.h>
#include"front_process.h"
CheapStepper down (4, 5, 6, 7);
boolean moveClockwise = false;
//int deg[30];
int deg[3]={0,4,8};
//int dis[30];
int dis[3]={193,242,204};
//char way[30];
char way[3]={'+','+','-'};
int in = 0;
bool flag = 0;
int total = 3;
bool end_flag = 0;
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
//  for (int k = 0; !flag; k++)
//  {
//    for (int i = 0; i < 9; i++)
//    {
//      while (!BT.available())
//      {
//      }
//      cmd[i] = BT.read();
//      //      Serial.print(int(cmd[i]));
//      if (cmd[i] == 'E')
//      {
//        flag = 1;
//        total = k;
//        break;
//      }
//    }
//    deg[k] = (cmd[1] - '0') * 100 + (cmd[2] - '0') * 10 + (cmd[3] - '0');
//    dis[k] = (cmd[5] - '0') * 100 + (cmd[6] - '0') * 10 + (cmd[7] - '0');
//    way[k] = cmd[0];
//  }
      
//  delay(3000);
}
void loop() {
  if (!end_flag)
  {
    for (int i = 0; i < total; i++)
    {
      if (way[i] == '-')
      {
        in = 180;
        down.moveDegrees(1, 180);
      }
      else
      {
        in = 0;
      }
      mpu.update();
      now = mpu.getAngleZ();
      //左正右負
      if (way[i] == '+')
      {
        target = now + deg[i];
      }
      else if (way[i] == '-')
      {
        target = now - deg[i];
      }
      mySerial.write('T');
      mySerial.write(way[i]);
      if (way[i] == '+')
      {
        while (1)
        {
          if (millis() - timer >= 3)
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
            timer = millis();
          }
        }
      }
      else if (way[i] == '-')
      {
        while (1)
        {
          if (millis() - timer >= 3)
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
            timer = millis();
          }
        }
      }
      int block = dis[i] / 100;
      for (int j = 0; j < block; j++)
      {
        moveClockwise = true;
        down.moveDegrees(moveClockwise, 430 - in);
        moveClockwise = false;
        delay(120);
        down.moveDegrees(moveClockwise, 430);
        if (j != block - 1)
        {
          mySerial.write('G');
        }
      }
    }
  }
}
