/*
 * Project: Arduino Multitask
 * Author: Eng. Matheus Toledo
 * Date: 22/03/2024
*/

// Definitions
#define LED1        PB1
#define LED2        PB2
#define LED3        PB3
#define DELAY_TIME  1000 // ms

// Global Variables
unsigned long timer1 = 0;
unsigned long timer2 = 0;
unsigned long timer3 = 0;

// Auxiliar functions
//********************************************************************************
int8_t task1(void)
{
  
  static bool ledState = true;

  ledState = !ledState;
  digitalWrite(LED1, ledState);

  Serial.println("Task-1");

  return 0;

}
//********************************************************************************
int8_t task2(void)
{
  
  static bool ledState = true;

  ledState = !ledState;
  digitalWrite(LED2, ledState);

  Serial.println("Task-2");

  return 0;

}
//********************************************************************************
int8_t task3(void)
{
  
  static bool ledState = true;

  ledState = !ledState;
  digitalWrite(LED3, ledState);

  Serial.println("Task-3");

  return 0;

}
//********************************************************************************
void task_management_thread()
{
  if((millis() - timer1) > 999)
  {
    task1();
    timer1 = millis();
  }

  if(millis() - timer2 > 4999)
  {
    task2();
    timer2 = millis();
  }

  if(millis() - timer3 > 9999)
  {
    task3();
    timer3 = millis();
  }
}

// main code
void setup() 
{

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  timer1 = millis();
  timer2 = millis();
  timer3 = millis();

  Serial.begin(9600);

}

void loop() 
{
  task_management_thread();
}
