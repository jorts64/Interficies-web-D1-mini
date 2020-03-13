#include "FSManager.h"
extern ESP8266WebServer server;




void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  
  SPIFFS.begin();
  initHelper(); //inclou connexió Wifi i server
                // Aquí podem afegir altres funcions server.on()
  server.begin();

  
}

void loop() {
   digitalWrite(LED_BUILTIN,LOW);  
   espera(1000);      
   digitalWrite(LED_BUILTIN,HIGH);  
   espera(1000);      
  
}
