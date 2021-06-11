#include <Arduino.h>
 
uint8_t stepper0[] = {D1, D2, D3, D4};
uint8_t motor_A[] = {D5, D6, D7, D8};

uint8_t stepper_states [4][4] =
{
   {HIGH, LOW , LOW , LOW }
  ,{LOW , HIGH, LOW , LOW }
  ,{LOW , LOW , HIGH, LOW }
  ,{LOW , LOW , LOW , HIGH}
};

// stepper motor control pins
#define IN0   D0
#define IN1   D1   // IN1 is connected to NodeMCU pin D1 (GPIO5)
#define IN2   D2   // IN2 is connected to NodeMCU pin D2 (GPIO4)
#define IN3   D3   // IN3 is connected to NodeMCU pin D3 (GPIO0)
#define IN4   D4   // IN4 is connected to NodeMCU pin D4 (GPIO2)
#define IN5   D5   // IN1 is connected to NodeMCU pin D1 (GPIO5)
#define IN6   D6   // IN2 is connected to NodeMCU pin D2 (GPIO4)
#define IN7   D7   // IN3 is connected to NodeMCU pin D3 (GPIO0)
#define IN8   D8   // IN4 is connected to NodeMCU pin D4 (GPIO2)
#define t   2500


int step_number = 0;

 
// void OneStep(uint8_t stepper[], bool dir)
// {
//   if(dir)
//   {
//     Serial.println("first loop");
//     switch(step_number)
//     {
//       case 0:
//       digitalWrite(stepper[0], HIGH);
//       digitalWrite(stepper[1], LOW);
//       digitalWrite(stepper[2], LOW);
//       digitalWrite(stepper[3], LOW);
//       break;
//       case 1:
//       digitalWrite(stepper[0], LOW);
//       digitalWrite(stepper[1], HIGH);
//       digitalWrite(stepper[2], LOW);
//       digitalWrite(stepper[3], LOW);
//       break;
//       case 2:
//       digitalWrite(stepper[0], LOW);
//       digitalWrite(stepper[1], LOW);
//       digitalWrite(stepper[2], HIGH);
//       digitalWrite(stepper[3], LOW);
//       break;
//       case 3:
//       digitalWrite(stepper[0], LOW);
//       digitalWrite(stepper[1], LOW);
//       digitalWrite(stepper[2], LOW);
//       digitalWrite(stepper[3], HIGH);
//       break;
//     } 
//     delayMicroseconds (t);
//   }
//   else
//   {
//     Serial.println("second loop");
//     switch(step_number)
//     {
//       case 0:
//       digitalWrite(stepper[0], LOW);
//       digitalWrite(stepper[1], LOW);
//       digitalWrite(stepper[2], LOW);
//       digitalWrite(stepper[3], HIGH);
//       break;
//       case 1:
//       digitalWrite(stepper[0], LOW);
//       digitalWrite(stepper[1], LOW);
//       digitalWrite(stepper[2], HIGH);
//       digitalWrite(stepper[3], LOW);
//       break;
//       case 2:
//       digitalWrite(stepper[0], LOW);
//       digitalWrite(stepper[1], HIGH);
//       digitalWrite(stepper[2], LOW);
//       digitalWrite(stepper[3], LOW);
//       break;
//       case 3:
//       digitalWrite(stepper[0], HIGH);
//       digitalWrite(stepper[1], LOW);
//       digitalWrite(stepper[2], LOW);
//       digitalWrite(stepper[3], LOW);
//     } 
//     delayMicroseconds (t);
//   }
//   step_number++;
//   if(step_number > 3)
//   {
//       step_number = 0;
//   }
//   yield();
// }

void setup(void)
{
  // pinMode(IN1, OUTPUT);
  // pinMode(IN2, OUTPUT);
  // pinMode(IN3, OUTPUT);
  // pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  Serial.begin(9600);

}
 
// main loop
void loop()
{

    for (int row=0; row<4; row++)
    {
        digitalWrite(motor_A[0], stepper_states[row][3]);
        digitalWrite(motor_A[1], stepper_states[row][2]);
        digitalWrite(motor_A[2], stepper_states[row][1]);
        digitalWrite(motor_A[3], stepper_states[row][0]);
        delayMicroseconds (t);
    } 
    yield();

}
