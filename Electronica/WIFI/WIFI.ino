#include <WiFi.h>

const char* ssid = "LatticeLabs";
const char* password = "12345678";

WiFiClient client;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  ConfigureAP();
}

void loop() {
  WaitConnection();
}