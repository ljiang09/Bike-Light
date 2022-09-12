// declare pins
const int buttonPin = 8;
const int redPin = 9;
const int greenPin = 10;
const int yellowPin = 11;
const int POTENTIOMETER_PIN = A0; // POTENTIOMETER

// light mode control variables
int counter = 0;
enum states {
    STATE0,
    STATE1,
    STATE2,
    STATE3,
    STATE4,
    STATE5
};
states state;

// variables for bounce
long currentTime = 0;
unsigned long debounceDuration = 100; // unit: millisecond
unsigned long lastTime = 0;
unsigned long timerOne = 0;

byte previousState = LOW;
byte lightState = HIGH;
bool startState5 = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(buttonPin,INPUT);

  // designate pin 13 as an OUTPUT pin for the LED
  pinMode (10, OUTPUT);

  // designate pin A0 as an Analog INPUT for the potentiometer
  pinMode (A0, INPUT);


  state = STATE0;

  Serial.begin(9600);
}

void loop() {
    currentTime = millis();
    
    if(currentTime > lastTime + debounceDuration){
        byte currentState = digitalRead(buttonPin);
        if(currentState != previousState){
            previousState = currentState;
            lastTime = millis();

            // change state based on button click
            if (currentState == LOW){
                counter++;
                if(counter % 6 == 0){state = STATE0;}
                if(counter % 6 == 1){state = STATE1;}
                if(counter % 6 == 2){state = STATE2;}
                if(counter % 6 == 3){state = STATE3;}
                if(counter % 6 == 4){state = STATE4;}
                if(counter % 6 == 5){state = STATE5;}
            }
        }
    }


    switch(state) {

    // The first state should be blank to indicate the cycle is reset.
    case STATE0:
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);
        startState5 = true;
        break;

    // Blink red, faster blink based on potentiometer [DOESN"T WORK!!!!]
    case STATE1:
//        int potValue = analogRead(POTENTIOMETER_PIN);
//        Serial.println(potValue);
        digitalWrite (redPin, HIGH);
//        delay (potValue);
//        digitalWrite (redPin, LOW);
//        delay (potValue);
        break;

    // Green light shows, brighter based on potentiometer [DOESN"T WORK!!!!]
    case STATE2:
        Serial.println("state 2");
//        int potentiometerValue = analogRead(POTENTIOMETER_PIN);
//        int brightness = potentiometerValue / 4;
//        analogWrite(greenPin, brightness);
        break;

    // all LEDs turn on
    case STATE3:
        Serial.println("state 3");
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin, HIGH);
        digitalWrite(yellowPin, HIGH);
        break;

    // alternate blinking between lights
    case STATE4:
        if (millis() - timerOne > 600) {
            digitalWrite(yellowPin, LOW);
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            timerOne = millis();      // reset timerOne
        }
        else if (millis() - timerOne > 450) {
            digitalWrite(yellowPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(redPin, HIGH);
        }
        else if (millis() - timerOne > 300) {
            digitalWrite(yellowPin, LOW);
            digitalWrite(greenPin, HIGH);
            digitalWrite(redPin, LOW);
        }
        else if (millis() - timerOne > 150) {
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(yellowPin, HIGH);
        }
        break;

    // green light reveals a secret code (this is what gatsby was trying to decipher)
    case STATE5:
        // -- .. .-.. -.-
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(yellowPin, LOW);

        const int shortOn = 200;
        const int longOn = 600;
        const int shortDelay = 200;
        const int longDelay = 400;

        if (startState5 > 0) {
            timerOne = millis();    // start a timerOne
            startState5 = false;
            Serial.println(timerOne);
        }

        // --
        if (millis() - timerOne < 600) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 800) {
            digitalWrite(yellowPin, LOW);
        }
        else if (millis() - timerOne < 1400) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 2000) {
            digitalWrite(yellowPin, LOW);
        }

        // ..
        else if (millis() - timerOne < 2200) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 2400) {
            digitalWrite(yellowPin, LOW);
        }
        else if (millis() - timerOne < 2600) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 3200) {
            digitalWrite(yellowPin, LOW);
        }

        // .-.. ..-.
        else if (millis() - timerOne < 3400) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 3600) {
            digitalWrite(yellowPin, LOW);
        }
        else if (millis() - timerOne < 4200) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 4400) {
            digitalWrite(yellowPin, LOW);
        }
        else if (millis() - timerOne < 4600) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 4800) {
            digitalWrite(yellowPin, LOW);
        }
        else if (millis() - timerOne < 5000) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 5600) {
            digitalWrite(yellowPin, LOW);
        }

        // -.-
        else if (millis() - timerOne < 6200) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 6400) {
            digitalWrite(yellowPin, LOW);
        }
        else if (millis() - timerOne < 6600) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 6800) {
            digitalWrite(yellowPin, LOW);
        }
        else if (millis() - timerOne < 7400) {
            digitalWrite(yellowPin, HIGH);
        } else if (millis() - timerOne < 9000) {
            digitalWrite(yellowPin, LOW);
        } else {
          startState5 = true;
        }
        
        break;
    }
}
