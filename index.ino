//#include "lcd.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

#define SET_BUTTON 11
#define SECONDS_BUTTON 12

Servo servo;
rgb_lcd lcd;

int counter = 0; 
String timerState = "UNLOCKED";

void setup() {
    Serial.begin(115200);
    lcd.begin(16, 2);
    servo.attach(9);
    servo.write(180);
    pinMode(SET_BUTTON, INPUT);
    pinMode(SECONDS_BUTTON, INPUT);
    delay(1000);
}

void loop() {
    Serial.println(timerState);
    Serial.println(digitalRead(SET_BUTTON));
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("JUUL is ");
    lcd.print(timerState);
    lcd.setCursor(0, 1);
    lcd.print(counter);
    lcd.print(" seconds left");

    if(timerState == "LOCKED") {
        servo.write(0);
        if(counter < 1) {
            timerState = "UNLOCKED";
        }
        else {
            counter--;
        }
    }
    else if (timerState == "UNLOCKED") {
        servo.write(180);

        if(digitalRead(SET_BUTTON) == HIGH) {
            timerState = "SET";
        } 
    }
    else if (timerState == "SET") {
        if(digitalRead(SECONDS_BUTTON) == HIGH) {
            counter = counter + 5;
        }
        else if (digitalRead(SET_BUTTON) == HIGH && counter > 5) {
            timerState = "LOCKED";
        }
    }
    delay(1000);
}
