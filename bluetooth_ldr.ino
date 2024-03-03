#include<SoftwareSerial.h>
SoftwareSerial B(10,11); //10 - RX and 11 - TX
const int analogPin = A0;  // Analog pin for photodiode
const int resistorValue = 10000;  // Resistance value in ohms (adjust as needed)
void setup() {
  Serial.begin(9600);  
  B.begin(9600);
}

void loop() {
  int sensorValue = analogRead(analogPin);  // Read analog value from the photodiode
  float io = 0.22;
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert analog value to voltage
  float current = (voltage / resistorValue) * 1000;  // Calculate current using Ohm's Law (I = V / R)
  float f = sqrt(current/io);
  float t = acos(f);
  
  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print("V, Current: ");
  Serial.print(current);  // Convert current to mA for easier reading
  Serial.println("mA");
  Serial.print("theta : ");
  Serial.print(t);
  delay(30);
  // now printing data on mobile

  B.print(voltage);
  B.print(";");
  B.print(current);
  B.print(";");

  delay(30);  // Delay for readability, adjust as needed
}