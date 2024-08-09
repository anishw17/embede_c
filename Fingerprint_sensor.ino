// Code By Anish Walke...!
#include <SoftwareSerial.h>
#include <Adafruit_Fingerprint.h>

SoftwareSerial fps (2,3);
Adafruit_Fingerprint fin = Adafruit_Fingerprint(&fps);

void setup()
{
  Serial.begin(9600);
  fin.begin(57600);
  Serial.println("Enter the ID :");
}

void loop()
{
  if(Serial.available()>0)
  {
    int id = Serial.parseInt();
    Serial.print("ID is :");
    Serial.println(id);

    Serial.print("waiting for finger");
    while (fin.getImage() != FINGERPRINT_OK);
    
    int fp = fin.image2Tz(1);
    if(fp == FINGERPRINT_OK)
    {
      Serial.println("Image taken");
    }
    else
    {
      Serial.print("Error");
    }
    Serial.println("Remove the finger");
    delay(2000);
    
    Serial.println("place the same finger");
    while (fin.getImage() != FINGERPRINT_OK);

    fp = fin.image2Tz(2);
    if(fp == FINGERPRINT_OK)
    {
      Serial.println("Image taken");
    }
    else
    {
      Serial.print("Error");
    }    
    Serial.println("Creating a model...");

    fp = fin.createModel();
    if(fp == FINGERPRINT_OK)
    {
      Serial.println("Model created!");
    }
    else
    {
      Serial.print("Error");
    }

    fp = fin.storeModel(id);
    if(fp == FINGERPRINT_OK)
    {
      Serial.println("Enrolled!!");
    }
    else
    {
      Serial.print("Error");
    }
  }
}