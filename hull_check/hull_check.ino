#include <SoftwareSerial.h>

void setup()
{
  // Set pin 5 as an input pin
  pinMode(5,INPUT);
  
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  
  Serial.begin(9600);
  Serial1.begin(1020);
  /*Serial2.begin(9440);
  Serial3.begin(8181);*/
}

void loop()
{ 
  String input;
  //If any input is detected in arduino
  if(Serial.available() > 0)
    { 
      //read the whole string until '\n' delimiter is read
      input = Serial.readStringUntil('\n');
      if (input.equals("0"))
        {
          digitalWrite(0, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(0, LOW);
        } 
      else if (input.equals("1"))
        {
          digitalWrite(1, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(1, LOW);
        }
     else if (input.equals("2"))
        {
          digitalWrite(2, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(2, LOW);
        }
     else if (input.equals("3"))
        {
          digitalWrite(3, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(3, LOW);
        }
     else if (input.equals("4"))
        {
          digitalWrite(4, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(4, LOW);
        }
     else if (input.equals("5"))
        {
          digitalWrite(5, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
              }
          delay(500);
          digitalWrite(5, LOW);
        }
     else if (input.equals("6"))
        {
          digitalWrite(6, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(6, LOW);
        }
     else if (input.equals("7"))
        {
          digitalWrite(7, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(7, LOW);
        }
     else if (input.equals("8"))
        {
          digitalWrite(8, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(8, LOW);
        }
     else if (input.equals("9"))
        {
          digitalWrite(9, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(9, LOW);
        }
     else if (input.equals("10"))
        {
          digitalWrite(10, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(10, LOW);
        }
     else if (input.equals("11"))
        {
          digitalWrite(11, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(11, LOW);
        }
     else if (input.equals("12"))
        {
          digitalWrite(12, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(12, LOW);
        }
     else if (input.equals("13"))
        {
          digitalWrite(13, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(13, LOW);
        }
     else if (input.equals("14"))
        {
          digitalWrite(14, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(14, LOW);
        }
     else if (input.equals("15"))
        {
          digitalWrite(15, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(15, LOW);
        }
     else if (input.equals("16"))
        {
          digitalWrite(16, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(16, LOW);
        }
     else if (input.equals("17"))
        {
          digitalWrite(17, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(17, LOW);
        }
     else if (input.equals("18"))
        {
          digitalWrite(18, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(18, LOW);
        }
     else if (input.equals("19"))
        {
          digitalWrite(19, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(19, LOW);
        }
     else if (input.equals("20"))
        {
          digitalWrite(20, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(20, LOW);
        }
     else if (input.equals("21"))
        {
          digitalWrite(21, HIGH);
          int reading = analogRead(5);
          if(reading > 1000)
            {
              Serial1.print("GOOD");
            }
            else
              {
                Serial1.print("BAD");
                }
          delay(500);
          digitalWrite(21, LOW);
        }
   }
}
