// import libraries

// define pins
#define MoisturePin1 1
#define MoisturePin2 2
#define MoisturePin3 3
#define MoisturePin4 4
#define MoisturePin5 5
#define LDRPin 6
#define DirPin 7
#define StepPin 8
#define MotorBoundPinClose 9 // End stop module next to controller
#define MotorBoundPinFar 10 // End stop module at far end of rail

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
  setup_motor();
}

void loop() {
  // put your main code here, to run repeatedly:

}


void setup_motor() {
  // function to find bounds of rails
  
}

void move_motor(dir, steps){
  // 
}
