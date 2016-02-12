int buzzer=8;
void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
  unsigned char i,j;
  while(1)
  {
//    digitalWrite(buzzer, HIGH);
    for(i = 0; i < 80; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(10);
    }

    for(i = 0; i < 100; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(2);
      digitalWrite(buzzer, LOW);
      delay(2);
    }
  }
}
