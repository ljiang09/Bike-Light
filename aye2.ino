
/*Green LED light brightens based on potentiometer*/

int LED_PIN = 9; // green
int POTENTIOMETER_PIN = A0; // POTENTIOMETER

/*
int LED2 = 10; // red
int LED3 = 11; // yellow
*/

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}
void loop()
{
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int brightness = potentiometerValue / 4;
  analogWrite(LED_PIN, brightness);
}
