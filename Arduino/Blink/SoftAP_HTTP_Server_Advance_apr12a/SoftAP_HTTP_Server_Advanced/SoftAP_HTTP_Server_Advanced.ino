#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <dht.h>/////////////////

const char *ssid = "ProjectMarmotta";
const char *password = "strategy";


int numClientOLD = 0;
int numClientCUR = 0;
int sensorPin= 12 //////
float temp =  00.00;
float hum = 00.00;
int ledValue = 0;/////
int ledPin = 7; // Digital I/O ARDUINO

//#define DHT11_PIN 12

char varHomePage[700];

ESP8266WebServer server(80);

void makeHomePage(){
   snprintf(varHomePage, 700, ////////////////?
    "<html>\
      <head>\
      <title>Domus Aurea Web</title>\
      <style>\
        h1{font-family:Verdana;}
        p{font-size:20px;}
      </style>\
      <meta name="description" content="Questa è l'interfaccia web della Domus Aurea">\
      <meta name="keywords" content="domusaurea,web,interfaccia,saas,iot,internet of things,arduino,progetto">\
      </head>\
      <body>\
      <center><h1 >Domus Web %s </h1><br><br>\
      <p >Il LED pin: %s &eacute %s<\p>
      <p >HUMIDITY: %s<\p>
      <p >TEMPERATURE: %s<\p>
      <p >Premi questo tasto per accendere <input href="/LED=ON" type="button" value="Accendi" style="background-color:green; font-weight:bold;"></input></p><br><br>\
      <hr>
      <p >Premi questo tasto per spegnere <input href="/LED=OFF" type="button" value="Spegni" style="background-color:red; font-weight:bold;"></p></input>\
      </center>\
      </body>\
     </html>"/, "%s1", "%02d", "%03d","%04f","%04f"
   /* "<html>\
        <head>\
          <meta http-equiv='refresh' content='5'/>\
          <title>Home Page</title>\
          <style>\
              body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
          </style>\
        </head>\
        <body>\
           <h1>ESP8266 MONITORAGGIO LED - %s</h1>\
           <p>Il LED pin %s &eacute %s</p>\
           <p>Premi su <a href=\"/LED=ON\">ON</a> per accendere</p>\
           <p>Premi su <a href=\"/LED=OFF\">OFF</a> per spegnere</p>\
        </body>\
      </html>", "%s1", "%02d", "%03d"*/
    );
}

void handleTemp(){
  
  
  }
 
void handleRoot() {
  Serial.read("%d",DHT11_PIN);
    Serial.read(temp);///////////////
    Serial.read(hum);//////////////// CONTROLLO TEMP

  
  
  
  String varTemp = String(varHomePage);
  varTemp.replace("%s1", "HomePage");
  varTemp.replace("%02d",String(ledPin));
  varTemp.replace("%03d",String(ledValue) );
  varTemp.replace("%04f",String (hum) );////////////
  varTemp.replace("%04f",String (temp) );///////////
  server.send(200, "text/html",varTemp);
}

void handleLedON(){
  
  Serial.read("%d",DHT11_PIN);
    Serial.read(temp);///////////////
    Serial.read(hum);//////////////// CONTROLLO TEMP
  
  
  
    
    if(ledValue == 0){
      ledValue = 140;
      Serial.printf("%d",ledPin);
      Serial.print("-");
      Serial.print(ledValue );
      Serial.println();
    }
    String varTemp = String(varHomePage);
    varTemp.replace("%s1", "Web Page LED ON");
    varTemp.replace("%02d",String(ledPin));
    varTemp.replace("%03d",String (ledValue) );
    varTemp.replace("%04f",String (hum) );///////////////
    varTemp.replace("%04f",String (temp) );/////////////
    server.send(200, "text/html",varTemp);
}
void handleLedOFF(){
    Serial.read("%d",DHT11_PIN);
    Serial.read(temp);///////////////
    Serial.read(hum);//////////////// CONTROLLO TEMP
  
    
    if(ledValue == 140){
      ledValue = 0;
      Serial.printf("%d",ledPin);
      Serial.print("-");
      Serial.print(ledValue);
      Serial.println();
    }
    String varTemp = String(varHomePage);
    varTemp.replace("%s1", "Web Page LED OFF");
    varTemp.replace("%02d",String(ledPin));
    varTemp.replace("%03d",String(ledValue) );
    varTemp.replace("%04f",String (hum) );///////////////
    varTemp.replace("%04f",String (temp) );/////////////
    server.send(200, "text/html",varTemp);
}

void fileNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) 
  {
    message += " " + server.argName (i) + ": " + server.arg (i) + "\n";
  }

  server.send (404, "text/plain", message);
}
 
void setup() {
  intHardware();
  setupWiFi();
  runServer();
}
 
void loop() {
  numClientCUR = WiFi.softAPgetStationNum();
  if ( numClientCUR != numClientOLD){
    Serial.printf("Stations connected = %d\n", numClientCUR);
    numClientOLD = numClientCUR;
  }
  server.handleClient();
  /*
       int chk = DHT.read11(DHT11_PIN);///////////////
         temp = DHT.temperature;
        hum = DHT.humidity;//////////////// CONTROLLO TEMP
      Serial.printf("%F",hum);
      Serial.print("-");
      Serial.print(temp);
      Serial.println();
  */
}

void setupWiFi(){
  WiFi.mode(WIFI_AP);
  Serial.println();
  Serial.println();
  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP(ssid, password) ? "Ready" : "Failed!");
}

void runServer(){
  makeHomePage();
  server.on("/", handleRoot);
  server.on("/LED=ON",handleLedON);
  server.on("/LED=OFF",handleLedOFF);
  server.onNotFound (fileNotFound);
  server.begin();
  Serial.print("Server IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.print("Server MAC address: ");
  Serial.println(WiFi.softAPmacAddress());
  Serial.println("Server listening");
}

void intHardware(){
    Serial.begin(115200);
}
