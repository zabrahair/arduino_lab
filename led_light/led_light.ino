int LED_RED=8;
int LED_GREEN=7;
int LED_YELLOW=6;

void setup()
{
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
}

void loop()
{
  digitalWrite(LED_RED,HIGH);
  digitalWrite(LED_GREEN,LOW);
  digitalWrite(LED_YELLOW, LOW);
  delay(1000);
  digitalWrite(LED_RED,LOW);
  digitalWrite(LED_GREEN,HIGH);
  digitalWrite(LED_YELLOW, LOW);
  delay(1000);
   digitalWrite(LED_RED,LOW);
  digitalWrite(LED_GREEN,LOW);
  digitalWrite(LED_YELLOW, HIGH);
  delay(1000);
}

