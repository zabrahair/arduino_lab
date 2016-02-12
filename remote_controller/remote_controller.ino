#define BUZZER 10 
#define LED_RED 11
#define IR_IN 8

#define STOP_BUTTON 0xff00
#define VOLUME_UP 0xfe01
#define VOLUME_DOWN 0xf609
#define PREVIOUS_SECTION 0xfb04
#define NEXT_SECTION 0xf906;

int pulseWidth = 0;
int irCode = 0x00;

// Initializes timer functions
void initTimer(void)  
{
  TCCR1A = 0x00;  
  // Defines the source of timer.
  TCCR1B = 0x05;
  TCCR1C = 0x00;
  TCNT1 = 0x00;
  // Forbbiden interrupt of timer overflow
  TIMSK1 = 0x00;
}

// Execute Decode Result Function
void remoteDeal(void)
{
  switch(irCode)
  {
    case STOP_BUTTON:
      digitalWrite(LED_RED, LOW);
      digitalWrite(BUZZER, LOW);
      break;
    case VOLUME_UP:
      digitalWrite(LED_RED, HIGH);
      break;
    case VOLUME_DOWN:
      digitalWrite(BUZZER, HIGH);
      break;
    default:
      return;
  }
}

// Check Logical Value
char checkLogicValue(){
  // Low level waiting
  while(!(digitalRead(IR_IN)));
  // Unit of TCNT1 is near to 60us
  pulseWidth = TCNT1;
  TCNT1 = 0;
  // Low level 560us
  if(pulseWidth >=7 && pulseWidth <= 10)
  {
    while(digitalRead(IR_IN));
    pulseWidth = TCNT1;
    TCNT1 = 0;
    // High level 560us
    if(pulseWidth >= 7 && pulseWidth <= 10)
      return 0;
    // High level 1.7ms
    else if(pulseWidth >= 25 && pulseWidth <= 27)
      return 1;
  }
  return -1;
}

// Receive Address code and Command Code
void pulseDeal()
{
  int i;
  // Execute 8 Zero
  for(i = 0; i < 8; i++)
  {
    if(checkLogicValue() != 0)
      return;  
  }

  // Execute 6 One
  for (i = 0; i < 6; i++)
  {
    if(checkLogicValue() != 1)
      return;
  }

  // Exec 1 Zero
  if (checkLogicValue() != 0)
    return;

   // Exe 1 One
   if(checkLogicValue() != 1)
    return;

  //Decode Command from remote controller
  irCode = 0x00;
  for (i = 0; i < 16; i++)
  {
    if (checkLogicValue() == 1)
    {
      irCode |=(1 << i );
    }
  }
}

// Decode Function
void remoteDecode(void)
{
  TCNT1 = 0x00;
  while (digitalRead(IR_IN))
  {
    if(TCNT1 >= 1563)
    {
      irCode = 0xff00;
      return;
    }
  }

  //If High level last less than 100ms
  TCNT1 = 0x00;

  while (!(digitalRead(IR_IN)));
  pulseWidth = TCNT1;
  TCNT1 = 0;
  // 9ms
  if(pulseWidth >= 140 && pulseWidth <= 141)
  {
    while (digitalRead(IR_IN));
    pulseWidth = TCNT1;
    TCNT1 = 0;
    // 4.5ms
    if(pulseWidth >= 68 && pulseWidth <= 72)
    {
      pulseDeal();
      return;
    }
    // 2.25ms
    else if( pulseWidth > 34 && pulseWidth <= 36)
    {
      while (!(digitalRead(IR_IN)));
      pulseWidth = TCNT1;
      TCNT1 = 0;
      // 560us
      if (pulseWidth >=7 && pulseWidth <= 10)
      {
        return;
      }
    }
  }
}
void setup() {
  unsigned char i;
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(IR_IN, INPUT);

}

void loop() {
  initTimer();
  while(1)
  {
    remoteDecode();
    remoteDeal();
  }
}
