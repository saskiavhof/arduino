#include <Servo.h>
Servo myServo1;
Servo myServo2;
int const potPin1 = A0;
int potVal1;
int angle1;
int const potPin2 = A1;
int potVal2;
int angle2;
int switchState = 0;
int LEDM = 0;
void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT); 
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
  myServo1.attach(9);
  myServo2.attach(10);
  Serial.begin(9600);
}

// MAIN CODE -------------------------------------------

void loop() {

  // LED Control ---------------------------------------
  switchState = digitalRead(2);

  if(switchState == HIGH && LEDM == 0) {
    LEDM = 1;
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    while(switchState == HIGH) {
      switchState = digitalRead(2);
    }
  }
  if(switchState == HIGH && LEDM == 1) {
    LEDM = 0;
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    while(switchState == HIGH) {
      switchState = digitalRead(2);
    }
  }

  // SERVO #1 -----------------------------------------
  potVal1 = analogRead(potPin1);
    Serial.print("potVal1: ");
    Serial.print(potVal1);
    angle1 = map(potVal1, 0, 1023, 0, 179);
    Serial.print(", angle1: ");
    Serial.println(angle1);
    myServo1.write(angle1);
    delay(15);

  // SERVO #2 -----------------------------------------
  potVal2 = analogRead(potPin2);
    Serial.print("potVal2: ");
    Serial.print(potVal2);
    angle2 = map(potVal2, 0, 1023, 0, 179);
    Serial.print(", angle2: ");
    Serial.println(angle2);
    myServo2.write(angle2);
    delay(15);

}


// END MAIN -------------------------------------------

