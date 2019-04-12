#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}


void SendMessage(){
  mySerial.write("AT+CMGF=1\r\n");
  delay(1000); 
  mySerial.write("AT+CMGS=\"+917984621327\"\r\n");
  delay(1000);
  mySerial.write("Test");
  delay(1000);   
  mySerial.write((char)26);
  delay(2000);
  }


 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 }
 
