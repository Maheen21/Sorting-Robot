float x_joystick;
float y_joystick;

// put your setup code here, to run once:
int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,   OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  x_joystick = pulseIn(A0, HIGH); 
  y_joystick = pulseIn(A1, HIGH);
  Serial.print("x:");
  Serial.println(x_joystick);
  Serial.print("y:");
  Serial.println(y_joystick);
  delay(50);

   // put your main code here, to run repeatedly:

  //Controlling speed (0   = off and 255 = max speed):    
  //(Optional)
  analogWrite(9, 200); //ENA   pin
  analogWrite(10, 200); //ENB pin
  //(Optional)
 if (x_joystick > 1900 ){
   digitalWrite(motor1pin1,   LOW); // front
   digitalWrite(motor1pin2, HIGH);
   digitalWrite(motor2pin1,   LOW);
   digitalWrite(motor2pin2, HIGH);
 }
  else if (x_joystick < 100){
   digitalWrite(motor1pin1,   HIGH); //back
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1,   HIGH);
   digitalWrite(motor2pin2, LOW);
 }
 else if (y_joystick < 100){
   analogWrite(9, 10); //ENA   pin
   analogWrite(10, 10); //ENB pin
   digitalWrite(motor1pin1,   LOW);
   digitalWrite(motor1pin2, HIGH);
   digitalWrite(motor2pin1,   HIGH);
   digitalWrite(motor2pin2, LOW);
 }
 else if (y_joystick > 1800){
   analogWrite(9, 10); //ENA   pin
   analogWrite(10, 10); //ENB pin
   digitalWrite(motor1pin1,   HIGH);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1,   LOW);
   digitalWrite(motor2pin2, HIGH);
 }
 else if (x_joystick >= 100 || x_joystick < 1900 && y_joystick >= 100 || y_joystick < 1900) {
   digitalWrite(motor1pin1,   LOW);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1,   LOW);
   digitalWrite(motor2pin2, LOW);
 }
  


  
}
