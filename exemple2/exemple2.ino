#include "FSManager.h"
extern ESP8266WebServer server;

#include <WEMOS_DHT12.h>
DHT12 dht12;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  
  pinMode(D1, OUTPUT);  
  SPIFFS.begin();
  initHelper(); //inclou connexió Wifi i server
                // Aquí podem afegir altres funcions server.on()
  server.on("/ajax_t.txt", HTTP_GET, []() {
     dht12.get();
     String txt = String(dht12.cTemp);
     server.send(200, "text/plain", txt);
     txt = String();
     });
  server.on("/ajax_hr.txt", HTTP_GET, []() {
     dht12.get();
     String txt = String(dht12.humidity);
     server.send(200, "text/plain", txt);
     txt = String();
     });
  server.begin();  
}

void loop() {
   digitalWrite(LED_BUILTIN,LOW);  
   espera(1000);      
   digitalWrite(LED_BUILTIN,HIGH);  
   espera(1000);      
  
}
