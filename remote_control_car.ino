float x_joystick;
float y_joystick;

// Motor Pins:
int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

void setup() {
  Serial.begin(9600);
  // setup code:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,   OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}


void loop() {
  // input from controller:
  x_joystick = pulseIn(A0, HIGH); 
  y_joystick = pulseIn(A1, HIGH);
  // print coordinates
  Serial.print("x:");
  Serial.println(x_joystick);
  Serial.print("y:");
  Serial.println(y_joystick);
  
  delay(50);

  //Controlling speed (0  = off and 255 = max speed):    
  analogWrite(9, 200); //ENA   pin (sets speed for front motors)
  analogWrite(10, 200); //ENB pin (sets speed for back motors)
  // Go forward
 if (x_joystick > 1900 ){
   digitalWrite(motor1pin1,   LOW); // front
   digitalWrite(motor1pin2, HIGH);
   digitalWrite(motor2pin1,   LOW);
   digitalWrite(motor2pin2, HIGH);
 }
   // Go Backwards
  else if (x_joystick < 100){
   digitalWrite(motor1pin1,   HIGH); //back
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1,   HIGH);
   digitalWrite(motor2pin2, LOW);
 }
  // Turn Right
 else if (y_joystick < 100){
   analogWrite(9, 10); //ENA   pin
   analogWrite(10, 10); //ENB pin
   digitalWrite(motor1pin1,   LOW);
   digitalWrite(motor1pin2, HIGH);
   digitalWrite(motor2pin1,   HIGH);
   digitalWrite(motor2pin2, LOW);
 }
  // Turn Left
 else if (y_joystick > 1800){
   analogWrite(9, 10); //ENA   pin
   analogWrite(10, 10); //ENB pin
   digitalWrite(motor1pin1,   HIGH);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1,   LOW);
   digitalWrite(motor2pin2, HIGH);
 }
   // Stop if joystick is not being moved
 else if (x_joystick >= 100 || x_joystick < 1900 && y_joystick >= 100 || y_joystick < 1900) {
   digitalWrite(motor1pin1,   LOW);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1,   LOW);
   digitalWrite(motor2pin2, LOW);
 }
  


  
}
