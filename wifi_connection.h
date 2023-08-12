#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_H

class WiFiConnection {
public:
  void begin();
  bool isConnected();

private:
  bool connected = false;
};

#endif