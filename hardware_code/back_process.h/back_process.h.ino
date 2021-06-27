//解讀指令

//1.接收指令
//2.將方向和角度分開存取
//3.執行
//4.確認完成此動作后繼續接受下一個指令
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12,13);
void get_cmd() {
  //look for commands
  char cmd[3]; //存放gcode
  for (int i = 0; i < 3; i++)
  {
    if (mySerial.available()) //如果有指令傳過來
    {
      cmd[i] = Serial.read();
    }
    process_cmd(cmd); //  丟進去process_cmd處理
  }
}
void get_angle(){
  
}
void process_cmd(char cmd[]) {

  //得到pass下來的指令
  //先不計入停下的指令，因爲如果沒有指令傳過來就表示工作停止
  char dir=cmd[0]; //儲存方向
  int angle=(cmd[1]-'0')*10+(cmd[2]-'0');
  switch (dir)
  {
    case 'L':
      //驅動馬達＋檢查角度
      //轉左程式碼
      if (!checkAngle())
        break;
    case 'R':
      if (!checkAngle())
        break;

  }

}

int checkAngle() {

  //計算角度程式碼, 如果達到要求的話就return false

  //return false;
}
