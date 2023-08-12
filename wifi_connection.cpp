#include "wifi_connection.h"
#include "wifi_config.h"
#include <WiFi.h>

void WiFiConnection::begin() {
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(100);
  }

  connected = true;
}

bool WiFiConnection::isConnected() {
  return connected;
}