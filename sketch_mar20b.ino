#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Initialize I2C LCD (change 0x27 to 0x3F if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define sensorPin 2   // Flow sensor signal pin
#define pumpPin 9     // PWM pin to control TIP122 transistor
#define potPin A0     // Potentiometer connected to A0
#define buzzerPin 8   // Buzzer pin
#define buttonPin 10  // Push button pin
#define lampPin 7     // Lamp pin (connected to LED or external lamp)

volatile unsigned long pulseCountNum = 0; 
float flowRate = 0;
unsigned long previousTime = 0;
int pumpSpeed = 255;
bool buzzerMute = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(pumpPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(lampPin, OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(sensorPin), pulseCountMethod, RISING);
  Serial.begin(9600);

  // Initialize I2C LCD
  lcd.init();
  lcd.backlight(); 

  lcd.setCursor(0, 0);
  lcd.print("Flow Meter Ready");
  delay(100);
  lcd.clear();
}

void loop() {
  measureFlowRate();
  adjustPumpSpeed();
  checkFluidLevel();
  updateDisplays();
  checkButton();
}

void measureFlowRate() {
  unsigned long currentTime = millis();
  if (currentTime - previousTime >= 1000) {
    previousTime = currentTime; 
    noInterrupts();
    flowRate = pulseCountNum / 120.0; // Adjust for your sensor's calibration
    pulseCountNum = 0;
    interrupts();
  }
}

void pulseCountMethod() {
  pulseCountNum++;  
}

void adjustPumpSpeed() {
  int potValue = analogRead(potPin);
  pumpSpeed = map(potValue, 0, 1023, 0, 255);
  analogWrite(pumpPin, pumpSpeed);

  Serial.print("Pump Speed: ");
  Serial.println(map(pumpSpeed, 0, 255, 0, 6));
  Serial.println(flowRate);
}

void checkFluidLevel() {
  if ((flowRate < 0.1 ) && !buzzerMute) { 
    ambulanceSiren();
    alertLamp();
    Serial.println("Warning: Fluid Empty!");
  } else {
    noTone(buzzerPin);
  }
}

void alertLamp() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(lampPin, HIGH);
    delay(200);
    digitalWrite(lampPin, LOW);
    delay(200);
  }
}

void checkButton() {
  bool currentButtonState = digitalRead(buttonPin);
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    delay(200);
    buzzerMute = !buzzerMute;
    Serial.print("Buzzer ");
    Serial.println(buzzerMute ? "Muted" : "Unmuted");
  }
  lastButtonState = currentButtonState;
}

void ambulanceSiren() {
  for (int freq = 1000; freq <= 2000; freq += 50) {
    tone(buzzerPin, freq);
    delay(30);
  }
  for (int freq = 2000; freq >= 1000; freq -= 50) {
    tone(buzzerPin, freq);
    delay(30);
  }
}

void updateDisplays() {
  int speedLevel = map(pumpSpeed, 0, 255, 0, 6);
  
  lcd.clear(); // Clear LCD before updating new values

  lcd.setCursor(0, 0);
  lcd.print("Flow: ");
  lcd.print(flowRate);
  lcd.print(" L/m"); 

  lcd.setCursor(0, 1);
  lcd.print("Pump: ");
  lcd.print(speedLevel);
}
