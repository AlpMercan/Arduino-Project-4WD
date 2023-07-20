//Colour Code
// Define left color sensor pins
#define S2_left 3
#define S3_left 4
#define sensorOut_left 5
// Define right color sensor pins
#define S2_right 8
#define S3_right 9
#define sensorOut_right 10
// Define button
#define button 11
#define r_led 6
#define g_led 7
#define b_led 2
#define ledPin 1
#define ledPin_1 7
#define ledPin_2 2
const int r_button = A0;
const int g_button = A1;
const int b_button = A4;
const int start_output = A2;
const int start_button_mode = A3;
// Calibration values
const int redMin=30;
const int redMax=195;
const int greenMin=27;
const int greenMax=187;
const int blueMin=28;
const int blueMax=162;
const int stepPin_l = 13;
const int stepPin_r = 12;
const int stepsPerRevolution_l = 2200;
const int stepsPerRevolution_r = 2200;
int color_l = 0;
int color_r = 0;
int red_counter_l = 0;
int green_counter_l = 0;
int blue_counter_l = 0;
int red_counter_r = 0;
int green_counter_r = 0;
int blue_counter_r = 0;
int selected_color = 0;
// counters
int leftCounter = 0;
int rightCounter = 0;
const int CoMmUnIcAtE = A5;
void setup() {
pinMode(button,INPUT);
pinMode(CoMmUnIcAtE, OUTPUT);
digitalWrite(CoMmUnIcAtE, LOW);
pinMode(r_button, INPUT);
pinMode(g_button, INPUT);
pinMode(b_button, INPUT);
pinMode(stepPin_l, OUTPUT);
pinMode(stepPin_r, OUTPUT);
pinMode(S2_left, OUTPUT);
pinMode(S3_left, OUTPUT);
pinMode(sensorOut_left, INPUT);
pinMode(S2_right, OUTPUT);
pinMode(S3_right, OUTPUT);
pinMode(sensorOut_right, INPUT);
// Set Pulse Width scaling to 20% for both sensors
pinMode(ledPin, OUTPUT);
pinMode(ledPin_1, OUTPUT);
pinMode(ledPin_2, OUTPUT);
pinMode(r_led, OUTPUT);
pinMode(g_led, OUTPUT);
pinMode(b_led, OUTPUT);
pinMode(start_button_mode, INPUT);
pinMode(start_output, OUTPUT);
digitalWrite(start_output, LOW);
Serial.begin(9600);
}
void loop() {
if (digitalRead(r_button) == HIGH) {
selected_color = 1;
digitalWrite(r_led, LOW);
digitalWrite(g_led, HIGH);
digitalWrite(b_led, HIGH);
Serial.println("RED!");
}
else if (digitalRead(g_button) == HIGH) {
selected_color = 2;
digitalWrite(r_led, HIGH);
digitalWrite(g_led, LOW);
digitalWrite(b_led, HIGH);
Serial.println("GREEN!");
}
else if (digitalRead(b_button) == HIGH) {
selected_color = 3;
digitalWrite(r_led, HIGH);
digitalWrite(g_led, HIGH);
digitalWrite(b_led, LOW);
Serial.println("BLUE!");
} else {
}
(digitalRead(start_button_mode) == HIGH) {
if (selected_color == 1) {
digitalWrite(r_led, LOW);
digitalWrite(g_led, LOW);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, LOW);
digitalWrite(g_led, HIGH);
digitalWrite(b_led, HIGH);
delay(1000);
digitalWrite(r_led, LOW);
digitalWrite(g_led, LOW);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, LOW);
digitalWrite(g_led, HIGH);
digitalWrite(b_led, HIGH);
delay(1000);
digitalWrite(r_led, LOW);
digitalWrite(g_led, LOW);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, LOW);
digitalWrite(g_led, HIGH);
digitalWrite(b_led, HIGH);
delay(1000);
digitalWrite(start_output, HIGH);
}
else if (selected_color == 2) {
digitalWrite(r_led, LOW);
digitalWrite(g_led, LOW);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, HIGH);
digitalWrite(g_led, LOW);
digitalWrite(b_led, HIGH);
delay(1000);
digitalWrite(r_led, LOW);
digitalWrite(g_led, LOW);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, HIGH);
digitalWrite(g_led, LOW);
digitalWrite(b_led, HIGH);
delay(1000);
digitalWrite(r_led, LOW);
digitalWrite(g_led, LOW);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, HIGH);
digitalWrite(g_led, LOW);
digitalWrite(b_led, HIGH);
delay(1000);
digitalWrite(start_output, HIGH);
}
else if (selected_color == 3) {
digitalWrite(r_led, LOW);
digitalWrite(g_led, LOW);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, HIGH);
digitalWrite(g_led, HIGH);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, LOW);
digitalWrite(g_led, LOW);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, HIGH);
digitalWrite(g_led, HIGH);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, LOW);
digitalWrite(g_led, LOW);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(r_led, HIGH);
digitalWrite(g_led, HIGH);
digitalWrite(b_led, LOW);
delay(1000);
digitalWrite(start_output, HIGH);
} else {
}
} else {
}
if (digitalRead(button) == HIGH) {
int color_l = SeNsOr_CoLoR(S2_left, S3_left, sensorOut_left);
int color_r = SeNsOr_CoLoR(S2_right, S3_right, sensorOut_right);
Serial.print("Color = L: ");
Serial.print(color_l);
Serial.print(" R: ");
Serial.println(color_r);
if (color_l == selected_color && color_r == selected_color) {
digitalWrite(ledPin, HIGH);
digitalWrite(ledPin_2, HIGH);
RuN_BoTh(stepPin_l, stepPin_r, stepsPerRevolution_l);
digitalWrite(ledPin, LOW);
digitalWrite(ledPin_2, LOW);
leftCounter++;
rightCounter++;
}
else if (color_l == selected_color) {
leftCounter++;
if (leftCounter > 2) {
digitalWrite(CoMmUnIcAtE, HIGH);
delay(5);
Serial.println("Ezgi <3");
digitalWrite(CoMmUnIcAtE, LOW);
delay(4000);
StEp_RuN(stepPin_l, stepsPerRevolution_l);
} else {
digitalWrite(ledPin, HIGH);
StEp_RuN(stepPin_l, stepsPerRevolution_l);
digitalWrite(ledPin, LOW);
Serial.println("left !");
}
}
else if (color_r == selected_color) {
digitalWrite(ledPin_2, HIGH);
StEp_RuN(stepPin_r, stepsPerRevolution_r);
digitalWrite(ledPin_2, LOW);
Serial.println("right !");
rightCounter++;
}
if (color_l != selected_color && color_r != selected_color) {
digitalWrite(ledPin, LOW);
digitalWrite(ledPin_2, LOW);
}
}
}
///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void StEp_RuN(const int stepPin, const int stepsPerRevolution) {
for (int x = 0; x < stepsPerRevolution; x++) {
digitalWrite(stepPin, HIGH);
delayMicroseconds(650);
digitalWrite(stepPin, LOW);
delayMicroseconds(1000);
}
}
void StEp_RuN_BoTh(const int stepPin_1, const int stepPin_2, const int
stepsPerRevolution) {
for (int x = 0; x < stepsPerRevolution; x++) {
digitalWrite(stepPin_1, HIGH);
digitalWrite(stepPin_2, HIGH);
delayMicroseconds(650);
digitalWrite(stepPin_1, LOW);
digitalWrite(stepPin_2, LOW);
delayMicroseconds(1000);
}
}
int SeNsOr_CoLoR(const int s_2, const int s_3, const int sens_out) {
const int redMin=30;
const int redMax=195;
const int greenMin=27;
const int greenMax=187;
const int blueMin=28;
const int blueMax=162;
int red_sum = 0;
int green_sum = 0;
int blue_sum = 0;
for (int i = 0; i < 5; i++) {
digitalWrite(s_2, LOW);
digitalWrite(s_3, LOW);
int red = pulseIn(sens_out, LOW);
digitalWrite(s_2, HIGH);
digitalWrite(s_3, HIGH);
int green = pulseIn(sens_out, LOW);
digitalWrite(s_2, HIGH);
digitalWrite(s_3, LOW);
int blue = pulseIn(sens_out, LOW);
int red_value = map(red, redMin, redMax, 255, 0);
int green_value = map(green, greenMin, greenMax, 255, 0);
int blue_value = map(blue, blueMin, blueMax, 255, 0);
red_sum += red_value;
green_sum += green_value;
blue_sum += blue_value;
}
int color = 0;
if ((red_sum > green_sum) && (red_sum > blue_sum)) {
color = 1;
} else if ((green_sum > red_sum) && (green_sum > blue_sum)) {
color = 2;
} else if ((blue_sum > green_sum) && (blue_sum > red_sum)) {
color = 3;
21
}
return color;
}







//Shield Code:
#include <AFMotor.h>
#include <Servo.h>
#define output_button 9
#define start_button 13
const int trigPin_1 = A1;
const int echoPin_1 = A0;
const int trigPin_2 = A2;
const int echoPin_2 = A3;
const int trigPin_3 = A5;
const int echoPin_3 = A4;
float duration_1, distance_1, duration_2, distance_2;
const int interruptPin2 = 2;
volatile bool interruptTriggered2 = false;
const int interruptPin10 = 10;
volatile bool interruptTriggered10 = false;
int flag = 0;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
void setup() {
motor1.setSpeed(100);
motor2.setSpeed(110);
motor3.setSpeed(155);
motor4.setSpeed(140);
pinMode(trigPin_1, OUTPUT);
pinMode(echoPin_1, INPUT);
pinMode(trigPin_2, OUTPUT);
pinMode(echoPin_2, INPUT);
pinMode(trigPin_3, OUTPUT);
pinMode(echoPin_3, INPUT);
pinMode(output_button,OUTPUT);
pinMode(start_button,INPUT);
pinMode(interruptPin2, INPUT);
attachInterrupt(digitalPinToInterrupt(interruptPin2), handleInterrupt2, RISING);
pinMode(interruptPin10, INPUT);
//attachInterrupt(digitalPinToInterrupt(interruptPin10), handleInterrupt,
RISING);
digitalWrite(output_button, LOW);
Serial.begin(9600);
}
void loop() {
if (digitalRead(start_button) == HIGH) {
delay(2000);
//FoRwArd_DiStAnCe(40);
FoRwArd(7000);
//digitalWrite(output_button, HIGH);
//delay(5);
//digitalWrite(output_button, LOW);
delay(10000);
SiDe_DiStAnCe(15);
delay(10000);
SiDe_R(1000);
delay(1000);
FoRwArd_R(2000);
delay(1000);
RoTaTE(2500);
FoRwArd_DiStAnCe(35);
delay(1000);
SiDe_DiStAnCe(20);
delay(1000);
FoRwArd_DiStAnCe(10);
}
}
///////////////////////////////////////////////////////////////////////////////////
///////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////
void FoRwArd(int DeLaY) {
motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(FORWARD);
delay(DeLaY);
}
void FoRwArd_R(int DeLaY) {
motor1.run(BACKWARD);
motor2.run(BACKWARD);
motor3.run(BACKWARD);
motor4.run(BACKWARD);
delay(DeLaY);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
void FoRwArd_DiStAnCe(float DiStAnCe) {
float currentDistance = ChEcK_DiStAnCe(trigPin_1, echoPin_1);
float sideDistance2 = ChEcK_DiStAnCe(trigPin_2, echoPin_2);
float sideDistance3 = ChEcK_DiStAnCe(trigPin_3, echoPin_3);
while (currentDistance > DiStAnCe) {
FoRwArd(50);
currentDistance = ChEcK_DiStAnCe(trigPin_1, echoPin_1);
sideDistance2 = ChEcK_DiStAnCe(trigPin_2, echoPin_2);
sideDistance3 = ChEcK_DiStAnCe(trigPin_3, echoPin_3);
float tilt = sideDistance2-sideDistance3;
Serial.println(currentDistance);
if (abs(tilt) > 0.2) {
if (tilt > 0.2) {
motor1.setSpeed(100);
motor2.setSpeed(110+20);
motor3.setSpeed(155+20);
motor4.setSpeed(140);
}
else if (tilt < -0.2) {
motor1.setSpeed(100+20);
motor2.setSpeed(110);
motor3.setSpeed(155);
motor4.setSpeed(140+20);
} else {
motor1.setSpeed(100);
motor2.setSpeed(110);
motor3.setSpeed(155);
motor4.setSpeed(140);
}
}
}
motor1.setSpeed(100);
motor2.setSpeed(110);
motor3.setSpeed(155);
motor4.setSpeed(140);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
void SiDe(int DeLaY) {
motor1.run(BACKWARD);
motor2.run(FORWARD);
motor3.run(BACKWARD);
motor4.run(FORWARD);
delay(DeLaY);
}
void SiDe_R(int DeLaY) {
motor1.setSpeed(100 + 10);
motor2.setSpeed(110 + 30);
motor4.setSpeed(140 + 20);
motor1.run(FORWARD);
motor2.run(BACKWARD);
motor3.run(FORWARD);
motor4.run(BACKWARD);
delay(DeLaY);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
motor1.setSpeed(100);
motor2.setSpeed(110);
motor4.setSpeed(140);
}
void SiDe_DiStAnCe(float DiStAnCe) {
digitalWrite(output_button, HIGH);
delay(10);
digitalWrite(output_button, LOW);
delay(4000);
float sideDistance2 = ChEcK_DiStAnCe(trigPin_2, echoPin_2);
float sideDistance3 = ChEcK_DiStAnCe(trigPin_3, echoPin_3);
while (sideDistance2 > DiStAnCe) {
if (flag == 1) {
delay(2000);
RoTaTE(2975);
delay(4000);
RoTaTE(2975);
flag = 0;
}
SiDe(50);
sideDistance2 = ChEcK_DiStAnCe(trigPin_2, echoPin_2);
sideDistance3 = ChEcK_DiStAnCe(trigPin_3, echoPin_3);
float tilt = sideDistance2 - sideDistance3;
Serial.println(sideDistance2);
if (tilt > 0.3) {
motor1.setSpeed(110 + 5);
motor2.setSpeed(147 + 5);
motor3.setSpeed(153 - 10);
motor4.setSpeed(153 - 10);
}
else if (tilt < -0.3) {
motor1.setSpeed(110 - 10);
motor2.setSpeed(147 - 10);
motor3.setSpeed(153 + 5);
motor4.setSpeed(153 + 5);
} else {
motor1.setSpeed(110);
motor2.setSpeed(147);
motor3.setSpeed(153);
motor4.setSpeed(153);
}
if (115 < sideDistance2 && sideDistance2 < 133) {
digitalWrite(output_button, HIGH);
delay(20);
Serial.println("Working");
digitalWrite(output_button, LOW);
}
else if (67 < sideDistance2 && sideDistance2 < 85) {
digitalWrite(output_button, HIGH);
delay(20);
Serial.println("Working");
digitalWrite(output_button, LOW);
}
else if (DiStAnCe + 10 < sideDistance2 && sideDistance2 < 35) {
digitalWrite(output_button, HIGH);
delay(20);
digitalWrite(output_button, LOW);
}
else {
digitalWrite(output_button, LOW);
delay(20);
}
}
motor1.setSpeed(110);
motor2.setSpeed(147);
motor3.setSpeed(153);
motor4.setSpeed(153);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
void RoTaTE(int DeLaY) {
motor1.run(FORWARD);
motor2.run(BACKWARD);
motor3.run(BACKWARD);
motor4.run(FORWARD);
delay(DeLaY);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
void RoTaTE_R(int DeLaY) {
motor1.run(BACKWARD);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(BACKWARD);
delay(DeLaY);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
//void handleInterrupt2() {
//interruptTriggered2 = true;
//unsigned long interruptTime2 = 0;
//const unsigned long interruptDelay2 = 5000;
//Serial.println("Interrupt occurred!");
//interruptTime2 = millis(); // Zaman damgasını al
//while (millis() - interruptTime2 < interruptDelay2) {
//}
//Serial.println("Interrupt finished!");
//}
void handleInterrupt2() {
interruptTriggered2 = true;
Serial.println("Interrupt occurred!");
flag = 1;
Serial.println("Interrupt finished!");
}
float ChEcK_DiStAnCe(const int trigPin1, const int echoPin1) {
digitalWrite(trigPin1, LOW);
delayMicroseconds(1);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin1, LOW);
float duration1 = pulseIn(echoPin1, HIGH);
float distance1 = (duration1/2) * 0.0343;
return distance1;
}
void ChEcK_PoSiTaTiOn() {
for (int i = 0; i < 10; i++) {
float dist1 = ChEcK_DiStAnCe(trigPin_1, echoPin_1);
if (dist1 <37) { //37.5
FoRwArd_R(50);
}
if (dist1 > 36.5) { //38.5
FoRwArd(50);
}
delay(500);
}
delay(500);
delay(5000);
for (int i = 0; i < 5; i++) {
float dist2 = ChEcK_DiStAnCe(trigPin_2, echoPin_2);
float dist3 = ChEcK_DiStAnCe(trigPin_3, echoPin_3);
float dist_side = (dist2+dist3)/2;
if (dist_side < 184.5) { //184.5
SiDe(50);
}
if (dist_side > 185.5) { //185.5
SiDe_R(50);
}
}
for (int i = 0; i < 40; i++) {
float dist2 = ChEcK_DiStAnCe(trigPin_2, echoPin_2);
float dist3 = ChEcK_DiStAnCe(trigPin_3, echoPin_3);
float tilt = dist2-dist3;
if (abs(tilt) > 0.3) {
(0.15 < tilt) {
RoTaTE_R(30);
}
if (tilt < -0.15) {
RoTaTE(30);
}
delay(500);
}
delay(500);
}
}
