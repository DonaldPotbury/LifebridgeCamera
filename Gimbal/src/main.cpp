#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
#define IN1   D1
#define IN2   D2
#define IN3   D3
#define IN4   D4
#define IN5   D5
#define IN6   D6
#define IN7   D7
#define IN8   D8


char auth[] = "NVzyY4H6Lu32A0COo33CwVS7oJRvjJD1";
char ssid[] = "FiOS-9HVM3";
char pass[] = "rod472frog3429cat";

//char ssid[] = "Production-Wifi";
//char pass[] = "Goldfish01";

int vpins[4] = {0,0,0,0};
int speed    = 3000;

// Stepper Motor Pins
uint8_t pan_motor[4] = {D1, D2, D3, D4};
uint8_t tilt_motor[4] = {D5, D6, D7, D8};

// states to increment the stepper 1 tick
uint8_t stepper_states [4][4] =
{
   {HIGH, LOW , LOW , LOW }
  ,{LOW , HIGH, LOW , LOW }
  ,{LOW , LOW , HIGH, LOW }
  ,{LOW , LOW , LOW , HIGH}
};

// Pan right
BLYNK_WRITE(V0)
{
  vpins[0] = param.asInt();
  Serial.println(vpins[0]);
}

// Pan left
BLYNK_WRITE(V1)
{
  vpins[1] = param.asInt();
  Serial.println(vpins[1]);
}

// 
BLYNK_WRITE(V2)
{
  vpins[2] = param.asInt();
  Serial.println(vpins[2]);
}

BLYNK_WRITE(V3)
{
  vpins[3] = param.asInt();
  Serial.println(vpins[3]);
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  // Init pins for the stepper motors
  for(int i=0; i<4; i++)
  {
    pinMode(pan_motor[i],OUTPUT);
    pinMode(tilt_motor[i],OUTPUT);
  }
}

void loop() {
  Blynk.run();

  if (vpins[0] == 1)
  {
    for (int row=0; row<4; row++)
    {
      digitalWrite(pan_motor[0], stepper_states[row][3]);
      digitalWrite(pan_motor[1], stepper_states[row][2]);
      digitalWrite(pan_motor[2], stepper_states[row][1]);
      digitalWrite(pan_motor[3], stepper_states[row][0]);
      delayMicroseconds (speed);
    } 
  }  
  if (vpins[1] == 1)
  {
    for (int row=0; row<4; row++)
    {
      digitalWrite(pan_motor[0], stepper_states[row][0]);
      digitalWrite(pan_motor[1], stepper_states[row][1]);
      digitalWrite(pan_motor[2], stepper_states[row][2]);
      digitalWrite(pan_motor[3], stepper_states[row][3]);
      delayMicroseconds (speed);
    } 
  }  

  if (vpins[2] == 1)
  {
    for (int row=0; row<4; row++)
    {
      digitalWrite(tilt_motor[0], stepper_states[row][0]);
      digitalWrite(tilt_motor[1], stepper_states[row][1]);
      digitalWrite(tilt_motor[2], stepper_states[row][2]);
      digitalWrite(tilt_motor[3], stepper_states[row][3]);
      delayMicroseconds (speed);
    } 
  }  
  if (vpins[3] == 1)
  {
    for (int row=0; row<4; row++)
    {
      digitalWrite(tilt_motor[0], stepper_states[row][3]);
      digitalWrite(tilt_motor[1], stepper_states[row][2]);
      digitalWrite(tilt_motor[2], stepper_states[row][0]);
      digitalWrite(tilt_motor[3], stepper_states[row][0]);
      delayMicroseconds (speed);
    } 
  }  
}