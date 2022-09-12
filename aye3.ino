/*blinking based on potentiometer*/
void setup() {
  // put your setup code here, to run once:
  
  // designate pin 13 as an OUTPUT pin for the LED
  pinMode (10, OUTPUT);

  // designate pin A0 as an Analog INPUT for the potentiometer
  pinMode (A0, INPUT);

  Serial.begin(9600);
  
}

void loop() {
 
  Serial.println  (A0);

  int potValue = analogRead (A0);

  digitalWrite (10, HIGH);

  delay (potValue);

  digitalWrite (10, LOW);

  delay (potValue);
}
