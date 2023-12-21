#include <Servo.h>
#include <IRremote.hpp>
#include <AFMotor.h>

#define maju_code 3877175040
#define mundur_code 2907897600
#define kanan_code 2774204160
#define kiri_code 4144561920
#define grip_code 3810328320
#define one_code 3125149440
#define three_code 3091726080
#define four_code 3141861120
#define five_code 3208707840
#define six_code 3158572800
#define seven_code 4161273600
#define nine_code 4127850240
#define two_code 3108437760

Servo gripper;
AF_DCMotor MotorKa(3);
AF_DCMotor MotorKi(4);

bool maju = false;
bool mundur = false;
bool kanan = false;
bool kiri = false;
bool grip = false;

void setup() {
  Serial.begin(9600);

  gripper.attach(10);
  IrReceiver.begin(9, ENABLE_LED_FEEDBACK);

  MotorKa.setSpeed(175);
  MotorKi.setSpeed(175);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
  gripper.write(0);

  Serial.println("Start.");
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("signal: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData);

    switch (IrReceiver.decodedIRData.decodedRawData) {
      case one_code:
        rotate45left();
        break;
      case three_code:
        rotate45right();
        break;
      case four_code:
        rotate90left();
        break;
      case six_code:
        rotate90right();
        break;
      case seven_code:
        rotate180left();
        break;
      case nine_code:
        rotate180right();
        break;
      case five_code:
        rotate360();
        break;
      case two_code:
      allMove();
        break;
      case maju_code:
        maju = true;
        break;
      case mundur_code:
        mundur = true;
        break;
      case kanan_code:
        kanan = true;
        break;
      case kiri_code:
        kiri = true;
        break;
      case grip_code:
        grip = !grip;
        if (grip) {
          grip = true;
          gripper.write(60);
        } else {
          grip = false;
          gripper.write(0);
        }
        break;
      default:
        break;
    }


    IrReceiver.resume();
  } else {
    maju = false;
    mundur = false;
    kanan = false;
    kiri = false;
  }

  if (maju) {
    MotorKa.setSpeed(175);
    MotorKi.setSpeed(175);
    MotorKa.run(FORWARD);
    MotorKi.run(FORWARD);
  } else if (mundur) {
    MotorKa.setSpeed(120);
    MotorKi.setSpeed(120);
    MotorKa.run(BACKWARD);
    MotorKi.run(BACKWARD);
  } else if (kanan) {
    MotorKa.setSpeed(120);
    MotorKi.setSpeed(120);
    MotorKa.run(BACKWARD);
    MotorKi.run(FORWARD);
  } else if (kiri) {
    MotorKa.setSpeed(120);
    MotorKi.setSpeed(120);
    MotorKa.run(FORWARD);
    MotorKi.run(BACKWARD);
  } else {
    MotorKa.run(RELEASE);
    MotorKi.run(RELEASE);
  }
  delay(150);
}

void rotate45left() {
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(FORWARD);
  MotorKi.run(BACKWARD);
  delay(200);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
}

void rotate45right() {
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(BACKWARD);
  MotorKi.run(FORWARD);
  delay(200);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
}

void rotate90left() {
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(FORWARD);
  MotorKi.run(BACKWARD);
  delay(695);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
}

void rotate90right() {
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(BACKWARD);
  MotorKi.run(FORWARD);
  delay(704);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
}

void rotate180left() {
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(FORWARD);
  MotorKi.run(BACKWARD);
  delay(1215);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
}

void rotate180right() {
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(BACKWARD);
  MotorKi.run(FORWARD);
  delay(1150);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
}

void rotate360() {
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(BACKWARD);
  MotorKi.run(FORWARD);
  delay(2300);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
}

void allMove() {
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(FORWARD);
  MotorKi.run(BACKWARD);
  delay(695);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
  delay(500);
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(FORWARD);
  MotorKi.run(FORWARD);
  delay(1000);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
  delay(500);
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(FORWARD);
  MotorKi.run(BACKWARD);
  delay(695);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
  delay(500);
  MotorKa.setSpeed(180);
  MotorKi.setSpeed(180);
  MotorKa.run(FORWARD);
  MotorKi.run(FORWARD);
  delay(1700);
  MotorKa.run(RELEASE);
  MotorKi.run(RELEASE);
  delay(500);
  gripper.write(0);
}