

int led = 6;
long blinkDefault = 1000;
unsigned int blinkRate = 1;
int blinkMap = 1;
int ledState = LOW;
long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:
  Handbrake.begin();
  pinMode(led, OUTPUT);
}

void loop() {
  int pot = analogRead(A7);
  int mapped = map(pot,0,1023,0,255);
  Handbrake.setThrottle(mapped);
  
  if (mapped < 1 ) {
    blinkMap = 1; 
  }
  else
  {
    blinkMap = mapped;
  }
  blinkRate = blinkDefault / blinkMap;

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > blinkRate) {
    previousMillis = currentMillis;
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
      
    digitalWrite(led, ledState);
  }
}
