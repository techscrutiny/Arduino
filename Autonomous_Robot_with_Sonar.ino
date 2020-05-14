//----Written by Tech Scrutiny---//


/*** SET UP MOTOR PINS ***/
/* First Motor Driver DRV8833 */
#define RIGHT_REAR_MOTOR_FORWARD 2
#define RIGHT_REAR_MOTOR_BACKWARD 3
#define LEFT_REAR_MOTOR_FORWARD 4
#define LEFT_REAR_MOTOR_BACKWARD 5

/* Second Motor Driver DRV8833 */
#define LEFT_FRONT_MOTOR_FORWARD  6
#define LEFT_FRONT_MOTOR_BACKWARD 7
#define RIGHT_FRONT_MOTOR_FORWARD 8
#define RIGHT_FRONT_MOTOR_BACKWARD 9 
/*** END MOTOR PINS SETUP ***/

/*** SET UP ULTRASONIC SENSOR ***/
#define echoPin 11 // assign pin D11 on Arduino as an Echo pin for the HC-SR04 sensor
#define triggerPin 10 // assign pin D10 on Arduino as a Trigger pin for the HC-SR04 sensor
long duration;
int distance;
/*** END ULTRASONIC SENSOR SETUP ***/

/*** Begin Initialization ***/
void setup() {
  Serial.begin(115200);

  //Initialize Ultrasonic Sensor
  pinMode(triggerPin, OUTPUT); // Setting up the tigger pin
  pinMode(echoPin, INPUT); // Setting up the echo pin


  //Initialize Motors
  pinMode(RIGHT_REAR_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_REAR_MOTOR_BACKWARD, OUTPUT);
  pinMode(LEFT_REAR_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_REAR_MOTOR_BACKWARD, OUTPUT);
  pinMode(LEFT_FRONT_MOTOR_FORWARD, OUTPUT);     
  pinMode(LEFT_FRONT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_FRONT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_FRONT_MOTOR_BACKWARD, OUTPUT);
  
  digitalWrite(RIGHT_REAR_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_MOTOR_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_MOTOR_BACKWARD, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_BACKWARD, LOW);
  

}
/*** End Initialization ***/

/*** MAIN LOOP ***/

void loop() {
  while(getDistance()>35) {
    moveForward();
  }
  while(getDistance()<=35) {
    turnRight();
  }
  moveBackward();
  delay(100);
}

/* END MAIN ARDUINO LOOP */


/***Measure Distance***/

int getDistance() {
 // Clears triggerPin 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the triggerPin active for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;   
  return distance;
}
/*** Motor Functions ***/
// These allow for the motors to Stop, Go Forward, Go Backward, Turn Left, Turn Right
//

void stopMoving() {
  digitalWrite(LEFT_FRONT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_MOTOR_BACKWARD, LOW);
  delay(50);
}

void moveForward() {
  digitalWrite(LEFT_FRONT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_FRONT_MOTOR_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_REAR_MOTOR_BACKWARD, LOW);
}

void moveBackward() {
  digitalWrite(LEFT_FRONT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_MOTOR_BACKWARD, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_MOTOR_FORWARD, LOW); 
  digitalWrite(RIGHT_REAR_MOTOR_BACKWARD, HIGH);
  delay(100);
  stopMoving();
}

void turnRight() {
  digitalWrite(LEFT_FRONT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_FRONT_MOTOR_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_MOTOR_BACKWARD, HIGH); 
  delay(500); 
  stopMoving();
}

void turnLeft() {
  digitalWrite(LEFT_FRONT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_MOTOR_BACKWARD, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_REAR_MOTOR_BACKWARD, LOW);
  delay(500);
  stopMoving();
}
//End Motor Functions
