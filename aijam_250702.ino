#include <DHT.h>
#define DHTTYPE DHT22
#define DHTPIN 2

DHT dhtSensor(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dhtSensor.begin();

}

void loop() {
  float temp = dhtSensor.readTemperature();
  float humid = dhtSensor.readHumidity();
  Serial.print("Nhiet do: ");
  Serial.println(temp);
  Serial.print("Do am: ");
  Serial.println(humid);

  delay(2000);
}
