#include "WiFiServer.h"
#include "include/MatrixControl.h"

int led_sock =  LED_BUILTIN;

void handleString(String s, WiFiClient client) {
    if (s.startsWith("hello")) {
        client.println("Hello World!");
    } else if (s.startsWith("led")) {
        if (s == "ledon") {
            digitalWrite(led_sock, HIGH);
        } else if (s == "ledoff") {
            digitalWrite(led_sock, LOW);
        }
    } else if (s.startsWith("set")) {
        // The command format should be `set x y`
        // Loop through the string and find the x and y
        int sep = s.lastIndexOf(' ');
        int x = s.substring(4, sep).toInt();
        int y = s.substring(sep).toInt();
        setBit(x, y);
        delay(500);
        renderBitMap();
    } else if (s.startsWith("message")) {
        String message = s.substring(8);
    }
}