// code by Anish Walke...!
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
int enA =A0;
int enB = A1;
void setup()
{
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}
void loop()
{
  while(Serial.available() > 0)
  {
    int d = Serial.read();
    switch(d)
    {
      case 'f' :
      digitalWrite(in1,HIGH);
      digitalWrite(in4,HIGH);
      analogWrite(enA,255);
      analogWrite(enB,255);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      break;

      case 'r':
      digitalWrite(in4,HIGH);
      analogWrite(enB,255);
      digitalWrite(in2,LOW);
      digitalWrite(in1,LOW);
      digitalWrite(in3,LOW);
      break;

      case 'l':
      digitalWrite(in1,HIGH);
      analogWrite(enA,255);
      digitalWrite(in2,LOW);
      digitalWrite(in4,LOW);
      digitalWrite(in3,LOW);
      break;

      case 'b':
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      analogWrite(enA,255);
      analogWrite(enB,255);
      digitalWrite(in1,LOW);
      digitalWrite(in4,LOW);
      break;

      case 'bb':
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
      break;
    }
  }
}