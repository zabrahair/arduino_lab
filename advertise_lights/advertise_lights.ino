void style_1(void)
{
  unsigned char j;
  for( j=1; j<=6; j++)
  {
    digitalWrite(j, HIGH);
    delay(200);
  }

  for(j=6; j>=1; j--)
  {
    digitalWrite(j, LOW);
    delay(200);
  }
}

void style_1_2(void)
{
  unsigned char j;
  for( j=1; j<=6; j++)
  {
    digitalWrite(j, HIGH);
    delay(200);
    digitalWrite(j, LOW);
    delay(200);
  }

  for(j=6; j>=1; j--)
  {
    digitalWrite(j, HIGH);
    delay(200);
    digitalWrite(j, LOW);
    delay(200);
  }
}

void style_1_3(void)
{
  unsigned char j;
  for( j=1; j<=6; j++)
  {
    digitalWrite(j, HIGH);
    digitalWrite(j+1, HIGH);
    delay(200);
    digitalWrite(j, LOW);
    digitalWrite(j+1, LOW);
    delay(200);
  }

  for(j=6; j>=1; j--)
  {
    digitalWrite(j, HIGH);
    digitalWrite(j-1, HIGH);
    delay(200);
    digitalWrite(j, LOW);
    digitalWrite(j-1, LOW);
    delay(200);
  }
}

void style_2(void)
{
  unsigned char j,k;
  k=1;
  for(j=3; j>=1; j--)
  {
    digitalWrite(j,HIGH);
    digitalWrite(j+k, HIGH);
    delay(400);
    k+=2;    
  }

  k=5;
  for(j=1; j<=3; j++)
  {
    digitalWrite(j,LOW);
    digitalWrite(j+k, LOW);
    delay(400);
    k-=2;
  }
}

void style_3(void)
{
  unsigned char j,k;
  k=5;
  for(j=1; j<=3; j++)
  {
    digitalWrite(j,HIGH);
    digitalWrite(j+k, HIGH);
    delay(400);
    digitalWrite(j,LOW);
    digitalWrite(j+k, LOW);
    delay(400);    
    k-=2;
  }

  k=3;
  for(j=2; j>=1; j--)
  {
    digitalWrite(j,HIGH);
    digitalWrite(j+k, HIGH);
    delay(400);
    digitalWrite(j,LOW);
    digitalWrite(j+k, LOW);
    delay(400);    
    k+=2;
  }
}
void flash(void)
{
  unsigned char j,k;
  for(k=0; k<=1; k++)
  {
    for( j=1; j<=6; j++)
    {
      digitalWrite(j, HIGH);    
    }
    delay(200);
  
    for(j=6; j>=1; j--)
    {
      digitalWrite(j, LOW);
    } 
    delay(200);  
  }
}

void setup()
{
  unsigned char i;
  for(i=1; i<=6; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  style_1_3();
  flash();
  style_1();
  flash();
  style_1_2();
  flash();
  style_2();
  flash();
  


}

