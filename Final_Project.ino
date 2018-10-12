#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "android-app-4a201.firebaseio.com"
#define FIREBASE_AUTH "ZmLoXdkmcfhdzUY3TznR1wsfTQ6tW23mMGLySmhs"
#define WIFI_SSID "TD"
#define WIFI_PASSWORD "tdC141csc801"

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
  //FirebaseObject object = Firebase.get(path);

  bool cam = Firebase.getBool("cam");
  bool fan = Firebase.getBool("fan");
  bool light = Firebase.getBool("light");
  bool pro = Firebase.getBool("pro");

  if(WiFi.status() == WL_CONNECTED){

 /*     Serial.println(cam);
      Serial.println(fan);
      Serial.println(light);
      Serial.println(pro);   */  
      Serial.println();
      if(cam == true){
        //digitalWrite(13, HIGH);   
         Serial.println("cam on");       
      } else {
       // digitalWrite(13, LOW); 
        Serial.println("cam off");    
       }

      if(fan == true){    
        digitalWrite(12, HIGH); 
         Serial.println("fan on");       
      } else {
        digitalWrite(12, LOW); 
        Serial.println("fan off");    
       }

        if(light == true){   
         Serial.println("light on");  
         digitalWrite(13, HIGH);      
      } else {
        digitalWrite(13, LOW);
        Serial.println("light off");    
       }

       if(pro == true){   
         Serial.println("pro on");       
      } else {
        Serial.println("pro off");    
       }
      
      
    }
 
  
  
  
}
