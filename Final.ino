#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "android-app-4a201.firebaseio.com"
#define FIREBASE_AUTH "ZmLoXdkmcfhdzUY3TznR1wsfTQ6tW23mMGLySmhs"
#define WIFI_SSID "TD"
#define WIFI_PASSWORD "tdC141csc801"


int WET= 16; // Wet Indicator at Digital PIN D0
int DRY= 2;  // Dry Indicator at Digital PIN D4

//Soil
int sense_Pin= 0; // Soil Sensor input at Analog PIN A0
int value= 0;
//UltraSonic
#define TRIGGER_PIN  5
#define ECHO_PIN     4

void setup() {
   Serial.begin(9600);
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
   Serial.print("connecting");
   while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
   //Soil
   pinMode(WET, OUTPUT);
   pinMode(DRY, OUTPUT);

  //UltraSonic
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
  
   delay(2000);
}

void loop() {

 if(WiFi.status() != WL_CONNECTED)
    {

       WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
       while (WiFi.status() != WL_CONNECTED) 
       {
         Serial.print(".");
         delay(500);
       }
  
      Serial.println();
      Serial.print("connected: ");
      Serial.println(WiFi.localIP());
      Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    }
  
  //Soil........................................................................................................................................................
   Serial.print("MOISTURE LEVEL : ");
   value= analogRead(sense_Pin);
   value= value/10;
   Serial.println(value);
   Firebase.setInt("/LabStatus/Moisture",value);
   
   /*if(value<50)
   {
      digitalWrite(WET, HIGH);
   }
   else
   {
      digitalWrite(DRY,HIGH);
   }
   delay(1000);
   digitalWrite(WET,LOW);
   digitalWrite(DRY, LOW);*/
Serial.println();

   // Ultra...................................................................................

    int duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;
 Firebase.setInt("/LabStatus/tankLevel",distance);
  if (distance < 2289){
    Serial.print(distance);
    Serial.println(" cm");
   // Firebase.setInt("/LabStatus/tankLevel",distance); 
    if(distance==5){
      //  Firebase.setBool("/Motor",true); 
      }else{
       // Firebase.setBool("/Motor",false); 
      }
   }else {
     Serial.println("Out of Range");
   }
 Serial.println();
 
    //Light intensity............................................................................................
     // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  int voltage = sensorValue * (5.0 / 1023.0);
  
  // print out the value you read:
  Serial.print("Light Intensity: ");
  Serial.println(voltage);
  Firebase.setInt("/LabStatus/Intensity",voltage); 
  //
   delay(1000);
}
