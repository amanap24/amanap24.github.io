
#define RELAY1  7   
char data = 1;                     
void setup()

{    


Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);       

}

  void loop()
{
  if (Serial.available() > 0)
  {
    data= Serial.read();
    if(data=='1')
    {
      Serial.print(data);
      Serial.print("=> LED OFF");
      Serial.print("\n");
      digitalWrite(RELAY1, HIGH);
    }

    else if(data == '0')
    {
      Serial.print(data);
      Serial.print("=> LED ON");
      Serial.print("\n");
      digitalWrite(RELAY1, LOW);
    }
  }
}
