//解讀指令

//1.接收指令 
//2.將方向和角度分開存取 
//3.執行 
//4.確認完成此動作后繼續接受下一個指令

void loop(){

    //look for commands
    char cmd; //存放gcode
    if (Serial.available()) //如果有指令傳過來
    {
        cmd = Serial.read();
        //Serial.print(cmd); debug用
        process_cmd(cmd); //  丟進去process_cmd處理
    }

}

void process_cmd(char c){
    
    //得到pass下來的指令
    //先不計入停下的指令，因爲如果沒有指令傳過來就表示工作停止
    

    
    char dir; //儲存方向
    switch(dir)
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

int checkAngle(){

    //計算角度程式碼, 如果達到要求的話就return false
    
    //return false;
}