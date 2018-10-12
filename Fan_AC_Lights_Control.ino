#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "android-app-4a201.firebaseio.com"
#define FIREBASE_AUTH "ZmLoXdkmcfhdzUY3TznR1wsfTQ6tW23mMGLySmhs"
//#define WIFI_SSID "UOJ Student"
//#define WIFI_PASSWORD "uojusu2018"
#define WIFI_SSID "TD"
#define WIFI_PASSWORD "tdC141csc801"

bool state1 = true;
bool state2 = true;

void setup() {
  Serial.begin(115200);
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

      Serial.println();

      if(Intensity < 25 || getMoter == false){
          if(state1){
              Firebase.setBool("/cam",true); 
            }
        }else if(Intensity >= 25 || getMoter == true){
            if(state2){
              Firebase.setBool("/cam",false); 
            }
        }

        if(getMoter == false){
            state1 = false;
            state2 = true;
              Firebase.setBool("/cam",false); 
          }else if(getMoter == true){
            state1 = true;
            state2 = false;
              Firebase.setBool("/cam",true);  
          }
   /*    if(Intensity < 25 || getMoter == true){
       // Serial.println("Intensity below 25 then motor On"); 
          Serial.println("Intensity < 25 || getMoter == true");
              
               if(Intensity < 25){ 
                setMoterValue = true;
               Serial.println("Intensity below 25 then motor On"); 
               SoilMoValue =false;  
               Firebase.setBool("/cam",true); 
               
               }else if(getMoter == true){
              
               Serial.println("Because getMoter == true"); 
               
                     if (SoilMoValue) {
                     setMoterValue = false; 
                     }   
               }
         }    
              if(getMoter == false){ 
               Serial.println("Because getMoter == off"); 
               setMoterValue = true; 
                    
               }
               
        if(setMoterValue){
            if(Intensity >= 25){
            Serial.println("Intensity over 25 then motor Off"); 
              getMoter = false;
              Firebase.setBool("/cam",false);
              SoilMoValue = true;
            }
        }*/
      
      //cam == water motor
    /*  if(cam == true){
        //digitalWrite(13, HIGH);   
         Serial.println("cam on");       
      } else { 
       // digitalWrite(13, LOW); 
        Serial.println("cam off");    
       }*/

   /*   if(fan == true){    
        digitalWrite(12, HIGH); 
         Serial.println("fan on"); 
               if(FanSpeed == 1){
                  Serial.println("fan 1"); 
                  
                } else if (FanSpeed == 2){
                  Serial.println("fan 2"); 
                  
                }else if(FanSpeed == 3){
                  Serial.println("fan 3"); 
                }
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
       }*/
      
      
    }
 
  
  
  delay(50);
}
