void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    // wait
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(1));
  delay(200);
}
