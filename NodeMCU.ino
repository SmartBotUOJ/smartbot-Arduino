#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

SoftwareSerial NodeMCU(D2,D3);

void setup(){
  Serial.begin(9600);
  NodeMCU.begin(4800);
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
}

void loop(){
    while(NodeMCU.available()>0){
    float val = NodeMCU.parseFloat();
    if(NodeMCU.read()== '\n'){
      Serial.println(val);  
    }
  }
  delay(30);
}

/*void loop(){
  int i=10;
  NodeMCU.print(i);
  NodeMCU.println("\n");
  delay(30);    
}*/


