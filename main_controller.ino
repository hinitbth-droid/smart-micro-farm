/**
 * Project: Smart Micro-Farm Control System
 * Author: hinitbth-droid
 * Description: Automated irrigation based on soil moisture levels.
 */

const int SOIL_SENSOR_PIN = A0; 
const int PUMP_RELAY_PIN = 7;   
const int MOISTURE_THRESHOLD = 500; // Calibrate based on soil type

void setup() {
  pinMode(PUMP_RELAY_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("System Initialized: Smart Micro-Farm Controller");
}

void loop() {
  int soilMoisture = analogRead(SOIL_SENSOR_PIN);
  
  Serial.print("Current Soil Moisture: ");
  Serial.println(soilMoisture);

  // Automatic Irrigation Logic
  if (soilMoisture < MOISTURE_THRESHOLD) {
    digitalWrite(PUMP_RELAY_PIN, HIGH); 
    Serial.println("Status: Low Moisture Detected. Pump ON.");
  } else {
    digitalWrite(PUMP_RELAY_PIN, LOW);  
    Serial.println("Status: Optimal Moisture. Pump OFF.");
  }
  
  delay(5000); // 5-second sampling rate
}
