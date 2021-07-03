#include <SoftwareSerial.h>
#include <Stepper.h>
#define STEPS 2048
SoftwareSerial mySerial(13, 12); //RX,TX
Stepper stepperL1(STEPS, 11, 9, 10, 8);
Stepper stepperR1(STEPS, 7, 5, 6, 4);
Stepper stepperL2(STEPS, 17, 15, 14, 16);
Stepper stepperR2(STEPS, 19, 3, 18, 2);
int deg = 0;
char cmd[3] ;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  //右後輪 逆cw 順ccw
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  //右前輪
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //左前輪 逆cw 順ccw
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  //左後輪
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  stepperL1.setSpeed(10); //設定速度 0-15
  stepperR1.setSpeed(10);
  stepperL2.setSpeed(10);
  stepperR2.setSpeed(10);
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
      stepperL1.step(-1);
      stepperL2.step(1);
      stepperR1.step(1);
      stepperR2.step(-1);
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
      stepperL1.step(1);
      stepperL2.step(-1);
      stepperR1.step(-1);
      stepperR2.step(1);
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
    stepperL1.step(-1);
    stepperL2.step(1);
    stepperR1.step(-1);
    stepperR2.step(1);
    }
  }
  else if (k == 2)
  {
    for (int i = 1; i <= 250 -deg*7; i++) //left
    {
    stepperL1.step(-1);
    stepperL2.step(1);
    stepperR1.step(-1);
    stepperR2.step(1);
    }
  }
  else
  {
    for (int i = 1; i <= 600+deg*7; i++)//right
    {
    stepperL1.step(-1);
    stepperL2.step(1);
    stepperR1.step(-1);
    stepperR2.step(1);
    }
  }
}

void loop() {
  //  char cmd = '#';
  //  if (mySerial.available())
  //  {
  //    cmd = mySerial.read();
  //    Serial.println(cmd);
  //    if (cmd == '+')
  //    {
  //      rotateLeft();
  //      forward(2);
  //    }
  //    if (cmd == '-')
  //    {
  //      forward(3);
  //      rotateRight();
  //
  //    }
  //    if (cmd == '0')
  //    {
  //      forward(1);
  //    }
  //  }
  for (int i = 0; i < 4; i++)
  {
    while (!mySerial.available())
    {
    }
    cmd[i] = mySerial.read();
  }
  deg = (cmd[1]-'0') * 100 + (cmd[2]-'0')*10+(cmd[3]-'0');
  if (cmd[0] == '+')
  {
    rotateLeft();
    forward(2);
  }
  if (cmd[0] == '-')
  {
    forward(3);
    rotateRight();

  }
  if (cmd[0] == '0')
  {
    forward(1);
  }
//rotateLeft();

}
