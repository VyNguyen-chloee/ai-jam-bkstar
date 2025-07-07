#include <LiquidCrystal_I2C.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

DHT dht(4, DHT11);
void setup() {
  // put your setup code here, to run once:
  
  lcd.init();
  lcd.backlight();
  dht.begin();
  lcd.print("xin chao");

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,1);
  lcd.print(dht.readTemperature());
  lcd.setCursor(0,3);
  lcd.print(dht.readHumidity());
}

