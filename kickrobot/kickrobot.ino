#include <Servo.h>

//Motores Arduino
#define BIT_MOTOR_1_A 1
#define BIT_MOTOR_1_B 2
#define BIT_MOTOR_2_A 3
#define BIT_MOTOR_2_B 4

//Mecanismo de chute
#define PIN_SERVO_1 9
#define PIN_SERVO_2 10
#define FINAL_VALUE 90
#define INITIAL_VALUE 0
#define DELAY_VALUE 200

Servo servo1; 
Servo servo2;

void setup() {
  servo1.attach(PIN_SERVO_1);
  servo2.attach(PIN_SERVO_2);
  writeServoPin(INITIAL_VALUE, INITIAL_VALUE, false);

  Serial.begin(9600);

  pinMode(BIT_MOTOR_1_A, OUTPUT);
  pinMode(BIT_MOTOR_1_B, OUTPUT);
  pinMode(BIT_MOTOR_2_A, OUTPUT);
  pinMode(BIT_MOTOR_2_B, OUTPUT);

  digitalWrite(BIT_MOTOR_1_A, HIGH);
  digitalWrite(BIT_MOTOR_1_B, HIGH);
  digitalWrite(BIT_MOTOR_2_A, HIGH);
  digitalWrite(BIT_MOTOR_2_B, HIGH);
}


void writeServoPin(unsigned int servoMotor1Value, unsigned int servoMotor2Value, boolean withDelay) {
  servo1.write(servoMotor1Value);
  servo2.write(servoMotor2Value);
  if (withDelay) delay(DELAY_VALUE);
}

void kick() {
  writeServoPin(FINAL_VALUE, INITIAL_VALUE, true);
  writeServoPin(INITIAL_VALUE, FINAL_VALUE, true);
}

void front(){
  digitalWrite(BIT_MOTOR_1_A, HIGH);
  digitalWrite(BIT_MOTOR_1_B, LOW);
  digitalWrite(BIT_MOTOR_2_A, HIGH);
  digitalWrite(BIT_MOTOR_2_B, LOW);
}

void back(){
  digitalWrite(BIT_MOTOR_1_A, LOW);
  digitalWrite(BIT_MOTOR_1_B, HIGH);
  digitalWrite(BIT_MOTOR_2_A, LOW);
  digitalWrite(BIT_MOTOR_2_B, HIGH);
}

void left(){
  digitalWrite(BIT_MOTOR_1_A, LOW);
  digitalWrite(BIT_MOTOR_1_B, HIGH);
  digitalWrite(BIT_MOTOR_2_A, LOW);
  digitalWrite(BIT_MOTOR_2_B, LOW);
}

void right(){
  digitalWrite(BIT_MOTOR_1_A, HIGH);
  digitalWrite(BIT_MOTOR_1_B, LOW);
  digitalWrite(BIT_MOTOR_2_A, LOW);
  digitalWrite(BIT_MOTOR_2_B, LOW);
}

void stop(){
  digitalWrite(BIT_MOTOR_1_A, LOW);
  digitalWrite(BIT_MOTOR_1_B, LOW);
  digitalWrite(BIT_MOTOR_2_A, LOW);
  digitalWrite(BIT_MOTOR_2_B, LOW);
}

chat last = '';
void loop() {

  while(Serial.available() > 0)
  {
    char c = Serial.read();
    if (c == 'F') {
      Serial.println("Front");
      front();
    }
    else if (c == 'B') {
      Serial.println("Back");
      back();
    }
    else if (c == 'L') {
      Serial.println("Left");
      left();
    }
    else if (c == 'R') {
      Serial.println("Right");
      right();
    }
    else if (c == '5' && last != '5') {
      Serial.println("Kick");
      kick();
    }

    last = c;
  }
  stop();

}
