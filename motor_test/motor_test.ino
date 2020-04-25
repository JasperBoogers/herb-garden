// import libraries
#include <AccelStepper.h>

// Define stepper motor connections and steps per revolution:
#define stepsPerRevolution 200
#define MotorInterface 1
#define dirPin 2
#define stepPin 3
#define faultPin 4
#define ledPin 5
#define endStopPin 6
#define homeStopPin 7

// define variables
AccelStepper stepper = AccelStepper(MotorInterface, stepPin, dirPin);
float end_location;

// define functions
void find_home(void);
float find_end(void);

void setup() {
  Serial.begin(9600);
  
  // setup stepper
  stepper.setMaxSpeed(1000);
  find_home();
  end_location = find_end();

  // setup home and end stops
  pinMode(homeStopPin, INPUT_PULLUP);
  pinMode(endStopPin, INPUT_PULLUP);

  // setup LED
  pinMode(faultPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
}

void find_home(void){
  stepper.setSpeed(100);
  long pos = -1;
  Serial.println("Finding home...");
  
  while(digitalRead(homeStopPin))
  {
    stepper.moveTo(pos);
    pos--;
    stepper.run();
    delay(5);
  }
  Serial.println("Found home end stop!");

  // found end stop, now move 2 full turns away from it
  stepper.move(400);
  stepper.runToPosition();

  // set the current position to be the home position
  stepper.setCurrentPosition(0);
}

float find_end(void){
  stepper.setSpeed(100);
  long pos = 1;
  Serial.println("Finding end...");

  // move stepper
  while(digitalRead(endStopPin))
  {
    stepper.moveTo(pos);
    pos++;
    stepper.run();
    delay(5);
  }
  Serial.print("Found end at position ");
  Serial.println(stepper.currentPosition());

  // found end stop, now move 2 full turns away from it and return position
  stepper.move(-400);
  stepper.runToPosition();
  return stepper.currentPosition();
}
