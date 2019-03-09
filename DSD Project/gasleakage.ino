
int buzzer = 10;
int smokeA0 = A5;
int red_light = 2;

// Your threshold value. You might need to change it.
int sensorThres = 335;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(red_light, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 200);
    digitalWrite(red_light, HIGH);
    delay(100);
  }
  else
  {
    noTone(buzzer);
    digitalWrite(red_light, LOW);
  }
}
