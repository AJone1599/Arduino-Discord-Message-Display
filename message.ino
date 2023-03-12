// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Contrast=75;
void setup() {
  analogWrite(6,Contrast);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("start");
}

void loop() {
  if (Serial.available()) {
    delay(100);  //wait some time for the data to fully be read
    lcd.clear();
    while (Serial.available() > 0) {
      char c = Serial.read();
      lcd.print(c);
      Serial.print(c);
      //delay(1000);
    }
    lcd.setCursor(0,1);  //Display position
    lcd.print("Test");
  }
}
