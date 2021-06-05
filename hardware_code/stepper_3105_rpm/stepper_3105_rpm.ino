#include <Stepper.h>                        //含入程式庫 Stepper.h
#define STEPS 2048                          //設定步進馬達轉一圈為 2048步，此數值不可改變
Stepper stepper(STEPS, 11, 9, 10, 8);       //因為步進馬達28BYJ-48 和程式庫 Stepper.h 的要求，這𥚃 9 和 10 不可互調

void setup() {
 stepper.setSpeed(5);                      //設定轉速為1分鐘12圈，容許設定的範圍為每分鐘 0-15 圈
}

void loop() {

//for (int i=0; i<8; i++){                    //正轉 256*8 = 2048 步共一圈
//stepper.step(256);
//                                            //步進馬達不需要 delay time
//}
//for (int i=0; i<8; i++){                    //反轉256*8 = 2048 步共一圈
//stepper.step(-256);
//}

  while(1){
    stepper.step(-1);
  }
 }
