#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11
#define POT_PIN A0

// Button pins
int buttons[] = {2, 3, 4, 5, 6}; 

// To track button states
bool buttonStates[5] = {false}; 
int lastPotValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  for (int i = 0; i < 5; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {
  // Check buttons
  for (int i = 0; i < 5; i++) {
    if (digitalRead(buttons[i]) == LOW && !buttonStates[i]) {
      Serial.print("BUTTON_");
      Serial.println(i + 1);
      buttonStates[i] = true;
    } else if (digitalRead(buttons[i]) == HIGH) {
      buttonStates[i] = false;
    }
  }

  // Check potentiometer
  int potValue = analogRead(POT_PIN);
  if (abs(potValue - lastPotValue) > 10) {
    int brightness = map(potValue, 0, 1023, 0, 255);
    setRGBBrightness(brightness);
    Serial.print("POT_");
    Serial.println(brightness);
    lastPotValue = potValue;
  }

  delay(50);
}

void setRGBBrightness(int brightness) {
  analogWrite(RED_PIN, brightness);
  analogWrite(GREEN_PIN, brightness);
  analogWrite(BLUE_PIN, brightness);
}
