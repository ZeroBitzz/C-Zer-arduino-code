#include <Servo.h>

Servo right_servo;
Servo left_servo;

int pos = 0;
const int trigPin = 10;
const int echoPin = 11;
bool tooClose = false;

long duration;
long distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  right_servo.attach(9);
  left_servo.attach(8);
}

void loop() {
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;
  Serial.print("distance: ");
  Serial.println(distance);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);

  if(distance > 50){
    left_servo.write(1);
    right_servo.write(180);
    delayMicroseconds(1000);
  }else {
    left_servo.write(180);
    right_servo.write(1);
    delayMicroseconds(1000);
//    left_servo.write(1);
//    right_servo.write(1);
//    delayMicroseconds(1000);
  }
}