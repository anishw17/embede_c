// rx tx connect karun ghe! declare chi garaj nahie!
#include<SoftwareSerial.h>

int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int led1 = 5;
int data;

void setup()
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
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
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);

    }
    else if (data == 'r')
    {
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
    }
    else if (data == 'l')
    {
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
    }
    else if (data == 'b')
    {
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
    }
    digitalWrite(led1,HIGH);
    
  }
}


