#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "android-app-4a201.firebaseio.com"
#define FIREBASE_AUTH "ZmLoXdkmcfhdzUY3TznR1wsfTQ6tW23mMGLySmhs"
#define WIFI_SSID "TD"
#define WIFI_PASSWORD "tdC141csc801"

#define TRIGGER_PIN  5
#define ECHO_PIN     4


int WET= 16; // Wet Indicator at Digital PIN D0
int DRY= 2;  // Dry Indicator at Digital PIN D4
int sense_Pin= 0; // Soil Sensor input at Analog PIN A0
int value= 0;

void setup() {
  Serial.begin(9600);
// ultr.................
    pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);

   //Soil.................................
   pinMode(WET, OUTPUT);
   pinMode(DRY, OUTPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
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

// ultra............................................................................
     int duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;
 Firebase.setInt("/LabStatus/tankLevel",distance);
 Serial.print(" Distance");
 Serial.print(distance);
 Serial.println(" cm");
 Serial.println();

 //Soil...................................................................................
 //Soil........................................................................................................................................................
   Serial.print("MOISTURE LEVEL : ");
   value= analogRead(sense_Pin);
   value= value/10;
   Serial.println(value);
   Firebase.setInt("/LabStatus/Moisture",value);
   Serial.println();

    //Light intensity............................................................................................
     // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // print out the value you read:
  Serial.print("Light Intensity: ");
  Serial.println(voltage);
  Firebase.setFloat("/LabStatus/Intensity",voltage); 
 
  delay(200);
}
