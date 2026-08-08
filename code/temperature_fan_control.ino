const int temperatureSensor = A0;
const int fanControl = 9;

void setup() {

  pinMode(fanControl, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(temperatureSensor);

  // Convert analog reading to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Reference calculation for an LM35-type sensor
  float temperature = voltage * 100.0;

  int fanSpeed;

  if (temperature < 25) {
    fanSpeed = 0;
  }
  else if (temperature < 30) {
    fanSpeed = 80;
  }
  else if (temperature < 35) {
    fanSpeed = 150;
  }
  else if (temperature < 40) {
    fanSpeed = 220;
  }
  else {
    fanSpeed = 255;
  }

  analogWrite(fanControl, fanSpeed);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Fan PWM: ");
  Serial.println(fanSpeed);

  delay(1000);
}
