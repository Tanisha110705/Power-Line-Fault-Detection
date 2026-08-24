#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// -------- PIN CONFIG --------
const int currentPin = A0;
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 12;

// -------- CALIBRATION (YOUR VALUE) --------
const float offsetVoltage = 2.08;

// -------- THRESHOLDS (CALIBRATED) --------
const float openThreshold = 0.05;
const float overLimit = 0.2;
const int distLimit = 15;

// -------- LCD --------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------- SETUP --------
void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.print("SYSTEM START");
  delay(1500);

  lcd.clear();
  lcd.print("CALIBRATING...");
  delay(1500);

  lcd.clear();
}

// -------- LOOP --------
void loop() {

  // ----- CURRENT SENSING (AVERAGING) -----
  float totalI = 0;

  for(int i = 0; i < 100; i++) {
    float v = (analogRead(currentPin) / 1024.0) * 5.0;
    float sample = (v - offsetVoltage) / 0.185;

    if (abs(sample) < 0.003) sample = 0; // noise removal

    totalI += abs(sample);
  }

  float current = totalI / 100.0;

  // ----- ULTRASONIC -----
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  int distance = duration * 0.034 / 2;

  if(distance == 0) distance = 999;

  // ----- CONDITION LOGIC -----
  String state;

  if (distance <= distLimit) {
    state = "OBSTACLE";

    // Double blink
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
  }

  else if (current < openThreshold) {
    state = "OPEN";

    // Slow blink
    digitalWrite(ledPin, HIGH);
    delay(400);
    digitalWrite(ledPin, LOW);
  }

  else if (current > overLimit) {
    state = "OVERCURRENT";

    // Fast blink
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
  }

  else {
    state = "NORMAL";

    // Steady ON
    digitalWrite(ledPin, HIGH);
  }

  // ----- LCD DISPLAY -----
  lcd.setCursor(0, 0);
  lcd.print("I:");
  lcd.print(current, 3);
  lcd.print("A ");

  lcd.print("D:");
  lcd.print(distance);
  lcd.print("cm ");

  lcd.setCursor(0, 1);
  lcd.print(state);
  lcd.print("        "); // clear extra chars

  // ----- SERIAL OUTPUT -----
  Serial.print("I=");
  Serial.print(current, 4);
  Serial.print("A  D=");
  Serial.print(distance);
  Serial.print("cm  State=");
  Serial.println(state);

  delay(300); // stable refresh
}
