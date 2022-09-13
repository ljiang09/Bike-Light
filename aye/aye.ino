
/*program sequentially turns on and turn off all 3 LEDs */ 

int LED1 = 10;//red
int LED2 = 9; //green
int LED3 = 11; //yellow

void setup() {
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
}


void loop() {
  digitalWrite(LED1, HIGH);    // turn on LED1 
  delay(200);                  // wait for 200ms
  digitalWrite(LED2, HIGH);    // turn on LED2
  delay(200);                  // wait for 200ms       
  digitalWrite(LED3, HIGH);    // turn on LED3 
  delay(200);                  // wait for 200ms
  digitalWrite(LED1, LOW);     // turn off LED1
  delay(300);                  // wait for 300ms
  digitalWrite(LED2, LOW);     // turn off LED2
  delay(300);                  // wait for 300ms
  digitalWrite(LED3, LOW);     // turn off LED3
  delay(300);                  // wait for 300ms before running program all over again
}
