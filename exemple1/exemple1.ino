#include "FSManager.h"
extern ESP8266WebServer server;

void engegar() {
  digitalWrite(D1, true);
  server.send(200, "text/plain", "ON");
}

void apagar() {
  digitalWrite(D1, false);
  server.send(200, "text/plain", "OFF");
}


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  
  pinMode(D1, OUTPUT);  
  SPIFFS.begin();
  initHelper(); //inclou connexió Wifi i server
                // Aquí podem afegir altres funcions server.on()
  server.on("/on", engegar);
  server.on("/off", apagar);
  server.begin();

  
}

void loop() {
   digitalWrite(LED_BUILTIN,LOW);  
   espera(1000);      
   digitalWrite(LED_BUILTIN,HIGH);  
   espera(1000);      
  
}
