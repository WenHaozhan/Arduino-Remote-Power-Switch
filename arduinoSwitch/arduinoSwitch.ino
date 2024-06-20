const int powerPin = 22; 
const String ON = "ON";
// const int inputSignalPin = 23;

// int lastPowerState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(powerPin, OUTPUT);
  // pinMode(inputSignalPin, INPUT_PULLUP);
  // pinMode(25, OUTPUT);
  // digitalWrite(25, LOW);
  // digitalWrite(powerPin, LOW);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.
  
  //TEST CODE
  // int reading = digitalRead(inputSignalPin);
  // if (reading != lastPowerState) {
  //   if (reading == HIGH) {
  //     digitalWrite(powerPin, HIGH);
  //     delay(400);
  //     digitalWrite(powerPin, LOW);
  //   } else {
  //     // low
  //     digitalWrite(powerPin, LOW);
  //   }
  // }
  // lastPowerState = reading;
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    Serial.print("You sent me: ");
    Serial.println(data);
    if (data == ON) {
      digitalWrite(powerPin, HIGH);
      delay(400);
      digitalWrite(powerPin, LOW);
    }
  }
}
