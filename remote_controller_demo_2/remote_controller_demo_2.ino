/*
红外遥控实验
*/
#include <IRremote.h>

int RECV_PIN = 8; //红外线接收器OUTPUT端接在pin 11
int LED = 11; // 定义LED引脚为11
int BUZZER = 10; //蜂鸣器
IRrecv irrecv(RECV_PIN); // 定义IRrecv 对象来接收红外线信号
decode_results results; //解码结果放在decode_results构造的对象results里


void irdisplay(unsigned long value) // 按下按键后，显示本遥控对应的按键
{
  Serial.print("Decode is: ");
  Serial.println(value, HEX);
  switch(value){ //判定按下的是哪个按键，串口显示按钮名称
    case 0xFF30CF:
      digitalWrite(LED, HIGH); //按下1键,打开LED灯
      break;
    case 0xFF6897:
      digitalWrite(LED, LOW); //按下0键,关闭LED灯
      break;
    case 0xFF18E7:
      digitalWrite(BUZZER, HIGH); //按下2键,打开蜂鸣器
      break;
    case 0xFF7A85:
      digitalWrite(BUZZER, LOW); //按下3键,关闭蜂鸣器
      break;
  }
}

void setup()
{
pinMode(LED,OUTPUT); // 定义LED为输出引脚
pinMode(BUZZER,OUTPUT); // 定义蜂鸣器输出引脚
Serial.begin(9600); //开启串口通信，并设定波特率为9600
irrecv.enableIRIn(); //启动红外解码
}

void loop() {
if (irrecv.decode(&results)) 
{
  //解码成功，收到一组红外线信号 
  irdisplay(results.value); 
  irrecv.resume(); 
} 
}
