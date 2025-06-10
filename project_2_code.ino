const int potPin = A1;
const int photoCellPin = A0;
const int ledPins[] = { 2, 3, 4, 5, 6, 7 };
const long length = sizeof(ledPins) / sizeof(ledPins[0]);
const float threshold = 5.0 / length;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < length; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int potValue = analogRead(potPin);
  float voltage = potValue * (5.0 / 1023.0);
  int photoValue = analogRead(photoCellPin);
  float voltagePhoto = photoValue * (5.0 / 1023.0);

  Serial.print("Photocell Voltage: ");
  Serial.println(voltagePhoto);

  if (voltagePhoto < 2.50) {
     Serial.print("Potentiometer Voltage: ");
    Serial.println(voltage);
    int count = 0;
    for (int i = 0; i < length; i++) {
      if (voltage > threshold * i) {
        digitalWrite(ledPins[i], HIGH);
        count = count + 1;
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }
    Serial.print("Number of LEDs on: ");
    Serial.println(count);
  }
  else{
    for (int i = 0; i < length; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    Serial.println("Too bright!");

  }

  delay(500);
}