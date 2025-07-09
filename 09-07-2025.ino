#include <DHT.h>


#define DHTPIN 2          
#define DHTTYPE DHT22     

#define MQ2_PIN A0        
#define BUZZER_PIN 8     

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW); 
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int gasValue = analogRead(MQ2_PIN);

 
  Serial.print("Nhiệt độ: "); Serial.print(temperature); Serial.println(" *C");
  Serial.print("Độ ẩm: "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Giá trị khí gas: "); Serial.println(gasValue);

 
  if (temperature > 30 || gasValue > 500) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW); 
  }

  delay(1000); 
}