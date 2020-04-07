// import libraries


// define pins
#define MoisturePin1 1
#define MoisturePin2 2
#define MoisturePin3 3
#define MoisturePin4 4
#define MoisturePin5 5
#define LDRPin 6
#define MotorDirPin 7
#define MotorStepPin 8
#define MotorBoundPinClose 9 // End stop module next to controller
#define MotorBoundPinFar 10 // End stop module at far end of rail

// define motor directions and locations
#define FORWARD LOW
#define BACKWARD HIGH
float CurrentLocation;
float MinLocation;
float MaxLocation;

// define plants
struct Plant1 {
  int number = 1;
  int location = 3;
  char dir[6] = "right";
  char species[15];
  };

struct Plant2 {
  int number = 2;
  int location = 2;
  char dir[6] = "right";
  char species[15];
  };

struct Plant3 {
  int number = 3;
  int location = 1;
  char dir[6] = "right";
  char species[15];
  };

struct Plant4 {
  int number = 4;
  int location = 3;
  char dir[6] = "left";
  char species[15];
  };

struct Plant5 {
  int number = 5;
  int location = 2;
  char dir[6] = "left";
  char species[15];
  };

void setup() {
  // put your setup code here, to run once:
  pinMode(MoisturePin1, INPUT);
  pinMode(MoisturePin2, INPUT);
  pinMode(MoisturePin3, INPUT);
  pinMode(MoisturePin4, INPUT);
  pinMode(MoisturePin5, INPUT);
  pinMode(LDRPin, INPUT);
  pinMode(DirPin, OUTPUT);
  pinMode(StepPin, OUTPUT);
  pinMode(MotorBoundPinClose, INPUT);
  pinMode(MotorBoundPinFar, INPUT);
  MinLocation = setup_motor(MaxLocation);
}

void loop() {
  // put your main code here, to run repeatedly:

}


float setup_motor(float Max) {
  // function to find bounds of rails
  // set MinLocation and MaxLocation

//  Max = ;
//  Min = ;
//  return Min;
}

void move_motor(float location){
  // move motor to location
  // use CurrentLocation to determine direction of motion
}
