#define PWMA 3
#define AIN1 4
#define AIN2 5
#define PWMB 6
#define BIN1 7
#define BIN2 8
#define STBY 9

#define IR_LEFT A0
#define IR_RIGHT A1

void setup() {
  Serial.begin(9600); // Start serial monitor

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  digitalWrite(STBY, HIGH); // Enable motor driver
}

void loop() {
  int left = digitalRead(IR_LEFT);
  int right = digitalRead(IR_RIGHT);

  // Print sensor values
  Serial.print("Left Sensor: ");
  Serial.print(left);
  Serial.print(" | Right Sensor: ");
  Serial.print(right);
  Serial.print(" --> ");

  if (left == LOW && right == LOW) {          // Forward
    Serial.println("Moving Forward");
    digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW);
    analogWrite(PWMA, 150); analogWrite(PWMB, 150);
  }
  else if (left == LOW && right == HIGH) {    // Turn right
    Serial.println("Turning Right");
    digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);  digitalWrite(BIN2, HIGH);
    analogWrite(PWMA, 150); analogWrite(PWMB, 150);
  }
  else if (left == HIGH && right == LOW) {    // Turn left
    Serial.println("Turning Left");
    digitalWrite(AIN1, LOW);  digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW);
    analogWrite(PWMA, 150); analogWrite(PWMB, 150);
  }
  else {                                      // Stop
    Serial.println("Stopping");
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
  }

  delay(200); // Small delay for readable output
}