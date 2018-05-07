
int LED = 7;
int state;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    if(Serial.peek() == 's')
    {
      Serial.read();
      state = Serial.parseInt();
      if(state == 1)
      {
        digitalWrite(LED, HIGH);
      }
      if(state == 0)
      {
        digitalWrite(LED, LOW);
      }
    }
  }
  while(Serial.available() > 0)
  {
    Serial.read();
  }
}
