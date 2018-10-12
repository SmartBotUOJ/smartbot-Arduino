#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "android-app-4a201.firebaseio.com"
#define FIREBASE_AUTH "ZmLoXdkmcfhdzUY3TznR1wsfTQ6tW23mMGLySmhs"
#define WIFI_SSID "TD"
#define WIFI_PASSWORD "tdC141csc801"

bool state1 = true;
bool state2 = true;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
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
bool path   = "/";
//int path1 = "/LabStatus";
  //FirebaseObject object = Firebase.get(path);
  //cam == water motor
  bool getMoter = Firebase.getBool("cam");
  bool fan = Firebase.getBool("fan");
  bool light = Firebase.getBool("light");
  bool pro = Firebase.getBool("pro");
  int FanSpeed = Firebase.getInt("/LabStatus/FanSpeed");
  //Intensity = soil moisture
  int Intensity = Firebase.getInt("/LabStatus/Intensity");
  if(WiFi.status() == WL_CONNECTED){

      Serial.println("..");

      if(Intensity < 25 && getMoter == false){
          if(state1){
              Firebase.setBool("/cam",true); 
              Serial.println("Intensity < 25 || getMoter == false");
            }
        }else if(Intensity >= 25 && getMoter == true){
            if(state2){
              Firebase.setBool("/cam",false); 
               Serial.println("Intensity >= 25 || getMoter == true");
            }
        }

        if(getMoter == false ){
            state2 = false;
            state1 = true;
            Serial.println("getMoter == false");
             // Firebase.setBool("/cam",false); 
          }else if(getMoter == true){
            state2 = true;
            state1 = false;
            Serial.println("getMoter == true");
             // Firebase.setBool("/cam",true);  
          }

  
  }
  
}
