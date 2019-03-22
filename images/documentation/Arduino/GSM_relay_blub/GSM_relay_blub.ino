char inchar; // variable to store the incoming character 
int Relay1 = 8;
char data = 1;
void setup()
{
  
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, LOW);
  // wake up the GSM shield
  Serial.begin(9600);
  delay(2000); 
  Serial.println("AT+CMGF=1"); // set SMS mode to text
  delay(100);
  Serial.println("AT+CNMI=2,2,0,0,0");
  // just to get a notification when SMS arrives &direct out SMS upon receipt to the GSM serial out
  delay(100);
}

void loop()
{
  //If a character comes in from the GSM...
  if(Serial.available() >0)
  {
    inchar=Serial.read();
    if (inchar=='@')
    {
      delay(10);

      inchar=Serial.read();
      if (inchar=='p')
      {
        delay(10);
        inchar=Serial.read();
        if (inchar=='0')
        {     
     digitalWrite(Relay1, LOW);
     Serial.println("Relay OFF");
        }
        else if (inchar=='1')
        {
          Serial.println("Relay ON");
          digitalWrite(Relay1, HIGH);
        }
        delay(100);
       Serial.println("AT+CMGD=1,4"); // delete all SMS
       delay(2000);
      }
    }
  }
}
