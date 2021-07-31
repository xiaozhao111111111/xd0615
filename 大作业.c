//输入
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
//功能
#define LT 7
#define BT 8
#define S1 9
#define S2 10

int pinInterrupt=2;
int tick = 0; //计数值
int state=0;

//中断服务程序
void myfunc()
{
  tick=-1;
  Serial.println(tick);
}
 
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(LT, OUTPUT);
  pinMode(BT, OUTPUT);
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);

  Serial.begin(9600); //初始化串口
  pinMode(13,OUTPUT);
  
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), myfunc, CHANGE);
}
 
byte income1=0;
byte income2=0;

void loop()
{
  
  Serial.println(tick++);
  if(tick==100) tick=0;
    
  income2=tick%10-'0';
  income1=tick/10-'0';
  
  digitalWrite(S1,LOW);
  digitalWrite(IN1,income1&0x1);
  digitalWrite(IN2,(income1>>1)&0x1);
  digitalWrite(IN3,(income1>>2)&0x1);
  digitalWrite(IN4,(income1>>3)&0x1);
  digitalWrite(S1,HIGH);
  
  digitalWrite(S2,LOW);
  digitalWrite(IN1,income2&0x1);
  digitalWrite(IN2,(income2>>1)&0x1);
  digitalWrite(IN3,(income2>>2)&0x1);
  digitalWrite(IN4,(income2>>3)&0x1);
  digitalWrite(S2,HIGH);
    
  state=~state;
  digitalWrite(13,state);
  delay(1000);
  
}
