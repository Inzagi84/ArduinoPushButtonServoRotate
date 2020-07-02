/*
Filip Crljenić 2.7.2020.
Project for learning Arduino.
Push button and Servo Rotation when its on 180 move back on push
*/
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
const short buttonPin = 11;     // the number of the pushbutton pin
const short servoPin = 9;
short degree = 0;
short multiplication = 1;
const short multiplicationChange = -1;
const short movingStep = 20;
bool pressed = false;
const short maxDegree = 180;
const short minDegree = 0;

// twelve servo objects can be created on most boards


void setup() {
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  pinMode(buttonPin, INPUT);

}



void loop() {
  short  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW)
  {
    pressed = false;
  }

  if (buttonState == HIGH)
  {
    if (pressed == false)
    {
      calculateDegree();

    }
    pressed = true;


  }
  myservo.write(degree);
}

void calculateDegree()
{
  degree += movingStep * multiplication;
  if (degree > maxDegree)
  {
    degree = maxDegree;
    multiplication *= multiplicationChange;
  }
  if (degree < minDegree)
  {
    degree = minDegree;
    multiplication *= multiplicationChange;
  }
}
