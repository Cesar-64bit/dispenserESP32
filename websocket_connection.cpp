#include "websocket_connection.h"
#include "websocket_config.h"

WebSocketConnection webSocketConnection;

void WebSocketConnection::begin() {
  webSocket.begin(serverIP, serverPort, "/");
  webSocket.onEvent(webSocketEvent);
}

void WebSocketConnection::loop() {
  webSocket.loop();
}

void WebSocketConnection::sendMessage(const String& message) {
  webSocket.sendTXT(const_cast<String&>(message));
}

String WebSocketConnection::getReceivedMessage() {
  return receivedMessage;
}

void WebSocketConnection::setMotorState(bool state) {
  motorState = state;
}

bool WebSocketConnection::getMotorState() {
  return motorState;
}

void WebSocketConnection::webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
  webSocketConnection.handleWebSocketMessage(payload, length);
}

void WebSocketConnection::handleWebSocketMessage(uint8_t* payload, size_t length) {
  receivedMessage = String((char*)payload);
  Serial.println("Received message: " + receivedMessage);

  if(receivedMessage.toInt() > 0) {
    int timeSeconds = receivedMessage.toInt() * 1000;

    delay(timeSeconds);
    Serial.println("Activating motor...");

    motorState = true;
  }
}
