
//-----------------------------------------------------------------------------
// Program: BlynkServo
// Author:  Don Potbury
// Description:
//    This program controls a servo and a stepper motor
//-----------------------------------------------------------------------------

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

uint8_t pan_motor[] = {D5, D6, D7, D8};

uint8_t stepper_states [4][4] =
{
   {HIGH, LOW , LOW , LOW }
  ,{LOW , HIGH, LOW , LOW }
  ,{LOW , LOW , HIGH, LOW }
  ,{LOW , LOW , LOW , HIGH}
};

#define IN4   D4   
#define IN5   D5   
#define IN6   D6   
#define IN7   D7   
#define IN8   D8   
#define speed   2500

Servo myservo;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "91ye5LuZciZSA0qM0YDyn2Qr2ixBFWQm";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "FiOS-9HVM3";
char pass[] = "rod472frog3429cat";

//char ssid[] = "Production-Wifi";
//char pass[] = "Goldfish01";


Servo servo;

int cw = 0;
int ccw = 0;


// Focus Left
BLYNK_WRITE(V0)
{
  //servo.write(param.asInt());
  int pos = param.asInt();
  ccw = pos;
  Serial.println(pos);
}

// Focus Right
BLYNK_WRITE(V1)
{
  int pos = param.asInt();
  cw = pos;
  Serial.println(pos);
}

// Zoom In
BLYNK_WRITE(V2)
{
  int pos = param.asInt();
  if (pos == 0)
  {
    myservo.write(90);
  }
  else
  {
    myservo.write(70);
  }
}

// Zoom Out
BLYNK_WRITE(V3)
{
  int pos = param.asInt();
  if (pos == 0)
  {
    myservo.write(90);
  }
  else
  {
    myservo.write(120);
  }
}

void setup()
{
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  myservo.attach(D4);
  myservo.write(90);
  Serial.begin(9600);
  
  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();  

  if (ccw == 1)
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


  if (cw == 1)
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
}
