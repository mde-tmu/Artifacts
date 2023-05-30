#include "WiFi.h"
#include <Time.h>
#include <string>

/*
 * Internet Settings
 * -----------------
 *   Change the ssid and password according to your WiFi.
 */
const char* ssid     = "ssid";
const char* password = "password";

/*
 * Server Configuration
 * --------------------
 *   Change the IP address to match the server.
 */
const char* server = "192.168.255.255";
const int port = 8088;

/*
 * Identifier
 * ----------
 *   Identifier for this device.
 */
const char* id = "1";

/*
 * WiFi Connection State
 * ---------------------
 *   Wrapper for connecting to a client.
 */
WiFiClient client;

/*
 * WiFi Connection Timeout
 * -----------------------
 *   WIFI:   timeout for when the device stops trying to connect to WiFi.
 *   CLIENT: timeout for when the device stops trying to connect to the Hub.
 */
const int WIFI_TIMEOUT   = 10000;
const int CLIENT_TIMEOUT = 5000;

/*
 * Message Queue
 * -------------
 *   Queue of messages to send to the Hub.
 */
const int MAX_QUEUE = 50;

String queue[MAX_QUEUE];
int queueLength = 0;

/*
 * Pins for the SmartLight subsystem.
 */
const int kSmartLight_LED = 5;
/*
 * Pins for the LightSensing subsystem.
 */
const int kLightSensing_LDR = 32;
/*
 * Pins for the WiFiLED subsystem.
 */
const int kWiFiLED_WiFiLED = 2;
/*
 * Pins for the ErrorDisplay subsystem.
 */
const int kErrorDisplay_a = 27;
const int kErrorDisplay_b = 14;
const int kErrorDisplay_c = 12;
const int kErrorDisplay_d = 13;
/*
 * Pins for the Debug subsystem.
 */
const int kDebug_DebugButton = 21;

void interactWithBoard();
void operateBoard();

/*
 *   Initializes the circuit and pins.
 */
void setup() {
	Serial.begin(115200);
	
	// Configures each pin.
	pinMode(kSmartLight_LED, OUTPUT);
	// Configures each pin.
	pinMode(kLightSensing_LDR, INPUT);
	// Configures each pin.
	pinMode(kWiFiLED_WiFiLED, OUTPUT);
	// Configures each pin.
	pinMode(kErrorDisplay_a, OUTPUT);
	pinMode(kErrorDisplay_b, OUTPUT);
	pinMode(kErrorDisplay_c, OUTPUT);
	pinMode(kErrorDisplay_d, OUTPUT);
	// Configures each pin.
	pinMode(kDebug_DebugButton, INPUT);
	
	wifiSetup();
	wifiConnect();
	
	postSetup();
	
	interactWithBoard();
	
	delay(2000);
}

void loop() {
	operateBoard();
}

/*
 * Function: wifiSetup
 * -------------------
 *   Sets up the WiFi.
 */
void wifiSetup() {
  WiFi.onEvent(onWiFiEvent);
  client.setTimeout(CLIENT_TIMEOUT);
}

/*
 * Function: wifiConnect
 * ---------------------
 *   Connects to WiFi.
 */
void wifiConnect() {
  WiFi.begin(ssid, password);
}

/*
 * Function: onWiFiEvent
 * ---------------------
 *   Called whenever there is a WiFi event.
 */
void onWiFiEvent(WiFiEvent_t event) {
  switch (event) {
    case SYSTEM_EVENT_STA_DISCONNECTED:
      wifiConnect();
      break;
    case SYSTEM_EVENT_STA_GOT_IP:
      break;
  }
}

/*
 * Function: queueMessage
 * ----------------------
 *   Appends a message to the queue.
 *   Returns true if successfully appended a message to the queue.
 */
void queueMessage(String json) {
  /* Removes the oldest item in the queue */
  if (queueLength >= MAX_QUEUE) {
    nextMessage();
  }

  queue[queueLength] = json;
  queueLength++;
}

/*
 * Function: nextMessage
 * ---------------------
 *   Gets the next message from the queue.
 */
String nextMessage() {
  String message = queue[0];

  /* Move the queue up. */
  for (int i = 0; i < queueLength - 1; i++) {
    queue[i] = queue[i+1];
  }
  
  queueLength--;
  return message;
}

/**
 * Function: queueEmpty
 * --------------------
 *   Returns true if the queue is empty.
 */
bool queueEmpty() {
  return queueLength == 0;
}

/* 
 * Function: generateJSON
 * ----------------------
 *   Generates a JSON file.
 *   id: the ID of this esp32,
 *   timestamp: the time in milliseconds since this esp32 started running,
 *   datatype: the type of data in value,
 *   value: some value of interest described in datatype.
 */
String generateJSON(const char* datatype, int value) {
  long timestamp = millis();
  
  String json = 
    "{ \"id\": " + String(id) + 
    ", \"timestamp\": " + String(timestamp) + 
    ", \"datatype\": " + "\"" + String(datatype) + "\"" + 
    ", \"value\": " + String(value) + 
    " }";
  
  return json;
}

void postSetup() {
}
int LDRMonitored() {
	int light_intensity = analogRead(kLightSensing_LDR);
	  		return light_intensity;
}
void LEDTurnOn() {
	digitalWrite(kSmartLight_LED, HIGH);
}
void LEDTurnOff() {
	digitalWrite(kSmartLight_LED, LOW);
}
void WiFiLEDTurnOn() {
	digitalWrite(kWiFiLED_WiFiLED, HIGH);
}
void WiFiLEDTurnOff() {
	digitalWrite(kWiFiLED_WiFiLED, LOW);
}
void ErrorDisplayShowNormalModeCode() {
	digitalWrite(kErrorDisplay_a, LOW );
			digitalWrite(kErrorDisplay_b, LOW );
			digitalWrite(kErrorDisplay_c, LOW );
			digitalWrite(kErrorDisplay_d, LOW );
}
void ErrorDisplayShowNoConnectionModeCode() {
	digitalWrite(kErrorDisplay_a, HIGH);
			digitalWrite(kErrorDisplay_b, LOW );
			digitalWrite(kErrorDisplay_c, LOW );
			digitalWrite(kErrorDisplay_d, LOW );
}
int DebugButtonMonitored() {
	int state = digitalRead(kDebug_DebugButton);
			return state;
}
