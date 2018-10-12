
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "android-app-4a201.firebaseio.com"
#define FIREBASE_AUTH "ZmLoXdkmcfhdzUY3TznR1wsfTQ6tW23mMGLySmhs"
#define WIFI_SSID "TD"
#define WIFI_PASSWORD "tdC141csc801"


int fan = 5;
int fanspeed1 = 4;
int fanspeed2 = 14;
int fanspeed3 = 12;
int device1Pin = 13;
int device1Pin =15;

void setup() {
  Serial.begin(9600);
  //pinMode(13, OUTPUT);
  pinMode(fan, OUTPUT); // initialize pin as OUTPUT
  pinMode(fanspeed1, OUTPUT); // initialize pin as OUTPUT
  pinMode(fanspeed2, OUTPUT); // initialize pin as OUTPUT
  pinMode(fanspeed3, OUTPUT); // initialize pin as OUTPUT
  pinMode(device1Pin, OUTPUT); // initialize pin as OUTPUT
  pinMode(device2Pin, OUTPUT);    // initialize pin as OUTPUT


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
  bool device1State = Firebase.getBool("device1");
  bool device2State = Firebase.getBool("device2");
  bool fan = Firebase.getBool("fan");
  bool light = Firebase.getBool("light");

  Serial.println();
  if(WiFi.status() == WL_CONNECTED){

        Firebase.setString("/message","WIFI connected"); 
          
            if (device1State == true) {
              Serial.println("device1State on");
              digitalWrite(device1Pin, LOW);
            } else if (device1State == false) {
              Serial.println("device1State off");
              digitalWrite(device1Pin, HIGH);
            }
          
            if (fan == true) {
              Serial.println("fan on");
              digitalWrite(fan, LOW);
          
              if (fanState == 1) {
                digitalWrite(fanspeed3, HIGH);
                digitalWrite(fanspeed2, HIGH);
                digitalWrite(fanspeed1, LOW);
                Serial.println("1");
              } else if (fanState == 2) {
                digitalWrite(fanspeed1, HIGH);
                digitalWrite(fanspeed3, HIGH);
                digitalWrite(fanspeed2, LOW);
                Serial.println("2");
              } else if (fanState == 3) {
                digitalWrite(fanspeed1, HIGH);
                digitalWrite(fanspeed2, HIGH);
                digitalWrite(fanspeed3, LOW);
                Serial.println("3");
              }
            } else  {
              Serial.println("fan off");
              digitalWrite(fan, HIGH);
              digitalWrite(fanspeed1, HIGH);
              digitalWrite(fanspeed2, HIGH);
              digitalWrite(fanspeed3, HIGH);
            }
          
            if (device2State == true) {
              Serial.println("device2State on");
              digitalWrite(device2Pin, LOW);
            } else if (device2State == false) {
              Serial.println("device2State off");
              digitalWrite(device2Pin, HIGH);
            }
       
  }else{
       Firebase.setString("/message","WIFI not connected");
    }




}




