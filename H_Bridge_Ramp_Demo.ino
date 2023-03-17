//H-Bridge Demo Program. Will ramp motor up and down in the forward and reverse directions
//NVE Corporation 3/17/2023

//H-Bridge Pin Definitions
#define pwm 10
#define dir 11
#define enable 12

//Ramp Speed
#define wait 20

void setup() {
  //set IO pin modes
  pinMode (pwm, OUTPUT);
  pinMode (dir, OUTPUT);
  pinMode (enable, OUTPUT);
  //Turn H-Bridge ON
  digitalWrite (enable, HIGH);
}

void loop() { 
  //ramp forward up
  for (int x = 0; x < 255; x++) {
    analogWrite (pwm, x);
    digitalWrite (dir, LOW);
    delay (wait);
  }
  //ramp forward down
  for (int x = 255; x > 0; x--) {
    analogWrite (pwm, x);
    digitalWrite (dir, LOW);
    delay (wait);
  }
  //ramp reverse up
  for (int x = 0; x < 255; x++) {
    analogWrite (pwm, x);
    digitalWrite (dir, HIGH);
    delay (wait);
  }
  //ramp reverse down
  for (int x = 255; x > 0; x--) {
    analogWrite (pwm, x);
    digitalWrite (dir, HIGH);
    delay (wait);
  }
}
