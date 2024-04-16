#define GREEN_LED 7
#define RED_LED 2
#define BUZZER 0

#define FULL_TANK_LEVEL 396
#define GREEN_LED_THRESHOLD 350
#define RED_LED_THRESHOLD 150
#define BUZZER_INTERVAL 10000

unsigned long previousTime = 0;

void setup()
{
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  noTone(BUZZER);
  unsigned long currentTime = millis();
  float distance = simulateDrain();
  handleLEDs(distance, currentTime);
  delay(50);
}

float simulateDrain()
{
  static float drainLevel = FULL_TANK_LEVEL;
  drainLevel -= 5;
  if (drainLevel < 0)
  {
    drainLevel = FULL_TANK_LEVEL;
  }
  return drainLevel;
}

void handleLEDs(float distance, unsigned long currentTime)
{
  if (distance >= GREEN_LED_THRESHOLD)
  {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }
  else if (distance >= RED_LED_THRESHOLD)
  {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
  else
  {
    digitalWrite(GREEN_LED, LOW);
    triggerBuzzer(currentTime);
  }
}

void triggerBuzzer(unsigned long currentTime)
{
  if (currentTime - previousTime >= BUZZER_INTERVAL)
  {
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER, 220, 250);
    delay(300);
    digitalWrite(RED_LED, LOW);
    previousTime = currentTime;
  }
}
