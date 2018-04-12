int misura = 0;
int pinLed = 11;
int val = 0;
int inputVal = 0;
String  accensione = "";

void setup() {

Serial.begin(9600);
  // put your setup code here, to run once:
pinMode (pinLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 val = analogRead (misura);

// val= val/4;
//if (Serial.available() > 0) {
    accensione = Serial.readString();
 //inputVal = map (val, 0, 1023, 0, 254);
  
  if (accensione == "on"){
    inputVal = map (val, 0, 1023, 0, 254);
  
  }else if (accensione == "off"){
    inputVal = 0;
    }
                // say what you got:
    Serial.print("I received: ");
    Serial.println(inputVal, DEC);
    Serial.println(accensione);
//}
/*
 Serial.print("valore letto da analogRead() = ");
 Serial.println(val);
 Serial.print("valore letto da map() = ");
 Serial.println(inputVal);
 Serial.print("");*/
 delay(1000);
 
 analogWrite(pinLed,inputVal);

}
