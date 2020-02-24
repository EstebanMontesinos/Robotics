char command;

int duration = 1000;
const int leftSide[3] = {3, 6};
const int rightSide[3] = {5, 10};
const int rReverse = 11;
const int lReverse = 9;
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(leftSide[i], OUTPUT);
    pinMode(rightSide[i], OUTPUT);
  }
  pinMode(rReverse, OUTPUT);
  pinMode(lReverse, OUTPUT);
  pinMode(A0,INPUT);
}

//Left
void left() {
  digitalWrite(rReverse, LOW);
  digitalWrite(lReverse, LOW);
  for (int i = 0; i < 3; i++) {
    digitalWrite(leftSide[i], HIGH);
    digitalWrite(rightSide[i], LOW);
  }
}//Left

//Right
void right() {
  digitalWrite(rReverse, LOW);
  digitalWrite(lReverse, LOW);
  for (int i = 0; i < 2; i++) {
    digitalWrite(leftSide[i], LOW);
    digitalWrite(rightSide[i], HIGH);
  }
}//Right

//Forwards
void forward() {
  digitalWrite(rReverse, LOW);
  digitalWrite(lReverse, LOW);
  for (int i = 0; i < 2; i++) {
    digitalWrite(leftSide[i], HIGH);
    digitalWrite(rightSide[i], HIGH);
  }
}//Forwards

//Reverse/backward
void reverse() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(leftSide[i], LOW);
    digitalWrite(rightSide[i], LOW);
  }
  digitalWrite(rReverse, HIGH);
  digitalWrite(lReverse, HIGH);
}//Reverse/backward

//Stop
void stopAll() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(leftSide[i], LOW);
    digitalWrite(rightSide[i], LOW);
  }
  digitalWrite(rReverse, LOW);
  digitalWrite(lReverse, LOW);
  command = 'x';
}//Stop

//Distance Sensor
long uDist(){
  	long inches;
  	long uDuration;
	pinMode(7,OUTPUT);
  	digitalWrite(7,LOW);
  	delayMicroseconds(2);
  	digitalWrite(7,HIGH);
  	delayMicroseconds(5);
  	digitalWrite(7,LOW);
  	
  	pinMode(7,INPUT);
  	uDuration = pulseIn(7,HIGH);
  	inches = uDuration/74/2;
  	Serial.println(inches);
  	return inches;  	
}//Distance Sensor
void loop() {
  if (Serial.available() != 0) {
    command = Serial.read();
  }
  if (command == 'f') {
    forward();
    delay(duration);
    stopAll();
  }
  else if (command == 'b') {
    reverse();
    delay(duration);
    stopAll();
  }
  else if (command == 'r') {
    right();
    delay(duration);
    stopAll();
  }
  else if (command == 'l') {
    left();
    delay(duration);
    stopAll();
  }
  
	uDist();
}
