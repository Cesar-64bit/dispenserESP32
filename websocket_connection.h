#ifndef WEBSOCKET_CONNECTION_H
#define WEBSOCKET_CONNECTION_H

#include <WebSocketsClient.h>

class WebSocketConnection {
public:
  void begin();
  void loop();
  void sendMessage(const String& message);
  String getReceivedMessage();
  void setMotorState(bool state);
  bool getMotorState();

private:
  WebSocketsClient webSocket;
  String receivedMessage;
  bool motorState = false;

  static void webSocketEvent(WStype_t type, uint8_t* payload, size_t length);
  void handleWebSocketMessage(uint8_t* payload, size_t length);
};

extern WebSocketConnection webSocketConnection;

#endif
