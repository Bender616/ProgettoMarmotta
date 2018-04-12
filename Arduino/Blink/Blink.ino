/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

int led1 =13;
 int led2 =12;
 int led3 = 11;


 int arr[]= {13,10,8};
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led1, OUTPUT); // rosso
  pinMode(led2, OUTPUT); // giallo
  pinMode(led3, OUTPUT); // verde
}

// the loop function runs over and over again forever
//void loop() {
//  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(50);    
//  digitalWrite(led1, LOW);// wait for a second
//  digitalWrite(led2, HIGH);    // turn the LED off by making the voltage LOW
//  delay(50);  
//   digitalWrite(led2, LOW);// wait for a second
//}

//void loop() {
//
//bool acceso = true;
//bool x = 0;  
//  do{
//    digitalWrite(led1, HIGH); // Accendi rosso
//    delay(3000);
//    digitalWrite(led1, LOW); // Spegni rosso
//    digitalWrite(led3, HIGH); // Accendi verde
//    delay(3000);
//    digitalWrite(led2, HIGH); // Accendi giallo
//    delay(1500);
//    digitalWrite(led3, LOW); // Spegni verde
//    
//    digitalWrite(led2, LOW); // Spegni giallo
//        
//    } while(acceso = true);
//}

void loop() {


digitalWrite(led3, LOW);
  for(int i=13;i>10;i--) // Accende le prime tre in sequenza
  {
    digitalWrite(i, HIGH);
    delay(150);
    digitalWrite(i, LOW); 
    }

    digitalWrite(led3, HIGH); // tiene accesa la verde

      for(int i=13;i>11;i--) // accende in sequenza le altre 2
  {
    digitalWrite(i, HIGH);
    delay(150);
    digitalWrite(i, LOW); 
    }

    digitalWrite(led2, HIGH); // tiene accesa la gialla

    digitalWrite(led1, HIGH);
    delay(500);

    for(int i = 10; i<14; i++) {
      digitalWrite(i, LOW);
      delay(200);
    }

    delay(1000);

    
  }

