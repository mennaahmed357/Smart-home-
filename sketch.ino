const int ldrPin     = 34;  
const int gasPin     = 35; 
const int nightLed    = 26;
const int redLed     = 25; 
const int buzzerPin  = 27;  

const int lightThreshold = 2000; 
const int gasAlarmLevel  = 250;  

void setup() {
  Serial.begin(9600);
  pinMode(nightLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  int ldrValue = analogRead(ldrPin); // من 0 لـ 4095
  Serial.print("LDR: ");
  Serial.println(ldrValue);

  if (ldrValue < lightThreshold) {
    digitalWrite(nightLed, HIGH); 
  } else {
    digitalWrite(nightLed, LOW);  
  }

   
  int gasValue = analogRead(gasPin); // من 0 لـ 4095
  Serial.print("Gas: ");
  Serial.println(gasValue);

  int brightness = map(gasValue, 0, 4095, 0, 255);
  analogWrite(redLed, brightness);

  Serial.print("Brightness: ");
  Serial.println(brightness);

  
  if (brightness >= gasAlarmLevel) {
    
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(300);
  } else {
    digitalWrite(buzzerPin, LOW); 
  }

  delay(200); }