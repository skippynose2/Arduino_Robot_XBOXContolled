

const int motorPin = 9;
const int motorPin2 = 10;
int motorSpeed;
int Turn;
const int backward = 6;
const int forward = 7;
const int forward1 = 4;
const int backward1 = 5;

void setup(){
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin, OUTPUT);
    Serial.begin(9600);
    pinMode(backward, OUTPUT);
    pinMode(forward, OUTPUT);
    digitalWrite(backward, LOW);
    digitalWrite(forward, HIGH);
    digitalWrite(backward1, LOW);
    digitalWrite(forward1, HIGH);
}

void loop(){
    if(Serial.available() > 0)
    {
      if(Serial.peek() == 'r')
      {
        digitalWrite(backward, LOW);
        digitalWrite(forward, HIGH);
        digitalWrite(backward1, LOW);
        digitalWrite(forward1, HIGH);
        Serial.read();
        motorSpeed = Serial.parseInt();
        analogWrite(motorPin, motorSpeed);
        analogWrite(motorPin2, motorSpeed);
      }
      if(Serial.peek() == 'b')
      {
        digitalWrite(backward, HIGH);
        digitalWrite(forward, LOW);
        digitalWrite(backward1, HIGH);
        digitalWrite(forward1, LOW);
        Serial.read();
        motorSpeed = Serial.parseInt();
        analogWrite(motorPin, motorSpeed);
        analogWrite(motorPin2, motorSpeed);
      }
      if(Serial.peek() == 't')
      {
        Serial.read();
        Turn = Serial.parseInt();
        if(Turn < 0)
        {
          analogWrite(motorPin, 200);
          analogWrite(motorPin2, 0);
        }else{
            analogWrite(motorPin2, 200);
            analogWrite(motorPin, 0);
          }
        }
       if(Serial.peek() == 's')
       {
        analogWrite(motorPin, 0);
        analogWrite(motorPin2, 0);
       }
       if(Serial.peek() == 'c')
      {
        Serial.flush();
      }
      }
      while (Serial.available() > 0)
      {
        Serial.read();  
      }
  }
