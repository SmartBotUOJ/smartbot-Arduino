#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(3,2);

const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;

void setup(){
  Serial.begin(9600);
  ArduinoUno.begin(4800);  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop(){
  /*while(ArduinoUno.available()>0){
    float val = ArduinoUno.parseFloat();
    if(ArduinoUno.read()== '\n'){
      Serial.println(val);  
    }
  }
  delay(30);*/
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW); 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
/*ArduinoUno.print("Distance: ");
ArduinoUno.println(distance);
ArduinoUno.println("\n");*/
   int i=10;
  ArduinoUno.print(i);
  ArduinoUno.println("\n");
  delay(30);    
}
