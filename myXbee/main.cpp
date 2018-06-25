#include <iostream>
#include "myxbee.h"

using namespace std;


myXbee xbee = myXbee("25OF");

void setup() {
  Serial.begin(9600);
  xbee.configureAutoFor1Card("13A200","417C2574","777D7EE5DB70B3880A062ED14F5568E6");
}

void loop() {
  if(!xbee.Available()) { return; }
  delay(1000);
  xbee.send("Anthony : Hello it's me");
}
