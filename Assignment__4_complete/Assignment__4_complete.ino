#include <Servo.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
//in 1- pin8, in 2- pin 10, 3 pin 9, 4 pin 11 etc..
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
Servo servo1; // create a servo object to control a servo
int stepCount = 0;  // number of steps the motor has taken
int servoPos = 0; //stores the servo position

int switchPin = 2;
int xPin = A0;
int yPin = A1;

int mappedX;
int mappedY;
int switchState;

int led = 13;

//annalog pin for pot
int potPin = A3;

//the value coming from potentiometer
int potValue = 0;

int xJoystick = A2;
void setup() {

  servo1.attach(7); //attaches servo to pin 9
  pinMode(switchPin, INPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  //printing out sensor values in serial monitor
  int potValue = analogRead(potPin);
  // map it to a range from 0 to 100:
  int motorSpeed = map(potValue, 0, 1023, 0, 15);
  // set the motor speed:
  mappedX = map(analogRead(xPin), 0, 1023, 0, 177);
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
  servo1.write(mappedX);

  Serial.print("Switch: ");
  Serial.print(digitalRead(switchPin));
  Serial.print("\n"); // \n = line break
  //delay(500);
  Serial.print("X: ");
  Serial.print(analogRead(xPin));
  Serial.print("\n");
  //delay(500);
  Serial.print("Y: ");
  Serial.print(analogRead(yPin));
  Serial.print("\n");
  //delay(500);

}
