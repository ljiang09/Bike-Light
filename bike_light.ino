const int buttonPin = 8;
const int redPin = 9;
const int greenPin = 10;
const int yellowPin = 11;
const int POTENTIOMETER_PIN = A0; // POTENTIOMETER
int counter = 0;
bool press = false;
long currentTime = 0;

int longDelay = 500;
int shortDelay = 200;

enum states{
  STATE0,
  STATE1,
  STATE2,
  STATE3,
  STATE4,
  STATE5
};
states state;

unsigned long debounceDuration = 100; //unit: millisecond
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
    // increment the counter to change the state
    unsigned long currentTime = millis();
    
    if(currentTime > lastTime + debounceDuration){
        byte currentState = digitalRead(buttonPin);
        if(currentState != previousState){
            previousState = currentState;
            lastTime = millis();
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

    // The frist state should be blank to indicate the cycle is reset
    case STATE0:
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);
        startState5 = true;
        break;

    // Blink red, faster blink based on potentiometer
    case STATE1:
//        int potValue = analogRead(POTENTIOMETER_PIN);
//        Serial.println(potValue);
        digitalWrite (redPin, HIGH);
//        delay (potValue);
//        digitalWrite (redPin, LOW);
//        delay (potValue);
        break;

    // Green light shows, brighter based on potentiometer
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
            timerOne = millis();      // reset timer one
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
        // -- .. .-.. ..-.
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
        if (millis() - timerOne < 600) {  // currentTime + longOn
            digitalWrite(yellowPin, HIGH);
            Serial.print("1 ");
            Serial.println(currentTime);
        } else if (millis() - timerOne < 800) {  // currentTime + shortDelay
            digitalWrite(yellowPin, LOW);
            currentTime += shortDelay;
            Serial.print("2 ");
            Serial.println(currentTime);
        }
        else if (millis() - timerOne < 1400) {  // currentTime + longOn
            digitalWrite(yellowPin, HIGH);
            currentTime += longOn;
            Serial.print("3 ");
            Serial.println(currentTime);
        } else if (millis() - timerOne < 2000) {  // currentTime + longDelay
            digitalWrite(yellowPin, LOW);
            currentTime += longDelay;
            Serial.print("4 ");
            Serial.println(currentTime);
        }

        // ..
        else if (millis() - timerOne < 2200) {  // currentTime + shortOn
            digitalWrite(yellowPin, HIGH);
            currentTime += shortOn;
        } else if (millis() - timerOne < 2400) {  // currentTime + shortDelay
            digitalWrite(yellowPin, LOW);
            currentTime += shortDelay;
        }
        else if (millis() - timerOne < 2600) {  // currentTime + shortOn
            digitalWrite(yellowPin, HIGH);
            currentTime += shortOn;
        } else if (millis() - timerOne < 3200) {  // currentTime + longDelay
            digitalWrite(yellowPin, LOW);
            currentTime += longDelay;
        }

        // .-.. ..-.
        else if (millis() - timerOne < 3400) {  // currentTime + shortOn
            digitalWrite(yellowPin, HIGH);
            currentTime += shortOn;
        } else if (millis() - timerOne < 3600) {  // currentTime + shortDelay
            digitalWrite(yellowPin, LOW);
            currentTime += shortDelay;
        }
        else if (millis() - timerOne < 4200) {  // currentTime + longOn
            digitalWrite(yellowPin, HIGH);
            currentTime += longOn;
        } else if (millis() - timerOne < 4400) {  // currentTime + shortDelay
            digitalWrite(yellowPin, LOW);
            currentTime += shortDelay;
        }
        else if (millis() - timerOne < 4600) {  // currentTime + shortOn
            digitalWrite(yellowPin, HIGH);
            currentTime += shortOn;
        } else if (millis() - timerOne < 4800) {  // currentTime + shortDelay
            digitalWrite(yellowPin, LOW);
            currentTime += shortDelay;
        }
        else if (millis() - timerOne < 5000) {  // currentTime + shortOn
            digitalWrite(yellowPin, HIGH);
            currentTime += shortOn;
        } else if (millis() - timerOne < 5600) {  // currentTime + longDelay
            digitalWrite(yellowPin, LOW);
            currentTime += longDelay;
        }

        // ..-.
        else if (millis() - timerOne < 5800) {  // currentTime + shortOn
            digitalWrite(yellowPin, HIGH);
            currentTime += shortOn;
        } else if (millis() - timerOne < 6000) {  // currentTime + shortDelay
            digitalWrite(yellowPin, LOW);
            currentTime += shortDelay;
        }
        else if (millis() - timerOne < 6200) {  // currentTime + shortOn
            digitalWrite(yellowPin, HIGH);
            currentTime += shortOn;
        } else if (millis() - timerOne < 6400) {  // currentTime + shortDelay
            digitalWrite(yellowPin, LOW);
            currentTime += shortDelay;
        }
        else if (millis() - timerOne < 7000) {  // currentTime + longOn
            digitalWrite(yellowPin, HIGH);
            currentTime += longOn;
        } else if (millis() - timerOne < 7200) {  // currentTime + shortDelay
            digitalWrite(yellowPin, LOW);
            currentTime += shortDelay;
        }
        else if (millis() - timerOne < 7400) {  // currentTime + shortOn
            digitalWrite(yellowPin, HIGH);
            currentTime += shortOn;
        } else if (millis() - timerOne < 8000) {  // currentTime + longDelay
            digitalWrite(yellowPin, LOW);
            currentTime += longDelay;
        }
        
        break;
    }
}

int flash(int onDuration, int delayDuration, int currentTime, bool needReset) {
    if (needReset) {
        timerOne = millis();
        Serial.println(timerOne);
    }
    if (millis() - timerOne < currentTime+onDuration) {
        digitalWrite(yellowPin, HIGH);
        currentTime += onDuration;
        Serial.println(currentTime);
    } else if (millis() - timerOne < currentTime+delayDuration) {
        digitalWrite(yellowPin, LOW);
        currentTime += delayDuration;
        Serial.println(currentTime);
    }
    Serial.println(currentTime);
    Serial.println();
    return currentTime;
}
