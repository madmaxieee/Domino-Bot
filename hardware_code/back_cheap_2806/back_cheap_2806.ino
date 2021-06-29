#include <SoftwareSerial.h>
#include <CheapStepper.h>
SoftwareSerial mySerial(13, 12); //RX,TX
CheapStepper stepperL1(8, 9, 10, 11);
CheapStepper stepperR1(4, 5, 6, 7);
CheapStepper stepperL2(14, 15, 16, 17);
CheapStepper stepperR2(2, 3, 18, 19);
int timer = 0;
bool first = 1;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  stepperL1.setRpm(10); //設定速度 0-15
  stepperR1.setRpm(10);
  stepperL2.setRpm(10);
  stepperR2.setRpm(10);
}
bool checkYaw() { //檢查前板是否回傳's'給後板 (to break Rotate Function)
  char cmd2;
  while (true)
  {
    cmd2 = mySerial.read();
    if (cmd2 == 'S')
    {
      return false;
      break;
    }
    else
      return true;
  }
}
void rotateRight()
{
  while (1) //轉彎
  {
    for (int i = 0; i <= 50; i++)
    {
      stepperL1.moveCW(1);
      stepperL2.moveCW(1);
      stepperR1.moveCCW(1);
      stepperR2.moveCW(1);
    }
    if (checkYaw() == false) //判斷如果前板說角度足夠就會break出去準備前進
    {
      break;
    }
  }
}
void rotateLeft()
{
  while (1) //轉彎
  {
    for (int i = 0; i <= 50; i++)
    {
      stepperL1.moveCCW(1);
      stepperL2.moveCCW(1);
      stepperR1.moveCW(1);
      stepperR2.moveCCW(1);
    }
    if (checkYaw() == false) //判斷如果前板說角度足夠就會break出去準備前進
    {
      break;
    }
  }
}

void forward(int k) //rotate後 繼續前進直到最終目的地
{
  //一步大概是5.625度 一圈是step2048的話 就直接 換算得到一百步是3200
  if (k == 1)
  {
    for (int i = 1; i <= 500; i++)
    {
      stepperL1.moveCW(1);
      stepperL2.moveCW(1);
      stepperR1.moveCW(1);
      stepperR2.moveCCW(1);
    }
  }
  else if (k == 2)
  {
    for (int i = 1; i <= 170; i++)
    {
      stepperL1.moveCW(1);
      stepperL2.moveCW(1);
      stepperR1.moveCW(1);
      stepperR2.moveCCW(1);
    }
  }
  else
  {
    for (int i = 1; i <= 600; i++)
    {
      stepperL1.moveCW(1);
      stepperL2.moveCW(1);
      stepperR1.moveCW(1);
      stepperR2.moveCCW(1);
    }
  }

}

void loop() {
  char cmd = '#';
  if (mySerial.available())
  {
    cmd = mySerial.read();
    Serial.println(cmd);
    if (cmd == '+')
    {
      rotateLeft();
      forward(2);
    }
    if (cmd == '-')
    {
      forward(3);
      rotateRight();

    }
    if (cmd == '0')
    {
      forward(1);
    }
  }

}
