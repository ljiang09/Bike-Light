const int buttonPin = 8;
const int redPin = 10;
const int greenPin = 9;
const int yellowPin = 11;
int counter = 0;
bool press = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(buttonPin,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(buttonPin) == LOW) {
    if (!press) {
      press = true;
      counter ++;
      Serial.println(counter);
    }
  } else {
    press = false;

    // Blink red, faster blink based on potentiometer
    if (counter%5 == 0) {
      digitalWrite(redPin, HIGH);
    } else {
      digitalWrite(redPin, LOW);
    }

    // Green light shows, brighter based on potentiometer
    if (counter%5 == 1) {
      digitalWrite(yellowPin, HIGH);
    } else {
      digitalWrite(yellowPin, LOW);
    }

    // All of them turn on
    if (counter%5 == 2) {
      digitalWrite(greenPin, HIGH);
    } else {
      digitalWrite(greenPin, LOW);
    }

    // alternate blinking between red, blue, and yellow
    if (counter%5 == 3) {
      digitalWrite(yellowPin, HIGH);
    } else {
      digitalWrite(yellowPin, LOW);
    }

    // morse code
    if (counter%5 == 4) {
      digitalWrite(greenPin, HIGH);
    } else {
      digitalWrite(greenPin, LOW);
    }
  }

}
