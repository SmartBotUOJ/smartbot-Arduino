#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
/*#define FIREBASE_HOST "android-app-4a201.firebaseio.com"
#define FIREBASE_AUTH "ZmLoXdkmcfhdzUY3TznR1wsfTQ6tW23mMGLySmhs"
#define WIFI_SSID "TD"
#define WIFI_PASSWORD "tdC141csc801"*/

#define TRIGGER_PIN  5
#define ECHO_PIN     4

void setup() {
  Serial.begin (9600);

  // connect to wifi.
 /* WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);*/

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;

  if (distance < 2289){
    Serial.print(distance);
    Serial.println(" cm");
    Firebase.setInt("/TankLevel",distance); 
    if(distance==5){
        Firebase.setBool("/Motor",true); 
      }else{
        Firebase.setBool("/Motor",false); 
      }
   }else {
     Serial.println("Out of Range");
   }
  
  delay(1000);
}
