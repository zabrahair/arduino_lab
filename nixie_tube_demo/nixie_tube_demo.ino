int a=7;
int b=6;
int c=4;
int d=2;
int e=1;
int f=9;
int g=10;
int dp=5;

int nixieLED[8] = {a,b,c,d,e,f,g,dp};
int nixieEncodeComHigh[11][8]=
  {
   {LOW,LOW,LOW,LOW,LOW,LOW,HIGH,HIGH}
  ,{HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH,HIGH}
  ,{LOW,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH}
  ,{LOW,LOW,LOW,LOW,HIGH,HIGH,LOW,HIGH}
  ,{LOW,LOW,LOW,HIGH,HIGH,LOW,LOW,HIGH}
  ,{LOW,HIGH,LOW,LOW,HIGH,LOW,LOW,HIGH}
  ,{LOW,HIGH,LOW,LOW,LOW,LOW,LOW,HIGH}
  ,{LOW,LOW,LOW,HIGH,HIGH,HIGH,HIGH,HIGH}
  ,{LOW,LOW,LOW,LOW,LOW,LOW,LOW,HIGH}
  ,{LOW,LOW,LOW,LOW,HIGH,LOW,LOW,HIGH}
  ,{HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW}
  };

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);
}

void loop() {
  unsigned char i,j;
  int *nixieShowEncodeArray;
  int show_number=6; // show number should be 0-9
  for(j=0; j <= 9; j++)
  {
    //nixieShowEncodeArray = (int*)malloc(sizeof(nixieEncodeComHigh[j])*sizeof(int));
    nixieShowEncodeArray = nixieEncodeComHigh[j];
    for(i = 0; i < 8; i++)
    {
      digitalWrite(nixieLED[i], nixieShowEncodeArray[i]);
    }
    delay(500);
  }
  
}
