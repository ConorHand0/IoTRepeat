const int ledPin =  6;
int soundSensorPin = A0;
const String GMAIL_USER_NAME = "iotrepeat@gmail.com";
const String GMAIL_PASSWORD = "QWERTY123?";
const String TO_EMAIL_ADDRESS = "iotrepeat@gmail.com";


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
    
    SendEmailChoreo.addInput("Password", GMAIL_PASSWORD);
 
    SendEmailChoreo.addInput("iotrepeat@gmail.com", TO_EMAIL_ADDRESS);
  
    SendEmailChoreo.addInput("Subject", "Tazz is on the couch!");
  
    SendEmailChoreo.addInput("MessageBody", "Doggy being bold");

    unsigned int returnCode = SendEmailChoreo.run();

    else (
  
}
