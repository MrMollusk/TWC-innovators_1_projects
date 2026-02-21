const int stepPin =9;
const int dirPin =8;
const int enPin =10;

void setup() {
pinMode(stepPin, OUTPUT);
pinMode(dirPin, OUTPUT);
pinMode(enPin, OUTPUT);

digitalWrite(enPin, LOW);
Serial.begin(9600);
Serial.println("Stepper ready. Commands: +(CW), -(CCW), s (stop)");

}

void loop() {
if (Serial.available()){
  char cmd=Serial.read();

  switch(cmd){
    case"+":
    digitalWrite(dirPin, HIGH); //clockwise
    Serial.println("Clockwise");
    break;
    case "s":
    digitalWrite(enPin, HIGH); //Disable motor
    Serial.println("Stopped");
    break;
    case "e":
    digitalWrite(enPin, LOW);
    Serial.println("Enabled");
    break;

  }
}

}
