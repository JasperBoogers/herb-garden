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
long init_pos=-1;

// define functions
void find_home(void);
float find_end(void);

void setup() {
  // setup stepper
  stepper.setMaxSpeed(1000);
  home_location = find_home();
  end_location = find_endd();

  // setup home and end stops
  pinMode(homeStopPin, INPUT_PULLUP);
  pinMode(endStopPin, INPUT_PULLUP);

  // setup error LED
  pinMode(faultPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  
}

void find_home(void){
  while(digitalRead(homeStopPin)){
    stepper.moveTo(init_pos);
    init_pos--;
    stepper.run();
    delay(5);
  }

  // found end stop, now move 2 full turns away from it
  stepper.move(400);
  stepper.runToPosition();

  // finally, set the current position to be the home position
  stepper.setCurrentPosition(0);
}

float find_end(void){
  
}
