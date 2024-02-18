// rx tx connect karun ghe! declare chi garaj nahie!
#include<SoftwareSerial.h>

int in1 = 6;
int in2 = 5;
int in3 = 3;
int in4 = 9;
int ledr = 7;
int ledg = 4;
int data;

void setup()
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop()
{
  while(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.print(data);
    if (data == 'f')
    {
      digitalWrite(6,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(ledg,HIGH);
    }
    else if (data == 'r')
    {
      digitalWrite(6,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(ledg,HIGH);
    }
    else if (data == 'l')
    {
      digitalWrite(5,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(ledg,HIGH);
    }
    else if (data == 'b')
    {
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(ledr,HIGH);
    }
    else if (data == 'rev')
    {
      digitalWrite(5,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(ledr,HIGH);

    }
    
  }
}


