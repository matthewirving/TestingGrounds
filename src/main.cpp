#include <Arduino.h>
#include <Wifi.h>
#include <WebServer.h>
#include "../credentials/info.h"
#include <iostream>
#include "../include/site.h"

const char *password = WIFI_PASSWORD_COL;
const char *network = WIFI_NETWORK_COL;

// sets Webserver to port 80
WebServer server(80);

// variable to store HTTP request
String header;

void connectToWifi()
{
    IPAddress localIP(192, 168, 1, 34);
    IPAddress DNS1(8, 8, 8, 8);
    IPAddress DNS2(8, 8, 4, 4);
    IPAddress gateway(192, 168, 1, 1);
    IPAddress subnet(255, 255, 255, 0);

    Serial.print("Connecting to WiFi");
    WiFi.mode(WIFI_STA);
    WiFi.begin(network, password);

    while(WiFi.status() != WL_CONNECTED)
    {
        Serial.print('.');
        delay(100);
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: " + WiFi.localIP());

}

void setup() //put setup code here to run once
{
    Serial.begin(115200);
}


void loop() //put code you want run continuously here
{

}