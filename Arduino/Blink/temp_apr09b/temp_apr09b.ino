
#include <dht.h>

dht DHT;

#define DHT11_PIN 12
int pinLed7 = 7;
int pinLed4 = 4;
int pinLed2 = 2;
int buzzer = 11;
float H = 00.00;


float sinVal;//////////////
int ledVal; 

void setup(){
  Serial.begin(9600);
  pinMode (pinLed2, OUTPUT);
  pinMode (pinLed4, OUTPUT);
  pinMode (pinLed7, OUTPUT);
  pinMode (buzzer, OUTPUT);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  H = DHT.humidity;
  
  
       //suona nota sul pin 12 alla frequenza di 1000Hz                     
  
  //if <h >=0 && h < 30
 if (H > 50.00 ){
      analogWrite(pinLed2,140);
      analogWrite(pinLed4,LOW);
      analogWrite(pinLed7,LOW);
      
  

      
      tone(buzzer,1000,200);  //suona nota sul pin 12 alla frequenza di 1000Hz   
      delay(1000);
      noTone(buzzer);}
   
      if ((H > 30.00) && ( H <= 50.00)){
        analogWrite(pinLed4,140);
        analogWrite(pinLed2,LOW);
        analogWrite(pinLed7,LOW);
    }
  
      if ((H> 00.00) && (H <= 30.00)){
        analogWrite(pinLed7,140);
        analogWrite(pinLed2,0);
        analogWrite(pinLed4,0);
    }
     delay(2000);
     ///////////////////////
  /* for (int x=0; x<180; x++) {
    sinVal = (sin(x*(3.1412/180)));
    ledVal = int(sinVal*255);
    analogWrite(ledPin11, ledVal);
    delay(50);}*/
}

