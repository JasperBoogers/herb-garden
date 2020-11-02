// import libraries


// define pins
unsigned int MoisturePins[5] = {1, 2, 3, 4, 5};
#define LDRPin 6
#define MotorDirPin 7
#define MotorStepPin 8
#define MotorBoundPinClose 9 // End stop module next to controller
#define MotorBoundPinFar 10 // End stop module at far end of rail

// define motor directions and locations
#define FORWARD LOW
#define BACKWARD HIGH
float currentLocation;
float minLocation;
float maxLocation;

// define plants
struct Plant {
  public:
  unsigned int location;
  char dir[6];
  unsigned int moisturePin;
  char species[15];
  float sensorThreshold;
  };

Plant plant1 = {3, "right", 1, "basilicum", 100.0};
Plant plant2 = {3, "left", 2, "tijm", 105.0};
Plant plant3 = {2, "right", 3, "munt", 88.4};
Plant plant4 = {2, "left", 4, "koriander", 150};
Plant plant5 = {1, "right", 5, "oregano", 99.0};

// create array of pointers to plant structs
Plant *plants[5] = {&plant1, &plant2, &plant3, &plant4, &plant5};

void setup() {
    Serial.begin(9600);
  while (!Serial) {
    // wait
  }
  // put your setup code here, to run once:
  for (int i=0; i<5; i++) {
    pinMode(MoisturePins[i], INPUT);
  }
  pinMode(LDRPin, INPUT);
  pinMode(MotorDirPin, OUTPUT);
  pinMode(MotorStepPin, OUTPUT);
  pinMode(MotorBoundPinClose, INPUT);
  pinMode(MotorBoundPinFar, INPUT);
  minLocation = findEndStop(true);
  maxLocation = findEndStop(false);
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
    Serial.print("checking plant ");
    Serial.print(plants[i]->species);
    Serial.print(" at location ");
    Serial.println(plants[i]->location);

    if ( abs(check_moisture_level(plants[i]->moisturePin)-plants[i]->sensorThreshold) > 0.1 ) {
      Serial.println("plant needs water");
      move_motor(plants[i]->location);
      dispense_water(plants[i]->dir);
    }
    else {
      Serial.println("plant does not need water");
    }
   delay(5000);
   }
   // move motor back to MinLocation
   Serial.println("Finished loop");
   move_motor((int)ceil(minLocation));
   delay(2000);
}

float findEndStop(bool near) {
  /* find the end-stops
   * if near is true --> home end-stop, else far end-stop
   * maybe add some margin to the location?
   */
  if (near) {
    Serial.println("searching for min location...");
    delay(2000);
    return 0.0;
  }
  else {
    Serial.println("searching for max location...");
    delay(2000);
    return 100.0;
  }
}

void move_motor(int location){
  /* move motor to location
   * use CurrentLocation to determine direction of motion
   * scale location with difference between minLocation and maxLocation
   * if zero --> go back to minLocation
   */
  Serial.println("moving motor...");
}

void dispense_water(char* d) {
  // dispense water either left or right
  if (strcmp(d, "left") == 0){ 
    Serial.println("dispensing left");
  }
  else {
    Serial.println("dispensing right");
  }
}

float check_moisture_level(int pin) {
  // check the moisture level of given moisturePin
  return (float)random(80, 160);
}

float check_water_level(){
  // use ultrasonic sensor to determine water reservoir height
  float height;
  return height;
}
