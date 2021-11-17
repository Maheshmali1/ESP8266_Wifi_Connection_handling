/* This program connect the ESP8266 to wifi using ESP8266WiFi.h library.
 *  It takes into consideration the following situations:
 *   1) Normally when Node MCU board is plugged in it will connect to saved wifi network details.
 *   2) When our wifi router get switch OFF the wifi connection on board will be disconnected and when wifi router switches ON then     
 *      it will try to reconnect with saved wifi details.
 *   3) when we press the RESET button on board it will wipe the saved details of wifi and ask for new details.
 *
 */

#include<ESP8266WiFi.h>
void wifi_setup();
void setup() {
  Serial.begin(9600);
   WiFi.begin("ESP_Project","esp8266_project");
   wifi_setup();
}

void loop() {
  int reason = ESP.getResetInfoPtr()->reason;
  if(reason == REASON_DEEP_SLEEP_AWAKE){
    WiFi.disconnect(true);
    Serial.println("Wifi data has been wiped. Please Give new Wifi SSID and Password.");
     
  }
  if(WiFi.status() != WL_CONNECTED){
    wifi_setup();
    delay(1000);
  }
 
}

void wifi_setup(){
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("Not connected");
    }
   Serial.println();
   Serial.println("Wifi connected");
   Serial.println("Wifi Name : ESP_Project");
}
