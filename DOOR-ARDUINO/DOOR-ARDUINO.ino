#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int pos = Serial.parseInt();

    if (pos >= 1 && pos <= 180) {
      myservo.write(pos);
      delay(2000);
      for (pos = 180; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        ///delay(15);
        break;
      }
    }
  }
}