#include "wifi_connection.h"
#include "websocket_connection.h"
#include <ESP32Servo.h>

WiFiConnection wifiConnection;
Servo myservo;

int pos = 0; 

void setup() {
  Serial.begin(9600);

  wifiConnection.begin();

  if(wifiConnection.isConnected()) {
    Serial.println("Connected to WiFi");
    
    webSocketConnection.begin();
    motorBegin();
  }
  else {
    Serial.println("Failed to connect to WiFi");
  }  
}

void loop() {
  webSocketConnection.loop();

  if(webSocketConnection.getMotorState() == true) {
    spinMotor();
  }
}

void motorBegin() {
  myservo.attach(22);
}

void spinMotor() {
  for (pos = 90; pos <= 135; pos++) {
    myservo.write(pos);
    delay(15);
  }
  
  delay(2000);
  
  for (pos = 135; pos >= 90; pos--) {
    myservo.write(pos);
    delay(15);
  }
  
  webSocketConnection.setMotorState(false);
}
