
// Declaration and initialization of input pins
int JoyStick_X = A0; // Signal of the X axis
int JoyStick_Y = A1; // Signal of the Y axis
int Button = 3; // Button
int val = 0;

void setup ()
{
  Serial.begin(9600);
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
  pinMode (Button, INPUT);
   
  
  digitalWrite(Button, HIGH);
  //configureNetwork();
 // configureAuto();
 configureAutoFor1Card("250F","13A200","417C2574","777D7EE5DB70B3880A062ED14F5568E6");
}

void loop ()
{
  delay(1000);

  //Send a message
  sendVal("ANTHONY : Hello it's me");  
}
//
/**
 * This is the configuration for the joystick. 
 *When I push the joystick's button, I send a "OK" and if I don't push the button I send 'KO'
 *When we made our own network, another Xbee received the values, a led was lit when the button was pressed.
 */
void configJoystick(){
  float x, y;
  int Knopf;
   
  //The values ​​are read and they are converted into voltage
  x = analogRead (JoyStick_X) * (5.0 / 1023.0); 
  y = analogRead (JoyStick_Y) * (5.0 / 1023.0);
  Knopf = digitalRead (Button);
  
  
  if(Knopf == val){
    
  }else{
    if(Knopf==1)
  {
      sendVal("OK");
      val = 1;
  }
  else
    {
        sendVal("KO");
        val = 0;
    }
  }
}

void sendVal(String val)
{
  Serial.print(val);
}


 

 

