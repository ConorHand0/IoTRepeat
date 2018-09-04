const int ledPin =  6;
int soundSensorPin = A0;
#include<Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h"; 
#define TEMBOO_ACCOUNT "iotrepeat"; 
#define TEMBOO_APP_KEY_NAME "myFirstApp";
#define TEMBOO_APP_KEY  "xG7CvCS2fQs6oy6VTXxwaobq8BMgdMki";
const String GMAIL_USER_NAME = "iotrepeat@gmail.com";
const String GMAIL_PASSWORD = "QWERTY123?";
const String TO_EMAIL_ADDRESS = "iotrepeat@gmail.com";

boolean success = false;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode (ledPin, OUTPUT);
  pinMode (soundSensorPin, INPUT);
  while(!Serial);
  Bridge.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int soundSensorPin = analogRead(A0);
  // print out the value you read:
  Serial.println(soundSensorPin);
  delay(1);
   if (soundSensorPin > 300) {
   
    digitalWrite(ledPin, HIGH);

    Serial.println("Running SendAnEmail...");
  
    TembooChoreo SendEmailChoreo;
    
    SendEmailChoreo.begin();
    
    // set Temboo account credentials
    SendEmailChoreo.setAccountName(TEMBOO_ACCOUNT);
    SendEmailChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendEmailChoreo.setAppKey(TEMBOO_APP_KEY);

    // identify the Temboo Library choreo to run (Google > Gmail > SendEmail)
    SendEmailChoreo.setChoreo("/Library/Google/Gmail/SendEmail");
  
    SendEmailChoreo.addInput("iotrepeat@gmail.com", GMAIL_USER_NAME);
    
    SendEmailChoreo.addInput("QWERTY123?", GMAIL_PASSWORD);
 
    SendEmailChoreo.addInput("iotrepeat@gmail.com", TO_EMAIL_ADDRESS);
  
    SendEmailChoreo.addInput("Subject", "Tazz is Barking");
  
    SendEmailChoreo.addInput("MessageBody", "Someone nearby");

    unsigned int returnCode = SendEmailChoreo.run();

    if (returnCode == 0) {
        Serial.println("Success! Email sent!");
        success = true;
    } 
    else {
  
      while (SendEmailChoreo.available()) {
        char c = SendEmailChoreo.read();
        Serial.print(c);
      }
    } 
    SendEmailChoreo.close();

    delay(60000);
  }
}
