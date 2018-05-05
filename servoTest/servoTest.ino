#include <Servo.h>

Servo myServo;
int pin = 11;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(pin);
  myServo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
