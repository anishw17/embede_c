const int analogPin = A1;  // Analog pin for photodiode
const int resistorValue = 10000;  // Resistance value in ohms (adjust as needed)
void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  int sensorValue = analogRead(analogPin);  // Read analog value from the photodiode
  float io = 0.22;
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert analog value to voltage
  float current = (voltage / resistorValue) * 1000;  // Calculate current using Ohm's Law (I = V / R)

  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print("V, Current: ");
  Serial.print(current);  // Convert current to mA for easier reading
  Serial.println("mA");

  delay(1000);  // Delay for readability, adjust as needed
}