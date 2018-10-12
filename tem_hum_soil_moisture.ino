//#include <ESP8266WiFi.h>
//#include <FirebaseArduino.h>
#include <DHT.h>  
#include <Adafruit_Sensor.h>

//#define FIREBASE_HOST "android-app-4a201.firebaseio.com"
//#define FIREBASE_AUTH "ZmLoXdkmcfhdzUY3TznR1wsfTQ6tW23mMGLySmhs"
//#define WIFI_SSID "nodemcu"
//#define WIFI_PASSWORD "Raspbian18"

#define DHTTYPE DHT11

#define DHT_dpin 5 // temo humidty sensor D1
int sense_Pin= 0;  // Soil Sensor input at Analog PIN A0
int value= 0;
DHT DHT(DHT_dpin, DHTTYPE);
 
void setup(void)
{ 
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature\n\n");
  delay(700);
 // WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 // Serial.print("connecting");
  
 /* while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }*/
  
 /* Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);*/
  
  Serial.println("Humidity and temperature\n\n");
  delay(700);
  
 
 

}
void loop() {

 /*   if(WiFi.status() != WL_CONNECTED)
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
      Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);*/
    }
    
    float h = DHT.readHumidity();
    float t = DHT.readTemperature();         
    Serial.print("Current humidity = ");
  //  Firebase.setFloat("/LabStatus/Humidity",h);
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
   // Firebase.setFloat("/LabStatus/Temp", t);
    Serial.print(t); 
    Serial.println("C  ");
    /*
    Serial.print("MOISTURE LEVEL : ");
    value= analogRead(sense_Pin);
    value= value/10;
  //  Firebase.setFloat("/LabStatus/Moisture",value);
    
    Serial.println(value);*/
    
    
    delay(1000);
}

