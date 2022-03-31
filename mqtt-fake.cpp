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
    while (millis()<entry + duration + 1000){
      for (int i = 0; i< sig.length(); i++){
        switch (sig[i]){
          case 'S':// short pulse freq
            sigPuls(SHORT_SIG);
            break;
          case 'L':
            sigPuls(LONG_SIG_DIST);
            break;
          case 'G':
            delayMicroseconds(SHORT_SPACE);
            break;
          case 'P':
            delayMicroseconds(LONG_SIG_DIST);
            break;
          case 'N':
            delayMicroseconds(BETW);
            break;
          default:
            Serial.println("Error");
            break;
        }
      }
    // serial printing the signals on mqtt
  }
}

void sigPuls(int duration){
    digitalWrite(SEND_PIN, HIGH);
    delayMicroseconds(duration);
    degitalWrite(SEND_PIN,LOW);
}
