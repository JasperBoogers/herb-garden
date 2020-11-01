// import libraries


// define pins
int MoisturePins[5] = {1, 2, 3, 4, 5};
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
struct Plant {
  public:
  int location;
  char dir[6];
  char species[15];
  float sensor_threshold;
  };

Plant plant1 = {3, "right", "basilicum", 100.0};
Plant plant2 = {3, "left", "tijm", 105.0};
Plant plant3 = {2, "right", "munt", 88.4};
Plant plant4 = {2, "left", "koriander", 150};
Plant plant5 = {1, "right", "oregano", 99.0};

// create array of pointers to plant structs
Plant *plants[5] = {&plant1, &plant2, &plant3, &plant4, &plant5};

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<5; i++) {
    pinMode(MoisturePins[i], INPUT);
  }
  pinMode(LDRPin, INPUT);
  pinMode(MotorDirPin, OUTPUT);
  pinMode(MotorStepPin, OUTPUT);
  pinMode(MotorBoundPinClose, INPUT);
  pinMode(MotorBoundPinFar, INPUT);
  MinLocation = find_min_location();
  MaxLocation = find_max_location();
  Serial.begin(9600);
}

void loop() {
  /*
   * loop over plants
   * for each plant, read sensor value and compare to threshold
   * if a plant is dry, move to that plant and water it
   * once watered, do not move watering head, but continue checking
   * if all plants watered, move back to MinLocation 
   */
   for (int i=0; i<5; i++) {
    move_motor(plants[i]->location);
    dispense_water(plants[i]->dir);
    delay(500);
   }
}


float find_min_location(){
//  float Min:
//  return Min;
}

float find_max_location(){
//  float Max;
//  return Max;
}

void move_motor(float location){
  // move motor to location
  // use CurrentLocation to determine direction of motion
}

void dispense_water(char* d) {
  // dispense water either left or right
  if (strcmp(d, "left") == 0){ 
    Serial.print("left");
  }
  else {
    Serial.print("right");
  }
  
}

float check_water_level(){
  // use ultrasonic sensor to determine water reservoir height
  float height;
  return height;
}
