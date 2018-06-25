/**
 * Manual configuration
 */
bool configureNetwork() {
  return
    sendConfiguration("+++", false,false) &&
    sendConfiguration("ATRE", true,false) &&
    sendConfiguration("ATCH C", true,false) &&
    sendConfiguration("ATID 4D37", true,false) &&
    sendConfiguration("ATDH 0000", true,false) &&
    sendConfiguration("ATDL FFFF", true,false) &&
    sendConfiguration("ATMY 250F", true,false) &&
    sendConfiguration("ATNI 250F", true,false) &&
    sendConfiguration("ATWR", true,false) &&
    sendConfiguration("ATCN", true,false);
}
/**
 * With this function I create my own network and my Xbee is the coordinator. *
 * ATID is the ID of my own network
 * 
 **/
bool configureCoordinator(String mynumberCard) {
  return
    sendConfiguration("+++", false,false) &&
    sendConfiguration("ATRE", true,false) &&
    sendConfiguration("ATCE 1", true,false) &&
    sendConfiguration("ATCH B", true,false) &&
    sendConfiguration("ATID 5B25", true,false) &&
    sendConfiguration("ATDH 0000", true,false) &&*/
    //Send only on the card 2503
    sendConfiguration("ATDL 2503", true,false) &&

    sendConfiguration("ATCH C", true,false) &&
    sendConfiguration("ATMY " + mynumberCard, true,false) &&
    sendConfiguration("ATNI " + mynumberCard, true,false) &&
    sendConfiguration("ATWR", true,false) &&
    sendConfiguration("ATCN", true,false);
}
/**
 * Auto configuration 
 */
bool configureAuto(String mynumberCard){
    sendConfiguration("+++", false,false) &&
    sendConfiguration("ATRE", true,false) &&   
    sendConfiguration("ATA1 7", true,false) &&
    sendConfiguration("ATMY " + mynumberCard, true,false) &&
    sendConfiguration("ATNI " + mynumberCard, true,false) &&
    sendConfiguration("ATWR", true,false) &&
    sendConfiguration("ATCN", true,false);
}
/**
 * Auto configuration to send for only one card and with encryption
 * ATDH is the DH of the other card
 * ATDL is the DL of the other card
 * KEY is the encryption key
 */
bool configureAutoFor1Card(String mynumberCard,String ATDH, String ATDL,String key){
    sendConfiguration("+++", false,false) &&
    sendConfiguration("ATRE", true,false) &&
   
    sendConfiguration("ATA1 7", true,false) &&
      
    sendConfiguration("ATMY " + mynumberCard, true,false) &&
    sendConfiguration("ATNI " + mynumberCard, true,false) &&
    sendConfiguration("ATDH " + ATDH, true,false) &&
    sendConfiguration("ATDL " + ATDL, true,false) &&
    sendConfiguration("ATNO 1", true,false) &&
    sendConfiguration("ATKY " + key,true,false) &&
    sendConfiguration("ATEE 1", true,false) &&
    sendConfiguration("ATAI", true,true) &&
    sendConfiguration("ATWR", true,false) &&
    sendConfiguration("ATCN", true,false);
}
/**
 * Sending the configuration according to the command
 * if the command is +++ : do not go back to the line
 * if is the other command : go to the line
 * bool b is for is to check the response of the command
 */
bool sendConfiguration(String configuration, bool useCR, bool b) {
  if (useCR) {
    Serial.println(configuration);
  }
  else {
    Serial.print(configuration);
  }

  return checkResponse(b);
}
/**
 * Check the response
 * if b is true the response must be '0' and if b is false the response must be 'OK'
 */
bool checkResponse(bool b) {
  while (!Serial.available()) { }

  String response = Serial.readString();
  if(b){
    if(response.indexOf("0") >= 0){
      return true;
    }
  }else if (response.indexOf("OK") >= 0) {
    return true;
  } 
    return false;
}
/**
*Use to read values ​​sent by another Xbee
*/
String read() {
  while (!Serial.available()) { }
  return Serial.readString();
}

