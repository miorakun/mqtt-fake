#include <WiFi.h>
extern "C" {
#include "freertos/FreeRTOS"
#include "freertos/timers.h"
}
#include <AsyncMqttClient.h>
#include <credentials.h>


#define MQTT_HOST IPAddress(192,168,1,112)
#define MQTT_PORT 1883
#define SHORT_SPACE 250
#define SHORT_SIG 350
#define BETW 16000
#define SEND_PIN 4

String extendCommand = "LGSPSPSPSPSPSPSPLGSPLGLGLGSPLGSPSPSN";
String reteractCommand = "LGSPSPSPSPSPSPSPLGSPLGLGLGSPLGSPLGSN";

String manCommand = "LGSPSPSPSPSPSPSPLGSPLGLGLGLGLN";
String autoCommand = "LGSPSPSPSPSPSPSPLGSPLGLGSPLGLGLGLGSN";

void sendSig(String sig) {
    if (duration < 1)duration =1 ;
    if (duration > 90)duration = 90;
    unsigned long entry = millis();
}