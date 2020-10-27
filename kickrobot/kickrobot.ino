#include <Servo.h>

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
}

void writeServoPin(unsigned int servoMotor1Value, unsigned int servoMotor2Value, boolean withDelay) {
  servo1.write(servoMotor1Value);
  servo2.write(servoMotor2Value);
  if (withDelay) delay(DELAY_VALUE);
}

void runFullCycle() {
  writeServoPin(FINAL_VALUE, INITIAL_VALUE, true);
  writeServoPin(INITIAL_VALUE, FINAL_VALUE, true);
  delay(3000);
}

void loop() {
  runFullCycle();
}
