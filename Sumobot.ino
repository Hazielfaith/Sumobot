
#include <Ultrasonic.h>
Ultrasonic ultrasonic1(9, 10);
Ultrasonic ultrasonic2(12, 11);
Ultrasonic ultrasonic3(A1, A0);
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;
int Speed = 0;
int USR, USL, USF;
int FSL, FSR, FSB;

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  delay(3900);
}
void loop()
{

  SensorUpdate();    


  if (USR<=15)
    {  switch(FSB)
      {
        case 1:
        BACKleft();
        delay(1000);
        Speed=255;
        FORWARD();
        delay(1000);
        Stop();
        SensorUpdate();
        break;
        
        case 0:
          Speed=255;
          FORWARD();
          delay(700);
          right();
          delay(850);
          Stop();
          SensorUpdate();
          break;
        
      } 
    }
  else if (USL<=15)
    {
      switch(FSB)
     {  case 1:
          BACKright();
          delay(1000);
          Speed=255;
          FORWARD();
          delay(1000);
          Stop();
          SensorUpdate();
          break;
        case 0:
          Speed=255;
          FORWARD();
          delay(700);
          left();
          delay(950);
          Stop();
          SensorUpdate();
          break; 
      }
    }
  else if (USF<=20)
    { 
      Speed=255; 
      FORWARD();
    }
  else if (((FSR==0) || (FSL==0)) || ((FSR==0) && (FSL==0)))
    { 
      Speed=150;
      FORWARD();
      delay(50);
      Speed=255;
      BACKWARD();
      delay(300);
      left();
      delay(500);
      SensorUpdate();
    }
  else if (FSB==0)
    { Speed=180;
      FORWARD(); 
      delay(100);
      left();
      delay(100);
    }
  else
    { 
      Speed=200; 
      FORWARD();
    }
}
void FORWARD() {
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  analogWrite(IN1, Speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, Speed);
  analogWrite(IN4, 0);
}//--------------------------------------------
void BACKWARD() {
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  analogWrite(IN1, 0);
  analogWrite(IN2, Speed);
  analogWrite(IN3, 0);
  analogWrite(IN4, Speed);
}//--------------------------------------------
void BACKleft()
{
  //When we want to let Motor To Rotate ,
  // just void this part on the loop section .
   analogWrite(IN1, 0);
   analogWrite(IN2, 255);
   analogWrite(IN3, 0);
   analogWrite(IN4, 130);
}//--------------------------------------------
void BACKright()
{
  //When we want to let Motor To Rotate ,
  // just void this part on the loop section .
   analogWrite(IN1, 0);
   analogWrite(IN2, 130);
   analogWrite(IN3, 0);
   analogWrite(IN4, 255);
}//--------------------------------------------
void right()
{
  //When we want to let Motor To move right ,
  // just void this part on the loop section .
   analogWrite(IN1, 0);
   analogWrite(IN2, 200);
   analogWrite(IN3, 130);
   analogWrite(IN4, 0);
}//--------------------------------------------
void left()
{
  //When we want to let Motor To move left ,
  // just void this part on the loop section .
   analogWrite(IN1, 200);
   analogWrite(IN2, 0);
   analogWrite(IN3, 0);
   analogWrite(IN4, 130);
}//--------------------------------------------
void Stop()
{
  //When we want to  Motor To stop ,
  // just void this part on the loop section .
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}
void SensorUpdate()
{
  FSL = digitalRead(6);
  FSR = digitalRead(7);
  FSB = digitalRead(8);
  Serial.print("Floor Sensors:");
  Serial.print(digitalRead(6));
  Serial.print(digitalRead(7));
  Serial.print(digitalRead(8));
  Serial.println("");
  Serial.print("USF: ");
  Serial.print(ultrasonic2.read());
  USF = ultrasonic2.read();
  Serial.println("cm");
  Serial.print("USR: ");
  Serial.print(ultrasonic1.read());
  Serial.println("cm");
  USR = ultrasonic1.read();
  Serial.print("USL: ");
  Serial.print(ultrasonic3.read());
  Serial.println("cm");
  USL = ultrasonic3.read();
}
