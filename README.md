# dispenserESP32

# Project Setup

This README provides instructions on creating and incorporating the `wifi_config.h` and `websocket_config.h` files into your project. These files will store the required credentials for WiFi and WebSocket server connections, respectively.

## Adding Configuration Files

1. Create two files in your project's source code directory: `wifi_config.h` and `websocket_config.h`.

2. Open the `wifi_config.h` file and insert the following content:

```c
#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

const char* ssid = "Your_SSID_name";
const char* password = "Your_password";

#endif
```

3. Open the `websocket_config.h` file and insert the following content:
   
```c
#ifndef WEBSOCKET_CONFIG_H
#define WEBSOCKET_CONFIG_H

const char* serverIP = "SERVER_IP";
const int serverPort = PORT;

#endif
```
