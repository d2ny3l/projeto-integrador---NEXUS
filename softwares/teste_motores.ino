const int IN1 = 3, IN2 = 4, IN3 = 5, IN4 = 6; 

void setup() {

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {
  digitalWrite(IN1, LOw);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(30);
 
 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(30);

  

}
