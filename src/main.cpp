#include <Arduino.h>
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 8;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature;
  float humidity;

  if(dht_sensor.measure(&temperature, &humidity)){
    Serial.print("T = ");
    Serial.print(temperature, 1);
    Serial.print("deg. C, H = ");
    Serial.print(humidity, 1);
    Serial.println("%");
  }
}
