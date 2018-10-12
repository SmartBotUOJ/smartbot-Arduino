#include<ESP8266WiFi.h>

const char* ssid="TD";
const char* password="tdC141csc801";

int ledPin0 =13;
int ledPin1 =12;

void Connected(int i){
  if(i==0){
  digitalWrite(ledPin0,LOW);
  digitalWrite(ledPin1,HIGH);
  Serial.println("Not Connected");
  }else if(i==1){
  digitalWrite(ledPin0,HIGH);
  digitalWrite(ledPin1,LOW);
  Serial.println("Connected");
  }
}

void setup() {
  pinMode(ledPin0,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  Connected(0);

  Serial.begin(115200);
  Serial.println();
  Serial.print("WiFi connecting to : ");
  Serial.println(ssid);

  WiFi.begin(ssid,password);

  Serial.println();
  Serial.print("Connecting");

  while(WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(".");
    }
    Connected(1);
//    digitalWrite(ledPin , HIGH);
    Serial.println();

    Serial.println("WiFi Connected Success !");
    Serial.println("NodeMCU IP Address : ");
    Serial.println(WiFi.localIP());
}

void loop() {
 if(WiFi.status() != WL_CONNECTED){
  Connected(0);
 }else{
  Connected(1);
 }
 delay(200);
}
