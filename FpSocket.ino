#include "WiFiServer.h"
#include "include/WifiControl.h"
#include "include/SocketHandler.h"
#include "include/MatrixControl.h"

WiFiServer socket_server(80);

int led =  LED_BUILTIN;

void setup() {

  Serial.begin(115200);
  beginMatrix();
  pinMode(led, PinMode::OUTPUT);      // set the LED pin mode

  // Connect to wifi
  connectWifi();
  printWifiStatus();

  socket_server.begin();
}

// Connect to wifi first

void loop() {
    WiFiClient client = socket_server.available();

    if (client) {
        Serial.println("new client");
        String current_line = "";
        while (client.connected()) {
            if (client.available()) {
                String c = client.readStringUntil('\n');
                handleString(c, client);
                
                Serial.println(c);
            }
        }
        client.stop();
        Serial.println("Client disconnected");
    }
}