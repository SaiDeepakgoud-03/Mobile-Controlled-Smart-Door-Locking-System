String readString;
#include <Servo.h>

Servo myservo;    


void setup()
{
  Serial.begin(9600);           
  myservo.attach(9);    
}
void loop()
{
  while(Serial.available())    //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = Serial.read();    //Conduct a serial read
    if (c == '#'){
      break;                   //Stop the loop once # is detected after a word
    }
    readString += c;                //Means readString = readString + c
  }
    if (readString.length() >0)
    {
      Serial.println(readString);
                  
     if(readString == "f success"){ 
        myservo.write(180);
        delay(4000);
        myservo.write(90);
      }
      readString="";
    }
}
