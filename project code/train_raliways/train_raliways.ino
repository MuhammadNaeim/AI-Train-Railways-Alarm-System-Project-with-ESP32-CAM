// Libraries
#include <Servo.h>
Servo myservo1;
Servo myservo2;

// pins

//// hall effect
int hepin1 = 2;
int hepin2 = 3;

//// servo
int servopin1 = 4;
int servopin2 = 5;

//// ultrasonic 1
#define echo1 6  // Pin to receive echo pulse
#define trig1 7  // Pin to send trigger pulse

//// ultrasonic 2
#define echo2 8  // Pin to receive echo pulse
#define trig2 9  // Pin to send trigger pulse

//// ultrasonic 3
#define echo3 10  // Pin to receive echo pulse
#define trig3 11  // Pin to send trigger pulse


// variables

//// ultrasonic
int dist1 = 0;
int dist2 = 0;
int dist3 = 0;

//// hall effect
int he1;
int he2;
int t = 1;


//// servo
int open = 90;
int close = 0;

void setup() {

  Serial.begin(9600);

  // servo1
  myservo1.attach(servopin1);
  myservo1.write(open);
  // servo2
  myservo2.attach(servopin2);
  myservo2.write(open);

  // pins mode

  //// hall effect
  pinMode(hepin1, INPUT);
  pinMode(hepin2, INPUT);

  //// servo
  pinMode(servopin1, OUTPUT);
  pinMode(servopin2, OUTPUT);

  //// ultrasonic
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig3, OUTPUT);
}

void loop() {

  // hall effect reading
  he1 = digitalRead(hepin1);
  he2 = digitalRead(hepin2);

  Serial.print(he1);
  Serial.println(he2);


  // ultrasonic distance
  dist1 = ultrasonic(trig1, echo1);
  dist2 = ultrasonic(trig2, echo2);
  dist3 = ultrasonic(trig3, echo3);

  Serial.print(dist1);
  Serial.print("  ");
  Serial.print(dist2);
  Serial.print("  ");
  Serial.println(dist3);


  //// gate control
  if (he1 == 0 & t == 1){
    myservo1.write(close);
    delay(500);
    t = 0;
  }
  else if (he1 == 0 & t == 0){
    myservo1.write(open);
    delay(500);
    t = 1;
  }
  else if (he2 == 0 & t == 1){
    myservo1.write(close);
    delay(500);
    t = 0;
  }
  else if (he2 == 0 & t == 0){
    myservo1.write(open);
    delay(500);
    t = 1;
  }


  //// block control
  if (dist1 < 5) {
    myservo2.write(180);
  }else {
    myservo2.write(0); 
  }

 
  // alarm control
  if (dist2 <= 5){
    digitalWrite(12, 1);
    delay(50);
    digitalWrite(12, 0);
    delay(10);
    digitalWrite(12, 1);
    delay(50);
    digitalWrite(12, 0);
    delay(500);

    digitalWrite(12, 1);
    delay(50);
    digitalWrite(12, 0);
    delay(10);
    digitalWrite(12, 1);
    delay(50);
    digitalWrite(12, 0);
  }
  else{
    digitalWrite(12, 0);
  }
  if (dist3 <= 5){
    digitalWrite(13, 1);
    delay(50);
    digitalWrite(13, 0);
    delay(10);
    digitalWrite(13, 1);
    delay(50);
    digitalWrite(13, 0);
    delay(500);

    digitalWrite(13, 1);
    delay(50);
    digitalWrite(13, 0);
    delay(10);
    digitalWrite(13, 1);
    delay(50);
    digitalWrite(13, 0);
  }
  else{
    digitalWrite(13, 0);
  }
}


// ultrasonic void
int ultrasonic(int trig, int echo) {

  // Start Ranging -Generating a trigger of 10us burst
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Distance Calculation
  int duration = pulseIn(echo, HIGH);
  int distance = (duration / 2) * 0.0343;
  /* The speed of sound is 340 m/s or 29 us per cm
  The Ultrasonic burst travels out & back.
  So to find the distance of object we divide by 58  */
  return distance;
}