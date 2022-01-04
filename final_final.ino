
#include <LiquidCrystal.h>
#include "DHT.h"
#define dht11PIN 8 
#define dht11TYPE DHT11  
DHT dht11(dht11PIN, dht11TYPE); 
int relay_pin = 9;

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

int led_pin = 6; 
int pot_pin = A1;
int output;
int led_value;
int relay_pin2 = 10;

#include<SoftwareSerial.h>
int sensorPin=A0;
int sensorValue = 0;
int led = 13;




void setup() {



  dht11.begin();
  pinMode(relay_pin, OUTPUT);
digitalWrite(relay_pin, HIGH);
lcd.begin(16,2);

  pinMode(led_pin, OUTPUT);
   pinMode(led, OUTPUT);
 Serial.begin(9600);
 // put your setup code here, to run once:

  pinMode(relay_pin2, OUTPUT);
digitalWrite(relay_pin2, HIGH);

               
}

void loop(){
  int chk = dht11.read(dht11PIN);
lcd.clear();

  float h = dht11.readHumidity();
    Serial.print("-----Humidity:");
    Serial.print(h);
  
  float t = dht11.readTemperature();
    Serial.print("-----temperature:");
    Serial.print(t);

  lcd.setCursor (0,0);
  lcd.print ("Humidi = ");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor (0,1);
  lcd.print (" Temp = ");
  lcd.print (t);
   lcd.print("C");
    //reading the temperature from the sensor
// Checking if the sensor is sending values or not

if (t >30){
  digitalWrite(relay_pin,LOW);
  Serial.print("----fan on");
  delay(1000);
}
  else{
  digitalWrite(relay_pin, HIGH);
 Serial.print("-----fan off");
}
delay(1000);


if (h > 80){
  digitalWrite(relay_pin2,LOW);
  Serial.print("----moter on");
   Serial.print("----LED on");
  delay(1000);
}
  else{
  digitalWrite(relay_pin2, HIGH);
 Serial.print("----moter off");
  Serial.print("-----LED off");
}
delay(1000);



 //Reading from potentiometer
  output = analogRead(pot_pin);
  //Mapping the Values between 0 to 255 because we can give output
  //from 0 -255 using the analogwrite funtion
  led_value = map(output, 0, 1023, 0, 255);
  analogWrite(led_pin, led_value);
  delay(1);



 Serial.println("light intensity");
 sensorValue = analogRead(sensorPin);
 Serial.println(sensorValue);
 if(sensorValue < 300)
 {
   Serial.println("LED light on");
   digitalWrite(led,HIGH);
   delay(2000);
 }
 digitalWrite(led,LOW);
 delay(sensorValue);
 // put your main code here, to run repeatedly:

}
