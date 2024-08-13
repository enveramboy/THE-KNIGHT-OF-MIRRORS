#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Ps3Controller.h>

// PCA9685 SETUP
Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver(0x40);
#define SERVO_MIN 125
#define SERVO_MAX 575

// GAIT & ANIMATIONS
int angleToPulse(int ang) {
  int pulse = map(ang, 0, 180, SERVO_MIN, SERVO_MAX);
  return pulse;
}

volatile int o1 = 60;
volatile int o3 = 0;
volatile int o5 = 60;
volatile int o7 = 0;

volatile int lunge = 0;
// aX[0] = orient value, aX[1] = thrust value
volatile int a2[2] = {70, 110};
volatile int a6[2] = {110, 70};
volatile int a0[2] = {70, 110};
volatile int a4[2] = {110, 70};

void idle() {
  // Setup Thigh Orientation
  board.setPWM(0, 0, angleToPulse(90));
  board.setPWM(2, 0, angleToPulse(90));
  board.setPWM(4, 0, angleToPulse(90));
  board.setPWM(6, 0, angleToPulse(90));

  // Setup Leg Orientation
  board.setPWM(1, 0, angleToPulse(o1));
  board.setPWM(3, 0, angleToPulse(o3));
  board.setPWM(5, 0, angleToPulse(o5));
  board.setPWM(7, 0, angleToPulse(o7));
}

void forward(unsigned long spd) {
  unsigned long delta = millis() % spd;
  if (delta < ((1*spd)/4)) {
    // Left Diagonal Raise
    board.setPWM(1, 0, angleToPulse(0));
    board.setPWM(5, 0, angleToPulse(0));
    board.setPWM(0, 0, angleToPulse(90));
    board.setPWM(4, 0, angleToPulse(90));

    // Right Diagonal Thrust
    board.setPWM(2, 0, angleToPulse(a2[1]));
    board.setPWM(6, 0, angleToPulse(a6[1]));
  }
  else if (delta < ((2*spd)/4)) {
    // Left Diagonal Lower
    board.setPWM(0, 0, angleToPulse(a0[0]));
    board.setPWM(4, 0, angleToPulse(a4[0]));
    board.setPWM(1, 0, angleToPulse(o1));
    board.setPWM(5, 0, angleToPulse(o5));
  }
  else if (delta < ((3*spd)/4)) {
    // Right Diagonal Raise
    board.setPWM(3, 0, angleToPulse(60));
    board.setPWM(7, 0, angleToPulse(60));
    board.setPWM(2, 0, angleToPulse(90));
    board.setPWM(6, 0, angleToPulse(90));

    // Left Diagonal Thrust
    board.setPWM(0, 0, angleToPulse(a0[1]));
    board.setPWM(4, 0, angleToPulse(a4[1]));
  }
  else {
    // Right Diagonal Lower
    board.setPWM(2, 0, angleToPulse(a2[0]));
    board.setPWM(6, 0, angleToPulse(a6[0]));
    board.setPWM(3, 0, angleToPulse(o3));
    board.setPWM(7, 0, angleToPulse(o7));
  }
}

void backward(unsigned long spd) {
  unsigned long delta = millis() % spd;
  if (delta < ((1*spd)/4)) {
    // Left Diagonal Raise
    board.setPWM(1, 0, angleToPulse(0));
    board.setPWM(5, 0, angleToPulse(0));
    board.setPWM(0, 0, angleToPulse(90));
    board.setPWM(4, 0, angleToPulse(90));

    // Right Diagonal Thrust
    board.setPWM(2, 0, angleToPulse(a2[0]));
    board.setPWM(6, 0, angleToPulse(a6[0]));
  }
  else if (delta < ((2*spd)/4)) {
    // Left Diagonal Lower
    board.setPWM(0, 0, angleToPulse(a0[1]));
    board.setPWM(4, 0, angleToPulse(a4[1]));
    board.setPWM(1, 0, angleToPulse(o1));
    board.setPWM(5, 0, angleToPulse(o5));
  }
  else if (delta < ((3*spd)/4)) {
    // Right Diagonal Raise
    board.setPWM(3, 0, angleToPulse(60));
    board.setPWM(7, 0, angleToPulse(60));
    board.setPWM(2, 0, angleToPulse(90));
    board.setPWM(6, 0, angleToPulse(90));

    // Left Diagonal Thrust
    board.setPWM(0, 0, angleToPulse(a0[0]));
    board.setPWM(4, 0, angleToPulse(a4[0]));
  }
  else {
    // Right Diagonal Lower
    board.setPWM(2, 0, angleToPulse(a2[1]));
    board.setPWM(6, 0, angleToPulse(a6[1]));
    board.setPWM(3, 0, angleToPulse(o3));
    board.setPWM(7, 0, angleToPulse(o7));
  }
}

void left(unsigned long spd) {
  unsigned long delta = millis() % spd;
  if (delta < ((1*spd)/4)) {
    // Left Diagonal Raise
    board.setPWM(1, 0, angleToPulse(0));
    board.setPWM(5, 0, angleToPulse(0));
    board.setPWM(0, 0, angleToPulse(90));
    board.setPWM(4, 0, angleToPulse(90));

    // Right Diagonal Thrust
    board.setPWM(2, 0, angleToPulse(a2[0]));
    board.setPWM(6, 0, angleToPulse(a6[1]));
  }

  else if (delta < ((2*spd)/4)) {
    // Left Diagonal Lower
    board.setPWM(0, 0, angleToPulse(a0[1]));
    board.setPWM(4, 0, angleToPulse(a4[0]));
    board.setPWM(1, 0, angleToPulse(o1));
    board.setPWM(5, 0, angleToPulse(o5));
  }

  else if (delta < ((3*spd)/4)) {
    // Right Diagonal Raise
    board.setPWM(3, 0, angleToPulse(60));
    board.setPWM(7, 0, angleToPulse(60));
    board.setPWM(2, 0, angleToPulse(90));
    board.setPWM(6, 0, angleToPulse(90));

    // Left Diagonal Thrust
    board.setPWM(0, 0, angleToPulse(a0[0]));
    board.setPWM(4, 0, angleToPulse(a4[1]));
  }

  else {
    // Right Diagonal Lower
    board.setPWM(2, 0, angleToPulse(a2[1]));
    board.setPWM(6, 0, angleToPulse(a6[0]));
    board.setPWM(3, 0, angleToPulse(o3));
    board.setPWM(7, 0, angleToPulse(o7));
  }
}

void right(unsigned long spd) {
  unsigned long delta = millis() % spd;
  if (delta < ((1*spd)/4)) {
    // Left Diagonal Raise
    board.setPWM(1, 0, angleToPulse(0));
    board.setPWM(5, 0, angleToPulse(0));
    board.setPWM(0, 0, angleToPulse(90));
    board.setPWM(4, 0, angleToPulse(90));

    // Right Diagonal Thrust
    board.setPWM(2, 0, angleToPulse(a2[1]));
    board.setPWM(6, 0, angleToPulse(a6[0]));
  }

  else if (delta < ((2*spd)/4)) {
    // Left Diagonal Lower
    board.setPWM(0, 0, angleToPulse(a0[0]));
    board.setPWM(4, 0, angleToPulse(a4[1]));
    board.setPWM(1, 0, angleToPulse(o1));
    board.setPWM(5, 0, angleToPulse(o5));
  }

  else if (delta < ((3*spd)/4)) {
    // Right Diagonal Raise
    board.setPWM(3, 0, angleToPulse(60));
    board.setPWM(7, 0, angleToPulse(60));
    board.setPWM(2, 0, angleToPulse(90));
    board.setPWM(6, 0, angleToPulse(90));

    // Left Diagonal Thrust
    board.setPWM(0, 0, angleToPulse(a0[1]));
    board.setPWM(4, 0, angleToPulse(a4[0]));
  }

  else {
    // Right Diagonal Lower
    board.setPWM(2, 0, angleToPulse(a2[0]));
    board.setPWM(6, 0, angleToPulse(a6[1]));
    board.setPWM(3, 0, angleToPulse(o3));
    board.setPWM(7, 0, angleToPulse(o7));
  }
}

// PS3 SETUP
volatile int states[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
volatile int pace = 1000;
volatile int head_pos = 110;

void notify() {
  // D-pad Buttons State
  if (Ps3.event.button_down.up) { states[0] = 1; }
  if (Ps3.event.button_up.up) {states[0] = 0; }

  if (Ps3.event.button_down.right) { states[1] = 1; }
  if (Ps3.event.button_up.right) { states[1] = 0; }

  if (Ps3.event.button_down.down) { states[2] = 1; }
  if (Ps3.event.button_up.down) { states[2] = 0; }

  if (Ps3.event.button_down.left) { states[3] = 1; }
  if (Ps3.event.button_up.left) { states[3] = 0; }

  // Middle Buttons State
  if (Ps3.event.button_down.select) { states[4] = 1; }
  if (Ps3.event.button_up.select) { states[4] = 0; }

  if (Ps3.event.button_down.ps) { states[5] = 1; }
  if (Ps3.event.button_up.ps) { states[5] = 0; }

  if (Ps3.event.button_down.start) { states[6] = 1; }
  if (Ps3.event.button_up.start) { states[6] = 0; }

  // Geometry Buttons State
  if (Ps3.event.button_down.triangle) { states[7] = 1; lunge++; }
  if (Ps3.event.button_up.triangle) { states[7] = 0; }

  if (Ps3.event.button_down.circle) { states[8] = 1; }
  if (Ps3.event.button_up.circle) { states[8] = 0; }

  if (Ps3.event.button_down.cross) { states[9] = 1; }
  if (Ps3.event.button_up.cross) { states[9] = 0; }

  if (Ps3.event.button_down.square) { states[10] = 1; board.setPWM(9, 0, angleToPulse(45)); }
  if (Ps3.event.button_up.square) { states[10] = 0; board.setPWM(9, 0, angleToPulse(0)); }

  // Shoulder Buttons State
  if (Ps3.event.button_down.l1) { states[11] = 1; o1 = 30; o3 = 30; o5 = 30; o7 = 30; }
  if (Ps3.event.button_up.l1) { states[11] = 0; o1 = 60; o3 = 0; o5 = 60; o7 = 0; }

  if (Ps3.event.button_down.l2) { states[12] = 1; }
  if (Ps3.event.button_up.l2) { states[12] = 0; }

  if (Ps3.event.button_down.r1) { states[13] = 1; pace = 750; }
  if (Ps3.event.button_up.r1) { states[13] = 0; pace = 1000; }

  if (Ps3.event.button_down.r2) { states[14] = 1;  }
  if (Ps3.event.button_up.r2) { states[14] = 0; }
}

void onConnect() {
  Ps3.setPlayer(7);
}

void setup() {
  board.begin();
  board.setPWMFreq(60);
  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("2c:81:58:3a:93:f7");
}

void loop() {
  if (!Ps3.isConnected()) return;

  if (states[14] == 1 && head_pos != 0) head_pos--;
  if (states[12] == 1 && head_pos != 180) head_pos++;
  board.setPWM(8, 0, angleToPulse(head_pos));

  if (lunge % 2 == 0) {
    a2[0] = 80; a2[1] = 100;
    a6[0] = 100; a6[1] = 80;
    a0[0] = 80; a0[1] = 100;
    a4[0] = 100; a4[1] = 80;
  }
  else {
    a2[0] = 60; a2[1] = 120;
    a6[0] = 120; a6[1] = 60;
    a0[0] = 60; a0[1] = 120;
    a4[0] = 120; a4[1] = 60;
  }

  int y = Ps3.data.analog.stick.ly;
  int x = Ps3.data.analog.stick.rx;
  if (y > 10) backward(pace);
  else if (y < -10) forward(pace);
  else if (x > 10) right(pace);
  else if (x < -10) left(pace);

  else idle();
}