#include "wifi_connection.h"
#include "websocket_connection.h"

WiFiConnection wifiConnection;

const int motorPin1 = 22;
const int motorPin2 = 1; 
const int motorPin3 = 3; 
const int motorPin4 = 21;

const int pasoSecuencia[] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };

const int velocidadMotor = 10;

void avanzarUnPaso() {
   unsigned long startTime = millis();

  while (millis() - startTime < 5000) {
    for (int i = 0; i < 8; i++) {
      int paso = pasoSecuencia[i];
      digitalWrite(motorPin1, bitRead(paso, 0));
      digitalWrite(motorPin2, bitRead(paso, 1));
      digitalWrite(motorPin3, bitRead(paso, 2));
      digitalWrite(motorPin4, bitRead(paso, 3));
      delay(velocidadMotor);
    }
  }
  webSocketConnection.setMotorState(false);
}

void setup() {
  Serial.begin(9600);

  wifiConnection.begin();

  if(wifiConnection.isConnected()) {
    Serial.println("Connected to WiFi");
    
    webSocketConnection.begin();

    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
  }
  else {
    Serial.println("Failed to connect to WiFi");
  }  
}

void loop() {
  webSocketConnection.loop();
  
  if(webSocketConnection.getMotorState() == true) {
    avanzarUnPaso();
  }
}
