//#include "lcd.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

#define BUTTON_PIN 12

Servo servo;
rgb_lcd lcd;

int counter = 10; 
String timerState = "LOCKED";

void setup() {
    Serial.begin(115200);
    lcd.begin(16, 2);
    servo.attach(9);
    servo.write(0);
    pinMode(BUTTON_PIN, INPUT);
    delay(1000);
}

void loop() {
    counter--;
    Serial.println(counter);
    Serial.println(digitalRead(BUTTON_PIN));
    if (digitalRead(BUTTON_PIN) == HIGH) {
        counter = counter + 5;
    }
    if (counter > 0) {
        timerState = "LOCKED";
        lcd.setCursor(0, 0);
        lcd.print("JUUL is ");
        lcd.print(timerState);
        lcd.setCursor(0, 1);
        lcd.print(counter);
        lcd.print(" seconds left");
    }
    else if (counter <= 0) {
        timerState = "UNLOCKED";
        counter = 0;
        lcd.setCursor(0, 0);
        lcd.print("JUUL is ");
        lcd.print(timerState);
        lcd.setCursor(0, 1);
        lcd.print(counter);
        lcd.print(" seconds left");
        servo.write(180);
    }
    delay(1000);
}
