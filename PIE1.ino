int RED = 10;
int GREEN = 9;
int YELLOW = 11;
int BTN = 8;
int count = 0;

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



void setup() {
  // put your setup code here, to run once:
  
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BTN, INPUT);
  state = STATE0;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
      if(currentTime > lastTime + debounceDuration){
        byte currentState = digitalRead(BTN);
        if(currentState != previousState){
          previousState = currentState;
          lastTime = millis();
          if (currentState == LOW){
            count++;
            if(count % 6 == 0){state = STATE0;}
            if(count % 6 == 1){state = STATE1;}
            if(count % 6 == 2){state = STATE2;}
            if(count % 6 == 3){state = STATE3;}
            if(count % 6 == 4){state = STATE4;}
            if(count % 6 == 5){state = STATE5;}
          }
        }
      }
  switch(state){
    case STATE0:
      break;

    case STATE1:
          // Blink red, faster blink based on potentiometer
            digitalWrite(RED, lightState);
            digitalWrite(YELLOW, lightState);
            digitalWrite(GREEN, lightState);
    break;
    
    case STATE2:
          // Green light shows, brighter based on potentiometer
            digitalWrite(RED, !lightState);
            digitalWrite(YELLOW, lightState);
            digitalWrite(GREEN, lightState);
    break;

    case STATE3:
          // ALL LEDS TURN ON
            digitalWrite(RED, HIGH);
            digitalWrite(YELLOW, HIGH);
            digitalWrite(GREEN, HIGH);
    break;

    case STATE4:
          //  ALTERNATE BLINK
        if (millis() - timerOne > 600){
          digitalWrite(YELLOW, LOW);
          digitalWrite(RED, LOW);
          digitalWrite(GREEN, LOW);
          timerOne = millis(); //reset timer one
        }
        else if (millis() - timerOne > 450){
          digitalWrite(YELLOW, LOW);
          digitalWrite(BLUE, LOW);
          digitalWrite(RED, HIGH);
              
        }
        else if (millis() - timerOne > 300) {
          digitalWrite(YELLOW, LOW);
          digitalWrite(GREEN, HIGH);
          digitalWrite(RED, LOW);
        }
        else if (millis() - timerOne > 150) {
          digitalWrite(RED, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(YELLOW, HIGH);
        }

    break;

    case STATE5:
          //  Red light blinks morse code for “piss”
            digitalWrite(RED, !lightState);
            digitalWrite(YELLOW, lightState);
            digitalWrite(GREEN, lightState);
    break;


      }
          }
